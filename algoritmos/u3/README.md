# 🦙 Trabalho da Unidade 3 🦙 

## Proposta

Desenvolver um programa em C que leia notas de alunos, calcule a média, identifique a maior e menor nota, conte quantos alunos passaram (nota ≥ 6) e quantos não passaram (nota < 6). Estrutura: 
1. Declaração de variáveis;
2. Leitura das notas dos alunos usando um loop (while);
3. Cálculo da média das notas;
4. Identificação da maior e menor nota usando estruturas condicionais (if); 
5. Contagem dos alunos que passaram e não passaram;
6. Impressão dos resultados;
7. Testar o Programa: Inserir diferentes notas para verificar se o programa calcula corretamente a média, maior e menor nota, e a contagem de alunos que passaram e não passaram. Testar com notas inválidas para garantir que o programa trate essas entradas corretamente. Testar a finalização do programa ao digitar -1.

## Solução 

Inicialização da biblioteca padrão de entrada/saída.
Declaração e içamento de funções de leitura e controle de entrada do usuário.

```
#include <stdio.h>

int get_alunos(void);
int get_aval(void);
float get_notas(int index);
```

:technologist: As funções get_alunos(void) e get_aval(void) rretornam um número inteiro dos inputs fornecidos pelo usuário - o número de alunos avaliados e o número de avaliações propostas.

```
int get_alunos(void){
  int alunos;
  
  printf("Quantos alunos foram avaliados? ");
  scanf("%d", &alunos);

  return alunos;
}

int get_aval(void){
  int aval;

  printf("Quantas avaliações ocorreram? ");
  scanf("%d", &aval);

  return aval;
}
```
:technologist: Esses valores serão utilizados para determinar o tamanho da matriz onde serão armazenadas as notas por alunos. <br>

:technologist: Na função principal, foram declaradas e inicializadas as variáveis necessárias para armazenar as notas, as médias, a maior e a menor nota, calcular a média e contar quantos alunos foram reprovados e quantos foram aprovados.

```
int main(void){
  int alunos = get_alunos();
  int aval = get_aval();
  float notas[alunos][aval];
  float medias[alunos];
  float soma, maior, menor = 10;
  int aprovados, reprovados;
  ...
}
```

:technologist: A matriz que armazena as notas foi inicializada com valores inseridos pelo usuário: aluno x aval, assim, por exemplo, se foram avaliados 10 alunos em 3 avaliações, a matriz será inicializada dessa forma: notas[10][3]. 

```
for(int i = 0; i < alunos; i++){
  printf("Entre com as notas do %do aluno:\n", i+1);
  for(int j = 0; j < aval; j++){
    notas[i][j] = get_notas(j);
  }    
}
```

:technologist: Neste trecho de código, o laço for foi utilizado para percorrer a matriz e receber os valores das notas dos alunos, assim a cada linha, ele chama a função de leitura das notas get_notas(int index) passando o índice corrente como parâmetro, e armazena o valor do input dado pelo usuário na matriz notas. Essa função também é responsável por controlar a entrada de dados do usuário, utilizando uma estrutura do-while, e impedindo a entrada de números negativos ou superiores a nota máxima. 

```
float get_notas(int index){
  float nota; 

  do {   
    printf("Nota %d: ", index+1);
    scanf("%f", &nota);
  } while (nota < 0.00 || nota > 10.00);

  return nota;
  
}
```
:technologist: Com a matriz de notas preenchida, voltando a função principal, foi utilizado novamente o laço for para percorrer a matriz de notas e o array medias, desta vez para fazer o cálculo das médias de cada aluno, determinar quem foi reprovado ou aprovado, qual foi a menor média e qual foi a maior média. Para isso, foi necessário inicializar a variável soma com zero a toda iteração no laço mais externo [alunos- i], para garantir que apenas some as notas de um aluno por vez, em vez de somar todos. <br>

:technologist: Ao entrar na iteração do laço mais interno [notas -j], a variável soma recebe o valor dela mesma acrescida do valor armazenado no ponto da matriz em que está notas[i][j], e repetirá isso até a última iteração do laço interno e iniciar a próxima iteração do laço externo. <br>

