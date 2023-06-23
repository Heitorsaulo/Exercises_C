#include <stdio.h>

int main(){
    int N,C,S,E;
    int total = 0;
    scanf("%d %d", &N, &C);

    for(int i = 0; i<N; i++){
        scanf("%d %d", &S, &E);
    
        total-=S;
        total+=E;

        if(total > C){
            printf("%c", 'S');
            break;
        }

        if(i == N-1){
            printf("%c", 'N');
        }
     }
     
    
    

}




