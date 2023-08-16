/* TAD: conta bancária */

/* tipo exportado */
typedef struct contabancaria ContaBancaria;

/* Funções importadas */
ContaBancaria* cria_conta(char* titular, int numero, float saldo);
void atualiza_saldo(ContaBancaria* dados, float novo_salario);
int saca(ContaBancaria* dados, float x);
void transfere(ContaBancaria* origem, ContaBancaria* destino, float valor);
int saldo(ContaBancaria* dados);
void exclui_conta(ContaBancaria* dados);
