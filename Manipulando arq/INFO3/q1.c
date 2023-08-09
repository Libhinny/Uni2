#include <stdio.h>
#include <stdlib.h>

typedef struct funcionarios{
    int id;
    char nome[80];
    float salario;
}Funcionarios;

int main(void){
    FILE * s;
    int n;

    printf("Digite a quantidade de funcionários a serem cadastrados: \n");
    scanf("%d", &n);

    Funcionarios * pessoal = (Funcionarios*)malloc(n*sizeof(Funcionarios));
        if (pessoal == NULL){
            printf("Erro na alocação de memória");
            exit(1);
        }

    for (int i = 0; i < n; i++){
        printf("Informe o id: \n");
        scanf("%d", &pessoal[i].id);
        printf("Informe o nome: \n");
        scanf(" %[^\n]", pessoal[i].nome);
        printf("Informe o salário: \n");
        scanf("%f", &pessoal[i].salario);
    }

    s = fopen("info.txt", "wt");
        if (s == NULL){
            printf("Erro ao criar o arquivo!\n");
            fclose(s);
            return 1;
        }
    fprintf(s, "Dados dos funcionários\n");
    for(int j = 0; j < n; j++){
        fprintf(s, "Dados\n Id: %d | Nome: %s | Salário: %.2f \n", pessoal[j].id, pessoal[j].nome, pessoal[j].salario);
    }

    fclose(s);
    free(pessoal);

    return 0;
}
