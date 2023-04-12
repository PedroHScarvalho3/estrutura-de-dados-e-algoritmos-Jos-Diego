#include <stdio.h>
#include <string.h>


int main() {
   char str[] = "points(-2,-1) (8,6) (4,0) (2,2) (4,2)";
   char *token;

   // divide a string em tokens com base nos caracteres que não são números, sinais de menos e vírgulas
   token = strtok(str, "points(), ");
   while (token != NULL) {
    
      
         printf("Numero: %s\n", token);
      
      token = strtok(NULL, "points(), ");
   }
   return 0;
}
