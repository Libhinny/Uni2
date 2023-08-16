/* TAD: Aluno */
#include "disciplina.h"

typedef struct aluno Aluno;

/* Funções importadas */
Aluno* cria_aluno(char nome[], int matricula);
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);
void exclui_aluno(Aluno* aluno);
