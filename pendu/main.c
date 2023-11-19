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
    int viesRestante = 21, len_mot = 0, lang_version = 0;
    // int *lang_vers_point = 
    char mot_mystere[100] = {0};
    char *letters_found = NULL, *filename = NULL;
    
    print_bienvenue();

    filename = choix_langage(&lang_version);

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

    if (lang_version == 0) printf(JAUNE FR_LEN_MOT_MYSTERE RESET, len_mot);
    else if (lang_version == 1) printf(JAUNE EN_LEN_MOT_MYSTERE RESET, len_mot);
    else {
        printf("[ERREUR] Mauvaise attribution du pointeur 'lang_version'.\n");
        exit(0);
    };

    while (viesRestante > 0){
        if (lang_version == 0) printf(JAUNE FR_ENTRER_LETTRE RESET);
        else if (lang_version == 1) printf(JAUNE EN_ENTRER_LETTRE RESET);
        else {
            printf("[ERREUR] Mauvaise attribution du pointeur 'lang_version'.\n");
            exit(0);
        };
        currentchar = lireCaractere(1);
     
     // La lettre n'est pas dans le mot
    if (!findLetter(currentchar, mot_mystere, letters_found, &lang_version)) {
        viesRestante -= 1;
        if (lang_version == 0) printf(ROUGE FR_LETTRE_ABSENTE RESET, currentchar);
        else if (lang_version == 1) printf(ROUGE EN_LETTRE_ABSENTE RESET, currentchar);
        print_pendu(viesRestante);
        // printf(JAUNE "%d vies restantes !\n\n" RESET, viesRestante);
    }

    else printMotMystere(mot_mystere, letters_found);
        if (nombreLettresTrouvees(mot_mystere, letters_found) == len_mot){
            if (lang_version == 0) printf(VERT FR_VICTOIRE RESET, mot_mystere);
            else if (lang_version == 1) printf(VERT EN_VICTOIRE RESET, mot_mystere);
            break;
        }
    }
    if (viesRestante == 0){
        if (lang_version == 0) printf(ROUGE FR_DEFAITE RESET, mot_mystere);
        else if (lang_version == 1) printf(ROUGE EN_DEFAITE RESET, mot_mystere);
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

int findLetter(char letter, char mot_mystere[], char letters_found[], int *lang_vers){
    int isLetterPresent = 0;
    int lenMot = strlen(mot_mystere);
    // Verifie si la lettre & déjà été entrée
    // TODO : À optimiser
    for(int i = 0; i < lenMot; i++){
        if (letters_found[i] == letter){
            if (*lang_vers == 0) printf(FR_LETTRE_ENTREE, letter);
            else if (*lang_vers == 1) printf(EN_LETTRE_ENTREE, letter);
            else printf(FR_LETTRE_ENTREE, letter); // Le programme n'a pas de raison de planter ici.
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

char* choix_langage(int *lang_version)
{
    char initial_char_value = '0';  // Valeur de 48, les autres ne sont que des incrémentations
    int choix = 0;
    char *langage = NULL;

    print_langages();
    printf(BLANC "Votre choix : ");
    choix = lireCaractere(0) - initial_char_value;
    printf("\n" RESET);

    switch (choix)
    {
    case 1:
        langage = "francais.txt";
        *lang_version = 0;
        break;

    case 2:
        langage = "english.txt";
        *lang_version = 1;
        break;
    case 3:
        langage = "espanol.txt";
        *lang_version = 1;
        break;
    case 4:
        langage = "deutsch.txt";
        *lang_version = 1;
        break;
    case 5:
        langage = "latine.txt";
        *lang_version = 1;
        break;
    case 6:
        langage = "dansk.txt";
        *lang_version = 1;
        break;
    case 7:
        langage = "norsk.txt";
        *lang_version = 1;
        break;
    case 8:
        langage = "italiano.txt";
        *lang_version = 1;
        break;
    case 9:
        langage = "nederlands.txt";
        *lang_version = 1;
        break;
    default:
        langage = "francais.txt";
        *lang_version = 0;
        break;
    }

    if (*lang_version == 0)  printf(BLANC FR_CHOIXLANGUE RESET, langage);
    else if (*lang_version == 1) printf(BLANC EN_CHOIXLANGUE RESET, langage);
    else printf(ROUGE "[ERREUR] Mauvaise attribution du pointeur 'lang_version'.\n");
    
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