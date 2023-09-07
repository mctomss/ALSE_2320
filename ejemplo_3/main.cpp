#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <ctime>


using namespace std;
 
int main(int argc, char** argv){
  std::clock_t start;
  double duration;
  start = std::clock();
  	
  if(argc < 2 ){
    printf("No incluyó el parámetro esperado\n");
    return 1;
  }

  string x( argv[1] );

  size_t pos = x.find_first_not_of("0123456789");
  if( pos != string::npos ){
    printf("El parámetro no tiene números\n");
    printf("Se convertirá de texto a número\n");
  }else{
    printf("El parámetro tiene números\n");
    printf("Se convertirá de número a texto\n");
  }

  duration = (std::clock() - start) / (double) CLOCKS_PER_SEC; 
  printf( "Duración del cálculo: %f in secs,  %f in msec.\n", duration, duration * 1000);
  return 0;
}
