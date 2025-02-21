#include <iostream>
#include <string>

using namespace std;

// Superclase
class Maquillaje {
protected:
    string marca;
    string tipo;
    string color;

public:
    Maquillaje(string _marca, string _tipo, string _color)
        : marca(_marca), tipo(_tipo), color(_color) {
    }

    virtual void mostrarDatos() {
        cout << "Marca: " << marca << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Color: " << color << endl;
    }

    virtual void aplicar() {
        cout << "Aplicando el producto de maquillaje...\n";
    }
};

// Subclases
class Labial : public Maquillaje {
private:
    bool mate;

public:
    Labial(string _marca, string _color, bool _mate)
        : Maquillaje(_marca, "Labial", _color), mate(_mate) {
    }

    void mostrarDatos() override {
        Maquillaje::mostrarDatos();
        cout << "Acabado mate: " << (mate ? "Sí" : "No") << endl;
    }

    void aplicar() override {
        cout << "Aplicando labial en los labios...\n";
    }
};

class Base : public Maquillaje {
private:
    string tipoPiel;

public:
    Base(string _marca, string _color, string _tipoPiel)
        : Maquillaje(_marca, "Base", _color), tipoPiel(_tipoPiel) {
    }

    void mostrarDatos() override {
        Maquillaje::mostrarDatos();
        cout << "Tipo de piel: " << tipoPiel << endl;
    }

    void aplicar() override {
        cout << "Aplicando base en el rostro...\n";
    }
};

class Sombra : public Maquillaje {
private:
    string textura;

public:
    Sombra(string _marca, string _color, string _textura)
        : Maquillaje(_marca, "Sombra", _color), textura(_textura) {
    }

    void mostrarDatos() override {
        Maquillaje::mostrarDatos();
        cout << "Textura: " << textura << endl;
    }

    void aplicar() override {
        cout << "Aplicando sombra en los ojos...\n";
    }
};

// Función principal con menú
int main() {
    int opcion;
    do {
        cout << "\n--- Menú de Maquillaje ---\n";
        cout << "1. Crear y mostrar Labial\n";
        cout << "2. Crear y mostrar Base\n";
        cout << "3. Crear y mostrar Sombra\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            Labial labial("Maybelline", "Rojo", true);
            labial.mostrarDatos();
            labial.aplicar();
        }
        else if (opcion == 2) {
            Base base("L'Oreal", "Beige", "Mixta");
            base.mostrarDatos();
            base.aplicar();
        }
        else if (opcion == 3) {
            Sombra sombra("Revlon", "Azul", "Polvo");
            sombra.mostrarDatos();
            sombra.aplicar();
        }

    } while (opcion != 4);

    cout << "¡Gracias por usar el sistema de maquillaje!\n";
    return 0;
}

