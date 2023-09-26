#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#include "builder.h"
const char *dirname = "build";

// Programme C à la façon d'un script pour construire le projet du pendu
// Exemple de : https://www.delftstack.com/fr/howto/c/mkdir-in-c/
int main(void) {

    errno = 0;
    int ret = mkdir(dirname, S_IRWXU);
    if (ret == -1) {
        switch (errno) {
            case EACCES :
                printf("the parent directory does not allow write");
                exit(EXIT_FAILURE);
            case EEXIST:
                printf("'%s' directory already exists...\n", dirname);
                break;
            case ENAMETOOLONG:
                printf("pathname is too long");
                exit(EXIT_FAILURE);
            default:
                perror("mkdir");
                exit(EXIT_FAILURE);
        }
    }

    else printf("'%s' directory created with sucess...\n", dirname);
    int return_code = system(CMD);
    if (return_code == 0){
        printf("Le programme a été compilé avec succès.\n");
        printf("Lancer ./build/pendu pour lancer le jeu.\n");
    }
    else {
        printf("La commande a échoué, avec le code d'erreur suivant: %d", return_code);
    }
    exit(EXIT_SUCCESS);
}
