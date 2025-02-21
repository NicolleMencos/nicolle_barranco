// viernes210220225-Clases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

// Clase Padre
class Zapatos {
protected:
    string marca;
    string color;
    string material;
    int talla;
    float precio;
public:
    Zapatos(string marca, string color, string material, int talla, float precio)
        : marca(marca), color(color), material(material), talla(talla), precio(precio) {
    }

    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Color: " << color << endl;
        cout << "Material: " << material << endl;
        cout << "Talla: " << talla << endl;
        cout << "Precio: Q" << precio << endl;
    }

    virtual ~Zapatos() {}
};

// Clases Hijas
class ZapatosDeportivos : public Zapatos {
private:
    string deporte;
public:
    ZapatosDeportivos(string marca, string color, string material, int talla, float precio, string deporte)
        : Zapatos(marca, color, material, talla, precio), deporte(deporte) {
    }

    void mostrarInfo() override {
        Zapatos::mostrarInfo();
        cout << "Deporte recomendado: " << deporte << endl;
    }
};

class ZapatosFormales : public Zapatos {
private:
    string estilo;
public:
    ZapatosFormales(string marca, string color, string material, int talla, float precio, string estilo)
        : Zapatos(marca, color, material, talla, precio), estilo(estilo) {
    }

    void mostrarInfo() override {
        Zapatos::mostrarInfo();
        cout << "Estilo: " << estilo << endl;
    }
};

class ZapatosCasuales : public Zapatos {
private:
    bool sonComodos;
public:
    ZapatosCasuales(string marca, string color, string material, int talla, float precio, bool sonComodos)
        : Zapatos(marca, color, material, talla, precio), sonComodos(sonComodos) {
    }

    void mostrarInfo() override {
        Zapatos::mostrarInfo();
        cout << "¿Son cómodos?: " << (sonComodos ? "Sí" : "No") << endl;
    }
};

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n--- Menu de Zapatos ---\n";
        cout << "1. Zapatos Deportivos\n";
        cout << "2. Zapatos Formales\n";
        cout << "3. Zapatos Casuales\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        Zapatos* miZapato = nullptr;

        switch (opcion) {
        case 1:
            miZapato = new ZapatosDeportivos("Nike", "Blanco", "Cuero", 42, 120.50, "Running");
            break;
        case 2:
            miZapato = new ZapatosFormales("Clarks", "Negro", "Piel", 43, 80.99, "Oxford");
            break;
        case 3:
            miZapato = new ZapatosCasuales("Vans", "Azul", "Lona", 41, 65.00, true);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }

        if (miZapato) {
            cout << "\n--- Informacion del zapato ---\n";
            miZapato->mostrarInfo();
            delete miZapato;
        }
    } while (opcion != 4);

    return 0;
}
