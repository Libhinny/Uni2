#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <contabancaria.h>

struct contabancaria{
    char titular[80]; //nome da pessoa
    int numero;
    float saldo;
};

ContaBancaria* cria_conta(char* titular, int numero, float saldo){
    ContaBancaria* dados = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (dados == NULL){
        printf("Sem memoria!");
        exit(1);
    }

    strcpy(dados->titular, titular);
    dados->numero = numero;
    dados->saldo = saldo;
    return dados;
}

void atualiza_saldo(ContaBancaria* dados, float novo_saldo){
    dados->saldo += novo_saldo;
    printf("Atualização do saldo realizada!\n");
}

int saca(ContaBancaria* dados, float x){
    if (dados->saldo >= x){
        dados->saldo -= x;
        printf("Saque realizado com sucesso!\n");
        return 1;
    } else{
        printf("Seu saldo é insuficiente para realizar o saque!\n");
    }
}

void transfere(ContaBancaria* origem, ContaBancaria* destino, float valor){
    if (origem->saldo >= valor){
        origem->saldo -= valor;
        destino->saldo += valor;
        printf("Transferencia realizada com sucesso!\n");
    }
    else {
        printf("A transferencia nao pode ser realizada!\n");
    }
}

int saldo(ContaBancaria* dados){
    return dados->saldo;
}

void exclui_conta(ContaBancaria* dados){
    free(dados);
}
