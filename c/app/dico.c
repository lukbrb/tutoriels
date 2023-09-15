#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

// Inspiré de http://user.oc-static.com/pdf/14189-apprenez-a-programmer-en-c.pdf
int piocherMot(char *motPioche){
    FILE* dico = NULL; // Pointeur vers le contenu du fichier
    int nombreMots = 0, numMotChoisi = 0;
    int caractereLu = 0;

    dico = fopen("app/dico.txt", "r");

    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire de mots.\n\n");
        return 0;
    }

    do {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);
    rewind(dico);

    while(numMotChoisi > 0){
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--; // On avance de ligne en ligne jusqu'au mot voulu
    }

    fgets(motPioche, 100, dico);

    motPioche[strlen(motPioche) - 1] = '\0'; // On enlève le '\n' à la fin.

    fclose(dico);

    return 1;
}

int nombreAleatoire(int nombreMax){
    srand(time(NULL));
    return (rand() % nombreMax);
}