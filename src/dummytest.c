#include "../include/dummytest.h"

void dummy_test_main(Dummy_single_test tests[], int lenght, const char *name)
{
    dummy_code_t local_state;
    printf("%s\n", name);
    puts("---------------------------------------------------");
    int n_tests = 0;

    for (int i = 0; i < lenght; i++)
    {
        local_state = tests[i].test();
        if (local_state)
        {
            printf(DUMMY_TEST_GREEN "%d. \t PASSED " DUMMY_TEST_RESET DUMMY_TEST_ITALIC "\t%s" DUMMY_TEST_RESET "\n" , i + 1, tests[i].name);
            n_tests++;
            continue;
        }
        printf(DUMMY_TEST_RED "%d. \t  FAILED " DUMMY_TEST_RESET DUMMY_TEST_ITALIC "\t%s"  DUMMY_TEST_RESET"\n", i+1,  tests[i].name);
    }
    puts("---------------------------------------------------");
    printf("Executed: %d tests\n", n_tests);
}
