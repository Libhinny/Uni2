#include <stdio.h>
#include <stdlib.h>

int main (void){
    int vet[10], menor, maior, soma = 0, media;
    FILE *e, *s;

    e = fopen("entrada1.txt", "rt"); // abre o arquivo
    if (e == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++){ // le os inteiros e armazena os elementos no vetor 
        if (fscanf(e, "%d", &vet[i]) != 1){
            printf("Erro ao ler o arquivo|n");
            fclose(e);
            return 1;
        }
    }

    fclose(e); // fecha o arquivo de entrada


// encontra o maior e menor elemento dentro do vetor
    menor = vet[0];
    maior = vet[0];
    for (int i = 1; i < 10; i++){
        if (vet[i]< menor){
            menor = vet[i];
        }
        if (vet[i] > maior){
            maior = vet[i];
        }
    }

// calcula a media dos elementos do vetor 
    for (int i = 0; i < 10; i++){
        soma += vet[i];
    }

    media = (float)soma/10;

    s = fopen("saida.txt", "wt"); // abre o arq de saida
    if ( s == NULL){
        printf("Erro ao criar o arquivo de saída!\n");
        return 1;
    }

// escreve as info no arq de saida
    fprintf(s, "menor elemento: %d\n", menor);
    fprintf(s, "maior elemento: %d\n", maior);
    fprintf(s, "media dos elementos: %d\n", media);

    fclose(s); // fecha o arq de saida

    printf("Verifique o arquivo de saida.\n");

    return 0;
}
