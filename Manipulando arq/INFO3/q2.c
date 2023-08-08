#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    char nome[80];
    float nota[3];
}Dados;

void dados(FILE* s,int n, Dados ** alunos){
    * alunos = (Dados *)malloc(n*sizeof(Dados));
    if (*alunos == NULL){
        printf("Erro na alocação de memória\n");
        exit (1);
    }
    for (int i = 0; i < n; i++){
        fscanf(s, "%[^\n]\t");
    }
}

int main(void){


    return 0;
}
