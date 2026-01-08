#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listaEstrutura {
    int id;
    char descricao[100];
    struct listaEstrutura* prox;
} listaEstrutura;

void inserirTarefa(listaEstrutura** inicio, int id, char* descricao) {
    listaEstrutura* nova = (listaEstrutura*) malloc(sizeof(listaEstrutura));
    nova->id = id;
    strcpy(nova->descricao, descricao);
    nova->prox = NULL;

    if (*inicio == NULL) {
        *inicio = nova;
    } else {
        listaEstrutura* temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nova;
    }
}

void listarTarefas(listaEstrutura* inicio) {
    listaEstrutura* temp = inicio;
    if (temp == NULL) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    while (temp != NULL) {
        printf("ID %d | Descricao %s\n", temp->id, temp->descricao);
        temp = temp->prox;
    }
}

void removerTarefas(listaEstrutura** inicio, int id) {
    listaEstrutura* temp = *inicio;
    listaEstrutura* anterior = NULL;

    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("Tarefa com ID %d nao encontrada.\n", id);
        return;
    }

    if (anterior == NULL) {
        *inicio = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("\nTarefa Removida com Sucesso\n");
}

int verificarID(listaEstrutura* inicio, int id) {
    listaEstrutura* temp = inicio;
    while (temp != NULL) {
        if (temp->id == id) {
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}

void limparBuffer(){
    int clear;
    while((clear = getchar()) != '\n' && clear != EOF);
}

int main() {
    listaEstrutura* lista = NULL;
    int idValido, opcao, id;
    char descricao[100];

    do {
        printf("\nBem vindo ao Agendador de tarefas\n");
        printf("Escolha a opcao!\n");
        printf("1 - Adicionar Tarefa\n");
        printf("2 - Listar Tarefas\n");
        printf("3 - Remover Tarefa\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida! Digite um número.\n");
            limparBuffer();
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                do {
                    printf("\nDigite o ID da Tarefa: ");
                    if (scanf("%d", &id) != 1) {
                        printf("Entrada inválida! Digite um número.\n");
                        limparBuffer();
                        idValido = 1; // força repetir o loop
                        continue;
                    }

                    idValido = verificarID(lista, id);
                    if (idValido) {
                        printf("ID já usado por outra tarefa!\n");
                    }
                } while (idValido);

                limparBuffer(); // limpa antes de ler a descrição
                printf("Digite a Descricao: ");
                scanf("%[^\n]", descricao);

                inserirTarefa(&lista, id, descricao);
                break;

            case 2:
                printf("\nListando Tarefas...\n");
                listarTarefas(lista);
                break;

            case 3:
                printf("\nDigite o ID da tarefa a remover: ");
                if (scanf("%d", &id) != 1) {
                    printf("Entrada inválida! Digite um número.\n");
                    limparBuffer();
                    break;
                }

                removerTarefas(&lista, id);
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}