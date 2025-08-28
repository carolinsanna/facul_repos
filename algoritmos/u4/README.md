# 🦙 Trabalho da Unidade 4 🦙 

## Proposta

Desenvolver um programa que implementa e compara dois tipos de funções recursivas para
calcular o n-ésimo número da sequência de Fibonacci. Procedimentos: 
1. Definição de Função Recursiva Simples; <br>
1.1 Implementar uma função recursiva para calcular o n-ésimo número da sequência de Fibonacci.
2. Definição de Função Recursiva em Cauda; <br>
2.1. Implementar a função Fibonacci utilizando recursividade em cauda.
3. Comparação entre Função Recursiva Simples e Recursiva em Cauda; <br>
3.1 Implementar um programa que utilize as funções recursivas para calcular e comparar os tempos de
execução para diferentes valores de n.;
4. Discussão sobre Eficiência; <br>
4.1. Escrever uma análise dos resultados que obteve ao comparar a função Fibonacci recursiva simples
com a função Fibonacci recursiva em cauda em termos de eficiência e desempenho.

## Solução 

Inicialização da biblioteca padrão de entrada/saída e da bilbioteca time.h (para calcular o tempo de execução das funções recursivas).
Declaração e içamento de funções de leitura e controle de entrada do usuário.
Declaração das funções recursivas.

```
#include <stdio.h>
#include <time.h>

int get_termos(void);
int fibonacci(int termos);
int fibo_tail(int termos, int p_t, int n_t);
```

:technologist: A função get_termos(void) solicita ao usuário um número correspondente ao termo da série que ele queira exibir no terminal. E retorna esse número subtraindo 1 - return termos-1; - pois vamos iniciar a contagem dos termos da série em 0 em vez de 1.

```
int get_termos(void){
  int termos;

  printf("Qual termo da série de Fibonacci você quer? ");  
  scanf("%d", &termos); 

  //Retorna o número inserido - 1
  //Pois vamos iniciar a contagem da série
  //em ZERO
  return termos-1;
}
```

### Função recursiva simples

Ocorre quando a chamada recursiva não é a última operação realizada na função. Isso significa que, após retornar da chamada recursiva, ainda existe trabalho a ser feito. Como consequência, a função precisa manter informações na pilha de chamadas (stack), consumindo memória a cada passo da recursão. Um exemplo clássico é o cálculo do fatorial ou da sequência de Fibonacci pela forma direta da sua fórmula matemática, onde cada chamada aguarda o resultado das chamadas subsequentes para concluir sua operação. 

```
//Função recursiva simples para calcular
//n termos da série de Fibonnaci
int fibonacci(int termos){
  if(termos == 0) return 0;
  if(termos == 1) return 1;
  return fibonacci(termos - 1) + fibonacci(termos - 2);
}
```
:technologist: Aqui, para calcular o termo n, a função precisa calcular n-1 e n-2, somar os resultados e retornar. Isso cria uma árvore de chamadas exponencial, com muitas recomputações redundantes. Por exemplo, ao calcular fibonacci(5), a função chamará fibonacci(4) e fibonacci(3), e dentro de fibonacci(4) chamará novamente fibonacci(3) — repetindo cálculos desnecessários.

### Função recursiva em cauda

Ocorre quando a chamada recursiva é a última instrução da função. Nesse caso, não há mais nenhum trabalho pendente após a recursão, o que permite ao compilador (em linguagens que implementam tail call optimization) reutilizar o mesmo espaço de pilha, reduzindo o custo de memória. Em termos práticos, a recursão em cauda se comporta de forma semelhante a um loop iterativo, com eficiência linear no tempo de execução e constante no consumo de pilha.

```
//Função recursiva em cauda para 
//chamar a função auxiliar
int fibonacci(int termos){
  return fibo_tail(termos, 0, 1);
}

//Função auxiliar  que calcula
//n termos da série de Fibonacci
int fibo_tail(int termos, int p_t, int n_t){
  if(termos == 0) return p_t;
  if(termos == 1) return n_t;
  return fibo_tail(termos - 1, n_t, p_t+n_t);
}
```

:technologist: Aqui, a função fibonacci() é implementada utilizando uma função auxiliar, fibo_tail(), que carrega dois acumuladores, onde p_t representa o termo anterior e n_t o termo atual. A cada chamada, os valores são atualizados e passados adiante. Diferente da versão simples, não há recomputação: cada passo usa diretamente os resultados já acumulados.
Isso significa que fibo_tail() percorre a sequência de Fibonacci em uma linha reta de chamadas, sem reconstruir toda a árvore recursiva. Dessa forma, o tempo de execução cresce linearmente com o valor termos, em vez de exponencialmente.

### Comparação de tempos de execução

Na função principal, a struct timespec e a variável timer, que serão utilizadas para calcular o tempo de execução, são declaradas.

```
int main(void){
  //inicialização da struct de início e fim do contador
  //e da variável que armazenará o resultado do tempo
  struct timespec start, end;
  double timer;
  ...
}
```

:technologist: Assim, o tempo de execução é medido utilizando funções da biblioteca time, como clock_gettime(); que recebe como parâmetros uma clock_id, que basicamente é a contagem de tempo de processamento pela CPU (nesse caso, em nanossegundos, foi utilizado CLOCK_MONOTONIC), e uma struct com o timespec - que é uma variável que armazena o clock do início ou do fim da execução. Por isso, ela é chamada duas vezes: uma antes de iniciar a execução do código principal, e outra depois, com a finalidade de determinar o intervalo de tempo.

