#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;


void ordenarBurbuja(double array[], string nombres[], string apellidos[], string correo[], int tam);
void ordenarSeleccion(double array[], string nombres[], string apellidos[], string correo[], int tam);
void ordenarInsercion(double array[], string nombres[], string apellidos[], string correo[], int tam);
void ordenarMergesort_dividir(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int pfinal);
void ordenarMergesort_fusionar(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int medio, int pfinal);
void ordenarQuicksort_orden(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int pfinal);
double ordenarQuicksort_mitad(double array[], int pinicial, int pfinal);

//Funcion ordena las calificaciones por metodo de burbuja
void ordenarBurbuja(double array[], string nombres[], string apellidos[], string correo[], int tam){

    int i, j;
    double aux;
    string auxNombres, auxApellidos, auxCorreo;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            if(array[j] > array[j + 1]){
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;

                auxNombres = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = auxNombres;

                auxApellidos = apellidos[j];
                apellidos[j] = apellidos[j + 1];
                apellidos[j + 1] = auxApellidos;

                auxCorreo = correo[j];
                correo[j] = correo[j + 1];
                correo[j + 1] = auxCorreo;
            }
        }
    }
}

//Funcion ordena las calificaciones por metodo de seleccion
void ordenarSeleccion(double array[], string nombres[], string apellidos[], string correo[], int tam){

    int i, j, min;
    double aux;
    string auxNombres, auxApellidos, auxCorreo;

    for(i = 0; i < tam; i++){
        min = i;
        for(j = i + 1; j < tam; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;

        auxNombres = nombres[i];
        nombres[i] = nombres[min];
        nombres[min] = auxNombres;

        auxApellidos = apellidos[i];
        apellidos[i] = apellidos[min];
        apellidos[min] = auxApellidos;

        auxCorreo = correo[i];
        correo[i] = correo[min];
        correo[min] = auxCorreo;
    }
}

//Funcion ordena las calificaciones por metodo de insercion
void ordenarInsercion(double array[], string nombres[], string apellidos[], string correo[], int tam){

    double aux;
    string auxNombres, auxApellidos, auxCorreo;

    for (int i = 0; i < tam; i++){
        aux = array[i];
        auxNombres = nombres[i];
        auxApellidos = apellidos[i];
        auxCorreo = correo[i];
        int p = i;
        while(p > 0){
            if (array[p - 1] > aux){
                array[p] = array[p - 1];
                array[p - 1] = aux;

                nombres[p] = nombres[p - 1];
                nombres[p - 1] = auxNombres;

                apellidos[p] = apellidos[p - 1];
                apellidos[p - 1] = auxApellidos;

                correo[p] = correo[p - 1];
                correo[p - 1] = auxCorreo;
            }
            p--;
        }
    }
}

//Funcion ordena las calificaciones por metodo de mergesort, parte 1
void ordenarMergesort_dividir(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int pfinal){

    if(pinicial >= pfinal){
        return;
    }
    int medio = pinicial + (pfinal - pinicial) / 2;
    ordenarMergesort_dividir(array, nombres, apellidos, correo, pinicial, medio);
    ordenarMergesort_dividir(array, nombres, apellidos, correo, medio + 1, pfinal);
    ordenarMergesort_fusionar(array, nombres, apellidos, correo, pinicial, medio, pfinal);
}

//Funcion ordena las calificaciones por metodo de mergesort, parte 2
void ordenarMergesort_fusionar(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int medio, int pfinal){

    int n1 = medio - pinicial + 1;
    int n2 = pfinal - medio;
    double L[n1], R[n2];
    string LNombres[n1], LApellidos[n1], RNombres[n2], RApellidos[n2], LCorreo[n1], RCorreo[n2];

    for (int i = 0; i < n1; i++){
        L[i] = array[pinicial + i];
        LNombres[i] = nombres[pinicial + i];
        LApellidos[i] = apellidos[pinicial + i];
        LCorreo[i] = correo[pinicial + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = array[medio + 1 + j];
        RNombres[j] = nombres[medio + 1 + j];
        RApellidos[j] = apellidos[medio + 1 + j];
        RCorreo[j] = correo[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = pinicial;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            nombres[k] = LNombres[i];
            apellidos[k] = LApellidos[i];
            correo[k] = LCorreo[i];
            i++;
        } else {
            array[k] = R[j];
            nombres[k] = RNombres[j];
            apellidos[k] = RApellidos[j];
            correo[k] = RCorreo[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        nombres[k] = LNombres[i];
        apellidos[k] = LApellidos[i];
        correo[k] = LCorreo[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        nombres[k] = RNombres[j];
        apellidos[k] = RApellidos[j];
        correo[k] = RCorreo[j];
        j++;
        k++;
    }
}

//Funcion ordena las calificaciones por metodo de quicksort, parte 1
void ordenarQuicksort_orden(double array[], string nombres[], string apellidos[], string correo[], int pinicial, int pfinal){
    int i = pinicial;
    int j = pfinal;
    double temp;
    string tempNombres, tempApellidos, tempCorreo;
    double piv = ordenarQuicksort_mitad(array, pinicial, pfinal);

    do{
        while(array[i] < piv){
            i++;
        }
        while(array[j] > piv){
            j--;
        }
        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            tempNombres = nombres[i];
            nombres[i] = nombres[j];
            nombres[j] = tempNombres;

            tempApellidos = apellidos[i];
            apellidos[i] = apellidos[j];
            apellidos[j] = tempApellidos;

            tempCorreo = correo[i];
            correo[i] = correo[j];
            correo[j] = tempCorreo;

            i++;
            j--;
        }
    } while(i <= j);

    if(pinicial < j){
        ordenarQuicksort_orden(array, nombres, apellidos, correo, pinicial, j);
    }
    if(i < pfinal){
        ordenarQuicksort_orden(array, nombres, apellidos, correo, i, pfinal);
    }
}

//Funcion ordena las calificaciones por metodo de quicksort, parte 2
double ordenarQuicksort_mitad(double array[], int pinicial, int pfinal){
    return array[(pinicial+pfinal)/2];
}
