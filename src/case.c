#include "libString.h"

#define IS_MINU(A)  (A >= 'a' && A <= 'z' ? 1 : 0)
#define IS_MAJU(A)  (A >= 'A' && A <= 'Z' ? 1 : 0)

/**
 * Function: capitalize
 * --------------------
 *  Returns a copy of the string with its first character
 *          capitalized and the rest lowercased.
 *   
 *  str: The original string
 */
char *capitalize(char *str)
{
    if (!str)
        return NULL;

    char *res = calloc(len(str), sizeof(char));

    for (int i = 0; str[i] != 0; i++)
    {
        res[i] = str[i];
        if (i == 0)
        {
            if (IS_MINU(str[i]))
                res[i] -= 32;
        }
        else if (IS_MAJU(str[i]))
        {
            res[i] += 32;
        }
    }
    return res;
}

/**
 * Function: casefold
 * ------------------
 *  Returns a casefolded copy of the string.
 *   
 *  str: The original string
 */
char *casefold(char *str)
{
    if (!str)
        return NULL;

    char *res = calloc(len(str), sizeof(char));

    for (int i = 0; str[i] != 0; i++)
    {
        res[i] = str[i];
        if (IS_MAJU(str[i]))
        {
            res[i] += 32;
        }
    }
    return res;
}