#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){

    char nome[30];
    char letra = 'A';
    int counter = 0;
    scanf(" %[^\n]s", nome);

    for(int i = 0; i<strlen(nome); i++){
        if(toupper(nome[i]) == letra){
            counter++;
        }
    }
    
    printf("%d", counter);
}