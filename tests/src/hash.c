#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


unsigned int funzione_hash(const char *chiave)
{
    unsigned valore = 0;
    while (*chiave != 0)
    {
        valore += *chiave;
        ++chiave;
    }

    double tmp = (valore * costante_Knuth);
    double parte_frazionaria = tmp - (int)tmp;
    valore += (int)(parte_frazionaria * GRANDEZZA_HASH);
    return 1;
}

void insert_Ricettario(Ricetta *Ricettario, Ricetta *ricetta)
{
    unsigned int valore = funzione_hash(ricetta->nome);

    if (Ricettario[valore].nome == NULL)
    {
        Ricettario[valore] = *ricetta;
    }
}

Ricetta get_Ricettario(Ricetta *Ricettario, const char *chiave)
{
    unsigned int valore = funzione_hash(chiave);
    Ricetta tmp = Ricettario[valore];
    return tmp;
}

void delete_Ricettario(Ricetta *Ricettario, const char *chiave)
{
    unsigned int valore = funzione_hash(chiave);
    if (Ricettario[valore].nome != NULL)
    {
        free(Ricettario[valore].nome);
        Ricettario[valore].nome = NULL;
        free(Ricettario[valore].ingredienti);
        Ricettario[valore].ingredienti = NULL;
    }
}

void inizializza_ricettario(Ricetta *Ricettario)
{
    for (int i = 0; i < GRANDEZZA_HASH; i++)
    {
        Ricettario[i].nome = NULL;
        Ricettario[i].ingredienti = NULL;
    }
}


/**
 * Magazzino.... hashtable con concatenamento dove ogni elemento è un array(dinamico) di puntatori a liste doppiamente concatenate.
 * Dato che si prende sempre il primo elemento, non c'è nessun overhead particolare
 *
 * Il Ricettario invece è un hastable che va per ispezione.
 */
// int main()
// {
//     char input[256];
//     Ricetta Ricettario[GRANDEZZA_HASH];
//     inizializza_ricettario(Ricettario);
//     Ricetta Pasta = {.nome = "Pasta", .ingredienti = NULL};
//     insert(Ricettario, &Pasta);
//     Ricetta tmp = get(Ricettario, "Pasta");
//     printf("%s\n", tmp.nome);
// }

