#include <stdio.h>

// Lendo as informações de um arquivo já criado

int main(){
    FILE * fp;
    char str[100];

    fp = fopen("arquivo1.txt", "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }
    fscanf(fp, "%s", str); // lê uma string formatada do arquivo fp e arma
    printf("%s", str); // imprime a string lida
    fclose(fp);

    return 0;
}
