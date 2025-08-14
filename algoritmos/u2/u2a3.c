#include <stdio.h>

const float JUROS = 0.05;

float get_investimento(void);

int get_anos(void); 

float calculo_investimento(float JUROS, int anos, float investimento);

int matriz(void);

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

float calculo_investimento(float JUROS, int anos, float investimento){
  float rendimento = investimento * (1 + (JUROS * anos));

  return rendimento;
}

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