// viernes210220225-Clases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
using namespace std;

// Superclase
class Animal {
protected:
    string nombre;
    int edad;
    string habitat;

public:
    // Constructor
    Animal(string nombre, int edad, string habitat)
        : nombre(nombre), edad(edad), habitat(habitat) {
    }

    // Métodos
    void comer() {
        cout << nombre << " esta comiendo." << endl;
    }

    void dormir() {
        cout << nombre << " esta durmiendo." << endl;
    }
};

// Subclase 1: Mamifero
class Mamifero : public Animal {
private:
    string tipoPelaje;

public:
    // Constructor
    Mamifero(string nombre, int edad, string habitat, string tipoPelaje)
        : Animal(nombre, edad, habitat), tipoPelaje(tipoPelaje) {
    }

    // Métodos específicos
    void amamantar() {
        cout << nombre << " esta amamantando a sus crías." << endl;
    }

    void correr() {
        cout << nombre << " esta corriendo." << endl;
    }
};

// Subclase 2: Ave
class Ave : public Animal {
private:
    string tipoPlumaje;
    bool puedeVolar;

public:
    // Constructor
    Ave(string nombre, int edad, string habitat, string tipoPlumaje, bool puedeVolar)
        : Animal(nombre, edad, habitat), tipoPlumaje(tipoPlumaje), puedeVolar(puedeVolar) {
    }

    // Métodos específicos
    void volar() {
        if (puedeVolar) {
            cout << nombre << " esta volando." << endl;
        }
        else {
            cout << nombre << " no puede volar." << endl;
        }
    }

    void ponerHuevos() {
        cout << nombre << " esta poniendo huevos." << endl;
    }
};

// Subclase 3: Reptil
class Reptil : public Animal {
private:
    string tipoEscamas;
    bool esVenemoso;

public:
    // Constructor
    Reptil(string nombre, int edad, string habitat, string tipoEscamas, bool esVenemoso)
        : Animal(nombre, edad, habitat), tipoEscamas(tipoEscamas), esVenemoso(esVenemoso) {
    }

    // Métodos específicos
    void arrastrarse() {
        cout << nombre << " esta arrastrandose." << endl;
    }

    void mudarPiel() {
        cout << nombre << " esta mudando la piel." << endl;
    }
};

// Menú principal
int main() {
    Mamifero* mamifero = nullptr;
    Ave* ave = nullptr;
    Reptil* reptil = nullptr;
    int opcion;

    while (true) {
        cout << "\n--- Menu ---\n1. Crear Mamifero\n2. Crear Ave\n3. Crear Reptil\n4. Acciones\n5. Salir\nSeleccione: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            string nombre, habitat, tipoPelaje;
            int edad;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cin.ignore();
            cout << "Hábitat: "; getline(cin, habitat);
            cout << "Tipo de pelaje: "; getline(cin, tipoPelaje);
            mamifero = new Mamifero(nombre, edad, habitat, tipoPelaje);
        }
        else if (opcion == 2) {
            string nombre, habitat, tipoPlumaje;
            int edad;
            bool puedeVolar;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cin.ignore();
            cout << "Habitat: "; getline(cin, habitat);
            cout << "Tipo de plumaje: "; getline(cin, tipoPlumaje);
            cout << "¿Puede volar? (1 para Sí, 0 para No): "; cin >> puedeVolar;
            cin.ignore();
            ave = new Ave(nombre, edad, habitat, tipoPlumaje, puedeVolar);
        }
        else if (opcion == 3) {
            string nombre, habitat, tipoEscamas;
            int edad;
            bool esVenemoso;
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad;
            cin.ignore();
            cout << "Habitat: "; getline(cin, habitat);
            cout << "Tipo de escamas: "; getline(cin, tipoEscamas);
            cout << "¿Es venenoso? (1 para Sí, 0 para No): "; cin >> esVenemoso;
            cin.ignore();
            reptil = new Reptil(nombre, edad, habitat, tipoEscamas, esVenemoso);
        }
        else if (opcion == 4) {
            if (mamifero) { mamifero->comer(); mamifero->amamantar(); }
            if (ave) { ave->comer(); ave->volar(); }
            if (reptil) { reptil->comer(); reptil->arrastrarse(); }
        }
        else if (opcion == 5) {
            break;
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }

    delete mamifero; delete ave; delete reptil;
    return 0;
}