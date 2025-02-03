#include <iostream>
#include "Pila.hpp"
#include "Vector.hpp"

/**

 * \file main.cpp

 * Este archivo contiene las pruebas del funcionamiento de los m&eacute;todos

 * \author Flor Machado y Elias Peregrina

 * \date 03/02/2025

 */
using namespace std;

int main()
{
    Pila<int, 10> PilaInt;
    Pila<Vector, 10> PilaVector;
    Pila<double> PilaDouble;

    PilaInt.Apilar(1000);
    PilaInt.imprimir();

    PilaVector.Apilar(Vector(2));
    PilaVector.imprimir();

    return 0;
}
