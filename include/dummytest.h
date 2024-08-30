#include <stdio.h>

#ifndef DUMMY_TEST_H
#define DUMMY_TEST_H

#define DUMMY_TEST_SUCCESS 1
#define DUMMY_TEST_ERROR 0
#define DUMMY_TEST_RED "\033[31m"
#define DUMMY_TEST_GREEN "\033[32m"
#define DUMMY_TEST_YELLOW "\033[33m"
#define DUMMY_TEST_BLUE "\033[36m"
#define DUMMY_TEST_ITALIC "\033[3m"
#define DUMMY_TEST_RESET "\033[0m"

typedef unsigned int dummy_code_t;

typedef dummy_code_t (*Dummy_test_function)();

typedef struct dummy_single_test
{
    Dummy_test_function test;
    const char *name;
} Dummy_single_test;

void dummy_test_main(Dummy_single_test tests[], int lenght, const char* name);

#define DUMMY_ASSERT_MSG(message)                                \
    do                                                           \
    {                                                            \
        fprintf(stderr, DUMMY_TEST_RED "Assertion failed: %s\n", \
                message ? message : "");                         \
    } while (0)

#define DUMMY_ASSERT_CONTEXT()                                       \
    do                                                               \
    {                                                                \
        fprintf(stderr, DUMMY_TEST_YELLOW "\tFile: %s\n", __FILE__); \
        fprintf(stderr, "\tLine: %d\n" DUMMY_TEST_RESET, __LINE__);  \
    } while (0)

#define DUMMY_GET_POINTER(ptr)                                    \
    do                                                            \
    {                                                             \
        fprintf(stderr, "\tFile pointer 1: %p\n", (void *)(ptr)); \
    } while (0)

#define dummy_assert(actual, expected, message) \
    do                                          \
    {                                           \
        if (actual != expected)                 \
        {                                       \
            DUMMY_ASSERT_MSG(message);          \
            DUMMY_ASSERT_CONTEXT();             \
            exit(EXIT_FAILURE);                 \
        }                                       \
    } while (0)

void dummy_assert_null(void *ptr);
void dummy_assert_string(const char *s1, const char *s2, const char *message);

#endif
