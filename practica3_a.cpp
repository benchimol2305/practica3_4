#include <iostream>
#include <vector>
using namespace std;

struct Coordenada {
    int x;
    int y;
};

string determinarCuadrante(const Coordenada& coord) {
    if (coord.x > 0 && coord.y > 0) {
        return "Primer cuadrante";
    } else if (coord.x < 0 && coord.y > 0) {
        return "Segundo cuadrante";
    } else if (coord.x < 0 && coord.y < 0) {
        return "Tercer cuadrante";
    } else if (coord.x > 0 && coord.y < 0) {
        return "Cuarto cuadrante";
    } else if (coord.x == 0 && coord.y != 0) {
        return "Eje Y";
    } else if (coord.x != 0 && coord.y == 0) {
        return "Eje X";
    } else {
        return "Origen";
    }
}

string ecuacionRecta(const Coordenada& p1, const Coordenada& p2) {
    if (p1.x == p2.x) {
        return "x = " + to_string(p1.x);
    } else {
        double pendiente = static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);
        double intercepto= p1.y - pendiente * p1.x;
        return "y = " + to_string(pendiente) + "x + " + to_string(intercepto);
    }
}
