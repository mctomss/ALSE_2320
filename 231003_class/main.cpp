
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <complex>
#include <string>
#include <iostream>

using namespace std;
/*libreria para escribir entradas y salidad cin y cout*/


bool ordenar ( complex <double> complejo[] , int& tam){
  bool flag;
  do{
    flag = false;
    for(int i=0;i < tam-1;i++){
      if (abs(complejo[i]) > arg(complejo[i])){
        complex<double> aux = complejo[i];
        complejo[i]=complejo[i+1];
        complejo[i+1]=aux;
        flag = true;
      }
      else if(arg(complejo[i])==arg(complejo[i+1]))
      {
        if (abs(complejo[i])>abs(complejo[i+1])){
        complex<double> aux = complejo[i];
        complejo[i]=complejo[i+1];
        complejo[i+1]=aux;
        flag = true;
      }
      }
    }
  }while (flag == true);
  return true;
}

int main(int argc, char** argv){
   

    if( argc < 2){
    printf("Debe pasar el path del archivo de los datos de entrada.\n");
    return 1;
  }else{
    printf("Se abrirá el archivo %s\n", argv[1]);
    char buff[255];
    FILE * archivo = fopen( argv[1], "r" );
    int i=0;
    while ( fgets(buff, 255, (FILE*) archivo )){
        i++;
    }
    complex<double> complejo[i];

    i=0;
    int num=0;
    fclose(archivo);
    archivo = fopen( argv[1], "r" );
    while ( fgets(buff, 255, (FILE*) archivo )){
        if (i%2==0){
            complejo[num].real(strtod(buff,NULL));
        }else {
            complejo[num].imag(strtod(buff,NULL));
            num++;
        }
        i++;
    }
    double reprom=0;
    double improm=0;
    for (int j=0;j<num;j++){
        cout<<"El complejo "<<j+1<<" es: "<<complejo[num];
        cout<<" | Su Norma es: "<<abs (complejo[j]);
        cout<<" | Su ángulo es (en rad): "<<arg (complejo[j])<<endl;
        reprom+=complejo[j].real();
        improm+=complejo[j].imag();
    }
    cout<<"El promedio de los números complejos es: "<<reprom/num<<improm/num<<"j"<<endl;

    bool flag = ordenar(complejo,num);
    if (flag == true){
      cout << "Los numeros complejos en orden son:"<<endl;
      for (int j=0;j<num;j++){
        cout<<complejo[j]<<endl;   
      }
    }else{
      cout<<"error"<<endl;
    }
  }
  return 0;
}

