#ifndef funcoes_jogo
#define funcoes_jogo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha_domino.h"
#include "listade_domino.h"

/*void imprime_mao(tp_listase *l){
  int i;

  for(i=0;i!=tamanho_listase(l);i++){
    imprime_peca(remove_listase(l, i));
  }
}*/

 

void criar_cava(tp_listase *lista, tp_pilha *pilha){//uso a lista qualquer
 
  srand ( time(NULL) );
  int i;
  peca temp;
   
    while(tamanho_listase(lista)>0){
		i = 1+(rand() % tamanho_listase(lista));

		temp = tira_da_listase(lista,i);
        
        remove_listase(&lista,tira_da_listase(lista, i));
        
		push(pilha, temp);//jogo as peças no cava
    }
    

  destroi_listase(&lista);// destruo a lista qualquer
}

void mao_jogador(tp_pilha *pilha,tp_listase **mao){// retira 7 pecas do cava para mao do jogador // uso outra lista chamada mao sem a q eu ja destrui
 
peca temp;
  int i;
  i=0;
  while(i!=7){
  pop(pilha,&temp);
  insere_listase_no_fim(mao,temp);// coloco do cava pra mao 7 pecas
  i++;
    }

  //imprime_listase(mao);
}


tp_listase* cria_pecas(tp_listase *lista){//envio pra uma lista qualquer

  
  peca _00, _01, _02, _03, _04, _05, _06, _11, _12, _13, _14, _15, _16, _22, _23, _24, _25, _26, _33, _34, _35, _36, _44, _45, _46, _55, _56, _66;

  _00.esquerda=0; _00.direita=0; _01.esquerda=0; _01.direita=1;_02.esquerda=0; _02.direita=2; _03.esquerda=0; _03.direita=3; 
  _04.esquerda=0; _04.direita=4; _05.esquerda=0; _05.direita=5; _06.esquerda=0; _06.direita=6; _11.esquerda=1; _11.direita=1; _12.esquerda=1; 
  _12.direita=2; _13.esquerda=1; _13.direita=3;_14.esquerda=1; _14.direita=4; _15.esquerda=1; _15.direita=5; _16.esquerda=1; _16.direita=6; _22.esquerda=2; 
  _22.direita=2; _23.esquerda=2; _23.direita=3; _24.esquerda=2; _24.direita=4; _25.esquerda=2; _25.direita=5; _26.esquerda=2; _26.direita=6; _33.esquerda=3; 
  _33.direita=3; _34.esquerda=3; _34.direita=4;_35.esquerda=3; _35.direita=5; _36.esquerda=3; _36.direita=6; _44.esquerda=4; _44.direita=4; _45.esquerda=4; 
  _45.direita=5; _46.esquerda=4;_46.direita=6; _55.esquerda=5; _55.direita=5; _56.esquerda=5; _56.direita=6; _66.esquerda=6; _66.direita=6;
 
  insere_listase_no_fim (&lista,_00);
  insere_listase_no_fim (&lista,_01);
  insere_listase_no_fim (&lista,_02);
  insere_listase_no_fim (&lista,_03);
  insere_listase_no_fim (&lista,_04);
  insere_listase_no_fim (&lista,_05);
  insere_listase_no_fim (&lista,_06);
  insere_listase_no_fim (&lista,_11);
  insere_listase_no_fim (&lista,_12);
  insere_listase_no_fim (&lista,_13);
  insere_listase_no_fim (&lista,_14);
  insere_listase_no_fim (&lista,_15);
  insere_listase_no_fim (&lista,_16);
  insere_listase_no_fim (&lista,_22);
  insere_listase_no_fim (&lista,_23);
  insere_listase_no_fim (&lista,_24);
  insere_listase_no_fim (&lista,_25);
  insere_listase_no_fim (&lista,_26);
  insere_listase_no_fim (&lista,_33);
  insere_listase_no_fim (&lista,_34);
  insere_listase_no_fim (&lista,_35);
  insere_listase_no_fim (&lista,_36);
  insere_listase_no_fim (&lista,_44);
  insere_listase_no_fim (&lista,_45);
  insere_listase_no_fim (&lista,_46);
  insere_listase_no_fim (&lista,_55);
  insere_listase_no_fim (&lista,_56);
  insere_listase_no_fim (&lista,_66);
  return lista;
}


