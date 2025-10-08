#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_{
    int peso;
    int valor;
    int chave;
};

ITEM *ItemCriar(int peso, int valor, int chave){
    //Cria o item
    ITEM *novoItem = (ITEM *)calloc(1, sizeof(ITEM));
    if(novoItem == NULL)
        return NULL;
    //Inicializa o peso e o valor do item
    novoItem->peso = peso;
    novoItem->valor = valor;
    novoItem->chave = chave;

    return novoItem;
}

int ItemGetValor(ITEM *item){
    if(item != NULL)
        return item->valor;
    return -1;
}

int ItemGetPeso(ITEM *item){
    if(item != NULL)
        return item->peso;
    return -1;
}

int ItemGetRazao(ITEM *item){
    if(item != NULL)
        return (item->valor / item->peso);
    return -1;
}

int ItemGetChave(ITEM *item){
    if(item != NULL)
        return item->chave;
    return -1;
}

void ItemApagar(ITEM **item){
    if(item != NULL && *item != NULL){
        free(*item);
        *item = NULL;
    }
}