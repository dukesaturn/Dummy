#include <stdlib.h>
#include <stdio.h>
#define SIZE 256

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

typedef Nodo *Coda;

void enqueue(Coda *coda, Coda *testa, Ordine *ordine)
{
    Nodo *nuovo_nodo = malloc(sizeof(Nodo));

    if (nuovo_nodo != NULL)
    {
        nuovo_nodo->ordine = *ordine;
        nuovo_nodo->prossimo_nodo = NULL;

        if (*testa == NULL)
        {
            *testa = nuovo_nodo;
            (*testa)->prossimo_nodo = NULL;
        }
        else
        {
            (*coda)->prossimo_nodo = nuovo_nodo;
        }

        *coda = nuovo_nodo;
    }
    else
        perror("Errore con l'allocazione del nodo per la coda");
}

Ordine dequeue(Coda *coda, Coda *testa)
{
    Ordine ordine = {.ricetta = NULL, .peso = 0};

    if (*testa != NULL)
    {
        Nodo *tmp = *testa;
        ordine.ricetta = tmp->ordine.ricetta;
        ordine.peso = tmp->ordine.peso;
        *testa = (*testa)->prossimo_nodo;
        free(tmp);
    }
    return ordine;
}

void print_list(Nodo *list)
{

    while (list != NULL)
    {
        printf("%s %d\n", list->ordine.ricetta, list->ordine.peso);
        list = list->prossimo_nodo;
    }
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


int main()
{
    Coda coda = NULL;
    Coda testa = NULL;
    Ordine nuovo = {.ricetta = "Pasta", .peso = 10};
    Ordine nuovo2 = {.ricetta = "Tonno", .peso = 20};
    Ordine nuovo3 = {.ricetta = "Dolce", .peso = 20};
    enqueue(&coda, &testa, &nuovo);
    enqueue(&coda, &testa, &nuovo2);
    enqueue(&coda, &testa, &nuovo3);
    Ordine tmp = dequeue(&coda, &testa);

    print_list(testa);
    unsigned int test = cerca_negli_ordini(testa, "Tonnox");

    printf("%s %d\n", tmp.ricetta, tmp.peso);
}
