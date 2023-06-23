/*
#include <stdio.h>

int main(){
    float rendaFixaN;
    float rendaFixaI;
    float rendaVariavelN;
    float rendaVariavelI;

    float rendaVariavelT;
    float total;
    float porcentagem;
    scanf("%f %f %f %f", &rendaFixaN, &rendaFixaI, &rendaVariavelN, &rendaVariavelI);

    total = rendaFixaI + rendaFixaN + rendaVariavelI + rendaVariavelN;
    rendaVariavelT = rendaVariavelI + rendaVariavelN;

    porcentagem = (rendaVariavelT/total)*100;
    if(porcentagem <= 10){
        printf("Conservador (%.2f%%)", porcentagem);
    }
    else if(porcentagem > 30){
        printf("Agressivo (%.2f%%)", porcentagem);
    }
    else{
        printf("Arrojado (%.2f%%)", porcentagem);
    }
}
*/
int main()
{
float valores[4];
for(int i = 0; i<4;i++){
    scanf ("%f",&valores [i]);
}
float porcentagem = 100.0* (valores [2]+valores [3])/(valores [0] + valores [1] + valores [2] + valores [3]);

if (porcentagem > 30) {
    printf("Agressivo (%.2f%%)", porcentagem);
}
else if(porcentagem <= 10) {
    printf("Conservador (%.2f%%)" ,porcentagem) ;
}
else{
    printf("Arrojado (%.2f%%)" ,porcentagem);
}
}