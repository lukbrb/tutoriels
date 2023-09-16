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
    char* filename = NULL;
    int len_mot = 0;
    
    print_bienvenue();

    filename = choix_langage();

    if (filename == NULL){
        printf("Impossible de récupérer le langage\n");
        exit(0);
    }

    if (!piocherMot(mot_mystere, filename))
        exit(0);
    len_mot = strlen(mot_mystere);
    letters_found = (char*) malloc(len_mot * sizeof(char));
    
    if(letters_found == NULL){
        exit(0);
    }
    for (int i = 0; i < len_mot; i++){
        letters_found[i] = '*';
    }


    printf(JAUNE "Le mot mystère fait %d lettres\n\n" RESET, len_mot);

    while (viesRestante > 0){
        printf(JAUNE "Entrer votre lettre: " RESET);
        currentchar = lireCaractere(1);

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

char lireCaractere(int color) {
    char caractere = 0;
    if (color)
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

char* choix_langage()
{
    char initial_char_value = '0';  // Valeur de 48, les autres ne sont que des incrémntations
    int choix = 0;
    char* langage = NULL;
    char filename[16];

    print_langages();
    printf(BLANC "Votre choix : ");
    choix = lireCaractere(0) - initial_char_value;
    printf("\n" RESET);

    switch (choix)
    {
    case 1:
        langage = "francais.txt";
        break;

    case 2:
        langage = "english.txt";
        break;
    case 3:
        langage = "espanol.txt";
        break;
    case 4:
        langage = "deutsch.txt";
        break;
    case 5:
        langage = "latine.txt";
        break;
    case 6:
        langage = "dansk.txt";
        break;
    case 7:
        langage = "norsk.txt";
        break;
    case 8:
        langage = "italiano.txt";
        break;
    case 9:
        langage = "nederlands.txt";
        break;
    default:
        langage = "francais.txt";
        break;
    }

    printf(BLANC "Vous avez choisi %s\n" RESET, langage);

    return langage;
}

void print_langages()
{
    printf(BLANC "Choisir un langage :\n");
    printf("1 - Français\n");
    printf("2 - English\n");
    printf("3 - Espanol\n");
    printf("4 - Deutsch\n");
    printf("5 - Latine\n");
    printf("6 - Dansk\n");
    printf("7 - Norsk\n");
    printf("8 - Italiano\n");
    printf("9 - Nederlands\n" RESET);

}