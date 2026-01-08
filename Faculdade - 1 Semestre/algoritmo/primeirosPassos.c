#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

    float nota1, nota2, media; // final de linha de comando
    
    printf("Digite a primeira nota: ");
    scanf("%2f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%2f", &nota2);
    
    media = (nota1 + nota2)/2;

    printf("A sua media será: %2f \n", media);
    scanf("%2f", &media);





    return 0;
    
}