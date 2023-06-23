#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N;

void lerMatrizes(int matriz[N][N]){
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
}

void produto(int matriz[N][N]){
    char numero[5];
    int multiplicadores;
    int contador = 0;
    for(int i = 0; i<100; i++){
        scanf("%s", numero);
        if(strcmp(numero, "*") == 0){
            break;
        }
        else{
            multiplicadores = atoi(numero);
            
            for(int i = 0; i<N; i++){
                for(int j = 0; j<N; j++){
                matriz[i][j] = matriz[i][j]*multiplicadores;
            }
        }
            
            
        }
    }
    
        
    
}

int main(){
   scanf("%d", &N);
   int matriz[N][N];
   lerMatrizes(matriz);
   produto(matriz);
   
   for(int i = 0; i<N; i++){
       if(i > 0){
            printf("\n");
       }
        for(int j = 0; j<N; j++){
            printf("%d ", matriz[i][j]);
        }
    }
}