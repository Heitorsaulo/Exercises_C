#include <stdio.h>
#include <string.h>

int main(){
    char time1[20];
    char time2[20];

    int pontosT1[3];
    int pontosT2[3];

    scanf("%s", &time1);
    for(int i = 0; i<3; i++){
        scanf("%d", &pontosT1[i]);
    }    
    scanf("%s", &time2);
    for(int i = 0; i<3; i++){
        scanf("%d", &pontosT2[i]);
    }

    for(int i = 0; i<3; i++){
       
        if(pontosT1[i] > pontosT2[i]){
            for(int i = 0; i<strlen(time1); i++){
                printf("%c", tolower(time1[i]));
            }
            
            break;
        }
        if(pontosT2[i] > pontosT1[i]){
            for(int i = 0; i<strlen(time2); i++){
                printf("%c", tolower(time2[i]));
            }

            break;
        }
        
        if(i == 2){
            printf("EMPATE");
        }
        
    }
}