```
  ...
  //inicia o registro de tempo de execução do código abaixo
  clock_gettime(CLOCK_MONOTONIC, &start);
  int termos = get_termos();

  printf("O %do termo da série de Fibonacci é %d\n", termos+1, fibonacci(termos));

  //encerra o registro de tempo de execução do código acima
  clock_gettime(CLOCK_MONOTONIC, &end);
  ...
```

:technologist: Feita a captura de time clock, agora precisamos calcular o tempo subtraindo o tempo final end.tv_sec do tempo inicial start.tv_sec em segundos, obtendo aqui os segundos inteiros (p. ex. se passaram 3.8 seg, ele retorna apenas 3). Para aumentar a precisão, basta diminuir o tempo final end.tv_nsec do tempo inicial start.tv_nsec em nanossegundos e, depois, dividir por 1 bilhão (1e9 em notação científica), convertendo os nanossegundos em segundos fracionados (p. ex. se passaram 3.8 seg, ele retorna os 0.8). E, então, finalmente somando os dois resultados, imprimindo o resultado logo em seguida. 

```
 {
  ...
  //calcula o tempo, subtraindo os segundos finais do segundos iniciais
  timer = (end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/1e9;

  printf("Tempo de execução : %.9f segundos\n", timer);

  return 0;
}
```

## Aplicação

### Tempo de execução da função recursiva simples

#### Compilação

```
$ make fibo
```

### Execução

```
$ ./fibo
```

### Input - teste com 42 termos

```
Qual termo da série de Fibonacci você quer? 42
```

### Output - teste com 42 termos

```
O 42o termo da série de Fibonacci é 165580141
Tempo de execução: 2.785212972 segundos
```

### Input - teste com 50 termos

```
Qual termo da série de Fibonacci você quer? 50
```

### Output - teste com 50 termos

```
O 50o termo da série de Fibonacci é -811192543
Tempo de execução: 52.573061530 segundos
```

:technologist: É possível observar que, apesar de ter aumentado apenas 8 termos entre uma execução e outra, o programa levou aproximadamente 50 segundos a mais pra ser executado na segunda tentativa. Além disso, o retorno do programa é impossível, uma vez que o 50o termo da série de Fibonacci certamente não é um número negativo.  <br>

:technologist: Essas peculiaridades ocorreram porque o algoritmo de recursividade simples tem complexidade exponencial. Significa dizer que a cada termo acrescentado, ele aumenta exponencialmente o número de chamadas da função à pilha de execução, levando cada vez mais tempo. Nos casos testados podem ter ultrapassado a 2 bilhões de chamadas, por conta da recomputação. <br>

:technologist: Ao retornar um número negativo fica evidente um overflow de inteiro, isso ocorre porque em C, as variáveis do tipo int tem limite de 32 bits (só podem armazenar valores entre -2.147.483.648 e 2.147.483.647). E como a sequência de Fibonacci cresce muito rapidamente, quando o programa chega no termo 47 ele já estoura esses 32 bits - F(46) = 1.836.311.903 -> F(47) = 2.971.215.073. E o número “vira” negativo, como se desse a volta no contador. Para aumentar essa capacidade de contagem de Fibonacci, podemos trocar o int por um long que suporta números de até 64 bits.

### Tempo de execução da função recursiva em cauda

#### Compilação

```
$ make fibotail
```

### Execução

```
$ ./fibotail
```
### Input - teste com 42 termos

```
Qual termo da série de Fibonacci você quer? 42
```

### Output - teste com 42 termos

```
O 42o termo da série de Fibonacci é 165580141
Tempo de execução: 1.614435116 segundos
```

### Input - teste com 50 termos

```
Qual termo da série de Fibonacci você quer? 50
```

### Output - teste com 50 termos

```
O 50o termo da série de Fibonacci é -811192543
Tempo de execução: 1.823151238 segundos
```

:technologist: O tempo de execução de uma função recursiva em cauda é evidentemente menor, e portanto, mais eficiente, restando como alternativa de melhora de performance em casos como este. Quanto maior o termo mais evidente fica a diferença de tempo de execução, demonstrando, mais uma vez, a complexidade exponencial das recursividades simples. <br>

:technologist: Referente ao valor negativo retornado pelo programa, já foi explicado sobre a limitação das variáveis do tipo inteiras em C.

## Conclusão

Comparando os dois códigos, observamos uma diferença marcante no tempo de execução. A versão com recursão simples gera recomputações exponenciais e, portanto, torna-se extremamente lenta para termos maiores da sequência de Fibonacci. Já a versão em recursão em cauda elimina a redundância ao carregar os valores parciais nos parâmetros da função, o que garante um tempo de execução linear e muito mais eficiente. <br>

Esse resultado retoma diretamente os conceitos iniciais: enquanto a recursão simples mantém operações pendentes após cada chamada e acumula trabalho na pilha, a recursão em cauda transforma o problema em uma sequência contínua de chamadas sem operações posteriores, equivalendo a um loop otimizado. Assim, o uso de recursão em cauda não só reduz o tempo de execução como também evita desperdício de recursos, confirmando sua superioridade prática em problemas desse tipo.