char comecar_jogo1(){//faz um sorteio para definir quem comeca

  srand ( time(NULL) );
  int i,primeiro;

  i= 1 + (rand()%2);
   
  if(i==1){
    
    primeiro=1;
    	
  }else{
    
    primeiro=2;
  }
  return primeiro;
}

char comecar_jogo2(){
  int i,primeiro;
  
  
    i= 1 + (rand()%4);
    
    if(i==1){
     
      primeiro=1;

    }else if(i==2){
      
     primeiro=2;
    }else if(i==3){
     
       primeiro=3;
    }else{
     
      primeiro=4;
    }
  
  return primeiro;
}

int cavar_peca(tp_listase *mao, tp_pilha *pilha, tp_listad *mesa){

  peca temp;
  int cont;
  cont =0;
  tp_listase *atu;
  atu = mao;

  if(pilha_vazia(pilha)) { 
    printf("O cava esta vazio\n");
    return 1;
  }

  
  while(atu!=NULL){

    if(atu->info.direita==mesa->fim->info.direita || atu->info.direita==mesa->ini->info.esquerda || atu->info.esquerda==mesa->fim->info.direita || atu->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu=atu->prox;
  }
  
  if(tamanho_listase(atu)==1){
  if(atu->info.direita==mesa->fim->info.direita || atu->info.direita==mesa->ini->info.esquerda || atu->info.esquerda==mesa->fim->info.direita || atu->info.esquerda==mesa->ini->info.esquerda){
    return 1;
  }}

  while(cont==0){
    pop(pilha,&temp);
    printf("Voce cavou a peca: ");
    imprime_peca(temp);
    printf("\n");

    insere_listase_no_fim(&mao,temp);
       
      
    if(temp.direita==mesa->fim->info.direita || temp.direita==mesa->ini->info.esquerda || temp.esquerda==mesa->fim->info.direita || temp.esquerda==mesa->ini->info.esquerda) {
    return 1;
    }  
    if(pilha_vazia(pilha)){
    printf("O cava esta vazio");
    return 1;}
  }
  return 1;
}
 
int jogar( tp_listad *mesa,tp_listase *l,int jogador_rodada,int quant_rodada){
  
  int opcao=0, posicao_peca=0;

  if(jogador_rodada==1){
    
    if(quant_rodada==1){
      
      printf("Jogador 1 voce eh o primeiro a jogar, escolha sua peca digitando a posicao dela\n");
     tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      scanf("%d",&posicao_peca);
      
      insere_listad_no_fim(mesa,tira_da_listase(l,posicao_peca));
     
      //remove_listase(&l,tira_da_listase(l,posicao_peca));
      return posicao_peca ;    
    }

    if(quant_rodada!=1){
      
      //printf("Imprimindo a MESA\n");
      //imprime_listad(mesa,1);
      
      printf("Jogador 1 essa eh sua mao: \n");
       tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
    
      
      printf ("Por favor, escolha sua peca, para isso digite a posicao dela em sua mao\n ");
      printf("Caso nao tenha peca pra jogar digite qualquer posicao e prossiga\n");
      scanf("%d",&posicao_peca);


      printf("Escolha uma das opcoes:\nJogar na Ponta Direita(Digite:1)\nJogar na Ponta Esquerda:(Digite: 2)\nPassar vez(Digite 3)\n");
      scanf("%d",&opcao);

      switch(opcao){
       case 1: 
         
        insere_listad_no_fim(mesa,joga_invertendo(mesa,l,posicao_peca,opcao ));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));
  
        break;

       case 2:
        insere_listad_no_inicio(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));
        
       break;
       
       case 3:
       posicao_peca=100;
       break;
      }
       return posicao_peca;
    }   
  }

  if(jogador_rodada==2){ 
    if(quant_rodada==1){
      printf("Jogador 2 voce eh o primeiro a jogar, escolha sua peca digitando a posicao dela\n");
       tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      scanf("%d",&posicao_peca);
      insere_listad_no_fim(mesa,tira_da_listase(l,posicao_peca));
      //remove_listase(&l,tira_da_listase(l,posicao_peca));
      return posicao_peca; 
    }
    
    if(quant_rodada!=1){
  
      //printf("MESA\n");
      //imprime_listad(mesa,1);
      
      printf("Jogador 2 essa eh sua mao: \n");
       tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      
      printf ("Por favor, escolha sua peca, para isso digite a posiçao dela em sua mao\n ");
      printf("Caso nao tenha peca pra jogar digite qualquer posicao e prossiga\n");
      scanf("%d",&posicao_peca);


      printf("Escolha uma das opcoes:\nJogar na Ponta Direita(Digite:1)\nJogar na Ponta Esquerda:(Digite: 2)\nPassar vez(Digite 3)\n");
      scanf("%d",&opcao);

      switch(opcao){
       case 1: 
         
        insere_listad_no_fim(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));

       break;

       case 2:
        insere_listad_no_inicio(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));
        


       break;
       
       case 3:
       posicao_peca = 100;
       break;
      }
      return posicao_peca;
    }    
  }

  if(jogador_rodada==3){
    
    if(quant_rodada==1){
      printf("Jogador 3 voce eh o primeiro a jogar,escolha sua peca digitando a posicao dela\n");
      tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}

      scanf("%d",&posicao_peca);
      insere_listad_no_fim(mesa,tira_da_listase(l,posicao_peca));
      //remove_listase(&l,tira_da_listase(l,posicao_peca));
      return posicao_peca; 
    }

    if(quant_rodada!=1){

      printf("Jogador 3 essa eh sua mao: \n");
       tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      
      printf ("Por favor,escolha sua peca,para isso digite a posicao dela em sua mao \n ");
      printf("Caso nao tenha peca pra jogar digite qualquer posicao e prossiga\n");
      scanf("%d",&posicao_peca);


      printf("Escolha uma das opcoes:\nJogar na Ponta Direita(Digite:1)\nJogar na Ponta Esquerda:(Digite: 2)\nPassar vez(Digite 3)\n");
      scanf("%d",&opcao);

      switch(opcao){
       case 1: 
         
       insere_listad_no_fim(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
       //remove_listase(&l,tira_da_listase(l,posicao_peca));

       break;

       case 2:
        insere_listad_no_inicio(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));
      
       break;
       
       case 3:
       posicao_peca = 100;
       break;
      }
      return posicao_peca;
    }  
  }

  if(jogador_rodada==4){
    if(quant_rodada==1){
      printf("Jogador 4 voce eh o primeiro a jogar,escolha sua peca digitando a posicao dela\n");
       tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      scanf("%d",&posicao_peca);
      insere_listad_no_fim(mesa,tira_da_listase(l,posicao_peca));
      return posicao_peca; 
    }

    if(quant_rodada!=1){    
      printf("Jogador 4 essa eh sua mao: \n");
      tp_listase *atu;
      atu=l;

      while(atu!=NULL){
      imprime_peca(atu->info);
      printf("\n");
        atu=atu->prox;}
      
      printf ("Por favor,escolha sua peca,para isso digite a posicao dela em sua mao\n ");
      printf("Caso nao tenha peca pra jogar digite qualquer posicao e prossiga\n");
      scanf("%d",&posicao_peca);


      printf("Escolha uma das opcoes:\nJogar na Ponta Direita(Digite:1)\nJogar na Ponta Esquerda:(Digite: 2)\nPassar vez(Digite 3)\n");
      scanf("%d",&opcao);

      switch(opcao){
       case 1: 

        insere_listad_no_fim(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));

       break;

       case 2:
        
        insere_listad_no_inicio(mesa,joga_invertendo(mesa,l,posicao_peca, opcao));
        //remove_listase(&l,tira_da_listase(l,posicao_peca));
      
       break;
       
       case 3:
       posicao_peca = 100;
       break;
    
      
      }
        return posicao_peca;
    }  
  }
}


