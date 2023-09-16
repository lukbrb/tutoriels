#ifndef DEF_AFFICHAGE
#define DEF_AFFICHAGE


#define NORMAL  "\x1B[0m"
#define ROUGE  "\x1B[31m"
#define VERT  "\x1B[32m"
#define JAUNE  "\x1B[33m"
#define BLEU  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define BLANC  "\x1B[37m"
#define RESET "\x1B[0m"

void printMotMystere(char motmystere[], char letters_found[]);
void print_bienvenue();
int print_pendu(int index_print);

#endif


