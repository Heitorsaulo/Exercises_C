#include <stdio.h>

int main(){
    int M;
    int N;
    scanf("%d", &M);
    scanf("%d", &N);

    if(M>N){
        printf("sem multiplos menores que %d", N);
    }
    else if(M == N){
        printf("%d", N);
    }
    
    else{
        for(int i = N; i>M; i--){
            if(i % M == 0){
                printf("%d", i);
                break;
            }
        }
    }


}