#include <iostream>
#include <fstream>
using namespace std;

void insercion(int array[], int n);
int Interpolacion(int array[], int n, int numBusqueda);
void escribirArchivoInsercion(int array[], int n, string archivo, string condicion);
void escribirArchivoInterpolacion(int numBusqueda, string archivo, int posicion);

int main(){

    int n;
    cout << "Ingrese el tamano del array" << endl;
    cin >> n;
    int array[n];
    int numBusqueda;
    string insercionTXT = "Resultados\\Insercion.txt";
    string interpolacionTXT = "Resultados\\Interpolacion.txt";
    string condicion;

    for(int i = 0; i < n; i++){
        cout << "Ingrese el elemento del array en la posicion " << i << ": " << endl;
        cin >> array[i];
    }


    condicion = "Elementos sin ordenar:";
    escribirArchivoInsercion(array, n, insercionTXT, condicion);
    insercion(array, n);
    condicion = "Elementos ordenados por Insercion:";
    escribirArchivoInsercion(array, n, insercionTXT, condicion);

    cout << "\nIngrese el elemento a buscar: " << endl;
    cin >> numBusqueda;

    escribirArchivoInterpolacion(numBusqueda, interpolacionTXT, Interpolacion(array, n, numBusqueda));

    return 0;
}

void insercion(int array[], int n){

    int aux;

    for (int i = 0; i < n; i++){
        aux = array[i];
        int p = i;
        while(p > 0){
            if (array[p - 1] > aux){
                array[p] = array[p - 1];
                array[p - 1] = aux;
            }
            p--;
        }
    }

    for (int i = 0; i < n; i++){
        cout << "[" << array[i] << "]";
    }
}

int Interpolacion(int array[], int n, int numBusqueda){

    int primero = 0;
    int ultimo = n - 1;
    int medio;
    int contador = 0;

    while(array[primero] != numBusqueda && contador < n){

        medio = primero + ((numBusqueda-array[primero])*(ultimo-primero))/(array[ultimo]-array[primero]);

        if(array[medio] < numBusqueda){
            primero = medio + 1;
        } else if(array[medio] > numBusqueda){
            ultimo = medio - 1;
        } else {
            primero = medio;
            break;
        }
        contador++;

    }

    if(array[primero] == numBusqueda){
        return primero;
    } else {
        return -1;
    }
}

void escribirArchivoInsercion(int array[], int n, string archivo, string condicion){

    ofstream archivos;
    archivos.open(archivo.c_str(), ios::out | ios::app);

    archivos << condicion << endl;
    for(int i = 0; i < n; i++){
        archivos << "[" << array[i] << "]";
    }
    archivos << endl;

    archivos.close();

}

void escribirArchivoInterpolacion(int numBusqueda, string archivo, int posicion){

    ofstream archivos;
    archivos.open(archivo.c_str(), ios::out | ios::app);

    archivos << "Elemento a encontrar: " << numBusqueda << endl;

    if(posicion == -1){
        archivos << "Elemento no encontrado." << endl;
    } else {
        archivos << "Elemento encontrado en la posicion " << posicion << "." << endl;
    }

    archivos.close();
}

