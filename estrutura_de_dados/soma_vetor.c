#include <stdio.h>

int main(){
    int vetor1[10];
    int vetor2[10];

    for(int i = 0; i<10; i++){
        scanf("%d", &vetor1[i]);
    }
     for(int i = 0; i<10; i++){
        scanf("%d", &vetor2[i]);
    }

    for(int i = 0; i<10; i++){
        printf("%d ", vetor1[i]+vetor2[i]);
    }
}