int vitoria(tp_listase *mao, char *i){

  if(listase_vazia(mao)){

    printf("Parabens %s voce venceu!!", i);
    exit(0);

  }
 return 1;
}

int fecha_jogo1(tp_listase **lista1,tp_listase **lista2,tp_listad *mesa,tp_pilha *pilha){
  int i;
  i=0;
tp_listase *atu; 
tp_listase *atu2;
atu=*lista1;
atu2=*lista2;

  if(!pilha_vazia(pilha)){return 1;}

  //for(i=0;i<tamanho_listase(lista1);i++){
   while(atu->prox!=NULL){

    if(atu->info.direita==mesa->fim->info.direita || atu->info.direita==mesa->ini->info.esquerda || atu->info.esquerda==mesa->fim->info.direita || atu->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu=atu->prox;
  }
 //for(i=0;i<tamanho_listase(lista2);i++){
  while(atu2->prox!=NULL){

    if(atu2->info.direita==mesa->fim->info.direita || atu2->info.direita==mesa->ini->info.esquerda || atu2->info.esquerda==mesa->fim->info.direita || atu2->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu2=atu2->prox;
  }

printf("O jogo fechou ,empate\n");
exit(0);

}
int fecha_jogo2(tp_listase **lista1,tp_listase **lista2,tp_listase **lista3,tp_listase **lista4,tp_listad *mesa,tp_pilha *pilha){
 // int i;
 // i=0;
tp_listase *atu; 
tp_listase *atu2;
tp_listase *atu3;
tp_listase *atu4;
atu=*lista1;
atu2=*lista2;
atu3=*lista3;
atu4=*lista4;

  if(!pilha_vazia(pilha)){return 1;};//pilha nao estiver vazia eu retorno 1
  //nesse caso a pilha ta vazia

  while(atu->prox!=NULL){
  //for(i=0;i<tamanho_listase(lista1);i++){

    if(atu->info.direita==mesa->fim->info.direita || atu->info.direita==mesa->ini->info.esquerda || atu->info.esquerda==mesa->fim->info.direita || atu->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu=atu->prox;
  }

  while(atu2->prox!=NULL){
  //for(i=0;i<tamanho_listase(lista2);i++){

    if(atu2->info.direita==mesa->fim->info.direita || atu2->info.direita==mesa->ini->info.esquerda || atu2->info.esquerda==mesa->fim->info.direita || atu2->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu2=atu2->prox;
  }
 
  while(atu3->prox!=NULL){
 // for(i=0;i<tamanho_listase(lista3);i++){

    if(atu3->info.direita==mesa->fim->info.direita || atu3->info.direita==mesa->ini->info.esquerda || atu3->info.esquerda==mesa->fim->info.direita || atu3->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu3=atu3->prox;
  }
  
  while(atu4->prox!=NULL){
 // for(i=0;i<tamanho_listase(lista4);i++){

    if(atu4->info.direita==mesa->fim->info.direita || atu4->info.direita==mesa->ini->info.esquerda || atu4->info.esquerda==mesa->fim->info.direita || atu4->info.esquerda==mesa->ini->info.esquerda){
      return 1;
    }
    
    atu4=atu4->prox;
  }




printf("O jogo fechou ,empate\n");
exit(0);

}
/*
void ordenar(tp_listase **l) {
  int i;

  int tam = tamanho_listase(*l);
  tp_listase *ant, *atu;
	peca temp;
  for(int i=0; i<tam - 1; i++) {
    ant = *l;
    atu = ant->prox;
    for(int j=0; j<tam -1; j++) {
            
            
      if((ant->info.direita+ant->info.esquerda) > (atu->info.direita+atu->info.esquerda)) {
        
		temp = ant->info;
		ant->info = atu->info;
		atu->info = temp;
      }

      atu = atu->prox;
      ant = ant->prox;
    }
  }
}
*/


/*tp_listase ordena_mao ( tp_listase *mao){
  
  tp_listase *aux;
  peca menor_peca;
  int i=1;

  while(mao!=NULL){

    menor_peca=tira_da_listase(mao,i);

    

    mao=mao->prox;
    i++;
  }*/


/*void ordenar(tp_listase **l) {

  int tam = tamanho_listase(*l);
  tp_listase *ant, *atu, *aux;

  for(int i=0; i<tam - 1; i++) {
    ant = *l;
    atu = ant->prox;
    for(int j=0; j<tam -1; j++) {
            
            
      if((ant->info.direita+ant->info.esquerda) > (atu->info.direita+atu->info.esquerda)) {
        

        printf("%i + %i= ",ant->info.direita,ant->info.esquerda);
        printf("%i\n",(ant->info.direita+ant->info.esquerda));
        printf("%i + %i= ",atu->info.direita,atu->info.esquerda);
        printf("%i\n",(atu->info.direita+atu->info.esquerda));
        
        
        
        
    



  
      
      }


      atu = atu->prox;
      ant = ant->prox;
    }
  }
}*/
#endif
