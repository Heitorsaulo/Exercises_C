#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int vetor[N];
    for(int i = 0; i<N; i++){
        scanf("%d", &vetor[i]);
    }
    int Posicao = 0;
    int Smaller = vetor[0];
    for(int i = 0; i<N; i++){
        
        if(vetor[i]<Smaller){
            Smaller = vetor[i];
            Posicao = i;
        }
    }
    printf("Menor valor: %d\n", Smaller); 
    printf("Posicao: %d", Posicao);
}