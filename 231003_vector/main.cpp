#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "punto.h"
#include <iostream>
#include <vector>


int main(int argc, char** argv){
  if( argc < 2){
    std::cout << "Debe pasar el path del archivo de los datos de entrada ";
    std::cout << "junto con las coordenadas de consulta.\n" << std::endl;
    return 1;
  }

  std::cout << "Se abrirá el archivo: " << argv[1] << std::endl;
  char buff[255];
  // Crear el punto de test llamando el construtor por parámetros
  Punto test( strtod( argv[2], NULL ), strtod( argv[3], NULL ) );
  // voy a crear un vector de puntos  
  std::vector<Punto> vecPuntos;
  Punto tmp;   // tmp se contruye con el constructor por omisión
  int i = 0;
  FILE * archivo = fopen( argv[1], "r" );
  while ( fgets(buff, 255, (FILE*) archivo )){
    if( i%2 == 0 )
      tmp.X( strtod( buff, NULL ) );
    else
      tmp.Y( strtod( buff, NULL ) );

    i++;
    vecPuntos.push_back( tmp );
  }
  fclose( archivo );

  double dist,dist1, dist2;
  dist1 = dist2 = 1000000000.;
  int indx1, indx2;
  indx1 = indx2 = 0;

  for( i = 0; i < vecPuntos.size(); i++){
    //std::cout << "( " << vecPuntos[i].X() << ", " << vecPuntos[i].Y() << " )" << std::endl;
    std::cout << vecPuntos[i] << std::endl;
    dist = test.distancia ( vecPuntos[i] ); 
    if( dist < dist1 ){
      dist2 = dist1;
      indx2 = indx1;
      dist1 = dist;
      indx1 = i;
    }
  }
 
  std::cout << "Los dos puntos más cercanos a ( " << test.X() << ", " << test.Y();
  std::cout << " ) son:" << std::endl;
  std::cout << vecPuntos[indx1] << std::endl;
  std::cout << vecPuntos[indx2] << std::endl;
  return 0;
}
