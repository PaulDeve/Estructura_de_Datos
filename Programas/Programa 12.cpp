#include <iostream>
using namespace std;
struct Persona {
    string nombre;
    int edad;
    void saludar() {
        cout << "Hola, me llamo " << nombre << " y tengo "<< edad <<endl;
    }};
int main() {
    Persona* ptrPersona = new Persona();
    ptrPersona->nombre = "Paul";
    ptrPersona->edad = 22;
    cout << "Nombre: " << ptrPersona->nombre << endl;
    cout << "Edad: " << ptrPersona->edad <<endl;
    ptrPersona->saludar();
    delete ptrPersona;
return 0;  
}
