#include <stdio.h>

int main(){
    int tri;
    float col;

    scanf("%d", &tri);
    scanf("%f", &col);

    if(tri < 0 || col <0){
        printf("Algum valor fora da caixa");
    }
    else{
        if (tri < 150) {
            printf("Triglicerideos %d mg/dl: DESEJAVEL\n", tri);
        }
        if(tri > 200) {
            printf("Triglicerideos %d mg/dl: ALTO\n" ,tri) ;
        }
        if(tri >= 150 && tri <= 200){
            printf("Triglicerideos %d mg/dl: LIMITROFE\n" ,tri);
        }
        if (col < 150) {
            printf("Colesterol total %.1f mg/dl (DESEJAVEL)\n", col);
        }
        if(col > 170) {
            printf("Colesterol total %.1f mg/dl (ALTO)\n" ,col) ;
        }
        if(col >= 150 && col <= 170){
            printf("Colesterol total %.1f mg/dl (LIMITROFE)\n" ,col);
        }
    
    }
}