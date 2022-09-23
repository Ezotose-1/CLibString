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

/**
 * Function: expandtabs
 * --------------------
 *  Returns a copy of the string where all tab characters
 *          are replaced by one or more spaces
 *
 *  str: The original string
 *  tabsize: Column given tab size
 */
char *expandtabs(char *str, unsigned int tabsize)
{
    unsigned int size  = len(str) + 1;
    char *res = calloc(size, sizeof(char));
    int i = 0;
    for (int pos = 0; str[pos] != 0; pos++)
    {
        if (str[pos] == '\t')
        {
            int complete = tabsize - i % tabsize;
            size += complete;
            res = realloc(res, size);
            for (; complete > 0; complete--)
                res[i++] = ' ';
        }
        else
            res[i++] = str[pos];
    }
    tabsize = tabsize;
    return res;
}