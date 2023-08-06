#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tmh_name 100

int main (void){
    char nome[tmh_name];
    float nota1, nota2, nota3, media;
    FILE *entrada, *saida; 

    entrada = fopen("entrada.txt", "r"); // abre o arquivo de entrada
    if (entrada == NULL){
        printf("Erro ao abrir o arquivo! ");
        return 1;
    }

    saida = fopen("saida.txt", "w"); // cria o arquivo de saida
    if (saida == NULL){
        printf("Não foi possivel abrir arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }

    while (fscanf(entrada, "%s\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3) == 4){ // manipula os dados do aluno
        media = (nota1 + nota2 + nota3)/3; // calculo da media

        const char * sit_apr = media >= 7.0 ? "aprovado" : "reprovado"; // verifica se o aluno foi aprovado ou não

        fprintf(saida, "%s\t%.2f\t%s\n", nome, media, sit_apr); // transfere as info no arq de saida
    }
    // fecha os arq
    fclose(entrada);
    fclose(saida);
    printf("Verifique o arquivo de saída!");

    return 0;
}

// sscanf(arquivo, "%s\t%f\t%f\t", nome, nota1, nota2, nota3) 
// possivel forma de ler um arquivo //
