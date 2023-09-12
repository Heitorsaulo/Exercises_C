#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ArvoreBinaria.c"

/////////////////////////////////////////////////////
// Visita um NO da arvore, imprimindo o valor da chave
// entre parenteses
void visite(ARVORE_BINARIA *arvore) {
    printf("%s", &arvore->item);
}

/////////////////////////////////////////////////////

int main()
{
   ARVORE_BINARIA *arv = NULL;
   ARVORE_BINARIA *arv2 = NULL;
   inicializar(arv);
   inicializar(arv2);
 
   ITEM item;
   item = '+';
   criarNo(item, &arv); // cria o no Raiz
   criarNo(item, &arv2);
   item = '2';
   adicionarFilho(item, NoEsquerdo, arv);
   adicionarFilho(item, NoEsquerdo, arv2);
   item = '+';
   adicionarFilho(item, NoDireito, arv);
   adicionarFilho(item, NoDireito, arv2);

   if(iguais(arv,arv2) == true){
        printf("iguais \n");
   }
   else{
        printf("diferentes \n");
   }
   
   item = '7';
   adicionarFilho(item, NoDireito, arv->dir);
   item = '*';
   adicionarFilho(item, NoEsquerdo, arv->dir);
   item = '3';
   adicionarFilho(item, NoEsquerdo, arv->dir->esq);
   item = '5';
   adicionarFilho(item, NoDireito, arv->dir->esq);

   if(iguais(arv,arv2) == true){
        printf("iguais");
   }
   else{
        printf("diferentes");
   }
   inOrdem(arv, visite);
   /*
                 1
              2     5
   */
   /*
   printf("inOrdem: ");
   inOrdem(arv, visite);
   printf("\n");
   printf("inOrdem: ");
   inOrdem(arv, visite);
   printf("\n");
   printf("posOrdem: ");
   posOrdem(arv, visite);
   printf("\n");
   printf("preOrdem: ");
   preOrdem(arv, visite);
   printf("\n");
*/
   

   

/*
                                1
                             2     5
                            3 4   6
                                   7
*/
/*
   printf("preOrdem: ");
   preOrdem(arv, visite); // Imprime: (1)(2)(3)(4)(5)(6)(7)
   printf("\n");

   deslocar(NoDireito, &arv);  // Vai para o No 5
   printf("Esperando 5, obtido %d\n", arv->item);   
   printf("Existe no esquerdo = %s\n", existeNo(NoEsquerdo, arv) ? "sim" : "nao");  // Deve ser TRUE
   printf("Existe no direito  = %s\n", existeNo(NoDireito, arv) ? "sim" : "nao");   // Deve ser FALSE

   deslocar(NoEsquerdo, &arv);  // Vai para 6
   deslocar(NoDireito, &arv);   // Vai para 7
   printf("Esperando 7, obtido %d\n", arv->item);

   deslocar(NoPai, &arv);  // Vai para 6
   printf("Esperando 6, obtido %d\n", arv->item);

   deslocar(NoRaiz, &arv); // Vai para 1
   printf("Esperando 1, obtido %d\n", arv->item);

   
   // Partindo da raiz, desce para o filho direito e executa um deltree
   deslocar(NoDireito, &arv);
   deltree(&arv);


                              1
                             2
                            3 4


   printf("preOrdem: ");
   preOrdem(arv, visite); // Imprime: (1)(2)(3)(4)
   printf("\n");
*/
   disposeArvore(arv);
   return 0;
}
