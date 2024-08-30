#include <stdlib.h>
#include <stdio.h>
#include "tests/include/stack.h"
#include "include/dummytest.h"

int main()
{

    Dummy_single_test tests[] = {{test_stack, "Test Stack"}, {test_stack, "Test Stack Stack"}};

    dummy_test_main(tests, 2, "Test Pasticceria");
}