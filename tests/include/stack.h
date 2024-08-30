#ifndef TEST_STACK_H
#define TEST_STACK_H
#include "../../include/dummytest.h"
#include "utilityprogramma.h"

typedef Nodo *Pila;

void pop(Pila *pila);
void push(Pila *pila, Ordine *ordine);
char* execution_test_stack();
Ordine inserisci_pila();
dummy_code_t test_stack();


#endif