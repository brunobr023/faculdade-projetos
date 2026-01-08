#include <stdio.h>
#include <math.h>
#include <string.h>

struct Usuario{
    char nome[50];
    int idade;
    float mediaNotas;

};

int main(){

    struct Usuario usuario1;

    strcpy(usuario1.nome, "Bruno Otavio");
    usuario1.idade = 20;
    usuario1.mediaNotas = 9.6;

    printf("Nome.....: %s \n", usuario1.nome);
    printf("Idade....: %d \n", usuario1.idade);
    printf("Média....: %.2f \n", usuario1.mediaNotas);


    printf("Fim do programa!\n");
    return 0;
}