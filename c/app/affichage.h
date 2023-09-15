#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE

struct Couleurs {
    char* VERT; // = "[\x1B[48;5;2m  ]";
    char* JAUNE; // = "[\x1B[48;5;3m  ]";
    char* ROUGE; // = "[\x1B[48;5;1m  ]";
};

void printMotMystere(char motmystere[], char letters_found[]);
void print_bienvenue();

#endif


