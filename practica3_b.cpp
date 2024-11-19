#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    int x;
    int y;
};

double calcularDistancia(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


bool dentroDelCuadrante(const Punto& p, int xMin, int xMax, int yMin, int yMax) {
    return (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax);
}

double distanciaMaxima(Punto puntos[], int n, int xMin, int xMax, int yMin, int yMax) {
    double maxDistancia = 0;
    bool found = false;  

    for (int i = 0; i < n; ++i) {
        if (!dentroDelCuadrante(puntos[i], xMin, xMax, yMin, yMax)) continue;
        for (int j = i + 1; j < n; ++j) {
            if (!dentroDelCuadrante(puntos[j], xMin, xMax, yMin, yMax)) continue;
            double distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia > maxDistancia) {
                maxDistancia = distancia;
                found = true;
            }
        }
    }
}