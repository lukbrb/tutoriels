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

// Messages affichés à l'écran

#define FR_CHOIXLANGUE "Vous avez choisi %s\n", 
#define EN_CHOIXLANGUE "You chose %s\n"

#define FR_LETTRE_ENTREE "La lettre %c a déjà été entrée\n"
#define EN_LETTRE_ENTREE "Letter %c has already been entered\n"

#define FR_LEN_MOT_MYSTERE "Le mot mystère fait %d lettres\n\n"
#define EN_LEN_MOT_MYSTERE "The hidden word is %d letters long\n\n"

#define FR_ENTRER_LETTRE "Entrer votre lettre : "
#define EN_ENTRER_LETTRE "Please enter a letter: "

#define FR_LETTRE_ABSENTE "%c n'est pas dans le mot mystère\n"
#define EN_LETTRE_ABSENTE "%c is not in the hidden word\n"

#define FR_VICTOIRE "Félicitations, le mot %s est trouvé\n"
#define EN_VICTOIRE "Congratulations, the hidden word is %s\n"

#define FR_DEFAITE "Perdu ! Le mot secret était : %s\n"
#define EN_DEFAITE "You lost... The hidden word is: %s\n"

void printMotMystere(char motmystere[], char letters_found[]);
void print_bienvenue();
int print_pendu(int index_print);

#endif


