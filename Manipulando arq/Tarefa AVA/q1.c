#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    int funcional;
    char nome[80];
    char departamento[80];
    float salario;
}Funcionario;

void copia_dados(FILE * fl, int n, Funcionario ** pessoal){
    * pessoal = (Funcionario *)malloc(n * sizeof(Funcionario)); //alocação do vetor funcionario
    if (*pessoal == NULL){
        printf("Erro na alocação de memória");//verifica se a alocação ocorreu corretamente
        exit (1);
    }
    
    char linha[100];
    fgets(linha, sizeof(linha), fl);

    for(int i = 0; i < n; i++){ // armazena os dados no vetor
        fscanf(fl, "%d\t%[^\n]\t%[^\n]\t%f\n", &(*pessoal)[i].funcional,(*pessoal)[i].nome, &(*pessoal)[i].departamento, &(*pessoal)[i].salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario ** pessoal, char * depto){
    float total = 0;

    for (int i = 0; i < n; i++){
        if (strcmp((*pessoal)[i].departamento, depto) == 0){
            total += (*pessoal)[i].salario;
        }
    }

    printf("Valor gasto para o departamento %s: R$ %.2f\n", depto, total);
}

void imprime(FILE * arq_saida, int n, Funcionario ** pessoal){
   
    fprintf(arq_saida, "----- Dados dos Funcionários -----\n");
    for (int i = 0; i < n; i++){
        fprintf("Funcional: %d | Nome: %s | Departamento: %s | Salario: R$ %.2f\n", (*pessoal)[i].funcional, (*pessoal)[i].nome, (*pessoal)[i].departamento, (*pessoal)[i].salario);
    }

    fprintf(arq_saida, "----------------------------------\n");
    fclose(arq_saida);
}

int main(void){
    FILE * arq, *s;
    char nome_arq[80];
    int num_fun;

    printf("Digite o nome do arquivo: \n"); // pede o nome do arquivo
    scanf(" %[^\n]", nome_arq);

    arq = fopen(nome_arq, "r"); // abre para leitura
    if (nome_arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fscanf(arq, "%d\n", &num_fun); // le o numero de funcionarios 

    // chama as funções para leitura dos dados e armazenamento
    Funcionario * funcionario;
    copia_dados(arq, num_fun, &funcionario);

    fclose(arq); // fecha o arquivo

    s = fopen("folha_pag.txt", "wt"); // abre o arq de saida
    if ( s == NULL){
        printf("Erro ao criar o arquivo de saída!\n");
        return 1;
    }
    imprime(s, num_fun, &funcionario); // imprime os dados

    free(funcionario); // libera a memória alocada

    return 0;
}
