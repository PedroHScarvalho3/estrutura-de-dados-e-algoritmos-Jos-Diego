#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <math.h>

//OBSERVAÇOES PARA PedroSCarvalho
/*
falta ordenar os nomes, numeros e pontos, da para fazer com afunção qsort, usada na função anterior, pelo menos com os numeros, tem que testar com os nomes e pontos
*/ 

int main(){
	
  FILE * arquivo_in, *arquivo_out;
  char * token;
  arquivo_in = fopen("L0Q2.in", "r");
  if(arquivo_in == NULL)
  	perror("erro ao abrir arquivo");
  
  arquivo_out = fopen("L0Q2-2.out", "w");
  char linha[256], str[100], ponto[100], number_f[100], number_i[100], numbers[100], teste[100]; 
  int i = 0, i_str = 0, i_ponto = 0, i_number = 0, cont = 0, valor_i = 0, j = 0, k = 0;

  while(fgets(linha, 255, arquivo_in) != NULL){
    // printf("******1*****\n");
    while(linha[i] != '\0'){
      if(linha[i] > 96 && linha[i] < 123){
      for(; linha[i] != ' '; i++, i_str++){
        str[i_str] = linha[i];
      }
      str[i_str] = linha[i];
      i_str++;
      i++;
      }else if(linha[i] == '('){
        for(; linha[i] != ' '; i++, i_ponto++){
          ponto[i_ponto] = linha[i];
        }
        ponto[i_ponto] = linha[i];
        i_ponto++;
        i++;
      }else{
        for(; linha[i] != ' '; i++, i_number++){
          if(linha[i] == '.'){
          	cont++;
		  }
          numbers[i_number] = linha[i];
        if(cont == 0){
          for(; valor_i < i_number; j++, valor_i++){
            number_i[j] = numbers[valor_i];
            number_i[j+1] = ' ';
          }
          j++;
          valor_i = i_number;
        }else{
          cont = 0;
          for(; valor_i < i_number; k++, valor_i++){
            number_f[k] = numbers[valor_i];
            number_f[k+1] = ' ';
          }
          k++;
        }
        number_f[k] = '\0';
        strcpy(teste, number_f);
        valor_i = i_number;
        i++;
      }
    }
    fprintf(arquivo_out, "str: %s /int: %s /float: %s  /p: %s", str, number_i, teste, ponto);
    i = 0, i_str = 0, i_ponto = 0, i_number = 0, cont = 0, valor_i = 0, j = 0, k = 0;
    memset(str, '\0', sizeof(str));
  }
  
  fclose(arquivo_in);
  fclose(arquivo_out);
  }
}