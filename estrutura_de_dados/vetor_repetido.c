#include <stdio.h>

int main(){
    int ProII[45];
    int ProIII[30];
    
    int num[30];
    int contador = 0;
    for (int i = 0; i < 45; i++)
    {
        scanf("%d", &ProII[i]);
    }
    
    for (int i = 0; i < 30; i++)
    {
        scanf("%d", &ProIII[i]);
    }

    for(int i = 0; i<45; i++){
        for(int j = 0; j<30; j++){
            if(ProII[i] == ProIII[j]){
                num[contador] = ProII[i];
                contador++;
            }
        }
    }

    for(int i = 0; i<contador;i++){
        if(i == contador-1){
            printf("%d", num[i]);
        }
        else{
            printf("%d ", num[i]);
        }
        
    }
}