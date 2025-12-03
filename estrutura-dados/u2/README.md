# 🦙 Trabalho da Unidade 2 🦙 
## Histórico de Operações com Pilha

Este projeto implementa um sistema simples de histórico de operações utilizando uma estrutura de dados do tipo **Pilha (Stack)** em C. O objetivo é simular o comportamento de "desfazer" (undo) de uma calculadora ou editor.

## 📋 Funcionalidades

- **Adicionar Operação (Push)**: Insere uma nova operação matemática no topo do histórico.
- **Desfazer Operação (Pop)**: Remove e retorna a operação mais recente do histórico.
- **Visualizar Histórico**: Exibe todas as operações armazenadas na pilha, do topo (mais recente) para a base (mais antiga).

## 🛠️ Estrutura do Código

O código define:
- `struct Node`: Um nó da lista encadeada que armazena a string da operação.
- `struct Stack`: A estrutura da pilha que mantém um ponteiro para o topo.
- Funções de manipulação: `initStack`, `push`, `pop`, `isEmpty`, `mostrar`.

## 🚀 Como Compilar e Executar

Certifique-se de ter um compilador C instalado (como o GCC).

### Compilação

Navegue até o diretório do projeto e execute:

```bash
gcc history.c -o history
```

### Execução

Após compilar, execute o programa:

```bash
./history
```

## 📝 Exemplo de Saída

Ao executar o programa, você verá uma simulação de operações sendo adicionadas e depois a última sendo desfeita:

```text
Operação '5 + 3' adicionada ao histórico.
Operação '8 * 2' adicionada ao histórico.
Operação '16 / 4' adicionada ao histórico.
Operação '4 ^ 2' adicionada ao histórico.
Histórico de operações (topo -> base):
 - 4 ^ 2
 - 16 / 4
 - 8 * 2
 - 5 + 3

Desfazendo a última operação...
Operação desfeita: 4 ^ 2

Estado atual do histórico:
Histórico de operações (topo -> base):
 - 16 / 4
 - 8 * 2
 - 5 + 3
```

## 📚 Contexto

Este exercício faz parte da unidade de **Estrutura de Dados (Pilhas)**.
