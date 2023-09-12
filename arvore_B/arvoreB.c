#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_B.h"


//mudar todos no nomes TApontador
//deixar o codigo mais legivel*********


void Inicializa(TApontador *arvB){
      *arvB = NULL; 
}

void inOrder(TApontador tree){
    int i;

    if(tree != NULL){

        for(i=0; i<tree->n; i++){
            inOrder(tree->p[i]);
            printf("%ld ", tree->r[i].item);
        }

        inOrder(tree->p[i]);
    }
    return;
}

bool Pesquisa(TRegistro *elem, TApontador Ap){
  long i = 1;
  if (Ap == NULL){ 
    printf("TRegistro nao esta presente na arvore\n");
    return FALSE;
  }
  while (i < Ap->n && elem->item > Ap->r[i-1].item){
    i++;
  }
    
  if (elem->item == Ap->r[i-1].item){
    *elem = Ap->r[i-1];
    return TRUE;
  }
  if (elem->item < Ap->r[i-1].item){
    Pesquisa(elem, Ap->p[i-1]);
  }
  
  else{
    Pesquisa(elem, Ap->p[i]);
  }
} 

void InsereNaPagina(TApontador Ap, TRegistro Reg, TApontador ApDir){
  short NaoAchouPosicao;
  int lenPag;
  lenPag = Ap->n;  
  NaoAchouPosicao = (lenPag > 0);
  while (NaoAchouPosicao){
     if(Reg.item >= Ap->r[lenPag-1].item){ 
        NaoAchouPosicao = FALSE;
        break;
      }
      //entender essa parte...
      Ap->r[lenPag] = Ap->r[lenPag-1];
      Ap->p[lenPag+1] = Ap->p[lenPag];
      lenPag--;
      if (lenPag < 1) NaoAchouPosicao = FALSE;
    }
  Ap->r[lenPag] = Reg; 
  Ap->p[lenPag+1] = ApDir;
  Ap->n++;
} 

void InsereAUX(TRegistro Reg, TApontador Ap, short *Cresceu,TRegistro *RegRetorno,  TApontador *ApRetorno){
  long posAux = 1; // Posição provavel do vetor em que novo indice sera inserido
  long j;
  TApontador ApTemp;

  if (Ap == NULL){ // Critério de parada da recursão. Pode ser usado para arvore vazia, arvore com espaço em folhas ou arvore que explode
   *Cresceu = TRUE; 
   (*RegRetorno) = Reg; 
   (*ApRetorno) = NULL;
    return;
  }

  while (posAux < Ap->n && Reg.item > Ap->r[posAux-1].item){
    posAux++; // Percorrendo vetores dos nós para encontrar valor maior (ou igual) que o novo indice
  }
  if (Reg.item == Ap->r[posAux-1].item){
    printf(" Erro: Registro ja esta presente\n"); 
    *Cresceu = FALSE;
    return;
  }

  if (Reg.item < Ap->r[posAux-1].item) {
    posAux--; // Como o valor nao é igual, só pode ser maior, entao volta-se uma posição
  }
  InsereAUX(Reg, Ap->p[posAux], Cresceu, RegRetorno, ApRetorno); // Chama-se recursivo para descer na arvore

  if (!*Cresceu) return;

  if (Ap->n < MM){/* Pagina tem espaco */    
       
       InsereNaPagina(Ap, *RegRetorno, *ApRetorno); // Chama insere na página pq tem espaço
      *Cresceu = FALSE;
      return;
    }

  /* Overflow: Pagina tem que ser dividida */ // Página nao tem espaço suficiente
  ApTemp = (TApontador)malloc(sizeof(TPagina)); // Cria nova pagina pra ser raiz da subarvore que vem do split
  ApTemp->n = 0; 
  ApTemp->p[0] = NULL; // Ela começa com zero indices e primeiro filho pra NULL
  if (posAux < M + 1){ 
    InsereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM]);
    Ap->n--;
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  } 
  else InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
  for (j = M + 2; j <= MM; j++){ 
    InsereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j]);
  }
  Ap->n = M;  
  ApTemp->p[0] = Ap->p[M+1];
  *RegRetorno = Ap->r[M];  
  *ApRetorno = ApTemp;
}

