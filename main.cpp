//Jose Guillermo Oliva Velásquez
//9941-23-6578
#include <iostream>
#include <string>

using namespace std;


struct Producto {
    int codigo;
    string nombre;
    double precio;
};


struct Nodo {
    Producto producto;
    Nodo* siguiente;
};

int main() {
    string nombreEstudiante;


    cout << "Ingrese su nombre completo: ";
    getline(cin, nombreEstudiante);


    Nodo* cabeza = nullptr;
    Nodo* actual = nullptr;
    double total = 0.0;


    for (int i = 0; i < 4; i++) {
        Nodo* nuevo = new Nodo;
        nuevo->siguiente = nullptr;

        cout << "Ingrese codigo del producto: ";
        cin >> nuevo->producto.codigo;
        cin.ignore();

        cout << "Ingrese nombre del producto: ";
        getline(cin, nuevo->producto.nombre);

        cout << "Ingrese precio del producto: Q";
        cin >> nuevo->producto.precio;
        cout << "--------------------" << endl;


        if (cabeza == nullptr) {
            cabeza = nuevo;
            actual = nuevo;
        } else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }
    }
    cout << endl << "Nombre: " << nombreEstudiante << endl << endl;

    cout << endl << "Listado de productos" << endl;
    cout << "--------------------" << endl;

    Nodo* aux = cabeza;
    while (aux != nullptr) {
        cout << "Codigo: " << aux->producto.codigo << endl;
        cout << "Nombre: " << aux->producto.nombre << endl;
        cout << "Precio: Q" << aux->producto.precio << endl;
        cout << "--------------------" << endl;

        total += aux->producto.precio;
        aux = aux->siguiente;
    }

    cout << "Total acumulado: Q" << total << endl;


    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}