#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 10


// Estrutura de Cada elemento na tabela hash

struct Elemento{
    char chave[50];
    char valor[50];
};


//Função para criar uma tabela hash vazia

struct Elemento* criarTabelaHash(){
    struct Elemento* tabela = (struct Elemento*) malloc(TAMANHO * sizeof(struct Elemento));
    for (int i = 0; i < TAMANHO; i++){
        strcpy(tabela[i].chave, "");
        strcpy(tabela[i].valor, "");
    }
    return tabela;
};

// Função de espalhamento perfeito

int calcularHash(char* chave){
    int hash = 0;
    for(int i = 0; i < strlen(chave); i++ ){
        hash += chave[i];
    }
    return hash % TAMANHO;
}


// Função para inserir um elemento na tabela hash

void inserir(struct Elemento* tabela, char* chave, char* valor){
    int indice = calcularHash(chave);
    while (strcmp(tabela[indice].chave, "") != 0){
        indice = (indice + 1) % TAMANHO; // Resolução de colisões por sondagem linear
    }
    strcpy(tabela[indice].chave, chave);
    strcpy(tabela[indice].valor, valor);
}

// Função para buscar um elemento na tabela hash


char* pesquisar(struct Elemento* tabela, char* chave){
    int indice = calcularHash(chave);
    while (strcmp(tabela[indice].chave, "") != 0){
        if (strcmp(tabela[indice].chave, chave) == 0){
            return tabela[indice].valor;
        }
        indice = (indice + 1 ) % TAMANHO; // Resolução de colisões por sondagem linear
    }
    return "Não encontrado!";
}


//Função MAIN
int main(){
    struct Elemento* tabela = criarTabelaHash();


    inserir(tabela, "ch1", "Professor");
    inserir(tabela, "ch2", "Programador");
    inserir(tabela, "ch3", "Médico");

    printf("%s\n", pesquisar(tabela, "ch1"));// Saida 1
    printf("%s\n", pesquisar(tabela, "ch2"));// Saida 2
    printf("%s\n", pesquisar(tabela, "ch4"));// Saida NULL (Sem chave)

    free(tabela);
    return 0;

}