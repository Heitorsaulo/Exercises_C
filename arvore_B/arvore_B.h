
#include<stdlib.h>
#include<stdio.h>
#define M 2
#define MM  (M * 2) //Ordem -1
#define FALSE 0
#define TRUE  1

typedef long ITEM;
typedef struct TRegistro {
  ITEM item;
  /*outros componentes*/
} TRegistro;
typedef struct TPagina* TApontador;

typedef struct TPagina {
  short n;
  TRegistro r[MM];
  TApontador p[MM + 1];
} TPagina;