#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef DUMMY_TEST_H
#define DUMMY_TEST_H

/**
 * Internal function or macros are for inner software handling, like errors of the software, or internal logics
 */
#define _DUMMY_TX_RED "\033[31m"
#define _DUMMY_TX_GREEN "\033[32m"
#define _DUMMY_TX_YELLOW "\033[33m"
#define _DUMMY_TX_BLUE "\033[34m"
#define _DUMMY_TX_ITALIC "\033[3m"
#define _DUMMY_TX_BOLD "\033[1m"
#define _DUMMY_TX_RESET "\033[0m"
#define _DUMMY_BG_RED "\033[41m"
#define _DUMMY_BG_GREEN "\033[42m"
#define _DUMMY_BG_YELLOW "\033[43m"
#define _DUMMY_BG_BLUE "\033[44m"
#define _DUMMY_BG_MAGENTA "\033[45m"
#define _DUMMY_BG_WHITE "\033[47m"
#define _DUMMY_BG_BLACK "\033[40m"
#define _DUMMY_TX_UNDERLINE "\033[4m"
#define _DUMMY_STRINGIFY(tok) #tok
#define _TAB_SUITE_N 42
#define _TAB_TEST_N 25
#define _DUMMY_API static inline

#define _DUMMY_ERROR(code)                                                                                                                                                                                                                                                                                         \
    do                                                                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                                                                              \
        fprintf(stderr,                                                                                                                                                                                                                                                                                            \
                _DUMMY_TX_RED _DUMMY_TX_BOLD "Wrong result for :" _DUMMY_TX_RESET " %s  \n $ " _DUMMY_TX_YELLOW "%s ->" _DUMMY_TX_RESET _DUMMY_TX_ITALIC " line:" _DUMMY_TX_RESET " " _DUMMY_BG_BLUE "%d" _DUMMY_TX_RESET "," _DUMMY_TX_ITALIC " file: " _DUMMY_TX_RESET _DUMMY_BG_BLUE "%s" _DUMMY_TX_RESET "\n", \
                __func__, code, __LINE__, __FILE__);                                                                                                                                                                                                                                                               \
    } while (0)

_DUMMY_API char *_internal_calc_tab(const char *str, int n)
{
    int l = n - strlen(str);
    char *s = malloc(l + 1);

    if (!s)
        _DUMMY_ERROR("malloc");

    memset(s, ' ', l);
    s[l] = '\0';

    return s;
}

_DUMMY_API void print_logo()
{
    puts(_DUMMY_TX_BOLD "    _____                                    _______        _   \n"
                        "   |  __ \\                                  |__   __|      | |  \n"
                        "   | |  | |_   _ _ __ ___  _ __ ___  _   _     | | ___  ___| |_ \n"
                        "   | |  | | | | | '_ ` _ \\| '_ ` _ \\| | | |    | |/ _ \\/ __| __|\n"
                        "   | |__| | |_| | | | | | | | | | | | |_| |    | |  __/\\__ \\ |_ \n"
                        "   |_____/ \\__,_|_| |_| |_|_| |_| |_|\\__, |    |_|\\___||___/\\__|\n"
                        "                                       _/ |                     \n"
                        "                                     |___/                      \n" _DUMMY_TX_RESET);
}

/*
 */
typedef struct dummy_code_t
{
    int code;
    char buffer[512];
} dummy_code_t;

typedef dummy_code_t (*Dummy_test_function)();

typedef struct dummy_single_test
{
    Dummy_test_function test;
    const char *name;
} Dummy_single_test;

#define DUMMY_API static inline
#define DUMMY_TEST_SUCCESS 1
#define DUMMY_TEST_SKIP 2
#define DUMMY_TEST_ERROR 0

#define DUMMY_SUCCESS              \
    do                             \
    {                              \
        return DUMMY_TEST_SUCCESS; \
    } while (0)

#define DUMMY_SKIP              \
    do                          \
    {                           \
        return DUMMY_TEST_SKIP; \
    } while (0)

#define DUMMY_ERROR              \
    do                           \
    {                            \
        return DUMMY_TEST_ERROR; \
    } while (0)

