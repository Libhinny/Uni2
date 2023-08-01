#include <stdio.h>

// Lendo um caracter do arquivo já criado 

int main(){
    FILE * fp;
    int c;

    fp = fopen("arquivo1.txt", "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }
    c = fgetc(fp); // lê um caracter do arquivo
    printf("%c\n", c); // imprime o caracter lido
    fclose(fp);

    return 0;
}
