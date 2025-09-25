#ifndef ITEM_H
    #define ITEM_H

    typedef struct item_ ITEM;

    ITEM *ItemCriar(float peso, float valor, int chave);
    float ItemGetValor(ITEM *item);
    float ItemGetPeso(ITEM *item);
    int ItemGetChave(ITEM *item);
    void ItemApagar(ITEM **item);

#endif