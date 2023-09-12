#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaEncadeada.c"


int main() {
  LISTA l;
  LISTA l2;
  LISTA l3;
  ITEM item = 12;
  ITEM item2 = 10;
  ITEM item3 = 11;
  ITEM item4 = 2;
  ITEM item5 = 13;
  ITEM item6 = 14;
  ITEM item0 = 200;
  ITEM a;

  inicializar(&l);
  inicializar(&l2);
  inicializar(&l3);

  inserir(item, &l);
  inserir(item2, &l);
  inserir(item3, &l);
  inserir(item4, &l);
  inserir(item5, &l);
  inserir(item0, &l);
  inserir(item6, &l);
  
  
  inserir(12,&l2);
  inserir(3,&l2);
  inserir(6,&l2);
  inserir(10,&l2);
  inserir(14,&l2);

  intercao(&l,&l2,&l3);

  exibirLista(&l3);

  exibirLista(&l);
  inverter(&l);
  removerDaPos(&a,2,&l);
  exibirLista(&l);

 
  getchar();
  return 0;
}