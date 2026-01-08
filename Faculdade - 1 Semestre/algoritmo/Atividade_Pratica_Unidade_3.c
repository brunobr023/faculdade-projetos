#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int continuarPrograma = 1;
    do
    {
        printf("Bem vindo ao programa! Deseja continuar?\n Digite 1 para SIM ou Digite 0 para NÃO.");
        scanf("%d", &continuarPrograma);
        if(continuarPrograma == 0){
            break;
        }

        //Exercício 1: Implementar um programa que leia um número inteiro e informe se ele é positivo, negativo ou zero.
        do{
            int numeroExercicio1;
            printf("\n Olá digite um número para verificar se ele é positivo ou negativo ou igual a zero...:");
            scanf("%d", &numeroExercicio1);
            if (numeroExercicio1 > 0){
                printf("É um número positivo!\n");
                printf("Deseja repetir esse programa? (1 = SIM) ( 0 NÃO)\n");
                scanf("%d", &continuarPrograma);
                if(continuarPrograma == 0){
                break;
                }
            }else if(numeroExercicio1 == 0 ){
                printf("É um número igual a 0 !\n");
                printf("Deseja repetir esse programa? (1 = SIM) ( 0 NÃO)\n");
                scanf("%d", &continuarPrograma);
                if(continuarPrograma == 0){
                break;
                }
            }else if(numeroExercicio1 <0 ){
                printf("É um número negativo.\n");
                printf("Deseja repetir esse programa? (1 = SIM) ( 0 NÃO)\n");
                scanf("%d", &continuarPrograma);
                if(continuarPrograma == 0){
                break;
                }
            }
        // Continuação do aplicativo
        } while (continuarPrograma == 1);
        printf("Deseja continuar?\n Digite 1 para SIM ou Digite 0 para NÃO.");
        scanf("%d", &continuarPrograma);
        if(continuarPrograma == 0){
            break;
        }
        


        //Exercício 2: Implementar um programa que imprima os números de 1 a 10.
        for ( int numero = 0; numero < 10; numero++)
        {
            printf("Os números em sequência são: %d.\n",numero);
        }
        //Continuação do aplicativo
        printf("Deseja continuar?\n Digite 1 para SIM ou Digite 0 para NÃO.");
        scanf("%d", &continuarPrograma);
        if(continuarPrograma == 0){
            break;
        }

        //Exercício 3: Implementar um programa que leia números inteiros até que o usuário digite zero, e então imprimir a soma desses números.
        int numeroExercicio3, somaTotal = 0;
        
        printf("Digite um número inteiro. (0 Para sair): ");
        scanf("%d", &numeroExercicio3);

        while (numeroExercicio3 != 0){
            somaTotal += numeroExercicio3;
            printf("Digite um número inteiro. (0 Para sair): ");
            scanf("%d", &numeroExercicio3);
        }
        printf("A soma dos números é: %d\n", somaTotal);

        //Continuação do aplicativo
        printf("Deseja continuar?\n Digite 1 para SIM ou Digite 0 para NÃO.");
        scanf("%d", &continuarPrograma);
        if(continuarPrograma == 0){
                break;
        }

        // Exercício 4: Implementar um programa que leia um número inteiro positivo e calcule seu fatorial.
        int numeroExercicio4, fatorial;
        do
        {
            printf("Digite um número inteiro positivo para calcular o fatorial: ");
            scanf("%d", &numeroExercicio4);

            if (numeroExercicio4 < 0) {
                printf("Número inválido! Digite apenas números positivos.\n");
            } else {
                fatorial = 1;
                for (int i = 1; i <= numeroExercicio4; i++) {
                    fatorial *= i;
                }
                printf("O fatorial de %d é: %d\n", numeroExercicio4, fatorial);
            }

            printf("Deseja repetir esse programa? (1 = SIM) (0 = NÃO)\n");
            scanf("%d", &continuarPrograma);
        } while (continuarPrograma == 1);
        
        /*
        Exercício 5: desenvolva um programa em C que leia notas de alunos,
        calcule a média, identifique a maior e menor nota, conte quantos
        alunos passaram (nota ≥ 6) e quantos não passaram (nota < 6).
        */
         do {
        float notas[4];
        float soma = 0, media;
        float maiorNota, menorNota;

        for (int i = 0; i < 4; i++) {
            printf("Digite a nota %d: ", i + 1);
            scanf("%f", &notas[i]);

            soma += notas[i];

            if (i == 0) {
                maiorNota = menorNota = notas[i];
            } else {
                if (notas[i] > maiorNota) maiorNota = notas[i];
                if (notas[i] < menorNota) menorNota = notas[i];
            }
        }

        media = soma / 4;

        printf("\nMédia das notas: %.2f\n", media);
        printf("Maior nota: %.2f\n", maiorNota);
        printf("Menor nota: %.2f\n", menorNota);

        printf("\nDeseja repetir esse programa? (1 = SIM) (0 = NÃO): ");
        scanf("%d", &continuarPrograma);

    } while (continuarPrograma == 1);
        

    } while (continuarPrograma == 1);
    printf("Fim do Programa!");
    return 0;
}