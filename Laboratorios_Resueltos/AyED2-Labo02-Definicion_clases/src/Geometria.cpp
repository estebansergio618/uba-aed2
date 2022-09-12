#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1
class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho); // CONTRUCTOR
        uint alto();
        uint ancho();
        float area();

    private:
        int _alto;
        int _ancho;

};

Rectangulo::Rectangulo(uint alto, uint ancho): _alto(alto),_ancho(ancho) {};

uint Rectangulo::alto() {
    return _alto;
}

// Completar definición: ancho
uint Rectangulo ::ancho() {
    return this->_ancho;
}

// Completar definición: area
float Rectangulo::area() {
    return _alto*_ancho;
}

// Ejercicio 2

// Clase Elipse
class Elipse{
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float  area();
    private:
        uint radio_a;
        uint radio_b;
        float PI;
};

Elipse::Elipse(uint a, uint b) :radio_a(a),radio_b(b),PI(3.14){}

uint Elipse::r_a() {
    return radio_a;
}

uint Elipse::r_b() {
    return radio_b;
}

float Elipse::area() {
    return PI*radio_b*radio_a;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo _r;
};

Cuadrado::Cuadrado(uint lado): _r(lado, lado) {}

uint Cuadrado::lado() {
    return _r.ancho();
}

float Cuadrado::area() {
    return _r.area();
}

// Ejercicio 4

// Clase Circulo
class Circulo{
    public:
        Circulo(uint radio);
        uint radio();
        float  area();

    private:
        Elipse _c;
};

Circulo::Circulo(uint radio): _c(radio,radio) {}

uint Circulo::radio() {
    return _c.r_b();
}

float Circulo::area() {
    return _c.area();
}

// Ejercicio 5

// OSTREAM ES UN FLUJO DE SALIA ("O DE OUT")
ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

// CUADRADO
ostream& operator<<(ostream& os, Cuadrado c){
    os << "Cuad(" << c.lado() << ")";
    return os;
}

// CIRCULO
ostream& operator<<(ostream& os, Circulo c){
    os << "Circ(" << c.radio() << ")";
    return os;
}