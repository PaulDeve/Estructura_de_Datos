
// Archivo: main.cpp
// Ver código completo en la respuesta anterior
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>
#include <set>
using namespace std;
using namespace chrono;
const int N = 10000;
struct Nodo {
    int val;
    Nodo* izq;
    Nodo* der;
    Nodo(int v) : val(v), izq(nullptr), der(nullptr) {}
};
class ArbolBinario {
public:
    Nodo* raiz = nullptr;
    Nodo* insertar(Nodo* nodo, int val) {
        if (!nodo) return new Nodo(val);
        if (val < nodo->val) nodo->izq = insertar(nodo->izq, val);
        else nodo->der = insertar(nodo->der, val);
        return nodo;
    }
    void insertar(int val) { raiz = insertar(raiz, val); }
    bool buscar(Nodo* nodo, int val) {
        if (!nodo) return false;
        if (nodo->val == val) return true;
        return val < nodo->val ? buscar(nodo->izq, val) : buscar(nodo->der, val);
    }
    bool buscar(int val) { return buscar(raiz, val); }
    Nodo* eliminar(Nodo* nodo, int val) {
        if (!nodo) return nodo;
        if (val < nodo->val) nodo->izq = eliminar(nodo->izq, val);
        else if (val > nodo->val) nodo->der = eliminar(nodo->der, val);
        else {
            if (!nodo->izq) return nodo->der;
            if (!nodo->der) return nodo->izq;
            Nodo* temp = nodo->der;
            while (temp->izq) temp = temp->izq;
            nodo->val = temp->val;
            nodo->der = eliminar(nodo->der, temp->val);
        }
        return nodo;
    }
    void eliminar(int val) { raiz = eliminar(raiz, val); }
    void actualizar(int viejo, int nuevo) { eliminar(viejo); insertar(nuevo); }
};
int main() {
    vector<int> datos(N); iota(datos.begin(), datos.end(), 0);
    shuffle(datos.begin(), datos.end(), mt19937(random_device{}()));
    ofstream archivo("tiempos.csv");
    archivo << "Estructura,Insercion,Busqueda,Eliminacion,Actualizacion\n";
    stack<int> pila;
    auto inicio = high_resolution_clock::now();
    for (int x : datos) pila.push(x);
    auto fin = high_resolution_clock::now();
    double t_insercion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) pila.top();
    fin = high_resolution_clock::now();
    double t_busqueda = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) pila.pop();
    fin = high_resolution_clock::now();
    double t_eliminacion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) pila.top();
    fin = high_resolution_clock::now();
    double t_actualizacion = duration<double>(fin - inicio).count();
    archivo << "Pila," << t_insercion << "," << t_busqueda << "," << t_eliminacion << "," << t_actualizacion << "\n";
    queue<int> cola;
    inicio = high_resolution_clock::now();
    for (int x : datos) cola.push(x);
    fin = high_resolution_clock::now();
    t_insercion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) cola.front();
    fin = high_resolution_clock::now();
    t_busqueda = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) cola.pop();
    fin = high_resolution_clock::now();
    t_eliminacion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) cola.front();
    fin = high_resolution_clock::now();
    t_actualizacion = duration<double>(fin - inicio).count();
    archivo << "Cola," << t_insercion << "," << t_busqueda << "," << t_eliminacion << "," << t_actualizacion << "\n";
    ArbolBinario arbol;
    inicio = high_resolution_clock::now();
    for (int x : datos) arbol.insertar(x);
    fin = high_resolution_clock::now();
    t_insercion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) arbol.buscar(datos[i]);
    fin = high_resolution_clock::now();
    t_busqueda = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) arbol.eliminar(datos[i]);
    fin = high_resolution_clock::now();
    t_eliminacion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) arbol.actualizar(datos[i+100], i);
    fin = high_resolution_clock::now();
    t_actualizacion = duration<double>(fin - inicio).count();
    archivo << "Arbol," << t_insercion << "," << t_busqueda << "," << t_eliminacion << "," << t_actualizacion << "\n";
    vector<int> lista;
    inicio = high_resolution_clock::now();
    for (int x : datos) lista.push_back(x);
    fin = high_resolution_clock::now();
    t_insercion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) find(lista.begin(), lista.end(), datos[i]);
    fin = high_resolution_clock::now();
    t_busqueda = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) lista.pop_back();
    fin = high_resolution_clock::now();
    t_eliminacion = duration<double>(fin - inicio).count();
    inicio = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) lista[i] = i;
    fin = high_resolution_clock::now();
    t_actualizacion = duration<double>(fin - inicio).count();
    archivo << "Lista," << t_insercion << "," << t_busqueda << "," << t_eliminacion << "," << t_actualizacion << "\n";
    archivo.close();
    cout << "CSV generado: tiempos.csv\n";
    return 0;
}
