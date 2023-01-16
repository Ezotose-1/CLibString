#include "libString.h"
#include <stdlib.h>
#include <string.h>

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

/**
 * Function: join
 * --------------------
 *  Returns A new build string that concat all string of the
 *          iterable. The separator between elements is the
 *          string provided.
 * 
 *  str: Separator
 *  iterable: List of strings
 *  list_length: Length of the string
 */
char *join(char *str, char **iterable, int list_length)
{
    int length = len(str) * (list_length - 1);
    for (int i = 0; i < list_length; i++)
        length += len(iterable[i]);

    char *new_str = calloc(length + 1, sizeof(char));
    int pos = 0;

    for (int j = 0; j < list_length; j++)
    {
        char *e = iterable[j];
        for (size_t k = 0; k < len(e); k++)
            new_str[pos++] = e[k];
        if (j != list_length - 1)
        {
            for (size_t k = 0; k < len(str); k++)
                new_str[pos++] = str[k];
        }
    }

    return new_str;
}

/**
 * Function: ljust
 * --------------------
 *  Returns A new build string that contains the
 *          original string left adjusted with the fillchars.
 * 
 *  str: Original string.
 *  width: Length of the new string.
 *  fillchar: Char to fill the new string adjustement.
 */
char *ljust(char *str, size_t width, char fillchar)
{
    size_t length = len(str);
    if (width > length)
        length += width - length;

    char *new_str = calloc(length + 1, sizeof(char));
    for (size_t pos = 0; pos < length; pos++)
    {
        if (pos < len(str))
            new_str[pos] = str[pos];
        else
            new_str[pos] = fillchar;
    }
    return new_str;
}

/**
 * Function: lstrip
 * --------------------
 *  Returns A new build string with all left
 *          padding stripped.
 * 
 *  str: Original string.
 *  chars: The left padding chars to remove.
 */
char *lstrip(char *str, char *chars)
{
    /* Count the left space */
    int lspace = 0;
    size_t i = 0;
    for (; i < len(str); i++)
    {
        int isin = 0;
        for (size_t j = 0; j < len(chars); j++)
        {
            if (str[i] == chars[j])
            {
                isin = 1;
                break;
            }
        }

        if (isin)
            lspace++;
        else
            break;
    }

    /* Build the new string */
    char *new_str = calloc(len(str) - lspace + 1, sizeof(char));
    for (; i < len(str); i++)
        new_str[i - lspace] = str[i];

    return new_str;
}

/**
 * Function: removeprefix
 * --------------------
 *  Returns A new build string with prefix removed
 * 
 *  str: Original string.
 *  prefix: The prefix we're looking to remove.
 */
char *removeprefix(char *str, char *prefix)
{
    if (count(str, prefix) == 0)
        return strcpy(calloc(sizeof(str) + 1, sizeof(char)), str);
    
    for (size_t i = 0; i < len(prefix); i++)
    {
        if (str[i] != prefix[i])
            return strcpy(calloc(sizeof(str) + 1, sizeof(char)), str);
    }

    char *new_str = calloc(len(str) - len(prefix) + 1, sizeof(char));
    int pos = 0;
    for (size_t i = len(prefix); i < len(str); i++)
    {
        new_str[pos++] = str[i];
    }

    return new_str;
}
