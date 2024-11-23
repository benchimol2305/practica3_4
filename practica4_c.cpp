#include <iostream>
using namespace std;

int contadorFuncion = 0; 

int sumar(int a, int b) {
    contadorFuncion++; 
    return a + b;
}
int obtenerNumeroDeLlamadas() {
    return contadorFuncion;
}
int main() {
    int opcion;
    do {
        cout << "elige una opcion:\n";
        cout << "1. realizar una suma\n";
        cout << "2. ver el numero de veces que se ha llamado a la funcion de suma\n";
        cout << "3. salir\n";
        cout << "opcion: ";
        cin >> opcion;
        
        if (opcion == 1) {
            int x, y;
            cout << "introduce dos numeros para sumar: ";
            cin >> x >> y;
            int resultado = sumar(x, y);
            cout << "el resultado de la suma es: " << resultado << endl;
        } else if (opcion == 2) {
            int llamadas = obtenerNumeroDeLlamadas();
            cout << "la funcion de suma se ha llamado " << llamadas << " veces." << endl;
        } else if (opcion == 3) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "opcion no valida, elige una opcion correcta." << endl;
        }
    } while (opcion != 3);

    return 0;
}
