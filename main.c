#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mochila.h"

MOCHILA *ForcaBruta(ITEM **todosItens, int quantItens, float pesoMaximo);
MOCHILA *Guloso(ITEM **todosItens, int quantItens, float pesoMaximo);
void ProgramacaoDinamica(ITEM **todosItens, float quantItens);

ITEM **OrdenarPorRazao(ITEM **todosItens, int quantItens);

int main(){
    float pesoMaximo;
    int quantidadeItens;
    ITEM **todosItens;
    
    //Pega o valor maximo
    printf("Digite o peso máximo da mochila: ");
    scanf(" %f", &pesoMaximo);
    
    //Cria todos os itens para inserir
    printf("Digite a quantidade de itens para inserir na mochila: ");
    scanf(" %d", &quantidadeItens);
    printf("\n");

    todosItens = (ITEM **)calloc(quantidadeItens, sizeof(ITEM *));

    for(int i = 0; i < quantidadeItens; i++){
        int chave;
        float peso, valor;
        printf("Digite a chave do item %d: ", i + 1);
        scanf(" %d", &chave);
        printf("Digite o peso do item %d: ", i + 1);
        scanf(" %f", &peso);
        printf("Digite o valor do item %d: ", i + 1);
        scanf(" %f", &valor);
        printf("\n");
        if(peso <= pesoMaximo)
            todosItens[i] = ItemCriar(peso, valor, chave);
    }

    //Solucoes

    //Forca bruta
    if(quantidadeItens <= 20){ //Se for maior que 20, vai ser extremamente demorado o processo
        MOCHILA *mochilaBruta = ForcaBruta(todosItens, quantidadeItens, pesoMaximo);
        
        MochilaEsvaziar(mochilaBruta);
        MochilaApagar(&mochilaBruta);
    }

    //Guloso
    MOCHILA *mochilaGulosa = Guloso(todosItens, quantidadeItens, pesoMaximo);

    MochilaEsvaziar(mochilaGulosa);
    MochilaApagar(&mochilaGulosa);
    
    //Programacao dinamica
    ProgramacaoDinamica(todosItens, quantidadeItens, pesoMaximo);


    //Libera a memoria dos itens e da mochila
    for(int i = 0; i < quantidadeItens; i++){
        free(todosItens[i]);
        todosItens[i] = NULL;
    }
    free(todosItens);
    todosItens = NULL;


    return 0;
}

MOCHILA *ForcaBruta(ITEM **todosItens, int quantItens, float pesoMaximo){
    if(todosItens){
        MOCHILA *mochila = MochilaCriar(pesoMaximo);

        for(int i = 0; i < quantItens; i++){
            
        }
    }

    return NULL;
}

MOCHILA *Guloso(ITEM **todosItens, int quantItens, float pesoMaximo){
    if(todosItens){
        MOCHILA *mochila = MochilaCriar(pesoMaximo);
        for(int i = 0; i < quantItens; i++){
            
        }
        return mochila;
    }

    return NULL;
}

void ProgramacaoDinamica(ITEM **todosItens, int quantItens, float pesoMaximo){
    if(todosItens){
        for(int i = 0; i < quantItens; i++){
            
        }
    }
}

ITEM **OrdenarPorRazao(ITEM **todosItens, int quantItens){
    
}