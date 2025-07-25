#include <iostream>
using namespace std;

struct Estudiante {
    int Codigo;
    string Apellido;
    string Nombre;
};

struct Lapicero {
    string color;
    string tipoTinta;
    string marca;
};

struct Carpeta {
    int numHojas;
    string color;
    string tamano;
};

struct Silla {
    string material;
    string color;
    bool tieneRespaldo;
};

struct Mochila {
    string marca;
    int capacidadLitros;
    string color;
};

struct CableUTP {
    float longitud;
    string categoria;
    string color;
};

struct Laptop {
    string marca;
    int ramGB;
    float tamanoPantalla;
};

struct Servidor {
    string sistemaOperativo;
    int nucleosCPU;
    int almacenamientoGB;
};

struct VariableEstadistica {
    string nombre;
    string tipo; // cualitativa o cuantitativa
    string nivelDeMedicion;
};

int main() {
    Estudiante estudiante;
    Lapicero lapicero;
    Carpeta carpeta;
    Silla silla;
    Mochila mochila;
    CableUTP cable;
    Laptop laptop;
    Servidor servidor;
    VariableEstadistica variable;

    // Ingreso de datos
    cout << "Ingrese los datos del estudiante:\n";
    cout << "Codigo: ";
    cin >> estudiante.Codigo;
    cout << "Apellido: ";
    cin >> estudiante.Apellido;
    cout << "Nombre: ";
    cin >> estudiante.Nombre;

    cout << "\nIngrese los datos del lapicero:\n";
    cout << "Color: ";
    cin >> lapicero.color;
    cout << "Tipo de tinta: ";
    cin >> lapicero.tipoTinta;
    cout << "Marca: ";
    cin >> lapicero.marca;

    cout << "\nIngrese los datos de la carpeta:\n";
    cout << "Numero de hojas: ";
    cin >> carpeta.numHojas;
    cout << "Color: ";
    cin >> carpeta.color;
    cout << "Tamaño: ";
    cin >> carpeta.tamano;

    cout << "\nIngrese los datos de la silla:\n";
    cout << "Material: ";
    cin >> silla.material;
    cout << "Color: ";
    cin >> silla.color;
    cout << "¿Tiene respaldo? (1 = Si, 0 = No): ";
    cin >> silla.tieneRespaldo;

    cout << "\nIngrese los datos de la mochila:\n";
    cout << "Marca: ";
    cin >> mochila.marca;
    cout << "Capacidad en litros: ";
    cin >> mochila.capacidadLitros;
    cout << "Color: ";
    cin >> mochila.color;

    cout << "\nIngrese los datos del cable UTP:\n";
    cout << "Longitud (en metros): ";
    cin >> cable.longitud;
    cout << "Categoria: ";
    cin >> cable.categoria;
    cout << "Color: ";
    cin >> cable.color;

    cout << "\nIngrese los datos de la laptop:\n";
    cout << "Marca: ";
    cin >> laptop.marca;
    cout << "RAM (en GB): ";
    cin >> laptop.ramGB;
    cout << "Tamaño de pantalla (en pulgadas): ";
    cin >> laptop.tamanoPantalla;

    cout << "\nIngrese los datos del servidor:\n";
    cout << "Sistema operativo: ";
    cin >> servidor.sistemaOperativo;
    cout << "Nucleos de CPU: ";
    cin >> servidor.nucleosCPU;
    cout << "Almacenamiento (en GB): ";
    cin >> servidor.almacenamientoGB;

    cout << "\nIngrese los datos de la variable estadistica:\n";
    cout << "Nombre: ";
    cin >> variable.nombre;
    cout << "Tipo (cualitativa/cuantitativa): ";
    cin >> variable.tipo;
    cout << "Nivel de medicion: ";
    cin >> variable.nivelDeMedicion;

    // Mostrar datos
    cout << "\n--- Datos Ingresados ---\n";
    cout << "Estudiante:\n";
    cout << "Codigo: " << estudiante.Codigo << ", Apellido: " << estudiante.Apellido << ", Nombre: " << estudiante.Nombre << "\n";

    cout << "Lapicero:\n";
    cout << "Color: " << lapicero.color << ", Tipo de tinta: " << lapicero.tipoTinta << ", Marca: " << lapicero.marca << "\n";

    cout << "Carpeta:\n";
    cout << "Numero de hojas: " << carpeta.numHojas << ", Color: " << carpeta.color << ", Tamaño: " << carpeta.tamano << "\n";

    cout << "Silla:\n";
    cout << "Material: " << silla.material << ", Color: " << silla.color << ", Tiene respaldo: " << (silla.tieneRespaldo ? "Si" : "No") << "\n";

    cout << "Mochila:\n";
    cout << "Marca: " << mochila.marca << ", Capacidad: " << mochila.capacidadLitros << " litros, Color: " << mochila.color << "\n";

    cout << "Cable UTP:\n";
    cout << "Longitud: " << cable.longitud << " metros, Categoria: " << cable.categoria << ", Color: " << cable.color << "\n";

    cout << "Laptop:\n";
    cout << "Marca: " << laptop.marca << ", RAM: " << laptop.ramGB << " GB, Tamaño de pantalla: " << laptop.tamanoPantalla << " pulgadas\n";

    cout << "Servidor:\n";
    cout << "Sistema operativo: " << servidor.sistemaOperativo << ", Nucleos CPU: " << servidor.nucleosCPU << ", Almacenamiento: " << servidor.almacenamientoGB << " GB\n";

    cout << "Variable estadistica:\n";
    cout << "Nombre: " << variable.nombre << ", Tipo: " << variable.tipo << ", Nivel de medicion: " << variable.nivelDeMedicion << "\n";

    return 0;
}

