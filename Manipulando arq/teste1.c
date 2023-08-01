#include <stdio.h>
#include <stdlib.h>

// Criando um arquivo

int main(void){
    FILE* fp;
    fp = fopen("entrada.txt", "wt"); // comando para abrir o arquivo
    if (fp == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    else{
        printf("Arquivo criado com sucesso!\n");
    }
    if(!fclose(fp)){ // '!' é o comando de negação
        printf("Arquivo fechado com sucesso!"); // comando para fechar o arquivo
    }

    return 0;
}
