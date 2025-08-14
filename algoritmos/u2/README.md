# 🦙 Trabalho da Unidade 2 🦙 

## Proposta

Desenvolver um programa em C, realizando as seguintes tarefas: 
1. Definir uma constante que represente a taxa de juros anual;
2. Declarar variáveis para armazenar o valor inicial do investimento, o número de anos e o valor final do investimento;
3. Solicitar ao usuário que insira o valor inicial do investimento e o número de anos;
4. Calcular o valor final do investimento utilizando a fórmula de juros simples: 
Valor Final = Valor Inicial * (1 + (Taxa de Juros * Anos));
5. Exibir o valor final do investimento;
6. Além disso, declarar um vetor de inteiros com 3 elementos e uma matriz 2x2 de inteiros, e inicializá-los com valores escolhidos;
7. Utilizar um ponteiro para acessar e modificar o primeiro elemento do vetor;
8. Exibir os valores dos elementos do vetor e da matriz, bem como os endereços de memória de cada elemento.

## Solução 

Inicialização da biblioteca padrão de entrada/saída.
Declaração da constante da taxa de juros anual em 5%.

```
#include <stdio.h>

const float JUROS = 0.05;
```

Declaração e içamento de funções específicas para cada tarefa do algoritmo.

```
float get_investimento(void);

int get_anos(void); 

float calculo_investimento(float JUROS, int anos, float investimento);

int matriz(void);
```

:technologist: As funções get_investimento(void) e get_anos(void) retornam os inputs do usuário - valor inicial do investimento e os anos de rendimento, respectivamente. A escolha por duas funções distintas de leitura se deu pela diferença do tipo de cada um dos inputs retornados, float e int. Além disso, posteriormente, o código pode ser refatorado mais facilmente. Por exemplo, evitar que o usuário entre com um valor negativo, refatorando apenas as funções de leitura para que os inputs do usuário sejam controlados e tratados, evitando ‘mexer’ em outros códigos na estrutura da função principal e mantendo um código limpo e semântico. 

```
float get_investimento(void){
  float investimento;

  printf("Quanto você vai investir? ");
  scanf("%f", &investimento);

  return investimento;
}

int get_anos(void){
  int anos;

  printf("Por quantos anos seu dinheiro vai render? ");
  scanf("%d", &anos);

  return anos;
}
```

:technologist: A função calculo_investimento(float JUROS, int anos, float investimento) recebe a constante juros e os inputs retornados das funções de leitura, calcula o rendimento do investimento no decorrer do tempo utilizando a fórmula da tarefa 4, e retorna um float com o resultado do cálculo.

```
float calculo_investimento(float JUROS, int anos, float investimento){
  float rendimento = investimento * (1 + (JUROS * anos));

  return rendimento;
}
```

:technologist: A função matriz(void) declara um vetor de 3 elementos, e uma matriz 2x2, declara um ponteiro e o direciona para o endereço de memória do primeiro item da matriz e altera o seu valor, depois, imprime os elementos do vetor e da matriz com seus respectivos endereços de memória.

```
int matriz(void){
  int vetor[] = {1, 3, 5};
  int matriz[2][2] = {
    {1, 3},
    {5, 8}
  };
  int tam_vetor = sizeof(vetor) / sizeof(vetor[0]);
  int lin_matriz = sizeof(matriz) / sizeof(matriz[0]);
  int col_matriz = sizeof(matriz[0]) / sizeof(matriz[0][0]);
  int *ponteiro;

  ponteiro = &matriz[0][0];
  *ponteiro = 13;

  printf("Valores e endereço de memória do vetor: \n");

  for(int index = 0; index < tam_vetor; index++){
    printf("| %p ", &vetor[index]);
    printf("%d | ", vetor[index]);
    printf("\n");
  }

  printf("\n");
  printf("Valores e endereço de memória da matriz: \n");

  for(int i = 0; i < col_matriz; i++){
    for(int j = 0; j < lin_matriz; j++){
      printf("| %p ", &matriz[i][j]);
      printf("%d | ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
```

:technologist: A função reservada sizeof() foi utilizada para calcular o tamanho do vetor e da matriz. Ela retorna o tamanho de um objeto em bytes, assim, dividindo o tamanho do objeto pelo tamanho de um dos elementos, é possível obter o tamanho de um vetor em número de elementos. O número de elementos dentro do vetor e da matriz é importante para controlar os laços de repetição para percorrê-los. <br>

:technologist: A função principal chama as funções de leitura e armazenam seus retornos em variáveis que serão utilizadas pela função de cálculo como parâmetros, logo após, imprime o resultado retornado da função de cálculo de rendimentos. E, por fim, chama a função de vetor e matriz.

```
int main(void){

  printf("-xXXx- Investimentos -xXXx-\n");
  printf("\n");

  float investimento = get_investimento();
  int anos = get_anos();
  
  printf("Seus R$ %.2f aplicados por %d anos renderão: R$%.2f\n", investimento, anos, calculo_investimento(JUROS, anos, investimento));
  printf("\n");

  printf("-xXXx- Vetores e Matrizes -xXXx-\n");
  printf("\n");
  
  matriz();

  return 0;
}
```

## Aplicação

### Compilação

```
$ make u2a3
```

### Execução

```
$ ./u2a3
```

### Input

```
-xXXx- Investimentos -xXXx-

Quanto você vai investir? 1200
Por quantos anos seu dinheiro vai render? 3
```

### Output

```
Seus R$ 1200.00 aplicados por 3 anos renderão: R$1380.00

-xXXx- Vetores e Matrizes -xXXx-

Valores e endereço de memória do vetor: 
| 0x7ffe1a601e54 1 | 
| 0x7ffe1a601e58 3 | 
| 0x7ffe1a601e5c 5 | 

Valores e endereço de memória da matriz: 
| 0x7ffe1a601e40 13 | | 0x7ffe1a601e44 3 | 
| 0x7ffe1a601e48 5 | | 0x7ffe1a601e4c 8 |
```





