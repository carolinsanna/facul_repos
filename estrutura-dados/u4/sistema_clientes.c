#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define MAX_NAME 100
#define MAX_PHONE 20

// Estrutura para armazenar os dados do cliente
typedef struct {
    char nome[MAX_NAME];
    char telefone[MAX_PHONE];
} Cliente;

// Nó da lista encadeada para tratamento de colisões
typedef struct Node {
    Cliente cliente;
    struct Node* next;
} Node;

// Tabela Hash (array de ponteiros para nós)
Node* hashTable[TABLE_SIZE];

// Função de Hash simples (soma dos caracteres)
unsigned int hash(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

// Inicializa a tabela hash
void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insere um novo cliente na tabela
void inserir(char *nome, char *telefone) {
    unsigned int index = hash(nome);
    
    // Cria novo nó
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    strcpy(novoNode->cliente.nome, nome);
    strcpy(novoNode->cliente.telefone, telefone);
    novoNode->next = NULL;

    // Inserção no início da lista (mais simples e eficiente)
    if (hashTable[index] == NULL) {
        hashTable[index] = novoNode;
    } else {
        // Tratamento de colisão: encadeamento
        novoNode->next = hashTable[index];
        hashTable[index] = novoNode;
    }
    printf("Cliente '%s' inserido com sucesso.\n", nome);
}

// Busca um cliente pelo nome
char* buscar(char *nome) {
    unsigned int index = hash(nome);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->cliente.nome, nome) == 0) {
            return current->cliente.telefone;
        }
        current = current->next;
    }
    return NULL;
}

// Exibe todos os clientes armazenados
void exibir_todos() {
    printf("\n--- Lista de Clientes ---\n");
    int empty = 1;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        if (current != NULL) {
            empty = 0;
            // printf("Índice %d:\n", i); // Debug opcional
            while (current != NULL) {
                printf("Nome: %s | Telefone: %s\n", current->cliente.nome, current->cliente.telefone);
                current = current->next;
            }
        }
    }
    if (empty) {
        printf("Nenhum cliente cadastrado.\n");
    }
    printf("-------------------------\n");
}

// Função para limpar o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    init_table();
    int opcao;
    char nome[MAX_NAME];
    char telefone[MAX_PHONE];

    do {
        printf("\n=== Sistema de Clientes (Hash Table) ===\n");
        printf("1. Inserir Cliente\n");
        printf("2. Buscar Cliente\n");
        printf("3. Exibir Todos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer(); // Consumir o newline após o scanf

        switch (opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, MAX_NAME, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remover o newline

                printf("Digite o telefone do cliente: ");
                fgets(telefone, MAX_PHONE, stdin);
                telefone[strcspn(telefone, "\n")] = 0; // Remover o newline

                inserir(nome, telefone);
                break;
            case 2:
                printf("Digite o nome para buscar: ");
                fgets(nome, MAX_NAME, stdin);
                nome[strcspn(nome, "\n")] = 0;

                char* tel = buscar(nome);
                if (tel != NULL) {
                    printf("Cliente encontrado! Telefone: %s\n", tel);
                } else {
                    printf("Cliente não encontrado.\n");
                }
                break;
            case 3:
                exibir_todos();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