void Insere(TRegistro Reg, TApontador *Ap)
{ 
  short Cresceu;
  TRegistro RegRetorno;
  TPagina *ApRetorno, *ApTemp;
  InsereAUX(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno); // Chamando funcao insere auxiliar
  if (Cresceu)  /* Arvore cresce na altura pela raiz */
  { 
    ApTemp = (TPagina *)malloc(sizeof(TPagina)); // Criando nova raiz
    ApTemp->n = 1;  // Definindo que a nova raiz só terá um índice
    ApTemp->r[0] = RegRetorno; // Definindo valor do unico indice da raiz
     ApTemp->p[1] = ApRetorno; // Definindo filho da direita da raiz, resultado do split que causou explosao no tamanho
    ApTemp->p[0] = *Ap;   // Definindo filho da esquerda da raiz, resultado do split que causou explosao no tamanho 
    *Ap = ApTemp; // Enderençando nova raiz
  }
}

void Reconstitui(TApontador ApPag, TApontador ApPai, int PosPai, short *Diminuiu){ 
  TPagina *Aux;  
  long DispAux, j;
  if (PosPai < ApPai->n){  /* Aux = TPagina a direita de ApPag */
    Aux = ApPai->p[PosPai+1];  
    DispAux = (Aux->n - M + 1) / 2;
    ApPag->r[ApPag->n] = ApPai->r[PosPai];
    ApPag->p[ApPag->n + 1] = Aux->p[0];  
    ApPag->n++;
    if (DispAux > 0){  /* Existe folga: transfere de Aux para ApPag */
      for (j = 1; j < DispAux; j++)
      InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j]);
      ApPai->r[PosPai] = Aux->r[DispAux-1];  Aux->n -= DispAux;
      for (j = 0; j < Aux->n; j++) Aux->r[j] = Aux->r[j + DispAux];
      for (j = 0; j <= Aux->n; j++) Aux->p[j] = Aux->p[j + DispAux];
      *Diminuiu = FALSE;
    }
    else{ /* Fusao: intercala Aux em ApPag e libera Aux */
       for(j = 1; j <= M; j++)
          InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j]);
        free(Aux);
        for (j = PosPai + 1; j < ApPai->n; j++){ 
        ApPai->r[j-1] = ApPai->r[j]; 
	    ApPai->p[j] = ApPai->p[j+1]; 
	  }
        ApPai->n--;
        if (ApPai->n >= M) *Diminuiu = FALSE;
    }
  }
  else{ /* Aux = TPagina a esquerda de ApPag */
      Aux = ApPai->p[PosPai-1]; DispAux = (Aux->n - M + 1) / 2;
      for (j = ApPag->n; j >= 1; j--) ApPag->r[j] = ApPag->r[j-1];
      ApPag->r[0] = ApPai->r[PosPai-1];
      for (j = ApPag->n; j >= 0; j--) ApPag->p[j+1] = ApPag->p[j];
      ApPag->n++;
      if (DispAux > 0) /* Existe folga: transf. de Aux para ApPag */
      { for (j = 1; j < DispAux; j++)
          InsereNaPagina(ApPag, Aux->r[Aux->n - j], 
	                 Aux->p[Aux->n - j + 1]);
        ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
        ApPai->r[PosPai-1] = Aux->r[Aux->n - DispAux];
        Aux->n -= DispAux;  
        *Diminuiu = FALSE;
      }
      else{ /* Fusao: intercala ApPag em Aux e libera ApPag */
          for (j = 1; j <= M; j++)
            InsereNaPagina(Aux, ApPag->r[j-1], ApPag->p[j]);
          free(ApPag);  ApPai->n--;
          if (ApPai->n >= M)  *Diminuiu = FALSE;
        }
    }
}

void Antecessor(TApontador Ap, int Ind, TApontador ApPai, short *Diminuiu){
    if (ApPai->p[ApPai->n] != NULL){ 
        Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
        if (*Diminuiu) 
        Reconstitui(ApPai->p[ApPai->n], ApPai, (long)ApPai->n, Diminuiu);
        return;
    }
  Ap->r[Ind-1] = ApPai->r[ApPai->n - 1]; 
  ApPai->n--;  *Diminuiu = (ApPai->n < M);
} 

