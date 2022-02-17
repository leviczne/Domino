#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
#include "listase_domino.h"


typedef peca tp_item;

typedef struct tp_no_aux {
    struct tp_no_aux *ant;
    tp_item info;
    struct tp_no_aux *prox;
}tp_no;
// dado estrturado que representa o nó da lista

typedef struct {
    tp_no  *ini;
    tp_no  *fim;

}tp_listad;
//aloca-se memória para o descritor(explicado no inicio deste arquivo)e faz o seus ponteiros apontarem para nulo

tp_listad *inicializa_listad (){
    tp_listad *lista= (tp_listad*) malloc(sizeof(tp_listad));
    lista->ini=NULL;
    lista-> fim =NULL;
    return lista;
}


int listad_vazia(tp_listad *lista){
	if(lista->ini==NULL)return 1;//verdade
	return 0;//falso
}

//aloca novo nó na lista
tp_no *aloca(){
tp_no* pt;
pt=(tp_no*) malloc (sizeof(tp_no));
return pt;
 
}

int insere_listad_no_fim (tp_listad *lista,tp_item e){

    tp_no *novo;
    novo=aloca();
    if(!novo) return 0;
    novo -> info =e ;
    if (listad_vazia(lista)){
        //se for primeiro elemento da lista
        novo -> prox =NULL;
        novo-> ant= NULL;
        lista-> ini =lista ->fim=novo;
    
    }
    else{
        novo-> prox=NULL;
        novo->ant=lista->fim;
        lista->fim->prox=novo;
        lista->fim=novo;
            }
    return 1;
}

 int insere_listad_no_inicio(tp_listad *lista, tp_item e){
    tp_no *novo;
    novo=aloca();
    if(!novo)    return 0;
    novo->info = e;

    if (listad_vazia(lista)){//Se for o primeiro elemento da lista
        novo->prox = NULL;
        novo->ant = NULL;
        lista->ini = lista->fim = novo;
    }
    else{
        novo->prox = lista->ini;
        novo->ant = NULL;
        lista->ini->ant = novo;
        lista->ini = novo;
        //lista tamanho++;
        return 1;
    }
    return 1;
}

void imprime_listad(tp_listad *lista,int ordem){
    tp_no *atu;

    switch(ordem){
        case 1: atu = lista-> ini;
         while (atu != NULL){
             imprime_peca(atu->info);
             atu=atu->prox;
         }
         break;

         case 2: atu=lista-> fim;
         while (atu != NULL){
             imprime_peca(atu->info);
             atu=atu-> ant;
         }
         break;
         default:printf("codigo invalido");


    }
    printf("\n\n");

}

int remove_listad (tp_listad *lista,tp_item e){
    tp_no *atu = lista -> ini;
    while((atu != NULL) && ((atu -> info.direita != e.direita)||(atu -> info.esquerda != e.esquerda))){
        atu=atu -> prox;}
        if(atu == NULL)return 0;
        if (lista -> ini == lista-> fim){//SE FOR O UNICO ELEMENTO NA LISTA
        lista ->ini = lista-> fim = NULL;}

        else{
            if (lista ->ini ==atu){
                //se for o primeiro elemento da lista
                lista ->ini =atu ->prox;
                atu ->prox->ant =NULL;
            }
            else {
                if(lista ->fim ==atu){
                    //se for o ultimo nó elemento da lista
                    lista ->fim =atu-> ant;
                    atu->ant->prox =NULL;
                }
                else {
                    atu->prox->ant =atu -> ant ;
                    atu->ant ->prox =atu ->prox;
                }
            }
        }

          free(atu);
          return 1;




    }

tp_listad *destroi_listad (tp_listad *lista){
        tp_no *atu;
        atu = lista -> ini;
        while(atu!= NULL){
            lista -> ini=atu ->prox;
            free(atu);
            atu =lista -> ini;
        }
        free (lista);
        return NULL;

    }
    
peca joga_invertendo(tp_listad *mesa, tp_listase *l, int posicao_peca, int opcao){
    peca aux;
    aux=tira_da_listase(l,posicao_peca);
    if(opcao==1){
        if(mesa->fim->info.direita == aux.direita ) {
            inverte_peca(&aux);
            return aux;
        }else {return aux;}
    }

    if(opcao==2){
        if(mesa->ini->info.esquerda == aux.esquerda ) {
        inverte_peca(&aux);
        return aux;
        }else{return aux;}
    }

return aux;
}

#endif