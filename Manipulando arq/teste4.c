#include <stdio.h>

// lendo a quantidade de linhas em determinado arquivo

int main(){
    int c;
    int nlinhas = 0;
    FILE * fp;
    fp = fopen("poema.txt", "rt"); // abre o aquivo para leitura
    if (fp == NULL){
        printf("Não foi possivel abrir o arquivo.\n");
        return 1;
    }
    while ((c = fgetc(fp)) != EOF){ // lê caracter a caracter
        if (c == '\n')
            nlinhas++;
    }

    fclose(fp); // fecha o arquivo
    printf("Numero de linhas = %d\n", nlinhas); // exibe o resultado na tela

    return 0;
}
