#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaEncadeada.c"


int main() {
  LISTA l;
  ITEM item = 12;
  ITEM item2 = 10;
  ITEM item3 = 11;
  ITEM item4 = 2;
  ITEM item5 = 13;
  ITEM item6 = 14;
  ITEM item0 = 200;
  

  inicializar(&l);
  inserir(item, &l);
  inserir(item2, &l);
  inserir(item3, &l);
  inserir(item4, &l);
  inserir(item5, &l);
  inserir(item0, &l);
  inserir(item6, &l);
  
  exibirLista(&l);


  getchar();
  return 0;
}