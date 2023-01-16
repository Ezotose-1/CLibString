#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/libString.h"

/**
 * List of all functions
 * https://docs.python.org/3/library/stdtypes.html#str.expandtabs
 */

void assert_str_eq(char *str1, char *str2)
{
    assert(strcmp(str1, str2) == 0);
}

int main(void)
{
    printf("Running tests..\n");
    
    /* String length */
    assert(len("votai Test.") == strlen("votai Test."));
    assert(len("") == strlen(""));
    assert(len(NULL) == 0);

    /* String capitalize */
    assert_str_eq(capitalize("votai Test."), "Votai test.");
    assert_str_eq(capitalize(""), "");
    assert(capitalize(NULL) == NULL);
    assert_str_eq(capitalize("aaaaaAAAA"), "Aaaaaaaaa");

    /* String casefold */
    assert_str_eq(casefold("votai Test."), "votai test.");
    assert_str_eq(casefold(""), "");
    assert(casefold(NULL) == NULL);
    assert_str_eq(casefold("aaaaaAAAA"), "aaaaaaaaa");

    /* String center */
    assert_str_eq(center("Votai Test.", 15), "  Votai Test.  ");
    assert_str_eq(center("Votai Test", 15), "   Votai Test  ");
    assert_str_eq(center("", 8), "        ");

    /* String expandtabs */
    assert_str_eq(expandtabs("Votai\tTest.\t", 4), "Votai   Test.   ");
    assert_str_eq(expandtabs("Votai\tTest.\t", 5), "Votai     Test.     ");
    assert_str_eq(expandtabs("Votai\tTe\tst.\t", 9), "Votai    Te       st.      ");
    assert_str_eq(expandtabs("Votai\tTe\tst.\t", 10), "Votai     Te        st.       ");
    assert_str_eq(expandtabs("Votai\tTest.\t", 10), "Votai     Test.     ");
    assert_str_eq(expandtabs("Votai\tT\test.\t", 11), "Votai      T          est.       ");
    assert_str_eq(expandtabs("", 11), "");
    assert_str_eq(expandtabs("\t\t", 5), "          ");

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

    /* String index */
    assert(index("Python", "Python") == 0);
    assert(index("Python", "python") == -1);
    assert(index("Python", "thon") == 2);
    assert(index("Votai Test.", ".") == 10);

    assert(py_isalnum("Bonuour") == 1);
    assert(py_isalnum("Bonuou5555r") == 1);
    assert(py_isalnum("Bonuour 5555") == 0);

    assert(py_isalpha("Bonuour") == 1);
    assert(py_isalpha("Bonuou5555r") == 0);
    assert(py_isalpha("Bonuour 5555") == 0);

    assert(py_isascii("AllLetter") == 1);
    assert(py_isascii("") == 1);
    assert(py_isascii("AllLetterAndN1251545_") == 1);
    assert(py_isascii("Wrong_éééé") == 0);
    assert(py_isascii("Copyright-©") == 0);

    assert(py_isdigit("Bonuour") == 0);
    assert(py_isdigit("127215") == 1);
    assert(py_isdigit("127215") == 1);
    assert(py_isdigit("192.168.0.19") == 0);

    assert(isidentifier("192.168.0.19") == 0);
    assert(isidentifier("foo") == 1);
    assert(isidentifier("foo_bar") == 1);
    assert(isidentifier("_boo") == 1);
    assert(isidentifier("1foo") == 0);
    assert(isidentifier("foo2bar") == 1);
    assert(isidentifier("") == 0);

    char *arr[] = {"1", "2", "3", "4", "5"};
    assert_str_eq(join("-", &arr[0], 5), "1-2-3-4-5");
    char *arr2[] = {"toutseul"};
    assert_str_eq(join("-", &arr2[0], 1), "toutseul");
    char *arr3[] = {"Feuille", "Pierre", "Ciseaux"};
    assert_str_eq(join(" bats ", &arr3[0], 3), "Feuille bats Pierre bats Ciseaux");
    char *arr4[] = {"bon", "j", "our"};
    assert_str_eq(join("", &arr4[0], 3), "bonjour");

    assert_str_eq(ljust("VotaiTest.", 15, ' '), "VotaiTest.     ");
    assert_str_eq(ljust("VotaiTest.", 12, '-'), "VotaiTest.--");
    assert_str_eq(ljust("Little", 5, '-'), "Little");
    assert_str_eq(ljust("Just1", 5, '-'), "Just1");
    assert_str_eq(ljust("Just2", 6, '-'), "Just2-");

    assert_str_eq(lstrip("   spacious   ", " "), "spacious   ");
    assert_str_eq(lstrip("www.example.com", "cmowz."), "example.com");
    assert_str_eq(lstrip("spacious   ", " "), "spacious   ");
    assert_str_eq(lstrip("      .", " "), ".");
    assert_str_eq(lstrip("      ", " "), "");

    assert_str_eq(removeprefix("TestHook", "Test"), "Hook");
    assert_str_eq(removeprefix("TestHook", "Test."), "TestHook");
    assert_str_eq(removeprefix("BaseTestCase", "Test"), "BaseTestCase");
    assert_str_eq(removeprefix("BaseTestCase", "BaseT"), "estCase");
    assert_str_eq(removeprefix("esaCtseTesaB", ""), "esaCtseTesaB");
    assert_str_eq(removeprefix("esaCtseTesaB", "esaCtseTesaB"), "");

    printf("All tests have passed.\n");
    return 0;
}
