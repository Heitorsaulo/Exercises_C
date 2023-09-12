#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaCircular.c"

// Imprime na tela o status da lista
void imprimirStatus(LISTA *l) {
  printf("Tamanho = %d\n", tamanho(l));
  exibirLista(l);
  printf("\n");
}

// Testa a insercao de valores na lista


/////////////////////////////////////////////////////

int main() {
LISTA l;
inicializar(&l); // Inicialize a lista l antes de cloná-la

insercaoOrdenada(7, &l);
insercaoOrdenada(9, &l);
insercaoOrdenada(2, &l);
insercaoOrdenada(5, &l);

LISTA *l2 = clonar(&l); // Agora clonar a lista l

imprimirStatus(&l);
imprimirStatus(l2);
inverter(&l);
imprimirStatus(&l);
destruir(&l);

getchar();
return 0;
}
