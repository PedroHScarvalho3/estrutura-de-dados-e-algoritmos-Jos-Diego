#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Dados os pontos A(xA, yA) e B (xB, Yb), para calcular a distância entre esses dois pontos, utilizamos a fórmula dAB² = (xB – xA)² + (yB – yA)².
// char * strtok( char * endereçoStrOrigem, char * endereçoStrDelimitador);

int main(){
  FILE * arquivo;
  arquivo = fopen("L0Q1.in", "r");

  char *dados, ponto[3], matriz[1000][255], linha[255];
  int cont = 0, linhas = 0;
  while(fgets(linha, 255, arquivo) != NULL){
    dados = strtok(linha, "(),");
    printf("%s\n", dados);
    dados = strtok(NULL,"(),");
  }
  // printf("linha: %s", matriz[0]);

  
  
}