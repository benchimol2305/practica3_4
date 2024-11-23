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
