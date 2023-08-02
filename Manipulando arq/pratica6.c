#include <stdio.h>
#include <ctype.h> //função toupper

int main (void){
    int c;
    char entrada[121]; // armazena nome do arquivo de entrada
    char saida[121]; // armazena nome do arquivo de saida
    FILE* e; // ponteiro do arquivo
    FILE* s; // ponteiro do arquivo de saida

    printf("digite o nome do arquivo de entrada: ");
    scanf("%120s", entrada);
    printf("Digite o nome do arquivo de saida: ");
    scanf("%120s", saida); 

    e = fopen(entrada, "rt");
    if (e == NULL){
        printf("Não foi possível abrir arquivo de entrada. \n");
        return 1;
    }

    s = fopen(saida, "wt");
    if (s == NULL){
        printf("Não foi possivel abrir arquivo de saida.\n");
        fclose(e);
        return 1;
    }

    while ((c = fgetc(e)) != EOF){
        fputc(toupper(c), s);
    }

    fclose(e);
    fclose(s);

    return 0;
}
