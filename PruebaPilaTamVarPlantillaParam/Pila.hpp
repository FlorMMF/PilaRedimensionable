#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX_TAM 100
/**

 * \file Pila.hpp

 * Este archivo contiene la definici&oacute;n de los m&eacute;todos que simulan una pila

 * \author Flor Machado y Elias Peregrina

 * \date 3/02/2025

 */

template <typename Tipo, int cap = 10>
/**Clase de tipo lifo, contenedor de vaolres de tipo double
    \param Tipo de dato
 */
class Pila{
public:
    /** \brief Constructor de la pila
     *
     * \param tam int, tama&ntilde;o predeterminado de la pila
     *
     */
    Pila(int tam = 10);

    /** \brief M&eacute;todo que apila un elemento a la pila
     *
     * \param valor Tipo el objeto que se podr&aacute; hasta arriba de la pila
     * \return void
     *
     */
    
     /** \brief Constructor de copias
     * 
     * \param const Pila, pila que se copiar&acute;
     */
    Pila(const Pila<Tipo>& otra);
    
    /** \brief Operador de asignaci&oacute;n, libera la memoria previa y copia los valores de la pila proporcionada
     *
     * \param const Pila, pila de la cual se copiar&acute;n los valores
     */
    Pila<Tipo>& operator=(const Pila<Tipo>& otra);
    
    /** \brief Destructor de la Pila
     *
     *
     */
    ~Pila();
    
    
    /** \brief Agrega un elemento agregado a la pila
     *  
     * \param Tipo valor, valor el cual se agrega&acute; a la matriz
     * \return void
     *
     */
    void Apilar(Tipo valor);

    /** \brief Quita el &uacute;  ltimo elemento agregado a la pila
     *
     * \return void
     *
     */
    void Desapilar();

    /** \brief Obtiene el &uacute;  ltimo elemento de la pila
     *
     * \return Tipo Devuelve el &uacute;  ltimo elemento de la pila
     *
     */
    Tipo ObtenerTOPE() const;

    /** \brief Comprueba si la pila esta vac&iacute;  a
     *
     * \return bool, si la pila esta vac&iacute;  a devuelve true
     *
     */
    bool EstaVacia() const;

    /** \brief Devuele el tope al estado inicial, simulando que la pila esta vac&iacute;  a
     *
     * \return void
     *
     */
    void Vaciar();

     /** \brief Cuenta el n&uacte;mero de elementos que se encuentran en la pila
     *
     * \return tope + 1, aumenta en 1 el tamaño del tope de la pila
     *
     */
    int NumeroElementos() const;
    
     /** \brief Conocer el tamaño de la pila
     *
     * \return capacidad, devuelve el tamaño actual de la pila (para pruebas)
     *
     */
    int Capacidad() const;

    /** \brief Imprime la pila
     *
     * \return void
     *
     */
    void imprimir() const;
private:
    void Redimensionar();
    bool EstaLlena() const;
    int capacidad;
    int tope;
    Tipo elementos[cap];
};

#include "Pila.tpp"
#endif // PILA_HPP_INCLUDED
