#include "libString.h"


/**
 * Function: len
 * -------------
 *  Returns the length of the given string
 *   
 *  str: The original string
 */
unsigned int len(char *str)
{
    if (!str)
        return 0;
    int l = 0;
    for (; str[l] != 0; l++)
        ;
    return l;
}