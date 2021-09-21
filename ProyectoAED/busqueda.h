#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int busquedaLineal(double array[], int tam, double busquedaUsuario);
int busquedaBinaria (double array[], int tam, double busquedaUsuario);
int busquedaInterpolacion(double array[], int tam, double busquedaUsuario);

//Funcion para buscar por metodo lineal
int busquedaLineal(double array[], int tam, double busquedaUsuario){
    for(int i = 0; i < tam; i++){
        if(array[i] == busquedaUsuario){
            return i;
        }
    }
    return -1;
}

//Funcion para buscar por metodo binario
int busquedaBinaria(double array[], int tam, double busquedaUsuario){

    int i = 0;
    int j = tam - 1;
    int k;

    do{
        k = (i + j) / 2;
        if(array[k] <= busquedaUsuario){
            i = k + 1;
        }
        if (array[k] >= busquedaUsuario){
            j = k - 1;
        }
    } while(i <= j);

    if(array[k] == busquedaUsuario){
        return k;
    }
    else {
        return -1;
    }
}

//Funcion para buscar por metodo de interpolacion
int busquedaInterpolacion(double array[], int tam, double busquedaUsuario){

    int primero = 0;
    int ultimo = tam - 1;
    int medio;
    int contador = 0;

    while(array[primero] != busquedaUsuario && contador < tam){

        medio = primero + ((busquedaUsuario - array[primero]) * (ultimo-primero)) / (array[ultimo] - array[primero]);

        if(array[medio] < busquedaUsuario){
            primero = medio + 1;
        } else if(array[medio] > busquedaUsuario){
            ultimo = medio - 1;
        } else {
            primero = medio;
            break;
        }
        contador++;
    }

    if(array[primero] == busquedaUsuario){
        return primero;
    } else {
        return -1;
    }
}
