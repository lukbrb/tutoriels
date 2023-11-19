#ifndef BUILDER_H

#define BUILDER_H


# if defined(__GNUC__)
# define CC "gcc"
# elif defined(__clang__)
# define CC "clang" 
# endif

#define CMD CC " pendu/*.c -o build/pendu"

#endif // BUILDER_H