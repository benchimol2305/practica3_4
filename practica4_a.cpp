#include <iostream>
using namespace std;

struct Punto {
    double x, y;
};
int determinarInterseccion(const Punto& inicio1, const Punto& fin1, const Punto& inicio2, const Punto& fin2) {
    double pendiente1 = (fin1.y - inicio1.y) / (fin1.x - inicio1.x);
    double pendiente2 = (fin2.y - inicio2.y) / (fin2.x - inicio2.x);
     if (pendiente1 == pendiente2) {
        // Las lineas son paralelas
        return 0;
    } else {
        double b1 = inicio1.y - pendiente1 * inicio1.x;
        double b2 = inicio2.y - pendiente2 * inicio2.x;
        double xInterseccion = (b2 - b1) / (pendiente1 - pendiente2);
        
        if ((xInterseccion >= min(inicio1.x, fin1.x) && xInterseccion <= max(inicio1.x, fin1.x)) &&
            (xInterseccion >= min(inicio2.x, fin2.x) && xInterseccion <= max(inicio2.x, fin2.x))) {
            return 1; // Las lineas se cruzan
        } else {
            return -1; // Las lineas no se cruzan ni son paralelas
        }
    }
}
int determinarInterseccion(const Punto& inicio1, const Punto& fin1, const Punto& inicio2, const Punto& fin2, bool checkPerpendicular) {
    double pendiente1 = (fin1.y - inicio1.y) / (fin1.x - inicio1.x);
    double pendiente2 = (fin2.y - inicio2.y) / (fin2.x - inicio2.x);
    
    if (pendiente1 == pendiente2) {
        return 0; // Las líneas son paralelas
    } else if (pendiente1 * pendiente2 == -1) {
        return 1; // Las líneas son perpendiculares
    } else {
        return -1; // Las líneas se cruzan pero no son perpendiculares
    }
}

int main() {
    Punto inicio1, fin1, inicio2, fin2;

    // Pide al usuario las coordenadas de las lineas
    cout << "introduce las coordenadas de la primera linea (inicio y fin):" << endl;
    cout << "inicio x1 y1: ";
    cin >> inicio1.x >> inicio1.y;
    cout << "fin x2 y2: ";
    cin >> fin1.x >> fin1.y;
    
    cout << "introduce las coordenadas de la segunda linea (inicio y fin):" << endl;
    cout << "Inicio x3 y3: ";
    cin >> inicio2.x >> inicio2.y;
    cout << "Fin x4 y4: ";
    cin >> fin2.x >> fin2.y;

    int resultado = determinarInterseccion(inicio1, fin1, inicio2, fin2);
    cout << "Resultado de interseccion: " << resultado << endl;
    int resultadoPerpendicular = determinarInterseccion(inicio1, fin1, inicio2, fin2, true);
    cout << "Resultado de perpendicularidad: " << resultadoPerpendicular << endl;

    return 0;
}
