#ifndef ITEM_H
    #define ITEM_H

    typedef struct item_ ITEM;

    ITEM *ItemCriar(int peso, int valor, int chave);
    int ItemGetValor(ITEM *item);
    int ItemGetPeso(ITEM *item);
    int ItemGetChave(ITEM *item);
    void ItemApagar(ITEM **item);
    int ItemGetRazao(ITEM *item);

#endif