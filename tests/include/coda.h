#ifndef TEST_CODA_H
#define TEST_CODA_H
#include "../../include/dummytest.h"
#include "utilityprogramma.h"


typedef Nodo *Coda;
void enqueue(Coda *coda, Coda *testa, Ordine *ordine);
void dequeue(Coda *coda, Coda *testa, Ordine *ordine);
int execution_test_stack();
Ordine inserisci_coda();
int test_stack();

#endif
