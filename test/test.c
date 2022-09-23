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
    
    printf("All tests have passed.\n");
    return 0;
}