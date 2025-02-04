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
Pila<Tipo>::Pila(int cap) : capacidad(cap), tope(-1), elementos(new Tipo[cap]) {}

template <typename Tipo, int cap>
Pila<Tipo>::Pila(const Pila<Tipo>& otra) : capacidad(otra.capacidad), tope(otra.tope), elementos(new Tipo[otra.capacidad]) {
    for (int i = 0; i <= tope; ++i) {
        elementos[i] = otra.elementos[i];
    }
}

template <typename Tipo, int cap>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>& otra) {
    if (this != &otra) {
        delete[] elementos;
        capacidad = otra.capacidad;
        tope = otra.tope;
        elementos = new Tipo[capacidad];
        for (int i = 0; i <= tope; ++i) {
            elementos[i] = otra.elementos[i];
        }
    }
    return *this;
}

template <typename Tipo, int cap>
Pila<Tipo>::~Pila() {
    delete[] elementos;
}

template <typename Tipo, int cap>
void Pila<Tipo>::Apilar(Tipo valor) {
    if (EstaLlena()) {
        Redimensionar();
    }
    elementos[++tope] = valor;
}

template <typename Tipo, int cap>
void Pila<Tipo>::Desapilar() {
    if (EstaVacia()) throw "Esta pila está vacía...";
    --tope;
}

template <typename Tipo, int cap>
Tipo Pila<Tipo>::ObtenerTOPE() const {
    if (EstaVacia()) throw "Esta pila está vacía...";
    return elementos[tope];
}

template <typename Tipo, int cap>
bool Pila<Tipo>::EstaVacia() const {
    return tope == -1;
}

template <typename Tipo, int cap>
void Pila<Tipo>::Vaciar() {
    tope = -1;
}

template <typename Tipo, int cap>
int Pila<Tipo>::NumeroElementos() const {
    return tope + 1;
}

template <typename Tipo, int cap>
int Pila<Tipo>::Capacidad() const {
    return capacidad;
}

template <typename Tipo, int cap>
void Pila<Tipo>::imprimir() const {
    for (int i = 0; i <= tope; ++i) {
        std::cout << elementos[i] << ", ";
    }
    std::cout << "\b\b <- TOPE" << std::endl;
}

template <typename Tipo, int cap>
void Pila<Tipo>::Redimensionar() {
    capacidad *= 2;
    Tipo* nuevoElemento = new Tipo[capacidad];
    for (int i = 0; i <= tope; ++i) {
        nuevoElemento[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevoElemento;
}

template <typename Tipo, int cap>
bool Pila<Tipo>::EstaLlena() const {
    return tope == capacidad - 1;
}
