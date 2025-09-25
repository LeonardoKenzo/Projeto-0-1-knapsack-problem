#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mochila.h"

void ForcaBruta(ITEM **todosItens, int quantItens, float pesoMaximo);
void Guloso(ITEM **todosItens, int quantItens, float pesoMaximo);
void ProgramacaoDinamica(ITEM **todosItens, int quantItens, float pesoMaximo);

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
        float peso, valor;
        printf("Digite o peso do item %d: ", i + 1);
        scanf(" %f", &peso);
        printf("Digite o valor do item %d: ", i + 1);
        scanf(" %f", &valor);
        printf("\n");
        if(peso <= pesoMaximo){
            todosItens[i] = ItemCriar(peso, valor, i + 1);
        }
    }

    //Forca Bruta
    ForcaBruta(todosItens, quantidadeItens, pesoMaximo);

    /*//Guloso
    MOCHILA *mochilaGulosa = Guloso(todosItens, quantidadeItens, pesoMaximo);

    MochilaEsvaziar(mochilaGulosa);
    MochilaApagar(&mochilaGulosa);
    
    //Programacao dinamica
    ProgramacaoDinamica(todosItens, quantidadeItens, pesoMaximo);

    */
    //Libera a memoria dos itens e da mochila
    for(int i = 0; i < quantidadeItens; i++){
        free(todosItens[i]);
        todosItens[i] = NULL;
    }
    free(todosItens);
    todosItens = NULL;


    return 0;
}

void ForcaBruta(ITEM **todosItens, int quantItens, float pesoMaximo){
    //Limita a quantidade de itens para 25, se for maior que isso fica muito longo
    if(todosItens && quantItens <= 25){
        //Medir o tempo de execução
        clock_t inicio, fim;
        double tempoExec;
        inicio = clock();

        MOCHILA *mochila = MochilaCriar(pesoMaximo);
        float melhorValor = 0, melhorPeso = 0;
        int melhorCombinacao;

        //2^quantItens Ex: 16 combinacoes = 10000 binario
        int totalCombinacoes = 1 << quantItens;
        
        //Testa todas as combinacoes possiveis
        for(int combinacoes = 1; combinacoes < totalCombinacoes; combinacoes++){
            //Garante que a mochila esta vazia
            MochilaEsvaziar(mochila);
            bool combinacaoValida = true;

            //Teste de combinacoes de itens
            for(int i = 0; i < quantItens; i++){
                //Seleciona o item a ser adicionado na mochila através de operacao com bits
                if(combinacoes & (1 << i)){
                    if(MochilaCabe(mochila, todosItens[i])){
                        MochilaAdicionarItem(mochila, todosItens[i]);
                    }
                    else{
                        combinacaoValida = false;
                        break;
                    }
                }
            }

            //Escolhe a melhor combinacao
            if(combinacaoValida && MochilaGetValor(mochila) >= melhorValor){
                melhorValor = MochilaGetValor(mochila);
                melhorPeso = MochilaGetPeso(mochila);
                melhorCombinacao = combinacoes;
            }
        }
        
        //Printa todas as informacoes do resultado
        printf("Método por Força Bruta!\n");
        printf("Melhor Peso: %.2f\n", melhorPeso);
        printf("Melhor valor: %.2f\n", melhorValor);
        printf("Melhor combinação de itens:\n");
        for(int i = 0; i < quantItens; i++){
            if(melhorCombinacao & (1 << i)){
                printf("Item %d\n", i + 1);
            }
        }
        printf("\n");
        
        MochilaApagar(&mochila);

        //Medir tempo de execucao do codigo
        fim = clock();
        tempoExec = ((double) (fim - inicio) / CLOCKS_PER_SEC);
        printf("Tempo de execução: %.5lf segundos!\n", tempoExec);
    }  
    else
        printf("Muitos itens para calcular por força bruta! (máximo de 20 itens).\n");
}

void Guloso(ITEM **todosItens, int quantItens, float pesoMaximo){
    if(todosItens){
        MOCHILA *mochila = MochilaCriar(pesoMaximo);
        for(int i = 0; i < quantItens; i++){
            
        }
    }
}

void ProgramacaoDinamica(ITEM **todosItens, int quantItens, float pesoMaximo){
    if(todosItens){
        for(int i = 0; i < quantItens; i++){
            
        }
    }
}