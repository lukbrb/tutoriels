#include<stdio.h>
#include<string.h>

#include "affichage.h"


void print_bienvenue(){
    printf(BLANC "---------------------------------------\n");
    printf(BLANC "Bienvenue dans le jeu du pendu en C !\n" RESET);
    printf(BLANC "---------------------------------------\n");
}


void printMotMystere(char motmystere[], char letters_found[]){
    int lenMot = strlen(motmystere);
    printf("\n");

    for(int i = 0; i < lenMot; i++){
            if(motmystere[i] == letters_found[i]){
                printf(BLANC "%c" RESET, motmystere[i]);
            }
            else {
                printf(BLANC "%c" RESET,'*');
            }
        }
    printf("\n\n");
}

int print_pendu(int index_print)
{
    FILE* fichier = NULL;
    int caractere_lu = 0, nb_caracteres = 0;
    char* filename = "media/dessin.txt";

    fichier = fopen(filename, "r");

    if (fichier == NULL){
        printf(ROUGE "[x] Impossible d'ouvrir le fichier '%s'\n" RESET, filename);
        return 0;
    }

    do {
        caractere_lu = fgetc(fichier);
        printf(BLANC "%c" RESET, caractere_lu);
        if (caractere_lu != '\n' && caractere_lu != ' ') nb_caracteres++;
    } while(caractere_lu != EOF && nb_caracteres < index_print);

    printf("\n");
    fclose(fichier);

    return 1;

}