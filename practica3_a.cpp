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