#include <stdio.h>
#include <stdlib.h>

int main (void){
    char c;
    char nome_arquivo[20];
    printf("Informe o nome do arquivo: \n");
    scanf(" %[^\n]", nome_arquivo); // exemplo: arquivo.txt

    FILE * arquivo = fopen(nome_arquivo, "w"); // abre o arquivo
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    else{
        printf("Arquivo criado com sucesso! \n");
    }
    fputc('B', arquivo); // escreve um caracter no arquivo

    while (!feof(arquivo)){ // enquanto não chegar ao final do arquivo
        c = fgetc(arquivo); // lê um caractere do arquivo
        printf("%c", c); // imprime o caracter lido
    }

    fclose(arquivo); // fecha o arquivo

    return 0;
}
