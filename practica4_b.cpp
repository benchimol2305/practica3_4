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