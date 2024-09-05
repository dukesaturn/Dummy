#include <stdlib.h>
#include <stdio.h>
#include "tests/include/stack.h"
#include "include/dummytest.h"

int main()
{
    // print_error("Ciao Mondo");
    Dummy_single_test tests[] = {{test_stack, "Test Stack"}, {test_stack, "Test Stack Stack"}};

    dummy_test_suite(tests, 2, "Test Pasticceria");
}