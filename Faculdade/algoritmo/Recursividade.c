#include <stdio.h>
#include <math.h>
#include <string.h>

// procedimento
void imprimirNumeros(int n){
(n == 100){
        return;
    }
    else{
        printf("%d ", n);
        imprimirNumeros(n + 1);
    }
}


int main(){

    int numero = 0;
    printf("Os primeiros %d numeros naturais em ordem crescente são..: ", numero);

    //chamar a função recrusiva
    imprimirNumeros(numero);
    printf("\n");



    printf("Fim do programa!\n");
    return 0;
}    
    //Caso base
    if