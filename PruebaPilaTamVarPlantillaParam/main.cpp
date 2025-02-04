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
    for(int i = 0; i < 12 ; ++i){
        PilaInt.Apilar(1000);
    }
    PilaInt.imprimir();

    cout << endl;
    Pila<double, 10> PilaDouble;
    for(int i = 0; i < 12 ; ++i){
        PilaDouble.Apilar('a');
    }
    PilaDouble.imprimir();

    Pila<Vector, 10> PilaVector;
    for(int i = 0; i < 12 ; ++i){
        PilaVector.Apilar(Vector(2));
    }
    PilaVector.imprimir();


    return 0;
}
