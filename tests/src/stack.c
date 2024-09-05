#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/stack.h"

void push(Pila *pila, Ordine *ordine)
{
    Nodo *nuovo_nodo = malloc(sizeof(Nodo));

    if (nuovo_nodo != NULL)
    {
        nuovo_nodo->ordine = *ordine;
        nuovo_nodo->prossimo_nodo = *pila;
        *pila = nuovo_nodo;
    }
    else
        perror("Errore con l'allocazione del nodo della pila");
}

void pop(Pila *pila)
{
    if (*pila != NULL)
    {
        Pila tmp = *pila;
        *pila = (*pila)->prossimo_nodo;
        free(tmp);
    }
    else
        perror("Errore con la deallocazione del nodo della pila");
}

void ottieni_risultato(Pila pila, char *buffer)
{
    if (pila == NULL)
        return;

    while (pila != NULL)
    {
        sprintf(buffer, "Nome: %s Peso: %d\n", pila->ordine.ricetta, pila->ordine.peso);
        pila = pila->prossimo_nodo;
    }
}

Ordine inserisci_pila()
{
    char input[SIZE];
    unsigned int peso = 0;
    Ordine nuovo_ordine;
    if (scanf("%s %d", input, &peso) == 2)
    {
        nuovo_ordine.ricetta = strdup(input);
        nuovo_ordine.peso = peso;
    }

    return nuovo_ordine;
}


dummy_code_t test_stack(const char* test_name)
{
    Ordine tmp;
    Pila pila = NULL;
    // FILE *input_test;
    // FILE *output_test;
    // input_test = fopen("dataset/input_stack.txt", "r");
    // output_test = fopen("dataset/input_stack.txt", "r");
    int a = 1, b = 2;

    dummy_assert(a, b, "");
    DUMMY_SUCCESS;
    unsigned int comando = 0;
    char buffer[SIZE];

    while (1)
    {
        if (scanf("%d", &comando) != 1)
            break;

        switch (comando)
        {
        case 1:
            tmp = inserisci_pila();
            push(&pila, &tmp);
            break;
        case 2:
            pop(&pila);
            break;
        default:
            break;
        }

        if (comando != 2 && comando != 1)
            break;
    }

    ottieni_risultato(pila, buffer);
}
