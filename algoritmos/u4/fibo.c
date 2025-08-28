#include <stdio.h>
#include <time.h>

int get_termos(void);
int fibonacci(int termos);

int main(void){
  //inicialização da struct de início e fim do contador
  //e da variável que armazenará o resultado do tempo
  struct timespec start, end;
  double timer;

  //inicia o registro de tempo de execução do código abaixo
  clock_gettime(CLOCK_MONOTONIC, &start);

  int termos = get_termos();

  printf("O %do termo da série de Fibonacci é %d\n", termos+1, fibonacci(termos));

  //encerra o registro de tempo de execução do código acima
  clock_gettime(CLOCK_MONOTONIC, &end);

  //calcula o tempo, subtraindo os segundos finais do segundos iniciais
  timer = (end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/1e9;

  printf("Tempo de execução : %.9f segundos\n", timer);

  return 0;
}

int get_termos(void){
  int termos;

  printf("Qual termo da série de Fibonacci você quer? ");
  scanf("%d", &termos); 

  //Retorna o número inserido - 1
  //Pois vamos iniciar a contagem da série
  //em ZERO
  return termos-1;
}

//Função recursiva simples para calcular
//n termos da série de Fibonnaci
int fibonacci(int termos){
  if(termos == 0) return 0;
  if(termos == 1) return 1;
  return fibonacci(termos - 1) + fibonacci(termos - 2);
}
