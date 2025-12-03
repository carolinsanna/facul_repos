# 🦙 Trabalho da Unidade 4 🦙 
## Sistema de Clientes com Tabela Hash

Este projeto implementa um sistema simples e eficiente para armazenamento e busca de dados de clientes (nome e telefone) utilizando a linguagem C e uma estrutura de dados de Tabela Hash (Hash Table).

## Funcionalidades

*   **Inserção de Clientes**: Permite adicionar novos clientes com nome e telefone.
*   **Busca Rápida**: Localiza o telefone de um cliente instantaneamente através do nome.
*   **Listagem Geral**: Exibe todos os clientes cadastrados no sistema.
*   **Tratamento de Colisões**: Utiliza encadeamento (listas ligadas) para resolver colisões de hash.

## Estrutura do Projeto

O projeto consiste nos seguintes arquivos:

*   `sistema_clientes.c`: Código fonte principal contendo a implementação da tabela hash e a lógica do programa.
*   `explicacao_tecnica.txt`: Documento detalhando o funcionamento técnico do código, estruturas de dados e testes.

## Como Compilar e Executar

Certifique-se de ter um compilador C (como o GCC) instalado.

1.  **Compilar**:
    Abra o terminal na pasta do projeto e execute:
    ```bash
    gcc sistema_clientes.c -o sistema_clientes
    ```

2.  **Executar**:
    Após a compilação, inicie o programa com:
    ```bash
    ./sistema_clientes
    ```

## Detalhes Técnicos

*   **Tamanho da Tabela**: 101 posições (número primo para melhor distribuição).
*   **Função Hash**: Algoritmo polinomial simples.
*   **Complexidade**:
    *   Inserção: O(1) médio.
    *   Busca: O(1) médio.

## Autor

Desenvolvido como parte da atividade prática da unidade 4 de Estrutura de Dados.
