// Bibliotecas importadas
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definindo uma constante de juros (5% / 100 = 0.05)
const float jurosAnual = 0.05;w

// Construindo uma estrutura de variável para o investimento
struct investimentoUsuario {
    float valorInvestimentoinicial;
    int qtdAnos;
    float valorInvestimentofinal;
};

// Executando o programa
int main() {
    
    setlocale(LC_ALL, "");

    //Chamando a estrutura
    struct investimentoUsuario usuario;

    //Incialização do Sistema
    printf("Olá, bem-vindo ao aplicativo de orçamento!\n");
    printf("Qual é o valor de investimento inicial:\n");
    scanf("%f", &usuario.valorInvestimentoinicial);

    printf("Qual é a quantidade de anos que pretende fazer?\n");
    scanf("%d", &usuario.qtdAnos);

    usuario.valorInvestimentofinal = usuario.valorInvestimentoinicial * (1 + (jurosAnual * usuario.qtdAnos));
    printf("O valor final do investimento será de: R$%.2f", usuario.valorInvestimentofinal);
    printf("\nPressione Enter para continuar...");
    getchar();  // Espera o Enter, mas as vezes não funciona.

    // Vetor de inteiros
    int saldo[3] = {2500, 3200, 4500};

    //ponteiro para o primeiro vetor
    int *Saldoptr = saldo;

    //Mostrnado os valores do Array
    printf("\n\nO valor do saldo inicial no vetor foi de: %d\n", saldo[0]);
    printf("O investimento no mês seguinte no vetor foi de: %d\n", saldo[1]);
    printf("E o valor final no vetor é de: %d\n\n\n", saldo[2]);
    printf("Pressione Enter para continuar...");
    getchar();  // Espera o Enter
    
    //alterando os valores dos vetores
    *(Saldoptr + 0) = 3600; // indice 0
    *(Saldoptr + 2) = 8500; // Indice 2

    for(int endrvet = 0; endrvet < 3; endrvet++){
        printf("Elemento %d: valor = %d, endereço = %p\n\n", endrvet, saldo[0], &saldo[2]);
    }

    printf("Pressione Enter para continuar...");
    getchar();  // Espera o Enter

    // Declarando matriz
    int matrizatividade[2][2] = {{25, 30}, {30, 35}};
    int *matrizptr = &matrizatividade [0][0];
    // Mostrando a matriz com endereços
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            printf("Elementos presentes na matriz: [%d][%d] ==> %d\nEndereço => %p\n\n",
                 l, c, matrizatividade[l][c], (void*)&matrizatividade[l][c]);
        }
    }


    printf("Pressione Enter para fechar...");
    getchar();  // Espera o Enter
    printf("\nFim do programa!!!\n");
    return 0;
}
