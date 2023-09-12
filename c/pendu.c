#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


void print_bienvenue();
int size_string(char mot[]);
char lireCaractere();
int findLetter(char letter, int lenMot, int count_found, char letters_found[]);
void printMotMystere(int lenMot, char letters_found[]);

char mot_mystere[] = "LUCAS";

int main() {
    // int indices_found[] = {};
    char currentchar = 0;
    int viesRestante = 10;
    int isLetterPresent = 0;
    int current_count, total_count = 0;
    char* letters_found = NULL;
    int len_mot = size_string(mot_mystere);
    letters_found = (char*) malloc(len_mot * sizeof(char));

    print_bienvenue();
    printf("Le fait mystère fait %d lettres\n", len_mot);

    while (viesRestante > 0){
        printf("%d vies restantes !\n", viesRestante);
        printf("Entrer votre lettre: ");
        currentchar = lireCaractere();
        isLetterPresent = findLetter(currentchar, len_mot, total_count, letters_found);
    if (isLetterPresent == 1) { // La lettre n'est pas dans le mot
        viesRestante -= 1;
    }
    else if (isLetterPresent == 0) {
        total_count += 1;
        // printf("Compte total:%d", total_count);
    }

        printMotMystere(len_mot, letters_found);
        if (total_count == len_mot){
        printf("Félicitations, le mot est trouvé !\n");
        break;
    }
    }
    
    return 0;
}


void print_bienvenue(){
    printf("Bievenue dans le jeu du pendu en C !\n");
    printf("Vous avez 10 vies pour déterminer le mot mystère...\n");
}

int size_string(char mot[]) {
    int i = 0;
    while (mot[i] != '\0'){
        i++;
    }
    return i;

}

char lireCaractere() {
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n');

    return caractere;
}

int findLetter(char letter, int lenMot, int count_found, char letters_found[]){
    int count = count_found;
    int isLetterPresent = 1;
    // Verifie si la lettre & déjà été entrée
    for(int i = 0; i <= lenMot; i++){
        if (letters_found[i] == letter){
            return 1999;
        }
    }
    for(int i = 0; i <= lenMot; i++){
        if (mot_mystere[i] == letter){
            letters_found[count] = letter;
            count++; // Prendre en compte quand plusieurs lettres similaires...
            isLetterPresent = 0;
        }
    }
    return isLetterPresent;
}

void printMotMystere(int lenMot, char letters_found[]){
    int found = 1;
    for(int i = 0; i <= lenMot; i++){
        found = 1;
        for(int j = 0; j <= lenMot; j++){
            if(mot_mystere[i] == letters_found[j]){
                printf("%c", mot_mystere[i]);
                found = 0;
            }
        }
        if (found == 1){
        printf("%c", '*');
        }
    }
    printf("\n");
}
