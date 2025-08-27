#include <stdio.h>

int get_alunos(void);
int get_aval(void);
float get_notas(int index);

int main(void){
  int alunos = get_alunos();
  int aval = get_aval();
  float notas[alunos][aval];
  float medias[alunos];
  float soma, maior, menor = 10;
  int aprovados, reprovados;

  for(int i = 0; i < alunos; i++){
    printf("Entre com as notas do %do aluno:\n", i+1);
    for(int j = 0; j < aval; j++){
      notas[i][j] = get_notas(j);
    }    
  }

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

  printf("A maior média foi %.2f\n", maior);
  printf("A menor média foi %.2f\n", menor);
  printf("Dos %d alunos, %d aprovaram e %d reprovaram\n", alunos, aprovados, reprovados);

  return 0;

}

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

float get_notas(int index){
  float nota; 

  do {   
    printf("Nota %d: ", index+1);
    scanf("%f", &nota);
  } while (nota < 0.00 || nota > 10.00);

  return nota;
  
}