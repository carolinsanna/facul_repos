# 🦙 Trabalho da Unidade 1 🦙 
## Gerenciador de Tarefas em C

Este projeto implementa um sistema simples de gerenciamento de tarefas
utilizando listas encadeadas em linguagem C. O programa permite
cadastrar, listar, remover e liberar todas as tarefas armazenadas na
memória.

## Funcionalidades

-   **Cadastrar tarefa**: inclui uma nova tarefa com ID, descrição e
    prioridade.
-   **Listar tarefas**: exibe todas as tarefas atualmente cadastradas.
-   **Remover tarefa**: exclui uma tarefa específica da lista com base
    no ID informado.
-   **Liberar lista**: remove todas as tarefas da memória desalocando
    cada nó.
-   **Menu interativo**: interface textual que guia o usuário pelas
    opções do sistema.

## Estrutura de Dados

As tarefas são armazenadas em nós de uma lista encadeada simples. Cada
nó contém: - `id` da tarefa\
- `descricao`\
- `prioridade`\
- ponteiro para o próximo nó

## Principais Funções

### cadastrar(lista)

Lê os dados necessários para criar uma tarefa, verifica se o ID já
existe e insere o novo nó na lista.

### listar(lista)

Percorre toda a lista e imprime cada tarefa na tela. Se a lista estiver
vazia, exibe uma mensagem adequada.

### remover(lista)

Localiza um nó pelo ID e reorganiza os ponteiros para removê-lo
corretamente sem quebrar a lista. Caso o ID não exista, informa ao
usuário.

### liberar(lista)

Percorre a lista liberando cada nó individualmente até que toda a
memória seja desalocada.

### main()

Gerencia o fluxo do programa exibindo o menu principal e chamando as
funções apropriadas conforme a escolha do usuário.

## Como Compilar

No terminal utilize:

    gcc main.c -o tarefas

## Como Executar

    ./tarefas

## Requisitos

-   Compilador GCC ou compatível
-   Ambiente Linux, Windows ou macOS
