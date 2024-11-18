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

bool enMismaLinea(const vector<Coordenada>& coords) {
    if (coords.size() < 2) return true;

    double pendienteInicial = static_cast<double>(coords[1].y - coords[0].y) / (coords[1].x - coords[0].x);

    for (size_t i = 2; i < coords.size(); ++i) {
        double pendienteActual = static_cast<double>(coords[i].y - coords[0].y) / (coords[i].x - coords[0].x);
        if (pendienteActual != pendienteInicial) return false;
    }
    return true;
}

int main (){

vector<Coordenada> coordenadas;
int x, y;
char opcion;

    do
    {
        cout<< "introduce las coordenadas x y: ";
        cin>> x >> y;
        coordenadas.push_back({x, y});
        cout<< "quieres introducir otra coordenadas? (s/n): ";
        cin>> opcion;

    } while (opcion=='s'|| opcion=='S');

    for (const auto& coord : coordenadas)
    {
        cout<<"la coordenada (" << coord.x << "," << coord.y << ") se encuentra en el" << determinarCuadrante(coord) << endl;

    }

    if (enMismaLinea(coordenadas)) {
        cout << "las coordenadas estan en la misma linea" << endl;
        if (coordenadas.size() > 1) {
            cout << "La ecuacion de la linea es: " << ecuacionRecta(coordenadas[0], coordenadas[1]) << endl;
        }
    } else {
        cout << "las coordenadas no estan en la misma linea" << endl;
    }

    return 0;
}
