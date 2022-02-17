#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>




 typedef struct peca {
  int direita;
  int esquerda;

}peca;


typedef peca tp_item;

typedef struct tp_no_se{
    tp_item  info;
    struct tp_no_se *prox;
   
}tp_listase;

void inverte_peca(peca *p){
    peca temp;
    
    temp.direita=p->esquerda;
    temp.esquerda=p->direita;
    p->direita=temp.direita;
    p->esquerda=temp.esquerda;

}

void imprime_peca(peca p){
  printf("[%d|%d]", p.esquerda, p.direita);

}

tp_listase * inicializa_listase(){
    return NULL;
}

int listase_vazia(tp_listase *lista){
    if(lista==NULL)return 1;
    return 0;
}

tp_listase * aloca_listase(){ // ela irá alocar um espaço na memória 
    tp_listase *novo_no;
    novo_no=(tp_listase*) malloc (sizeof(tp_listase));// vai fazer a variavel novo_no receber o endereço de memória de tp_listase
    return novo_no;
}

int insere_listase_no_fim(tp_listase **l,tp_item e){
    tp_listase *novo_no, *atu;
    atu=*l;
    
   
    novo_no=aloca_listase();
    if(novo_no==NULL) return 0; //Não alocou memória
    // atribuir os valores para o novo no;
    
    novo_no->info=e;
    novo_no->prox=NULL;
    // finaliza o encadeamento do nó

    if(listase_vazia(*l)||atu->info.direita+atu->info.esquerda>e.direita+ e.esquerda){
        peca *temp;
        temp=atu;
        novo_no->prox=temp;
        //se for o primeiro entra aq    
    *l=novo_no;
    }else{
        atu= *l;
        while (atu -> prox!= NULL){
            if(atu->prox->info.direita + atu->prox->info.esquerda >e.direita+e.esquerda){
        break;
            }
            atu=atu-> prox; // aponta para o ultimo nó
           
        }
        peca *aux;
        aux=atu->prox;
        novo_no->prox=aux;
        atu-> prox=novo_no; 
    }

return 1;


}

void imprime_listase(tp_listase *lista){
    tp_listase *atu;
    atu=lista;

    while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;
    }
}

int tamanho_listase (tp_listase *lista){
    int cont=0;
    tp_listase *atu;
    atu=lista;
    while (atu!=NULL){
        cont ++;
        atu=atu-> prox;
    }
return cont;
}

int remove_listase (tp_listase **lista ,tp_item e ){
    tp_listase *ant, *atu;
    atu=*lista;
    ant=NULL;
    
    while ((atu!= NULL) && ((atu -> info.direita!= e.direita)||(atu -> info.esquerda!= e.esquerda))){
        ant=atu;
        atu=atu-> prox;
    }
    
    if (atu==NULL)return 0;
    if (ant==NULL){
        *lista=atu -> prox;
    }
    else{
        ant-> prox=atu -> prox;
    }
    free (atu);
    atu=NULL;
    return 1;
}

peca tira_da_listase (tp_listase *lista ,int e ){
    int cont=1;
    tp_listase *atu;
    atu=lista;
    while ( cont < e){
        atu=atu-> prox;
        cont ++;
    }
    return atu->info;
}

void destroi_listase(tp_listase **l){
    tp_listase *atu;
    atu = *l;
    while (atu!=NULL){
        *l=atu->prox;
        free(atu);
        atu = *l;
    }
}


#endif