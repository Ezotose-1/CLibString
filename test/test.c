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

    /* String expandtabs */
    assert(strcmp(expandtabs("Votai\tTest.\t", 4), "Votai   Test.   ") == 0);
    assert(strcmp(expandtabs("Votai\tTest.\t", 5), "Votai     Test.     ") == 0);
    assert(strcmp(expandtabs("Votai\tTe\tst.\t", 9), "Votai    Te       st.      ") == 0);
    assert(strcmp(expandtabs("Votai\tTe\tst.\t", 10), "Votai     Te        st.       ") == 0);
    assert(strcmp(expandtabs("Votai\tTest.\t", 10), "Votai     Test.     ") == 0);
    assert(strcmp(expandtabs("Votai\tT\test.\t", 11), "Votai      T          est.       ") == 0);
    assert(strcmp(expandtabs("", 11), "") == 0);
    assert(strcmp(expandtabs("\t\t", 5), "          ") == 0);

    /* String count */
    assert(count("Votai Test.", "otai") == 1);
    assert(count("Votai Test.", "t") == 2);
    assert(count("This is a test and ist should work", "is") == 3);
    assert(count("", "is") == 0);
    assert(count("Votai Test.", "Votai Test. is the best") == 0);

    /* String endswith */
    assert(endswith("Votai Test.", "Test.") == 1);
    assert(endswith("Votai Test.", "Votai Test.") == 1);
    assert(endswith("Votai Test.", "test.") == 0);
    assert(endswith("This is a test and ist should work", "ist should work") == 1);
    assert(endswith("This is a test and ist should work", "and ist should wor") == 0);
    assert(endswith("is", "this is") == 0);
    assert(endswith("Votai Test. is the best", "Votai Test. is the best") == 1);

    assert(index("Python", "Python") == 0);
    assert(index("Python", "python") == -1);
    assert(index("Python", "thon") == 2);
    assert(index("Votai Test.", ".") == 10);


    printf("All tests have passed.\n");
    return 0;
}