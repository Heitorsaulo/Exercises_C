#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n);
    int vetor1[n];
    int vetor2[n];
    

    for(int i = 0; i<n; i++){
        scanf("%d", &vetor1[i]);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &vetor2[i]);
    }
    for(int i = 0; i<n;i++){
        printf("%d\n%d\n", vetor1[i],vetor2[i]);
    }
}