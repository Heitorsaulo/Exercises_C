#include <stdio.h>

void AnalisarSituacao(float nota1,float nota2,float nota3,float nota4){
    float mediaP = (nota1+nota2*2+nota3*3+nota4*4)/10.0;
   
    if(mediaP >= 9){
        printf("aprovado com louvor");
    }
    else if(mediaP >= 7){
        printf("aprovado");
    }
    else if(mediaP < 3){
        printf("reprovado");
    }
    else{
        printf("prova final");
    }
}   


int main(){
    float notas[4];
    for(int i = 0; i<4;i++){
        scanf("%f", &notas[i]);
    }

    AnalisarSituacao(notas[0],notas[1],notas[2],notas[3]);
    
}