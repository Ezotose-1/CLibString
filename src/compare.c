#include "libString.h"

#define IS_ALPHA(A)  ( (A >= 'a' && A <= 'z') || (A >= 'A' && A <= 'Z') ? 1 : 0)
#define IS_DIGIT(A)  (A >= '0' && A <= '9' ? 1 : 0)


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

/**
 * Function isalnum
 * ----------------
 *  Return True if all the characters are alpha numerics
 * 
 *  str: The original string
 */
int py_isalnum(char *str)
{
    for (; *str != 0; str++)
    {
        if (!IS_ALPHA(*str) && !IS_DIGIT(*str))
            return 0;
    }
    return 1;
}

/**
 * Function isalpha
 * ----------------
 *  Return True if all the characters are alpha
 * 
 *  str: The original string
 */
int py_isalpha(char *str)
{
    for (; *str != 0; str++)
    {
        if (!IS_ALPHA(*str))
            return 0;
    }
    return 1;
}