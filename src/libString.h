#include <stdlib.h>

/* UTILS */
unsigned int len(char *str);

/* CASE */
char *capitalize(char *str);
char *casefold(char *str);

/* ALLIGN */
char *center(char * str, unsigned int width);
char *expandtabs(char *str, unsigned int tabsize);