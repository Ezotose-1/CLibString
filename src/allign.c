#include "libString.h"

/**
 * Function: center
 * ----------------
 *  Returns centered in a string of length width.
 *   
 *  str: The original string
 *  width: Length of the attended string
 */
char *center(char * str, unsigned int width)
{
    if (!str)
        return NULL;
    
    if (len(str) >= width)
        return str;
    
    char *res = calloc(width + 1, sizeof(char));
    unsigned int rSize = (width - len(str)) / 2;
    unsigned int lSize = width - len(str) - rSize;
    
    unsigned int pos = 0;
    for (; pos < lSize; pos++)
        res[pos] = ' ';
    for (; pos < len(str) + lSize; pos++)
        res[pos] = str[pos - lSize];
    for (; pos < width; pos++)
        res[pos] = ' ';
    
    return res;
}