// viernes210220225-Clases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// Clase Padre
class Pastel {
protected:
    string sabor;
    float precio;
public:
    Pastel(string sabor, float precio) : sabor(sabor), precio(precio) {}

    virtual void mostrarInfo() {
        cout << "Sabor: " << sabor << endl;
        cout << "Precio: $" << precio << endl;
    }

    virtual ~Pastel() {} // Destructor virtual para herencia
};

// Clases hijas
class PastelChocolate : public Pastel {
private:
    int porcentajeCacao;
public:
    PastelChocolate(float precio, int porcentajeCacao)
        : Pastel("Chocolate", precio), porcentajeCacao(porcentajeCacao) {
    }

    void mostrarInfo() override {
        Pastel::mostrarInfo();
        cout << "Porcentaje de cacao: " << porcentajeCacao << "%" << endl;
    }
};

class PastelVainilla : public Pastel {
private:
    bool conCrema;
public:
    PastelVainilla(float precio, bool conCrema)
        : Pastel("Vainilla", precio), conCrema(conCrema) {
    }

    void mostrarInfo() override {
        Pastel::mostrarInfo();
        cout << "Con crema: " << (conCrema ? "Si" : "No") << endl;
    }
};

class PastelFresa : public Pastel {
private:
    int cantidadFresas;
public:
    PastelFresa(float precio, int cantidadFresas)
        : Pastel("Fresa", precio), cantidadFresas(cantidadFresas) {
    }

    void mostrarInfo() override {
        Pastel::mostrarInfo();
        cout << "Cantidad de fresas: " << cantidadFresas << endl;
    }
};

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n--- Menu de Pasteles ---\n";
        cout << "1. Pastel de Chocolate\n";
        cout << "2. Pastel de Vainilla\n";
        cout << "3. Pastel de Fresa\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        Pastel* miPastel = nullptr;

        switch (opcion) {
        case 1:
            miPastel = new PastelChocolate(12.50, 70);
            break;
        case 2:
            miPastel = new PastelVainilla(10.99, true);
            break;
        case 3:
            miPastel = new PastelFresa(14.30, 5);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }

        if (miPastel) {
            cout << "\n--- Informacion del pastel ---\n";
            miPastel->mostrarInfo();
            delete miPastel; // Liberar memoria
        }
    } while (opcion != 4);

    return 0;
}
