#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;



#define TAM 50
//Prototipos
void menu();
void verificarInput();
void ingresarDatos(double nota1[], double nota2[], double calificacionFinal[], string nombres[], string apellidos[], string correo[], int tam);

int aprobados(double array[], int tam);
int reprobados(double array[], int tam);
int suspendidos(double array[], int tam);



//Funcion Menu Principal
void menu(){
    cout << "\n\n" << setw(90) << "----------- SISTEMA DE CALIFICACIONES -----------" << endl;
    cout << setw(93) << "            - INSTITUTO DE EDUCACION SUPERIOR -          " << endl;
    cout << setw(90) << "-------------------------------------------------" << endl;
    cout << setw(70) << "Menu Principal" << endl;
    cout << setw(75) << "1.- Ingresar Calificaciones" << endl;
    cout << setw(74) << "2.- Ordenar Calificaciones" << endl;
    cout << setw(73) << "3.- Buscar Calificaciones" << endl;
    cout << setw(57) << "4.- Salir" << endl;
    cout << setw(68) << "Ingrese una opcion: " << endl;
}

//Funcion verifica que lo que el usuario ingrese sea valido y no cause un bucle infinito
void verificarInput(){
    if(cin.fail()){
        cout << "Input no valido." << endl;
        cin.clear();
        cin.ignore();
    }
    cin.ignore(INT_MAX, '\n');
    cin.good();
}

//Funcion llena el array con las calificaciones y nombre del estudiante
void ingresarDatos(double nota1[], double nota2[], double calificacionFinal[], string nombres[], string apellidos[], string correo[], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Ingrese el primer nombre del estudiante numero " << i + 1 << ": " << endl;
        cin.ignore();
        getline(cin, nombres[i]);
        cout << "Ingrese el primer apellido del estudiante numero " << i + 1 << ": " << endl;
        getline(cin, apellidos[i]);
        cout << "Ingrese la dirrecion de correo del estudiante " << nombres[i] << " " << apellidos[i] << ": " << endl;
        getline(cin, correo[i]);
        cout << "Ingrese la nota del primer bimestre del estudiante " << nombres[i] << " " << apellidos[i] << ": " << endl;
        cin >> nota1[i];
        cout << "Ingrese la nota del segundo bimestre del estudiante " << nombres[i] << " " << apellidos[i] << ": " << endl;
        cin >> nota2[i];
    }
    for(int i = 0; i < tam; i++){
        calificacionFinal[i] = nota1[i] + nota2[i];
    }
}




//Funcion cuenta cuantos alumanos fueron aprobados
int aprobados(double array[], int tam){
    int apr = 0;
    for(int i = 0; i < tam; i++){
        if(array[i] >= 14 && array[i] <= 20){
            apr++;
        }
    }
    return apr;
}

//Funcion cuenta cuantos alumanos fueron reprobados
int reprobados(double array[], int tam){
    int rep = 0;
    for(int i = 0; i < tam; i++){
        if(array[i] >= 0 && array[i] < 9){
            rep++;
        }
    }
    return rep;
}

//Funcion cuenta cuantos alumanos fueron suspendidos
int suspendidos(double array[], int tam){
    int sus = 0;
    for(int i = 0; i < tam; i++){
        if(array[i] >= 9 && array[i] < 14){
            sus++;
        }
    }
    return sus;
}

