#include <iostream>
#include <fstream>
using namespace std;

string nombrearchivo;
void crearArchivo();
void escribirArchivo();
void leerArchivo();
void menu();

int main(){

    bool terminar = false;
    int opcionMenu;

    crearArchivo();
    while(!terminar){
        menu();
        cin >> opcionMenu;
        switch(opcionMenu){
            case 1:
                cin.ignore();
                escribirArchivo();
                break;
                case 2:
                    leerArchivo();
                    break;
                    case 3:
                        cout << "Muchas gracias." << endl;
                        terminar = true;
                        break;
                        default:
                            cout << "Opcion no valida" << endl;
                            break;
        }
    }

    return 0;
}

void crearArchivo(){
    ofstream archivoprueba;
    cout<<"Ingrese el nombre del archivo: ";
    getline(cin,nombrearchivo);
    archivoprueba.open(nombrearchivo.c_str(),ios::out);
    archivoprueba.close();
}

void escribirArchivo(){
    ofstream archivoprueba;
    string nombre;
    string apellido;
    string carrera;
    int edad;
    char r;

    archivoprueba.open(nombrearchivo,ios::app);
    do{
        cout<<"\t Ingrese el nombre:";
        getline(cin,nombre);
        cout<<"\t Ingrese el apellido:";
        getline(cin,apellido);
        cout<<"\t Ingrese la carrera:";
        getline(cin,carrera);
        cout<<"\t Ingrese la edad:";
        cin>>edad;
        archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
        cout<<"Desea ingresar otro contacto s/n ";
        cin>>r;
        cin.ignore();
    }
    while(r == 's');
    archivoprueba.close();
}

void leerArchivo(){
    string nombre;
    string apellido;
    string carrera;
    int edad;
    ifstream archivolectura(nombrearchivo);
    string texto;
    //    archivolectura.open(nombrearchivo,ios::in);
    while(!archivolectura.eof()){
        archivolectura>>nombre>>apellido>>carrera>>edad;
        if(!archivolectura.eof()){
            cout << "------------------------" << endl;
            cout<<"Nombre:"<<nombre<<endl;
            cout<<"Apellido:"<<apellido<<endl;
            cout<<"Carrera:"<<carrera<<endl;
            cout<<"Edad:"<<edad<<endl;
            cout << "------------------------" << endl;
        }
    }
    archivolectura.close();
}

void menu(){
    cout << "\n-------------------------------------------------" << endl;
    cout << "Menu Principal" << endl;
    cout << "1.- Ingresar Datos" << endl;
    cout << "2.- Mostrar Datos" << endl;
    cout << "3.- Salir" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Ingrese una opcion: " << endl;
}