#include <stdlib.h>

/* UTILS */
unsigned int len(char *str);
unsigned int count(char *str, char *sub);
int index(char *str, char *sub);

/* CASE */
char *capitalize(char *str);
char *casefold(char *str);

/* ALLIGN */
char *center(char * str, unsigned int width);
char *expandtabs(char *str, unsigned int tabsize);

/* COMPARE */
int endswith(char *str, char *suffix);
int py_isalnum(char *str);