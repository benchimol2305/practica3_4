#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x, y;
};

double calcularAngulo(const Punto& inicio1, const Punto& fin1, const Punto& inicio2, const Punto& fin2, bool enGrados = false) {
    double dx1 = fin1.x - inicio1.x;
    double dy1 = fin1.y - inicio1.y;

    double dx2 = fin2.x - inicio2.x;
    double dy2 = fin2.y - inicio2.y;

    double productoEscalar = dx1 * dx2 + dy1 * dy2;

    double magnitud1 = sqrt(dx1 * dx1 + dy1 * dy1);
    double magnitud2 = sqrt(dx2 * dx2 + dy2 * dy2);

    double angulo = acos(productoEscalar / (magnitud1 * magnitud2));

     if (enGrados) {
        angulo = angulo * 180.0 / M_PI;
    }

    return angulo;
}

int main() {
    Punto inicio_1, fin_1, inicio_2, fin_2;

    cout << "introduce las coordenadas de la primera linea (inicio y fin):" << endl;
    cout << "inicio x1 y1: ";
    cin >> inicio_1.x >> inicio_1.y;
    cout << "fin  x2 y2: ";
    cin >> fin_1.x >> fin_1.y;
    
    cout << "introduce las coordenadas de la segunda línea (inicio y fin):" << endl;
    cout << "inicio x3 y3: ";
    cin >> inicio_2.x >> inicio_2.y;
    cout << "fin x4 y4: ";
    cin >> fin_2.x >> fin_2.y;
