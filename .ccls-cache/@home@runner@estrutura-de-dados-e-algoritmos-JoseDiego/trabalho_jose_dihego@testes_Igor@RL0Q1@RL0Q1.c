#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmpfunc(const void* a, const void* b) {
    const int* x = (const int*) a;
    const int* y = (const int*) b;
    // printf("dists")
    return (*x - *y);
}
/*OBSERVACOES PARA PedroSCarvalho: 
--Após a leitura do arquivo que você me enviou não entendi muito bem o que era 'distance' e 'sortcut' (e não me recordo da sua explicação) por isso faltam esse dois parametros no arquivo de saida, sinta-se a vontade para coloca-los, mas para isso copie o arquivo .c em questão para outro lugar, a fim de evitar perdas em caso de erros.

--Em decorrencia do uso da biblioteca <math.h> é necessário um novo comando para compilar 'gcc RL0Q1.c -o t2 -lm', note o uso do sufixo 'lm' ao já habitual comando

--É possivel aprimorar o código em termos de eficiencia no uso de memória usando alocação dinamina, se der tempo a gente faz*/


// d = √[(x2 - x1)² + (y2 - y1)²] formula da distancia euclidiana

int main(){
  FILE * arquivo_in, *arquivo_out;
  char * token;
  arquivo_in = fopen("L0Q1.in", "r"); // fopen() abre a função e recebe como argumento o nome e o modo de abertura; retorna um ponteiro para o arquivo
  arquivo_out = fopen("L0Q1.out", "w");
  char linha[255]; 

  
  int cont = 0, pontos[2], distancia[255], i = 0, matriz[255][3];
  while(fgets(linha, 255, arquivo_in) != NULL){ //fgets lê o arquivo linha por linha, recebe como argumentos uma variavel que vai guardar o conteudo da linha em memoria, o buffer dessa variavel e um ponteiro para o arquivo
    token = strtok(linha, "points(), ");
    while (token != NULL) {
      pontos[cont] = atoi(token);
      token = strtok(NULL, "points(), ");
      cont++;
      if(cont > 1){
        distancia[i] = sqrt(pow(pontos[0] - pontos[1], 2) + pow((0 - 0), 2));
        matriz[i][0] = distancia[i];
        matriz[i][1] = pontos[0];
        matriz[i][2] = pontos[1];
        i++; 
        cont = 0;
      }
    }
    qsort(matriz, i, sizeof(matriz[0]), cmpfunc);// ordena a matriz com as distancias e os pontos
    fprintf(arquivo_out, "points"); // fprintf() imprime um conteudo no arquivo, recebe como argumento um ponteiro para o arquivo e oq vai ser impresso; note: caso queira impriimir uma variável use o mesmo padrão da função printf("format", name_variable) com a mais do primeiro parametro que será um ponteiro;
    for(int j = 0; j < i; j++){
     fprintf(arquivo_out, "(%d, %d) ", matriz[j][1], matriz[j][2]);
   } 
  }
  fclose(arquivo_in);//fecha o arquivo; recebe como arg. um ponteiro para arquivo FILE *fp
  fclose(arquivo_out);
}