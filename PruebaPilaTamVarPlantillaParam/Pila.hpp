#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX_TAM 100
template <typename Tipo, int cap = 10>
/**Clase de tipo lifo, contenedor de vaolres de tipo double
    \param Tipo de dato
 */
class Pila{
public:
    Pila(int tam = 10);
    void Apilar(Tipo valor);
    void Desapilar();
    Tipo ObtenerTOPE() const;

    bool EstaVacia() const;
    bool EstaLlena() const;

    void Vaciar();
    //para pruebas
    void imprimir() const;
private:
    int tope;
    Tipo elementos[cap];

};
#include "Pila.tpp"
#endif // PILA_HPP_INCLUDED
