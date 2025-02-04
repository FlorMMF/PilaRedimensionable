#include <iostream>
#include "Pila.hpp"

/**

 * \file Pila.tpp

 * Este archivo contiene el desarrollo de los m&eacute;todos que simulan una pila

 * \author Flor Machado y Elias Peregrina

 * \date 03/02/2025

 */

//******************************************
template <typename Tipo, int cap>
Pila<Tipo, cap>::Pila(int capa) : capacidad(capa), tope(-1), elementos(new Tipo[cap]) {}

template <typename Tipo, int cap>
Pila<Tipo, cap>::Pila(const Pila<Tipo, cap>& otra) : capacidad(otra.capacidad), tope(otra.tope), elementos(new Tipo[otra.capacidad]) {
    for (int i = 0; i <= tope; ++i) {
        elementos[i] = otra.elementos[i];
    }
}

template <typename Tipo, int cap>
Pila<Tipo, cap>& Pila<Tipo, cap>::operator=(const Pila<Tipo, cap>& otra) {
    if (this != &otra) {
        delete[] elementos;
        capacidad = otra.capacidad;
        tope = otra.tope;

        for (int i = 0; i <= tope; ++i) {
            elementos[i] = otra.elementos[i];
        }
    }
    return *this;
}

template <typename Tipo, int cap>
Pila<Tipo, cap>::~Pila() {
    delete[] elementos;
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Apilar(Tipo valor) {
    if (EstaLlena()) {
        Redimensionar();
    }
    ++tope;
    elementos[tope] = valor;
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Desapilar() {
    if (EstaVacia()) throw "Esta pila está vacía...";
    --tope;
}

template <typename Tipo, int cap>
Tipo Pila<Tipo, cap>::ObtenerTOPE() const {
    if (EstaVacia()) throw "Esta pila está vacía...";
    return elementos[tope];
}

template <typename Tipo, int cap>
bool Pila<Tipo, cap>::EstaVacia() const {
    return tope == -1;
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Vaciar() {
    tope = -1;
}

template <typename Tipo, int cap>
int Pila<Tipo, cap>::NumeroElementos() const {
    return tope + 1;
}

template <typename Tipo, int cap>
int Pila<Tipo, cap>::Capacidad() const {
    return capacidad;
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::imprimir() const {
    for (int i = 0; i <= tope; ++i) {
        std::cout << elementos[i] << ", ";
    }

    std::cout << "\b\b <- TOPE" << std::endl;
    std::cout << std::endl << Capacidad();
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Redimensionar() {

    Tipo* nuevoElemento = new Tipo[cap*2];
    for (int i = 0; i <= tope; ++i) {
        nuevoElemento[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevoElemento;
    capacidad = cap*2;
}

template <typename Tipo, int cap>
bool Pila<Tipo, cap>::EstaLlena() const {
    return tope == capacidad - 1;
}
