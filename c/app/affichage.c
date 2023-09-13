#include<stdio.h>
#include<string.h>


void print_bienvenue(){
    printf("Bienvenue dans le jeu du pendu en C !\n");
    printf("Vous avez 10 vies pour déterminer le mot mystère...\n");
}


void printMotMystere(char motmystere[], char letters_found[]){
    int lenMot = strlen(motmystere);
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