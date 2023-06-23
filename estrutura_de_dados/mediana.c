#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int listaMed[50];
    int min;
    int max;
    char verifica[100];
    char intermedio[5];
    int contador = 0;
    
    scanf("%s", verifica);
    scanf("%d", &min);
    scanf("%d", &max);

    
    for(int i = 0; i<100; i++){
        if(verifica[i] == ','){
            continue;
        }
        else if(verifica[i] == '\n'){
            break;
        }
        else if(verifica[i+1] != ',' && verifica[i] != '\n'){
            snprintf(intermedio,5,"%s%s",verifica[i],verifica[i+1]);
            listaMed[contador] = atoi(intermedio);
            printf("%d", listaMed[contador]);
            contador++;
        }
        else{
            
            listaMed[contador] = atoi(verifica[i]);
            printf("%d", listaMed[contador]);
            contador++;
            
        }
    }                                                                        
}