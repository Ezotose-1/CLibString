#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/libString.h"

/**
 * List of all functions
 * https://docs.python.org/3/library/stdtypes.html#str.expandtabs
 */

int main(void)
{
    printf("Running tests..\n");
    
    /* String length */
    assert(len("votai Test.") == strlen("votai Test."));
    assert(len("") == strlen(""));
    assert(len(NULL) == 0);

    /* String capitalize */
    assert(strcmp(capitalize("votai Test."), "Votai test.") == 0);
    assert(strcmp(capitalize(""), "") == 0);
    assert(capitalize(NULL) == NULL);
    assert(strcmp(capitalize("aaaaaAAAA"), "Aaaaaaaaa") == 0);

    /* String casefold */
    assert(strcmp(casefold("votai Test."), "votai test.") == 0);
    assert(strcmp(casefold(""), "") == 0);
    assert(casefold(NULL) == NULL);
    assert(strcmp(casefold("aaaaaAAAA"), "aaaaaaaaa") == 0);

    /* String center */
    assert(strcmp(center("Votai Test.", 15), "  Votai Test.  ") == 0);
    assert(strcmp(center("Votai Test", 15), "   Votai Test  ") == 0);
    assert(strcmp(center("", 8), "        ") == 0);


    printf("All tests have passed.\n");
    return 0;
}