:technologist: A cada iteração do laço externo, ao fim dessas somas, o resultado da divisão da variável soma por aval (soma/aval) é atribuído ao array medias, medias[i] = soma/aval, garantindo que o valor não se perderá e estará relacionado ao aluno correto. <br>

:technologist: Ainda dentro da iteração do laço mais externo do for, foi utilizado a estrutura condicional if-then-else para verificar qual é a maior e a menor média. A variável menor foi inicializada com a nota mais alta possível 10, e a variável maior foi inicializada com a menor nota possível 0. Primeiramente, o valor armazenado naquela posição do array medias[i] é comparada com o valor armazenado na variável maior, caso o valor dela seja maior que esta última, a variável maior recebe o seu valor. Passando para a próxima instrução, o valor de medias[i] é novamente comparada, mas desta vez com a variável menor, se o valor dela for menor que o da variável menor, então esta recebe o valor de medias[i]. Essa verificação é feita a cada iteração do for, garantindo que cada um dos valores em medias[i] será verificada. <br> 

:technologist: Obs: Não foi utilizado o else nesse caso, porque se a verificação retornar falso no if não significa que será necessariamente verdadeira no else. Por exemplo, a média testada pode não ser maior que a variável maior, mas não necessariamente ela será menor que a variável menor. Por isso é necessário testar as duas hipóteses antes de atribuir valores a essas variáveis de controle. <br>

:technologist: Em seguida, novamente foi utilizada a estrutura condicional if-then-else para testar se a média do aluno é suficiente para a aprovação. Caso o valor de medias[i] seja menor que 6, a variável reprovados soma +1 e o programa imprime na tela os resultados daquele aluno. Caso o valor de medias[i] seja igual ou superior a 6, a variável aprovados soma +1 e o programa imprime na tela os resultados daquele aluno.

```
for(int i = 0; i < alunos; i++){
  soma = 0;
  for(int j = 0; j < aval; j++){
   soma += notas[i][j];      
  }
  medias[i] = soma/aval;
  if(medias[i] > maior){
    maior = medias[i];
  }
  if(medias[i] < menor){
    menor = medias[i];
  }
  if(medias[i] < 6){
    reprovados++;
    printf("A média do %do aluno é %.2f -- reprovado\n", i+1, medias[i]);
  } else {
    aprovados++;
    printf("A média do %do aluno é %.2f -- aprovado\n", i+1, medias[i]);
  }
  
}
```
:technologist: Ao terminar de percorrer a matriz e fazer as validações necessárias dentro dela. O programa finalmente imprime qual foi a maior média, qual foi a menor média, e quantos alunos foram aprovados e reprovados.
```
int main(void){
  ...

  printf("A maior média foi %.2f\n", maior);
  printf("A menor média foi %.2f\n", menor);
  printf("Dos %d alunos, %d aprovaram e %d reprovaram\n", alunos, aprovados, reprovados);

  return 0;

}
```

## Aplicação

### Compilação

```
$ make u3a3
```

### Execução

```
$ ./u3a3
```

### Input

```
Quantos alunos foram avaliados? 4
Quantas avaliações ocorreram? 3
Entre com as notas do 1o aluno:
Nota 1: 2.5
Nota 2: 6.7
Nota 3: 4
Entre com as notas do 2o aluno:
Nota 1: 9
Nota 2: 5
Nota 3: 8.4
Entre com as notas do 3o aluno:
Nota 1: 0
Nota 2: 3.5
Nota 3: 7.9
Entre com as notas do 4o aluno:
Nota 1: 5.6
Nota 2: 8.3
Nota 3: 9.4
```

### Output

```
A média do aluno 1o aluno é 4.40 -- reprovado
A média do aluno 2o aluno é 7.47 -- aprovado
A média do aluno 3o aluno é 3.80 -- reprovado
A média do aluno 4o aluno é 7.77 -- aprovado
A maior média foi 7.77
A menor média foi 3.80
Dos 4 alunos, 2 aprovaram e 2 reprovaram
```

:technologist: Ao inserir um valor fora do permitido, o programa solicita a entrada do valor novamente ao usuário. Ou seja, o programa solicita uma entrada ao usuário até que este insira um valor válido.





