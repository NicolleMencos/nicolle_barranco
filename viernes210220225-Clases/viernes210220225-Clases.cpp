#include <iostream>
using namespace std;

// Superclase
class Flor {
protected:
    string color;
    string tamano;  // Cambié 'tamaño' por 'tamano' sin tilde
    string fragancia;

public:
    Flor(string c, string t, string f) : color(c), tamano(t), fragancia(f) {}
    virtual void mostrarDatos() {
        cout << "Color: " << color << "\nTamano: " << tamano << "\nFragancia: " << fragancia << endl;
    }
    virtual void marchitar() {
        cout << "La flor se ha marchitado." << endl;
    }
};

// Subclase Rosa
class Rosa : public Flor {
public:
    Rosa(string c, string t, string f) : Flor(c, t, f) {}
    void mostrarDatos() override {
        cout << "--- Rosa ---\n";
        Flor::mostrarDatos();
    }
    void marchitar() override {
        cout << "La rosa ha perdido sus petalos." << endl; // También cambié 'pétalos' por 'petalos'
    }
};

// Subclase Girasol
class Girasol : public Flor {
public:
    Girasol(string c, string t, string f) : Flor(c, t, f) {}
    void mostrarDatos() override {
        cout << "--- Girasol ---\n";
        Flor::mostrarDatos();
    }
    void marchitar() override {
        cout << "El girasol ha inclinado su cabeza." << endl;
    }
};

// Subclase Tulipan
class Tulipan : public Flor {
public:
    Tulipan(string c, string t, string f) : Flor(c, t, f) {}
    void mostrarDatos() override {
        cout << "--- Tulipan ---\n";
        Flor::mostrarDatos();
    }
    void marchitar() override {
        cout << "El tulipan se ha secado." << endl;
    }
};

int main() {
    Rosa rosa("Rojo", "Mediano", "Dulce");
    Girasol girasol("Amarillo", "Grande", "Suave");
    Tulipan tulipan("Rosa", "Pequeno", "Ligera");  // Cambié 'Pequeño' por 'Pequeno' sin tilde

    int opcion;
    do {
        cout << "\nMenu de Flores:" << endl;  // Cambié 'Menú' por 'Menu' sin tilde
        cout << "1. Mostrar datos de la Rosa" << endl;
        cout << "2. Mostrar datos del Girasol" << endl;
        cout << "3. Mostrar datos del Tulipan" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";  // Cambié 'opción' por 'opcion' sin tilde
        cin >> opcion;

        switch (opcion) {
        case 1:
            rosa.mostrarDatos();
            break;
        case 2:
            girasol.mostrarDatos();
            break;
        case 3:
            tulipan.mostrarDatos();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;  // Cambié 'Opción' por 'Opcion' sin tilde
        }
    } while (opcion != 4);

    return 0;
}

