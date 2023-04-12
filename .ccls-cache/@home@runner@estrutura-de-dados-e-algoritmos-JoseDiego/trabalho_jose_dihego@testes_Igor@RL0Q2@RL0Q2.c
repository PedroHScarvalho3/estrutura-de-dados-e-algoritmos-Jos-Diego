#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <math.h>



int main(){
  FILE * arquivo_in, *arquivo_out;
  char * token;
  arquivo_in = fopen("L0Q2.in", "r");
  arquivo_out = fopen("L0Q2.out", "w");
  char linha[256], str[100], ponto[100], number_f[100], number_i[100]; 
  int i = 0, i_str = 0, i_ponto = 0, i_number = 0, cont = 0, valor_i = 0;

  while(fgets(linha, 255, arquivo_in) != NULL){
    printf("******1*****\n");
    while(linha[i] != '\0'){
      if(linha[i] > 96 && linha[i] < 123){
      for(; linha[i] != ' '; i++, i_str++){
        str[i_str] = linha[i];
      }//printf("%d\n", i_str);
      // i_str++;
      str[i_str] = linha[i];
      // printf("str: %s\n", str);
      i_str++;
      i++;
      }else if(linha[i] == '('){
        for(; linha[i] != ' '; i++, i_ponto++){
          ponto[i_ponto] = linha[i];
        }
        ponto[i_ponto] = linha[i];
        // printf("p: %s\n", ponto);
        i_ponto++;
        i++;
      }else{
        for(; linha[i] != ' '; i++, i_number++){
          if(linha[i] == '.')
            cont++;
          number_f[i_number] = linha[i];
        }printf("float: %s\n", number_f);
        if(cont != 0){
          for(valor_i += 1;valor_i <= i; valor_i++){
            number_i[valor_i] = number_f[valor_i];
            printf("int %s\n", number_i);
          }
          
        }  
        else
          cont = 0;
        valor_i = i_number;
        printf("valo_i %d\n", valor_i);
        i++;
      }
    }
  fprintf(arquivo_out, "str: %s /int: %s /float: %s /p: %s", str, number_i, number_f, ponto);
  }
  fclose(arquivo_in);
  fclose(arquivo_out);
}