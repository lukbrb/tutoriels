#include<stdio.h>

void print_bienvenue(){
    printf("Bienvenue dans le jeu du pendu en C !\n");
    printf("Vous avez 10 vies pour déterminer le mot mystère...\n");
}


void printMotMystere(int lenMot, char motmystere[], char letters_found[]){
    int found = 1;
    for(int i = 0; i <= lenMot; i++){
            if(motmystere[i] == letters_found[i]){
                printf("%c", motmystere[i]);
            }
            else {
                printf("%c",'*');
            }
        }
    printf("\n");
}