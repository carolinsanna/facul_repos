#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um nó da pilha
typedef struct Node {
    char operacao[50];
    struct Node *next;
} Node;

// Estrutura da pilha
typedef struct {
    Node *top;
} Stack;

// Inicializa a pilha
void initStack(Stack *s) {
    s->top = NULL;
}

// Verifica se a pilha está vazia
int isEmpty(Stack *s) {
    return (s->top == NULL);
}

// Operação push: insere no topo
void push(Stack *s, char *op) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(novo->operacao, op);
    novo->next = s->top;
    s->top = novo;

    printf("Operação '%s' adicionada ao histórico.\n", op);
}

// Operação pop: remove do topo
char* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Histórico vazio. Nada para desfazer.\n");
        return NULL;
    }

    Node *temp = s->top;
    s->top = temp->next;

    char *opRemovida = (char*) malloc(50 * sizeof(char));
    strcpy(opRemovida, temp->operacao);

    free(temp);

    return opRemovida;
}

// Mostrar conteúdo da pilha
void mostrar(Stack *s) {
    if (isEmpty(s)) {
        printf("Histórico vazio.\n");
        return;
    }

    printf("Histórico de operações (topo -> base):\n");

    Node *atual = s->top;
    while (atual != NULL) {
        printf(" - %s\n", atual->operacao);
        atual = atual->next;
    }
}


int main() {
    Stack historico;
    initStack(&historico);

    // Simulação de operações da calculadora
    push(&historico, "5 + 3");
    push(&historico, "8 * 2");
    push(&historico, "16 / 4");
    push(&historico, "4 ^ 2");

    mostrar(&historico);

    printf("\nDesfazendo a última operação...\n");
    char *desfeita = pop(&historico);
    if (desfeita != NULL) {
        printf("Operação desfeita: %s\n", desfeita);
        free(desfeita);
    }

    printf("\nEstado atual do histórico:\n");
    mostrar(&historico);

    return 0;
}
