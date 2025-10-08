#ifndef MOCHILA_H
    #define MOCHILA_H
    #include <stdbool.h>
    #include "item.h"

    typedef struct mochila_ MOCHILA;

    MOCHILA *MochilaCriar(int pesoMaximo);
    ITEM *MochilaRemoverItem(MOCHILA *mochila, int chave);
    int MochilaGetValor(MOCHILA *mochila);
    int MochilaGetPeso(MOCHILA *mochila);
    int MochilaGetQuantidadeItens(MOCHILA *mochila);
    bool MochilaAdicionarItem(MOCHILA *mochila, ITEM *item);
    bool MochilaCabe(MOCHILA *mochila, ITEM *item);
    bool MochilaEstaVazia(MOCHILA *mochila);
    bool MochilaEsvaziar(MOCHILA *mochila);
    void MochilaApagar(MOCHILA **mochila);

#endif