#define DUMMY_ASSERT(actual, expected)                                                                                                                                                                                                                                                                                                                                                 \
    do                                                                                                                                                                                                                                                                                                                                                                                 \
    {                                                                                                                                                                                                                                                                                                                                                                                  \
        dummy_code_t buff = {.code = DUMMY_TEST_ERROR, .buffer = {0}};                                                                                                                                                                                                                                                                                                                 \
        snprintf(buff.buffer, sizeof(buff.buffer), _DUMMY_TX_RED _DUMMY_TX_BOLD "              Assert failed: " _DUMMY_TX_RESET "[" _DUMMY_STRINGIFY(actual) " != " _DUMMY_TX_RESET _DUMMY_STRINGIFY(expected) "] \n              " _DUMMY_TX_UNDERLINE _DUMMY_TX_YELLOW "%s ->" _DUMMY_TX_RESET _DUMMY_TX_UNDERLINE _DUMMY_TX_ITALIC " line:" _DUMMY_TX_RESET _DUMMY_TX_UNDERLINE " " \
                                                                                                                                                                                                               "%d" _DUMMY_TX_RESET _DUMMY_TX_UNDERLINE "," _DUMMY_TX_ITALIC " file: " _DUMMY_TX_RESET _DUMMY_TX_UNDERLINE "%s" _DUMMY_TX_RESET "\n",                                  \
                 __func__, __LINE__, __FILE__);                                                                                                                                                                                                                                                                                                                                        \
        return buff;                                                                                                                                                                                                                                                                                                                                                                   \
    } while (0)

#define DUMMY_END                                                    \
    dummy_code_t buff = {.code = DUMMY_TEST_SUCCESS, .buffer = {0}}; \
    return buff;

DUMMY_API void dummy_test_suite(Dummy_single_test tests[], int lenght, const char *name)
{
    dummy_code_t local_code;
    char *tab_name = _internal_calc_tab(name, _TAB_SUITE_N);
    printf(_DUMMY_TX_BOLD _DUMMY_BG_BLUE "SUITE" _DUMMY_TX_RESET _DUMMY_BG_BLUE "                   %s %s" _DUMMY_TX_RESET "\n", name, tab_name);
    puts("-------------------------------------------------------------------");

    int n_tests = 0;

    struct timespec before, after;

    for (int i = 0; i < lenght; i++)
    {
        timespec_get(&before, TIME_UTC);
        local_code = tests[i].test();
        timespec_get(&after, TIME_UTC);
        int local_state = local_code.code;
        long int diff_ns = after.tv_nsec - before.tv_nsec;
        char *tab = _internal_calc_tab(tests[i].name, _TAB_TEST_N);

        switch (local_state)
        {
        case DUMMY_TEST_SUCCESS:
            printf(_DUMMY_BG_GREEN _DUMMY_TX_BOLD "%d.       PASS " _DUMMY_TX_RESET _DUMMY_TX_ITALIC "          %s %s" _DUMMY_TX_RESET " %ldns\n", i + 1, tests[i].name, tab, diff_ns);
            n_tests++;
            continue;
        case DUMMY_TEST_SKIP:
            printf(_DUMMY_BG_YELLOW _DUMMY_TX_BOLD "%d.       SKIP " _DUMMY_TX_RESET _DUMMY_TX_ITALIC "          %s %s" _DUMMY_TX_RESET " %ldns\n", i + 1, tests[i].name, tab, diff_ns);
            n_tests++;
            continue;
        case DUMMY_TEST_ERROR:
            printf(_DUMMY_BG_RED _DUMMY_TX_BOLD "%d.       FAIL " _DUMMY_TX_RESET _DUMMY_TX_ITALIC "          %s %s" _DUMMY_TX_RESET " %ldns\n", i + 1, tests[i].name, tab, diff_ns);
            printf("%s\n", local_code.buffer);
            n_tests++;
            continue;
        }

        free(tab);
    }
    puts("-------------------------------------------------------------------");
    printf("Executed: %d tests\n", n_tests);
}

#endif
