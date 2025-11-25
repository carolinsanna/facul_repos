#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char descricao[100];
    struct Node *next;
} Node;

void inserir(Node **head, int id, char descricao[]);
int existeID(Node *head, int id);
void exibir(Node *head);
void remover(Node **head, int id);
void liberarLista(Node *head);

int main() {
    Node* lista = NULL;
    int opcao, id;
    char desc[100];

    do {
        printf("\n=== GERENCIAMENTO DE TAREFAS ===\n");
        printf("1. Inserir tarefa\n");
        printf("2. Exibir tarefas\n");
        printf("3. Remover tarefa\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch(opcao) {
            case 1:
                printf("ID da tarefa: ");
                scanf("%d", &id);
                getchar();
                printf("Descricao: ");
                fgets(desc, 100, stdin);
                desc[strcspn(desc, "\n")] = '\0'; // remover \n
                inserir(&lista, id, desc);
                break;

            case 2:
                exibir(lista);
                break;

            case 3:
                printf("ID da tarefa a remover: ");
                scanf("%d", &id);
                remover(&lista, id);
                break;

            case 4:
                liberarLista(lista);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para criar um novo nó
Node* criarNo(int id, char descricao[]) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->id = id;
    strcpy(novo->descricao, descricao);
    novo->next = NULL;
    return novo;
}

// Inserção no final
void inserir(Node **head, int id, char descricao[]) {
    if (existeID(*head, id)) {
        printf("Erro: Ja existe uma tarefa com o ID %d.\n", id);
        return;
    }

    Node* novo = criarNo(id, descricao);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = novo;
}

// Verifica se a ID inserida já existe, evitando conflitos em remoções futuras
int existeID(Node *head, int id) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return 1; // ID encontrado
        temp = temp->next;
    }
    return 0; // ID não encontrado
}

// Percurso e exibição
void exibir(Node *head) {
    if (head == NULL) {
        printf("\nNenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE TAREFAS ---\n");
    Node* temp = head;

    while (temp != NULL) {
        printf("ID: %d | Descricao: %s\n", temp->id, temp->descricao);
        temp = temp->next;
    }
    printf("-------------------------\n");
}

// Remoção por identificador
void remover(Node **head, int id) {
    if (*head == NULL) {
        printf("Lista vazia! Nao ha o que remover.\n");
        return;
    }

    Node* temp = *head;
    Node* anterior = NULL;

    // Caso seja o primeiro nó
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Tarefa removida com sucesso.\n");
        return;
    }

    // Procurar o nó a remover
    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Tarefa com ID %d nao encontrada.\n", id);
        return;
    }

    anterior->next = temp->next;
    free(temp);
    printf("Tarefa removida com sucesso.\n");
}

// Liberar memória ao final
void liberarLista(Node *head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
