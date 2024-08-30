#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct ordine
{
    char *ricetta;
    unsigned int peso;
} Ordine;

typedef struct nodo
{
    Ordine ordine;
    struct nodo *prossimo_nodo;
} Nodo;

typedef Nodo *Pila;
void push(Pila *pila, Ordine *ordine);

void push(Pila *ptr, Ordine *ordine)
{
    Nodo *nuovo_nodo = malloc(sizeof(Nodo));

    if (nuovo_nodo != NULL)
    {
        alloca_stringa(&nuovo_nodo->ordine.ricetta, ordine->ricetta);
        nuovo_nodo->ordine.peso = ordine->peso;
        nuovo_nodo->prossimo_nodo = *ptr;
        *ptr = nuovo_nodo;
    }
    else
        perror("Errore con l'allocazione del nodo della pila");
}

Ordine pop(Pila *ptr)
{
    Ordine ordine = {.ricetta = NULL, .peso = 0};

    if (*ptr != NULL)
    {
        Pila tmp = *ptr;
        ordine.ricetta = (*ptr)->ordine.ricetta;
        ordine.peso = (*ptr)->ordine.peso;
        *ptr = (*ptr)->prossimo_nodo;
        free(tmp);
    }
   
   return ordine;
}

unsigned int cerca_negli_ordini(Nodo *lista, const char *nome)
{
    unsigned int match = 0;

    if (nome == NULL)
        return 0;

    while (lista != NULL)
    {

        if (lista->ordine.ricetta != NULL && !strcmp(lista->ordine.ricetta, nome))
        {
            match = 1;
            break;
        }
        lista = lista->prossimo_nodo;
    }

    return match;
}

void print_list(Nodo* list){

    while(list != NULL){
        printf("%s %d\n", list->ordine.ricetta, list->ordine.peso);
        list = list->prossimo_nodo;
    }
}

int main()
{
    Pila pila = NULL;
    Ordine nuovo = {.ricetta = "Pasta", .peso = 10};
    Ordine nuovo2 = {.ricetta = "Tonno", .peso = 20};
    Ordine nuovo3 = {.ricetta = "Dolce", .peso = 20};

    push(&pila, &nuovo);
    push(&pila, &nuovo2);
    push(&pila, &nuovo2);
    Ordine tmp = pop(&pila);
    unsigned int test = cerca_negli_ordini(pila, "Tonnox");
    print_list(pila);
    printf("%s %d\n", tmp.ricetta, tmp.peso);
    
}