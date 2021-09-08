int ordenarQuicksort_mitad(int array[],int pinicial, int pfinal){
    return array[(pinicial+pfinal)/2];
}

void ordenarQuicksort_orden(int array[],int pinicial, int pfinal){
    int i = pinicial;
    int j = pfinal;
    int temp;
    int piv = ordenarQuicksort_mitad(array, pinicial, pfinal);

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
            i++;
            j--;
        }
    } while(i <= j);

    if(pinicial < j){
        ordenarQuicksort_orden(array, pinicial, j);
    }
    if(i < pfinal){
        ordenarQuicksort_orden(array, i, pfinal);
    }
}

