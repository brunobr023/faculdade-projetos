#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definição da estrutura do nó da lista ligada
struct Node{
    char data[100]; // Dados do nó > Uma string de tamanho 100
    struct Node* next; // Define a que essa é a cabeça e manda para o proximo nó da estrutura
};

void insert(struct Node** head, char* newData){ // Dois parametros
    // alocando memoria para o novo nó
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //Copiar dados para o novo nó
    strcpy(newNode->data, newData);

    //Define o próximo nó como o antigo início da lista
    newNode->next = *head;

    //Define o novo nó como inicio da lista
    *head = newNode;

};

// Função para imprimir os elementos da lista
void printList(struct Node* node){
    while(node != NULL){ // Evita que estoura a pilha
        printf("%s ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main (){
    // inicializa a lista como vazia
    struct Node* head = NULL;
    
    // insersão de elementos na lista

    insert(&head, "Primeiro da Lista Exemplo");
    insert(&head, "ta bom");
    insert(&head, "fim");
    insert(&head, "coisa boa");
    insert(&head, "top");
    insert(&head, "ultimo da lista exemplo 2");

    // imprimir os elementos da lista
    printf("Lista ligada de strings: ");
    
    printList(head);
    

    return 0;
}