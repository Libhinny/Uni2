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

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
Pior caso: 
c1 + c2*(n-1) + c3*(n-1) + c4*(n-1) + [(n^2-n)/2]c5 + [(n^2-n)/2]c6 + [(n^2-n)/2]c7 + c8*(n-1)
T(n) = a + b*(n-1) + [(n^2-n)/2]*c
T(n) = O(n^2)

Melhor caso:
c1 + C2*(n-1) + c3*(n-1) + c4*(n-1) +  + c6*(n-1)
T(n) = O(n)
*/

// Questão 4

#include <stdio.h>

unsigned long long factorial (int n ) {
    if ( n == 0 || n == 1) { 
    return 1; 
    }
    unsigned long long result = 1; // c1
    for (int i = 2; i <= n ; i ++) { // c2*n
    result *= i ; // c3*n
    }
    return result; // c4
}
int main () {
int n = 10; // c5
    unsigned long long result = factorial ( n ); // c6
    printf (" Factorial of %d is %f\n", n , result ); // c7
    return 0; // c8
}
/* 

T(n)= O(n) 

*/ 