void Ret(ITEM Ch, TApontador *Ap, short *Diminuiu){ 
  long j, Ind = 1;
  TApontador Pag;
  if (*Ap == NULL){ 
    printf("Erro: registro nao esta na arvore\n"); *Diminuiu = FALSE;
    return;
  }
  Pag = *Ap;
  while (Ind < Pag->n && Ch > Pag->r[Ind-1].item) Ind++;
  if (Ch == Pag->r[Ind-1].item) 
  { if (Pag->p[Ind-1] == NULL)   /* TPagina folha */
    { Pag->n--;
      *Diminuiu = (Pag->n < M); // Detecta underflow
      for (j = Ind; j <= Pag->n; j++) // Deslocando vetor
        { Pag->r[j-1] = Pag->r[j];  Pag->p[j] = Pag->p[j+1]; }
      return;
    }
    /* TPagina nao e folha: trocar com antecessor */
    Antecessor(*Ap, Ind, Pag->p[Ind-1], Diminuiu);
    if (*Diminuiu) 
    Reconstitui(Pag->p[Ind-1], *Ap, Ind - 1, Diminuiu);
    return;
  }
  if (Ch > Pag->r[Ind-1].item) Ind++;
  Ret(Ch, &Pag->p[Ind-1], Diminuiu);
  if (*Diminuiu) Reconstitui(Pag->p[Ind-1], *Ap, Ind - 1, Diminuiu);
}  

void Retira(ITEM Ch, TApontador *Ap)
{ short Diminuiu;
  TApontador Aux;
  Ret(Ch, Ap, &Diminuiu);
  if (Diminuiu && (*Ap)->n == 0)  /* Arvore diminui na altura */
  { Aux = *Ap;   *Ap = Aux->p[0]; // Elimina antiga raiz
    free(Aux);
  }
}  

void ImprimeI(TApontador p, int nivel){ 
  long i;
  if (p == NULL) return;
  printf("Nivel %d : ", nivel);
  for (i = 0; i < p->n; i++)
    printf("%ld ",(long)p->r[i].item);
  putchar('\n');
  nivel++;
  for (i = 0; i <= p->n; i++)
    ImprimeI(p->p[i], nivel);
} 

void Imprime(TApontador p){ 
  int  n = 0; 
  ImprimeI(p, n); 
} 

void TestaI(TApontador p, int pai, short direita)
{ int i;
  int antecessor = 0;
  if (p == NULL) return;
  if (p->r[0].item > pai && direita == FALSE) 
  { printf("Erro: filho %12ld maior que pai %d\n", p->r[0].item, pai);
    return;
  }
  for (i = 0; i < p->n; i++) 
    { if (p->r[i].item <= antecessor) 
      { printf("Erro: irmao %ld maior que irmao a esquerda %d\n",
        (long)p->r[i].item, antecessor);
        return;
      }
      antecessor = p->r[i].item;
    }
  for (i = 0; i < p->n; i++) 
    TestaI(p->p[i], p->r[i].item, FALSE);
  TestaI(p->p[p->n], p->r[i].item, TRUE);
}

void Testa(TApontador p)
{ int i;
  if (p == NULL) return;
  for (i = 0; i < p->n; i++) 
    TestaI(p->p[i], p->r[i].item, FALSE);
  TestaI(p->p[p->n], p->r[i].item, TRUE);
}

int main(int argc, char *argv[])
{ 
  printf("############################################################\n");
  printf("Bem vindo ao terceiro tp de AEDS!\n");
  printf("Digite as items de entrada, ou 0 para começar a remoção\n");
  printf("############################################################\n");
  TRegistro x;
  TPagina *arvB;
  Inicializa(&arvB);
  printf("item: ");
  scanf("%ld%*[^\n]", &x.item);
  getchar();
  while (x.item != 0) 
    { 
      Insere(x, &arvB);
      Imprime(arvB); 
      inOrder(arvB);
      printf("\n");
      printf("item: ");
      scanf("%ld%*[^\n]", &x.item);
      getchar();
    }
  Testa(arvB);
  printf("############################################################\n");
  printf("Digite as items para a remoção, ou 0 para sair do programa\n");
  printf("############################################################\n");
  printf("item: ");
  scanf("%ld%*[^\n]", &x.item);
  getchar();
  while (x.item != 0) 
    { Retira(x.item, &arvB);
      Imprime(arvB);
      printf("item: ");
      scanf("%ld%*[^\n]", &x.item);
      getchar();
    }
  Testa(arvB);
  return 0;
}