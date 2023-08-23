// Questao 1
#include <stdio.h>

int sum(int n){
    int i; // c1
    int soma = 0; // c3
    for (i = 0; i <= n; i++){ // n*c3
        soma += soma; // n*c4
    }
    return soma; // c5
}

//T(n) = O(n)

// Questão 2

/*
c1*(n-1) + c2*(n-1) + c3*(n-1) + c4 + c5 + c6 + c7 + c8 + c9 + c10 + c11 + c12 + c13
t(n) = a(n-1) + b
t(n) = O((a(n-1))
t(n) = O(n)

*/

// Questão 3
