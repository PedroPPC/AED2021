#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void escribirArchivo_calificaciones(string nombreEstudiante[], string apellidoEstudiante[], int tam, string materia, string nombreDocente, int cedulaDocente, string correo[], double nota1[], double nota2[], double calificacionFinal[]);
void escribirArchivo_ordenamiento(int tam, string nombreDocente, int cedulaDocente, double calificacionFinal[], string tipoOrdenamiento);
void escribirArchivo_busqueda(string nombreEstudiante[], string apellidoEstudiante[], string nombreDocente, int cedulaDocente, string correo[], string tipoBusqueda, double busquedaUsuario, int posicion);
void archivoLectura(string nombreArchivo);


//Funcion para llenar archivo con calificaciones y tambien imprimir en consola
void escribirArchivo_calificaciones(string nombreEstudiante[], string apellidoEstudiante[], int tam, string materia, string nombreDocente, int cedulaDocente, string correo[], double nota1[], double nota2[], double calificacionFinal[]){

    double promedioCurso = 0;
    ofstream archivos;
    string direccionArchivo = "Colegio\\Calificaciones.txt";
    archivos.open(direccionArchivo.c_str(), ios::out);

    for(int i = 0; i < tam; i++){
        promedioCurso += calificacionFinal[i];
    }
    promedioCurso = promedioCurso / tam;

    archivos << setw(76) << "Instituto de Educacion Superior" << endl;
    archivos << setw(73) <<  "Reporte de Calificaciones" << endl << endl;
    archivos << "Año lectivo: 2021 - 2022" << endl;
    archivos << "Materia: " << materia << endl << endl;
    archivos << setw(15) << left << "#" << setw(15) << "Nombre" << setw(15) << "Apellido" << setw(35) << "Correo" << setw(15) << "Nota 1" << setw(15) << "Nota 2" << setw(15) << "Total" << endl;
    for(int i = 0; i < tam; i++){
        archivos << setw(15) << left << i + 1 <<setw(15) << nombreEstudiante[i] << setw(15) << apellidoEstudiante[i] << setw(35) << correo[i] << setw(15) << nota1[i] << setw(15) << nota2[i] << setw(15) << calificacionFinal[i] << endl;
    }
    archivos << endl;
    archivos << "Resumen" << endl;
    archivos << "Promedio del curso: " << setw(41) << right << promedioCurso << "/20" << endl;
    archivos << "\nTotal: " << setw(63) << "Aprobados  (14-20)" << setw(45) << aprobados(calificacionFinal, tam) << endl
    << setw(70) << "Suspenso   (09-13)" << setw(45) << suspendidos(calificacionFinal, tam) << endl
    << setw(70) << "Reprobados (01-08)" << setw(45) << reprobados(calificacionFinal, tam) << "\n\n\n\n\n\n";
    archivos << setw(84) << "___________________________________________" << endl
    << setw(65) << "Docente" << endl
    << setw(65) << nombreDocente << endl
    << setw(65) << cedulaDocente;

    archivos.close();

    archivoLectura(direccionArchivo);
}

//Funcion para llenar archivo con calificaciones ordenadas y tambien imprimir en consola
void escribirArchivo_ordenamiento(int tam, string nombreDocente, int cedulaDocente, double calificacionFinal[], string tipoOrdenamiento){

    ofstream archivos;
    string direccionArchivo = "Colegio\\Ordenamiento.txt";
    archivos.open(direccionArchivo.c_str(), ios::out);

    archivos << setw(76) << "Instituto de Educacion Superior" << endl;
    archivos << setw(73) <<  "Reporte de Calificaciones" << endl << endl;
    archivos << "Calificaciones ordenadas:" << endl << endl;
    archivos << "Algoritmo: " << tipoOrdenamiento << endl;
    archivos << "→ ";
    for(int i = 0; i < tam; i++){
        archivos << "[" << calificacionFinal[i] << "]";
    }
    archivos << "\n\n\n\n\n\n" << setw(84) << "___________________________________________" << endl
    << setw(65) << "Docente" << endl
    << setw(65) << nombreDocente << endl
    << setw(65) << cedulaDocente;

    archivos.close();
    

    archivoLectura(direccionArchivo);
}

//Funcion para llenar archivo con la calificacion buscada por el usuario y tambien imprimir en consola
void escribirArchivo_busqueda(string nombreEstudiante[], string apellidoEstudiante[], string nombreDocente, int cedulaDocente, string correo[], string tipoBusqueda, double busquedaUsuario, int posicion){

    ofstream archivos;
    string direccionArchivo = "Colegio\\Busqueda.txt";
    archivos.open(direccionArchivo.c_str(), ios::out);

    archivos << setw(76) << "Instituto de Educacion Superior" << endl;
    archivos << setw(73) <<  "Reporte de Calificaciones" << endl << endl;
    archivos << "Busqueda de calificaciones." << endl << endl;
    archivos << "Algoritmo: " << tipoBusqueda << endl;
    archivos << "La calificacion a buscar es de: " << busquedaUsuario << endl << endl;
    if(posicion == -1){
        archivos << "La calificacion a buscar no se encuentra ingresada en el reporte de calificaciones." << endl;
    } else {
        archivos << "Correspondiente al estudiante:" << endl;
        archivos << nombreEstudiante[posicion] << " " << apellidoEstudiante[posicion] << endl;
        archivos << correo[posicion] << endl;
    }
    archivos << "\n\n\n\n\n\n" << setw(84) << "___________________________________________" << endl
    << setw(65) << "Docente" << endl
    << setw(65) << nombreDocente << endl
    << setw(65) << cedulaDocente;

    archivos.close();

    archivoLectura(direccionArchivo);
}

//Funcion para leer cualquier archivo que se le envie como parametro
void archivoLectura(string nombreArchivo){

    ifstream archivosLectura;
    string texto;

    archivosLectura.open(nombreArchivo.c_str(), ios::in);

    if(archivosLectura.fail()){
        cout << "El archivo no puedo ser encontrado." << endl;
    } else {
        while(!archivosLectura.eof()){
            getline(archivosLectura, texto);
            cout << texto << endl;
        }
    }
    archivosLectura.close();
}