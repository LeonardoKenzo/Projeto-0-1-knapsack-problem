#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"

typedef struct no_{
    ITEM *item;
    struct no_ *proximo;
    struct no_ *anterior;
}NO;

struct mochila_{
    NO *inicio;
    NO *fim;
    int quantidadeItens; //Tamanho da lista
    int pesoAtual;
    int pesoMaximo;
    int valorTotal;
};


MOCHILA *MochilaCriar(int pesoMaximo){
    //Cria a mochila
    MOCHILA *novaMochila = (MOCHILA *)calloc(1, sizeof(MOCHILA));
    if(novaMochila == NULL){
        return NULL;
    }
    //Inicializa o peso, quantidade de itens e os nos da mochila
    novaMochila->inicio = NULL;
    novaMochila->fim = NULL;
    novaMochila->quantidadeItens = 0;
    novaMochila->pesoAtual = 0;
    novaMochila->valorTotal = 0;
    novaMochila->pesoMaximo = pesoMaximo;

    return novaMochila;
}

//Funcao auxiliar usado para criar um no
NO *CriarNo(ITEM *item){
    //Cria o no
    NO *novoNo = (NO *)calloc(1, sizeof(NO));
    if(novoNo == NULL){
        return NULL;
    }
    //Inicializa o item e o proximo no 
    novoNo->item = item;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    return novoNo;
}

//Adiciona o item no começo da lista da mochila
bool MochilaAdicionarItem(MOCHILA *mochila, ITEM *item){
    if(mochila == NULL){
        return false;
    }
    //Se o peso do item estourar o peso maximo nao adiciona
    if(mochila->pesoAtual + ItemGetPeso(item) > mochila->pesoMaximo){
        return false;
    }

    //Criar um no para o item
    NO *noItem = CriarNo(item);
    if(noItem == NULL){
        return false;
    }

    //Se a mochila esta vazia
    if(MochilaEstaVazia(mochila)){
        mochila->inicio = noItem;
        mochila->fim = noItem;
    }
    //Se a mochila ja tem item
    else{
        noItem->proximo = mochila->inicio;
        mochila->inicio->anterior = noItem;
        mochila->inicio = noItem;
    }
    //Adiciona o item
    mochila->pesoAtual += ItemGetPeso(item);
    mochila->valorTotal += ItemGetValor(item);
    mochila->quantidadeItens++;
    return true;
}

//Remove o item da mochila pela chave
ITEM *MochilaRemoverItem(MOCHILA *mochila, int chave){
    NO *auxiliar;
    if(mochila != NULL && !MochilaEstaVazia(mochila)){
        auxiliar = mochila->inicio;

        //Busca o item procurado na mochila
        while(auxiliar != NULL && ItemGetChave(auxiliar->item) != chave){
            auxiliar = auxiliar->proximo;
        }

        if(auxiliar != NULL){
            //Ajusta a mochila para remover o item
            if(auxiliar == mochila->inicio)
                mochila->inicio = auxiliar->proximo;
            else
                auxiliar->anterior->proximo = auxiliar->proximo;
            if(auxiliar == mochila->fim)
                mochila->fim = auxiliar->anterior;
            else
                auxiliar->proximo->anterior = auxiliar->anterior;
            
            //Remove o item
            mochila->pesoAtual -= ItemGetPeso(auxiliar->item);
            mochila->valorTotal -= ItemGetValor(auxiliar->item);
            mochila->quantidadeItens--;

            auxiliar->proximo = NULL;
            auxiliar->anterior = NULL;

            free(auxiliar);
            return auxiliar->item;
        }
    }
    return NULL;
}

int MochilaGetValor(MOCHILA *mochila){
    if(mochila)
        return mochila->valorTotal;
    return -1;
}

int MochilaGetPeso(MOCHILA *mochila){
    if(mochila)
        return mochila->pesoAtual;
    return -1;
}

int MochilaGetQuantidadeItens(MOCHILA *mochila){
    if(mochila)
        return mochila->quantidadeItens;
    return -1;
}

bool MochilaEstaVazia(MOCHILA *mochila){
    if(mochila->inicio == NULL)
        return true;
    return false;
}

//Verifica se o item escolhido cabe na mochila
bool MochilaCabe(MOCHILA *mochila, ITEM *item){
    if(mochila && item){
        if((mochila->pesoAtual + ItemGetPeso(item)) <= mochila->pesoMaximo)
            return true;
        else
            return false;   
    }
    return false;
}

//Funcao auxiliar para apagar todos os elementos da mochila
void EsvaziarRecursivo(NO *no){
    if(no == NULL){
        return;
    }
    //Apaga os itens e nos de toda a mochila
    EsvaziarRecursivo(no->proximo);
    
    no->proximo = NULL;
    no->anterior= NULL;
    free(no);
    no = NULL;
}

bool MochilaEsvaziar(MOCHILA *mochila){
    if(mochila){
        EsvaziarRecursivo(mochila->inicio);
        mochila->inicio = NULL;
        mochila->fim = NULL;
        mochila->pesoAtual = 0;
        mochila->quantidadeItens = 0;
        mochila->valorTotal = 0;
        return true;
    }
    return false;
}

//Apaga a mochila
void MochilaApagar(MOCHILA **mochila){
    if(mochila && *mochila){
        MochilaEsvaziar(*mochila);
        free(*mochila);
        *mochila = NULL;
    }
}