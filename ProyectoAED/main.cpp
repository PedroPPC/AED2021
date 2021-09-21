#include <iomanip>
#include <limits.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "ordenamiento.h"
#include "busqueda.h"
#include "BDD.h"
using namespace std;


int main(){
system("clear");

    string usuario, password, materia, nombreDocente, nombreEstudiante[TAM], apellidoEstudiante[TAM], correo[TAM], tipoOrdenamiento, tipoBusqueda;
    int opcion, opcionOrdenamiento, opcionBusqueda, size, cedulaDocente;
    bool terminar = false;
    double nota1[TAM], nota2[TAM], calificaciones[TAM], busquedaUsuario;
    bool ingreseCalificaciones = false, ingreseOrdenamiento = false;

    cout << "Ingrese su usuario: " << endl;
    cin >> usuario;
    cout << "Ingrese la contrasena: " << endl;
    cin >> password;

    if(usuario == "docente" && password == "aed2021"){
        cout << "\n\nBienvenido." << endl;
        while(!terminar){
            menu();
            cin >> opcion;
            verificarInput();
            if(opcion == 1){
                ingreseCalificaciones = true;
            }
            while(!ingreseCalificaciones && opcion != 4){
                cout << "Por favor ingrese sus calificaciones antes de acceder a los otros modulos." << endl;
                cin >> opcion;
                verificarInput();
                if(opcion == 1){
                    ingreseCalificaciones = true;
                } else if(opcion == 4){
                    break;
                }
            }
            if(opcion == 2 && ingreseCalificaciones){
                ingreseOrdenamiento = true;
            }
            while((!ingreseOrdenamiento && opcion != 1) && (opcion != 4)){
                cout << "Por favor ingrese ingrese al modulo de ordenamiento de calificaciones antes de ingresar al modulo de busqueda." << endl;
                cin >> opcion;
                verificarInput();
                if(opcion == 2){
                    ingreseOrdenamiento = true;
                } else if(opcion == 4){
                    break;
                }
            }

            switch(opcion){
                case 1:
                    cout << "Ingrese su nombre:" << endl;
                    getline(cin, nombreDocente);
                    cout << "Ingrese su numero de cedula:" << endl;
                    cin >> cedulaDocente;
                    while(cin.fail()){
                        verificarInput();
                        cout << "Ingrese su numero de cedula:" << endl;
                        cin >> cedulaDocente;
                    }
                    cout << "Ingrese el nombre de la materia:" << endl;
                    cin.ignore();
                    getline(cin, materia);
                    cout << "Ingrese el numero de estudiantes de los cuales va a ingresar calificaciones: " << endl;
                    cin >> size;
                    ingresarDatos(nota1, nota2, calificaciones, nombreEstudiante, apellidoEstudiante, correo, size);
                    escribirArchivo_calificaciones(nombreEstudiante, apellidoEstudiante, size, materia, nombreDocente, cedulaDocente, correo, nota1, nota2, calificaciones);
                    break;
                case 2:
                    cout << "Seleccione el metodo de ordenamiento que desea utilizar:" << endl
                    << "1.- Burbuja" << endl
                    << "2.- Seleccion" << endl
                    << "3.- Insercion" << endl
                    << "4.- Mergesort" << endl
                    << "5.- Quicksort" << endl
                    << "6.- Volver al menu principal" << endl;
                    cin >> opcionOrdenamiento;
                    verificarInput();
                    switch(opcionOrdenamiento){
                        case 1:
                            tipoOrdenamiento = "Burbuja";
                            ordenarBurbuja(calificaciones, nombreEstudiante, apellidoEstudiante, correo, size);
                            escribirArchivo_ordenamiento(size, nombreDocente, cedulaDocente, calificaciones, tipoOrdenamiento);
                            break;
                        case 2:
                            tipoOrdenamiento = "Seleccion";
                            ordenarSeleccion(calificaciones, nombreEstudiante, apellidoEstudiante, correo, size);
                            escribirArchivo_ordenamiento(size, nombreDocente, cedulaDocente, calificaciones,tipoOrdenamiento);
                            break;
                        case 3:
                            tipoOrdenamiento = "Insercion";
                            ordenarInsercion(calificaciones, nombreEstudiante, apellidoEstudiante, correo, size);
                            escribirArchivo_ordenamiento(size, nombreDocente, cedulaDocente, calificaciones,tipoOrdenamiento);
                            break;
                        case 4:
                            tipoOrdenamiento = "MergeSort";
                            ordenarMergesort_dividir(calificaciones, nombreEstudiante, apellidoEstudiante, correo, 0, size - 1);
                            escribirArchivo_ordenamiento(size, nombreDocente, cedulaDocente, calificaciones,tipoOrdenamiento);
                            break;
                        case 5:
                            tipoOrdenamiento = "QuickSort";
                            ordenarQuicksort_orden(calificaciones, nombreEstudiante, apellidoEstudiante, correo, 0, size - 1);
                            escribirArchivo_ordenamiento(size, nombreDocente, cedulaDocente, calificaciones,tipoOrdenamiento);
                        case 6:
                            break;
                        default:
                            cout << "Opcion incorrecta." << endl;
                            break;
                    }
                    break;
                case 3:
                    cout << "Seleccione el metodo de busqueda que desea utilizar:" << endl
                    << "1.- Lineal" << endl
                    << "2.- Binaria" << endl
                    << "3.- Interpolacion" << endl
                    << "4.- Volver al menu principal" << endl;
                    cin >> opcionBusqueda;
                    verificarInput();
                    if(opcionBusqueda != 4){
                        cout << "Ingrese la calificacion final que desea buscar:" << endl;
                        cin >> busquedaUsuario;
                        while(cin.fail()){
                            verificarInput();
                            cout << "Ingrese la calificacion final que desea buscar:" << endl;
                            cin >> busquedaUsuario;
                        }
                        while(busquedaUsuario < 0){
                            cout << "La calificacion no puede ser negativa." << endl;
                            cout << "Ingrese la calificacion final que desea buscar:" << endl;
                            cin >> busquedaUsuario;
                        }
                    }
                    switch(opcionBusqueda){
                        case 1:
                            tipoBusqueda = "Lineal";
                            escribirArchivo_busqueda(nombreEstudiante, apellidoEstudiante, nombreDocente, cedulaDocente, correo, tipoBusqueda, busquedaUsuario, busquedaLineal(calificaciones, size, busquedaUsuario));
                            break;
                        case 2:
                            tipoBusqueda = "Binaria";
                            escribirArchivo_busqueda(nombreEstudiante, apellidoEstudiante,nombreDocente, cedulaDocente, correo, tipoBusqueda, busquedaUsuario, busquedaBinaria(calificaciones, size, busquedaUsuario));
                            break;
                        case 3:
                            tipoBusqueda = "Interpolacion";
                            escribirArchivo_busqueda(nombreEstudiante, apellidoEstudiante, nombreDocente, cedulaDocente, correo, tipoBusqueda, busquedaUsuario, busquedaInterpolacion(calificaciones, size, busquedaUsuario));
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Opcion incorrecta." << endl;
                            break;
                    }
                    break;
                case 4:
                    cout << "Hasta luego." << endl;
                    terminar = true;
                    break;
                    default:
                        cout << "Opcion Incorrecta" << endl;
                        break;
            }
        }
    } else {
        cout << "Login incorrecto." << endl;
    }

    return 0;
}

