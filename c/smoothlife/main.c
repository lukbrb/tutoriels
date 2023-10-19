#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

char level[] = " .-=coaA@#";
#define level_count (sizeof(level)/sizeof(level[0]) - 1)

float grid[HEIGHT][WIDTH] = {0};

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

int main(void){
    srand(time(0));
    for (size_t y = 0; y < HEIGHT; ++y){
        for (size_t x = 0; x < WIDTH; ++x){
            grid[y][x] = rand_float();
            // printf("%f ", grid[y][x]);
            char c = level[(int)(grid[y][x] * (level_count - 1))];
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}