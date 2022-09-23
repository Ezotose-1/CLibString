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

/**
 * Function: count
 * ---------------
 *  Returns the number of non-overlapping occurrences of
 *          substring sub in the range.
 *   
 *  str: The original string
 *  sub: Searched substring
 */
unsigned int count(char *str, char *sub)
{
    unsigned int i = 0;
    unsigned int count = 0;
    for (unsigned int pos = 0; pos < len(str); pos++)
    {
        if (str[pos] == sub[i])
        {
            if (i == len(sub) - 1)
            {
                count++;
                i = 0;
            }
            else
                i++;
        }
        else
            i = 0;
    }
    return count;
}

/**
 * Function: index/find
 * --------------------
 *  Returns the lowest index in the string where substring sub
 *          is found.
 * 
 *  str: The original string
 *  sub: Searched substring 
 */
int index(char *str, char *sub)
{
    unsigned int i = 0;
    unsigned int startPos = len(str) + 1;

    for (unsigned int pos = 0; pos < len(str); pos++)
    {
        if (str[pos] == sub[i])
        {
            startPos = (startPos > len(str)) ? pos : startPos;
            if (i == len(sub) - 1)
            {
                return startPos;
            }
            else
                i++;
        }
        else
        {
            i = 0;
            startPos = -1;
        }
    }
    return -1;
}