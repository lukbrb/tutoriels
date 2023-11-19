#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

char level[] = " .-=coaA@#";
#define level_count (sizeof(level)/sizeof(level[0]) - 1)

float grid[HEIGHT][WIDTH] = {0};
float grid_diff[HEIGHT][WIDTH] = {0};

// float ra = 11;
// float alpha_n = 0.028; 
// float alpha_m = 0.147;
// float b1 = 0.278;
// float b2 = 0.365;
// float d1 = 0.267;
// float d2 = 0.445;
// float dt = 0.05f; 

typedef struct Parameters {
    float ra;
    float alpha_n; 
    float alpha_m;
    float b1;
    float b2;
    float d1;
    float d2;
    float dt;
} Parameters;

void read_params(Parameters *param_struct){
    float data[8] = {0};
    size_t num_ligne = 0;
    FILE *fichier = NULL;
    char ligne[50] = "";
    fichier = fopen("parameters.config", "r");

    if (fichier != NULL){
        while (fgets(ligne, 50, fichier) && num_ligne <= 8){
            char *token = strtok(ligne, "=");
            int colonne = 0;

            while (token) {
                if (colonne % 2 != 0) data[num_ligne] = atof(token);
                colonne += 1;
                token = strtok(NULL, "=");
            }
            num_ligne += 1;
        }

        fclose(fichier);
        
        *param_struct = (Parameters) {
            .ra = data[0],
            .alpha_n = data[1],
            .alpha_m = data[2],
            .b1 = data[3],
            .b2 = data[4],
            .d1 = data[5],
            .d2 = data[6],
            .dt = data[7]
        };

    }
    else {
        fprintf(stderr, "Impossible d'ouvrir le fichier de paramètres.\n");
    }
}

int main2(void)
{   Parameters params;
    read_params(&params);
    printf("Données dans la strcuture : \n");
    printf("ra = %f\n", params.ra);
    printf("alpha_n: %f\n", params.alpha_n);
    printf("alpha_m: %f\n", params.alpha_m);
    printf("b1: %f\n", params.b1);
    printf("b2: %f\n", params.b2);
    printf("d1: %f\n", params.d1);
    printf("d2: %f\n", params.d2);
    printf("dt: %f\n", params.dt);

    return 0;
}
float rand_float(void)
{
    return (float)rand()/(float)RAND_MAX;
}

void random_grid(void)
{
    size_t w = WIDTH/3;
    size_t h = HEIGHT/3;

    for (size_t dy = 0; dy < h; ++dy){
        for (size_t dx = 0; dx < WIDTH; ++dx){
            // Centrer l'affichage
            size_t x = dx + WIDTH/2 - w/2;
            size_t y = dy + HEIGHT/2 - h/2;
            grid[y][x] = rand_float();
        }
    }
}

void display_grid(float grid[HEIGHT][WIDTH])
{
    for (size_t y = 0; y < HEIGHT; ++y){
        for (size_t x = 0; x < WIDTH; ++x){
            char c = level[(int)(grid[y][x] * (level_count - 1))];
            fputc(c, stdout);
            fputc(c, stdout);

        }
        fputc('\n', stdout);
    }
}

// Pour remettre 'num' dans les limites de la grille
int emod(int num, int container)
{
    return (num % container + container) % container;
}

float sigma(float x, float a, float alpha)
{
    return 1.0f / (1.0f + expf(-(x - a) * 4/alpha));
}

// float sigma2(float x, float a, float b)
// {
//     return sigma1(x, a) * (1 - sigma1(x, b));
// }

float sigma_n(float x, float a, float b, Parameters *params){
    return sigma(x, a, params->alpha_n) * (1 - sigma(x, b, params->alpha_n));
}

float sigma_m(float x, float y, float m, Parameters *params)
{
    return x * (1 - sigma(m, 0.5f, params->alpha_m)) + y * sigma(m, 0.5f, params->alpha_m);

}

float s(float n, float m, Parameters *params)
{
    return sigma_n(n, sigma_m(params->b1, params->d1, m, params), sigma_m(params->b2, params->d2, m, params), params);
}

void compute_grid_diff(Parameters *params)
{
    // int cx = 0;
    // int cy = 0;
    for (int cy = 0; cy < HEIGHT; ++cy){
        for (int cx = 0; cx < WIDTH; ++cx){
            float m = 0, M = 0;
            float n = 0, N = 0;
            float ri = params->ra/3;


            for (int dy = -(params->ra - 1); dy <= (params->ra -1); ++dy){
                for (int dx = -(params->ra - 1); dx <= (params->ra - 1); ++dx){
                    int x = emod(cx + dx, WIDTH);
                    int y = emod(cy + dy, HEIGHT);

                    if (dx * dx + dy * dy <= ri*ri) {
                        m += grid[y][x];
                        M += 1;
                    }
                    else if (dx * dx + dy * dy <= params->ra * params->ra) {
                        n += grid[y][x];
                        N += 1;
                    }
                }

            }
            m /= M;
            n /= N;
            float q = s(n, m, params);
            grid_diff[cy][cx] = 2 * q - 1;
            // [0, 1] -> [-1, 1]
        } 
    }
}

void clamp(float *x, float l, float h)
{
    if (*x < l) *x = l;
    if (*x > h) *x = h;
}


void apply_grid_diff(Parameters *params)
{
    for (size_t y = 0; y < HEIGHT; ++y){
        for (size_t x = 0; x < WIDTH; ++x){
                grid[y][x] += params->dt * grid_diff[y][x];
                clamp(&grid[y][x], 0, 1);
        }
    }
}

int main(void)
{   
    Parameters params;
    read_params(&params);
    srand(time(0));
    random_grid();
    display_grid(grid);
    for (;;){
        compute_grid_diff(&params);
        apply_grid_diff(&params);
        display_grid(grid);
    }
    
    return 0;
}
