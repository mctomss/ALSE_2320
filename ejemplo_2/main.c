#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv){
  printf("Número de argumentos: %d\n", argc);
  printf("El valor de X es:  %s\n", argv[1] );
  float x = atof( argv[1] );
  printf("Los coeficientes del polinomio son:\n");
  float coef[argc - 2];
  float res = 0.;
  for(int i=2; i<argc; i++){
    printf("coeficiente: %d es %s\n",i-2, argv[i]);
    coef[i-2] = atof( argv[i] );
    if( i == 2 )
      res = coef[0];
    else
      res += coef[i-2] * pow(x,i-2);
    
  }

  FILE* fp;
  fp = fopen("salida.out", "w+");
  fprintf(fp,"El polinomio evaluado en %f es %f\n", x, res);
  fclose(fp);
  return 0;
}
