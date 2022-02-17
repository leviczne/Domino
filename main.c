#include <stdio.h>
#include "funcoes_do_jogo (1).h"
#include <string.h>





int main(){
char jogador1[10],jogador2[10],jogador3[10],jogador4[10];
int a, quantidade_jogadores,cavar, primeiro,jogador_rodada,quant_rodada=1;

tp_listad  *mesa;
tp_listase *mao1;
tp_listase *mao2;
tp_listase *mao3;
tp_listase *mao4;
tp_listase *lista;//lista em que as peças sao armazenadas inicialmente dps de ser usado a funçao "cria_pecas"
tp_pilha pilha;//cava 

tp_listase *verifica;

inicializa_pilha(&pilha);
mao1=inicializa_listase();
mao2=inicializa_listase();
mao3=inicializa_listase();
mao4=inicializa_listase();
mesa=inicializa_listad();
lista=inicializa_listase();


lista= cria_pecas(lista);// criamos as peça do jogo na função e as colocamos em uma lista
criar_cava(lista, &pilha);



printf("DOMINO\n");
printf("Defina a quantidade de jogadores (2 ou 4)\n");
scanf("%i", &quantidade_jogadores);
 
if(quantidade_jogadores==2){
  printf("Digite o nome do jogador1: \n");
  scanf("%s", jogador1);
  printf("Digite o nome do jogador2:\n");
  scanf("%s", jogador2);
  
 
  
  mao_jogador(&pilha,&mao1);
  mao_jogador(&pilha,&mao2);

  primeiro=comecar_jogo1();//diz quem vai começar o jogo para 2 pessoas
}

if(quantidade_jogadores==4){
  printf("Digite o nome do jogador 1: \n");
  scanf("%s", jogador1);
  
  printf("Digite o nome do jogador 2: \n");
  scanf("%s", jogador2);
  
  printf("Digite o nome do jogador 3: \n");
  scanf("%s", jogador3);
  
  printf("Digite o nome do jogador 4: \n");
  scanf("%s", jogador4);
  

  mao_jogador(&pilha,&mao1);
  mao_jogador(&pilha,&mao2);
  mao_jogador(&pilha,&mao3);
  mao_jogador(&pilha,&mao4); 

  primeiro=comecar_jogo2();//diz quem vai começar o jogo para 4 pessoas
} 



if(quantidade_jogadores==2){
  if(primeiro==1){
  
    while(!(listase_vazia(mao1) || listase_vazia(mao2))){
    
      jogador_rodada=1;
    
      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      
      
      
      vitoria(mao1, jogador1);
      jogador_rodada=2;
      quant_rodada++;

      system("cls");
      printf("MESA:\n");
      imprime_listad(mesa,1);//#

      
      //cavar_peca(mao2,&pilha,mesa);
      verifica=mao2;
      while(verifica!=NULL){
        cavar=0;
        if(verifica->info.direita==mesa->fim->info.direita || verifica->info.direita==mesa->ini->info.esquerda || verifica->info.esquerda==mesa->fim->info.direita || verifica->info.esquerda==mesa->ini->info.esquerda){
        cavar=1;
        break;
        }
        verifica=verifica->prox;
      }
      if(cavar!=1){
       cavar_peca(mao2,&pilha,mesa); 
      }

      a=jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      vitoria(mao2, jogador2);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      //cavar_peca(mao1,&pilha,mesa);
      verifica=mao1;
      while(verifica!=NULL){
        cavar=0;
        if(verifica->info.direita==mesa->fim->info.direita || verifica->info.direita==mesa->ini->info.esquerda || verifica->info.esquerda==mesa->fim->info.direita || verifica->info.esquerda==mesa->ini->info.esquerda){
        cavar=1;
        break;
        }
        verifica=verifica->prox;
      }
      fecha_jogo1(mao1,mao2,mesa,&pilha);
      if(cavar!=1){
       cavar_peca(mao1,&pilha,mesa); 
      }
      
    }
 
  }else if (primeiro==2){
    while(!(listase_vazia(mao1)|| listase_vazia(mao2))){
    
      jogador_rodada=2;
  
      
      a=jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      
      
      
      
      vitoria(mao2, jogador2);
      jogador_rodada=1;
      quant_rodada++;

      system("cls");

      printf("MESA:\n");
      imprime_listad(mesa,1);//#

      verifica=mao1;
      while(verifica!=NULL){
        cavar=0;
        if(verifica->info.direita==mesa->fim->info.direita || verifica->info.direita==mesa->ini->info.esquerda || verifica->info.esquerda==mesa->fim->info.direita || verifica->info.esquerda==mesa->ini->info.esquerda){
        cavar=1;
        break;
        }
        verifica=verifica->prox;
      }
      if(cavar!=1){
       cavar_peca(mao1,&pilha,mesa); 
      }

      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      vitoria(mao1, jogador1);

      system("cls");

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      //cavar_peca(mao2,&pilha,mesa);
      verifica=mao2;
      while(verifica!=NULL){
        cavar=0;
        if(verifica->info.direita==mesa->fim->info.direita || verifica->info.direita==mesa->ini->info.esquerda || verifica->info.esquerda==mesa->fim->info.direita || verifica->info.esquerda==mesa->ini->info.esquerda){
        cavar=1;
        break;
        }
        verifica=verifica->prox;
      }
      fecha_jogo1(mao1,mao2,mesa,&pilha);
      if(cavar!=1){
       cavar_peca(mao2,&pilha,mesa); 
      }
    }
  }

}else{
  if(primeiro==1){
    while(!listase_vazia(mao1)|| !listase_vazia(mao2)|| !listase_vazia(mao3)||!listase_vazia(mao4)){
      jogador_rodada=1;
      
      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      
      vitoria(mao1, jogador1);
      jogador_rodada=2;
      quant_rodada++;
     

      system("cls");
      printf("MESA:\n");
      imprime_listad(mesa,1);


      a=jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      vitoria(mao2, jogador2);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
    
      jogador_rodada=3;
      
      a=jogar(mesa,mao3,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao3, tira_da_listase(mao3, a));
      }
      vitoria(mao3, jogador3);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
    
      jogador_rodada=4;
     
      a=jogar(mesa,mao4,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao4, tira_da_listase(mao4, a));
      }
      vitoria(mao4, jogador4);
     
     // system("cls");      
      fecha_jogo2(&mao1,&mao2,&mao3,&mao4,mesa,&pilha);
      printf("MESA:\n");
      imprime_listad(mesa,1);
      
    }

  }else if (primeiro==2){
    while(!listase_vazia(mao1)|| !listase_vazia(mao2)|| !listase_vazia(mao3)||!listase_vazia(mao4)){
      jogador_rodada=2;
     
      a=jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      vitoria(mao2, jogador2);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      
      
      jogador_rodada=3;
      quant_rodada++;
     
      jogar (mesa,mao3,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao3, tira_da_listase(mao3, a));
      }
      vitoria(mao3, jogador3);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      
      
      
      jogador_rodada=4;
     
      a=jogar (mesa,mao4,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao4, tira_da_listase(mao4, a));
      }
      vitoria(mao4, jogador4);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      
      jogador_rodada=1;
     
      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      vitoria(mao1, jogador1);
     
      //system("cls");      
      fecha_jogo2(&mao1,&mao2,&mao3,&mao4,mesa,&pilha);
      printf("MESA:\n");
      imprime_listad(mesa,1);

     
    }

  }else if(primeiro==3){
    while(!listase_vazia(mao1)|| !listase_vazia(mao2)|| !listase_vazia(mao3)||!listase_vazia(mao4)){
      jogador_rodada=3;
     
      a=jogar (mesa,mao3,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao3, tira_da_listase(mao3, a));
      }
      vitoria(mao3, jogador3);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      jogador_rodada=4;
      quant_rodada++;
    
      a=jogar (mesa,mao4,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao4, tira_da_listase(mao4, a));
      }
      vitoria(mao4, jogador4);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      
      
      jogador_rodada=1;
   
      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      vitoria(mao1, jogador1);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      jogador_rodada=2;
   
      jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      vitoria(mao2, jogador2);
     
      //system("cls");      
      fecha_jogo2(&mao1,&mao2,&mao3,&mao4,mesa,&pilha);
      printf("MESA:\n");
      imprime_listad(mesa,1);


    
    }

  }else{
    while(!listase_vazia(mao1)|| !listase_vazia(mao2)|| !listase_vazia(mao3)||!listase_vazia(mao4)){
      jogador_rodada=4;
    
      a=jogar (mesa,mao4,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao4, tira_da_listase(mao4, a));
      }
      vitoria(mao4, jogador2);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
     
     
      jogador_rodada=1;
      quant_rodada++;
   
      a=jogar(mesa,mao1,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao1, tira_da_listase(mao1, a));
      }
      vitoria(mao1, jogador1);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      jogador_rodada=2;
    
      a=jogar(mesa,mao2,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao2, tira_da_listase(mao2, a));
      }
      vitoria(mao2, jogador2);
     
      system("cls");      

      printf("MESA:\n");
      imprime_listad(mesa,1);
      
      
      
      jogador_rodada=3;
  
  
      a=jogar(mesa,mao3,jogador_rodada,quant_rodada);
      if(a!=100){
        remove_listase(&mao3, tira_da_listase(mao3, a));
      }
      vitoria(mao3, jogador3);
     
     // system("cls");      
      fecha_jogo2(&mao1,&mao2,&mao3,&mao4,mesa,&pilha);
      printf("MESA:\n");
      imprime_listad(mesa,1);
      
    }
  }
}


return 0;
}
