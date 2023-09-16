#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "affichage.h"
#include "dico.h"


int main() {
    // int indices_found[] = {};
    char currentchar = 0;
    int viesRestante = 21;
    char mot_mystere[100] = {0};
    char* letters_found = NULL;
    int len_mot = 0;
    
    if (!piocherMot(mot_mystere))
        exit(0);
    len_mot = strlen(mot_mystere);
    letters_found = (char*) malloc(len_mot * sizeof(char));
    
    if(letters_found == NULL){
        exit(0);
    }
    for (int i = 0; i < len_mot; i++){
        letters_found[i] = '*';
    }

    print_bienvenue();
    printf(JAUNE "Le mot mystère fait %d lettres\n\n" RESET, len_mot);

    while (viesRestante > 0){
        printf(JAUNE "Entrer votre lettre: " RESET);
        currentchar = lireCaractere();

    if (!findLetter(currentchar, mot_mystere, letters_found)) { // La lettre n'est pas dans le mot
        viesRestante -= 1;
        printf(ROUGE "%c n'est pas dans le mot mystère\n" RESET, currentchar);
        print_pendu(viesRestante);
        // printf(JAUNE "%d vies restantes !\n\n" RESET, viesRestante);
    }

    else printMotMystere(mot_mystere, letters_found);
        if (nombreLettresTrouvees(mot_mystere, letters_found) == len_mot){
            printf(VERT "Félicitations, le mot %s est trouvé\n" RESET, mot_mystere);
            break;
        }
    }
    if (viesRestante == 0)
        printf(ROUGE "Perdu ! Le mot secret était : %s\n" RESET, mot_mystere);
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
    printf(JAUNE);
    caractere = getchar();
    caractere = toupper(caractere);
    printf(RESET);
    while (getchar() != '\n');

    return caractere;
}

int findLetter(char letter, char mot_mystere[], char letters_found[]){
    int isLetterPresent = 0;
    int lenMot = strlen(mot_mystere);
    // Verifie si la lettre & déjà été entrée
    for(int i = 0; i < lenMot; i++){
        if (letters_found[i] == letter){
            printf("La lettre %c a déjà été entrée\n", letter);
            return 1999;
        }
    }
    for(int i = 0; i < lenMot; i++){
        if (mot_mystere[i] == letter){
            letters_found[i] = letter;
            isLetterPresent = 1;
        }
    }
    return isLetterPresent;
}
