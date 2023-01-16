#include <stdlib.h>

/* UTILS */
unsigned int len(char *str);
unsigned int count(char *str, char *sub);
int index(char *str, char *sub);
char *join(char *str, char **iterable, int list_length);
char *ljust(char *str, size_t width, char fillchar);
char *lstrip(char *str, char *chars);
char *removeprefix(char *str, char *prefix);

/* CASE */
char *capitalize(char *str);
char *casefold(char *str);

/* ALLIGN */
char *center(char * str, unsigned int width);
char *expandtabs(char *str, unsigned int tabsize);

/* COMPARE */
int endswith(char *str, char *suffix);
int py_isalnum(char *str);
int py_isalpha(char *str);
int py_isascii(char *str);
int py_isdigit(char *str);
int isidentifier(char *str);
