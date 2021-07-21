#include <iostream>
using namespace std;
#define tam 50
void ingresar(int a[],int n);
void ordenar(int a[],int n);
void imprimir(int a[],int n);

int main()
{
    int arreglo1[tam];
    int n;
    cout<<"INGRESE EL TAÑAMO DEL ARREGLO";
    cin>>n;
    ingresar(arreglo1,n);
    ordenar(arreglo1,n);
    imprimir (arreglo1,n);
    return 0;
}


void ingresar(int a[],int n)
{

	for(int i=0;i<n;i++)
	{
		cout<<"Ingresa numero "<<i+1<<": ";
		cin>>a[i];
	}

}

void imprimir(int a[],int n)
{
    for (int i=0; i<n;i++)
    {
        cout<<a[i];
    }
}


void ordenar(int a[],int n)
{
    int i,j,aux;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
            aux=a[j];
            a[j]=a[j+1];
            a[j+1]=aux;
            }
        }

    }
}
