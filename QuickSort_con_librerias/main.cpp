#include <iostream>
#include "Ordenamiento.h"
using namespace std;

int main() {

int array[10] = {5, 9, 26, -8, 0, 7, 33, -99, 42, 71};

cout << "Array original:" << endl;
for(int i = 0; i < 10; i++){
  cout << "[" << array[i] << "]";
}

ordenarQuicksort_orden(array, 0, 9);

cout << "\nArray ordenado por QuickSort, usando librerias:" << endl;
for(int i = 0; i < 10; i++){
  cout << "[" << array[i] << "]";
}

return 0;

}