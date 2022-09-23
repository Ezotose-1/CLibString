#include "libString.h"

/**
 * Function: endswith
 * ------------------
 *  Returns True if the string ends with the specified suffix
 *   
 *  str: The original string
 *  suffix: Searched suffix
 */
int endswith(char *str, char *suffix)
{
    if (len(suffix) == 0)
        return 1;
    unsigned int i = len(suffix) - 1;
    for (int pos = len(str) - 1; pos >= 0; pos--)
    {
        if (str[pos] != suffix[i])
            return 0;
        if (i == 0)
            return 1;
        i--;
    }
    return 0;
}