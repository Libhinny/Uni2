#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "contabancaria.h"

int main(void){
    ContaBancaria* conta1 = cria_conta("Luan", 40028922, 1000.00);
    ContaBancaria* conta2 = cria_conta("Noel", 40028, 1000.00);

    printf("Saldo da conta de %s: %.2f\n", conta1->titular, saldo(conta1));
    printf("Saldo da conta de %s: %.2f\n", conta2->titular, saldo(conta2));

    saca(conta1, 500.0);
    printf("Saldo atualizado da conta de %s: %.2f\n", conta1->titular, saldo(conta1));

    transfere(conta1, conta2, 100.0);
    printf("Saldo atualizado na conta de %s: %.2f\n", conta1->titular, saldo(conta1));
    printf("Saldo atualizado na conta de %s: %.2f\n", conta2->titular, saldo(conta2));
    
    exclui_conta(conta1);
    exclui_conta(conta2);

    return 0;
}
