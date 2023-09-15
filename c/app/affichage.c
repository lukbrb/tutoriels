#include<stdio.h>
#include<string.h>

#include "affichage.h"


void print_bienvenue(){
    printf(BLANC "---------------------------------------\n");
    printf(BLANC "Bienvenue dans le jeu du pendu en C !\n" RESET);
    printf(BLANC "---------------------------------------\n");
    printf(JAUNE "Vous avez 10 vies pour déterminer le mot mystère...\n" RESET);
}


void printMotMystere(char motmystere[], char letters_found[]){
    int lenMot = strlen(motmystere);
    for(int i = 0; i < lenMot; i++){
            if(motmystere[i] == letters_found[i]){
                printf(BLANC "%c" RESET, motmystere[i]);
            }
            else {
                printf(BLANC "%c" RESET,'*');
            }
        }
    printf("\n");
}