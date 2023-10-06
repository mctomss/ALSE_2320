#include <fstream>
#include "punto.h"
#include <iostream>
#include <vector>


int main(int argc, char** argv){
  if( argc < 4){
    std::cout << "Debe pasar el path del archivo de los datos de entrada ";
    std::cout << "junto con las coordenadas de consulta.\n" << std::endl;
    return 1;
  }

  std::cout << "Se abrirá el archivo: " << argv[1] << std::endl;
  //char buff[255];
  // Crear el punto de test llamando el construtor por parámetros
  Punto test( strtod( argv[2], NULL ), strtod( argv[3], NULL ) );
  // voy a crear un vector de puntos  
  std::vector<Punto> vecPuntos;
  Punto tmp;   // tmp se contruye con el constructor por omisión
  int i = 0;
  //FILE * archivo = fopen( argv[1], "r" );
  std::ifstream archivo( argv[1] );
  double x, y;
  if( archivo.is_open() ){
    while ( archivo >> x >> y ){
      tmp.X( x );
      tmp.Y( y );
      vecPuntos.push_back( tmp );
    }
    archivo.close();
  }

  double dist,dist1, dist2;
  dist1 = dist2 = 1000000000.;
  int indx1, indx2;
  indx1 = indx2 = 0;
  Punto centroide(0.0,0.0);
  double radio;
  for( i = 0; i < vecPuntos.size(); i++){
    //std::cout << "( " << vecPuntos[i].X() << ", " << vecPuntos[i].Y() << " )" << std::endl;
    std::cout << vecPuntos[i] ;
    dist = test.distancia ( vecPuntos[i] ); 
    std::cout << ", distancia= " << dist << std::endl;
    if( dist < dist1 ){
      dist2 = dist1;
      indx2 = indx1;
      dist1 = dist;
      indx1 = i;
    }else if( dist < dist2 ){
      dist2 = dist;
      indx2 = i;
    }
    centroide += vecPuntos[i];
  }
  centroide /= vecPuntos.size();
  radio = test.distancia(centroide);
  std::cout << "Los dos puntos más cercanos a " << test << " son:" << std::endl;
  std::cout << vecPuntos[indx1] << std::endl;
  std::cout << vecPuntos[indx2] << std::endl;
  std::cout << "El centroide se encuentra en"<<centroide<< std::endl; 
  std::cout << "La distancia entre el centroide y el punto es: "<<radio<< std:: endl;
  std::cout << "Los puntos dentro de la circunferencia son: "<< std:: endl;
  for( i = 0; i < vecPuntos.size(); i++){
    if (radio >= centroide.distancia ( vecPuntos[i] )){
      std::cout << vecPuntos[i] << std::endl;
    }
        
  }
  return 0;
}