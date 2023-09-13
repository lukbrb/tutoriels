#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"affichage.h"


// int size_string(char mot[]); IL existe strlen dans la bibliothèque string.h
char lireCaractere();
int findLetter(char letter, char letters_found[]);
int nombreLettresTrouvees(char motsecret[], char lettres_trouvees[]);

char mot_mystere[] = "LUCASBARBIER";

int main() {
    // int indices_found[] = {};
    char currentchar = 0;
    int viesRestante = 10;
    int LetterPresent = 0;
    int current_count, total_count = 0;
    char* letters_found = NULL;
    int len_mot = strlen(mot_mystere);
    letters_found = (char*) malloc(len_mot * sizeof(char));

    if(letters_found == NULL){
        exit(0);
    }

    print_bienvenue();
    printf("Le mot mystère fait %d lettres\n\n", len_mot);

    while (viesRestante > 0){
        printf("\n\n%d vies restantes !\n", viesRestante);
        printf("Entrer votre lettre: ");
        currentchar = lireCaractere();
        LetterPresent = findLetter(currentchar, letters_found);

    if (!LetterPresent) { // La lettre n'est pas dans le mot
        viesRestante -= 1;
    }

        printMotMystere(mot_mystere, letters_found);
        if (nombreLettresTrouvees(mot_mystere, letters_found) == len_mot){
            printf("Félicitations, le mot %s est trouvé !\n", mot_mystere);
            break;
        }
    }
    free(letters_found);
    return 0;
}

int nombreLettresTrouvees(char motsecret[], char lettres_trouvees[]){
    int compteur = 0;
    for (int i = 0; i < strlen(motsecret); i++){
        if (motsecret[i] == lettres_trouvees[i]){
            compteur += 1;
        }
    }
    return compteur;
}

char lireCaractere() {
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n');

    return caractere;
}

int findLetter(char letter, char letters_found[]){
    int isLetterPresent = 0;
    int lenMot = strlen(mot_mystere);
    // Verifie si la lettre & déjà été entrée
    for(int i = 0; i <= lenMot; i++){
        if (letters_found[i] == letter){
            return 1999;
        }
    }
    for(int i = 0; i <= lenMot; i++){
        if (mot_mystere[i] == letter){
            letters_found[i] = letter;
            isLetterPresent = 1;
        }
    }
    return isLetterPresent;
}
