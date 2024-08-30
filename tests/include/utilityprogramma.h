#define SIZE 256

typedef struct ordine
{
    const char *ricetta;
    unsigned int peso;
} Ordine;

typedef struct nodo
{
    Ordine ordine;
    struct nodo *prossimo_nodo;
} Nodo;
