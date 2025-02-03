
/**

 * \file Vector.hpp

 * Este archivo contiene el desarrollo de los m&eacute;todos que simulan un vector

 * \author Flor Machado y Elias Peregrina

 * \date 03/02/2025

 */

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#define MAX_DIM 10

/**< Vector es la clase para el manejo de vectores alg&eacute;braicos */
class Vector{

    /** \brief Operador de escalar por vector
     *
     * \param escalar Es el escalar por el que se multiplica un vector
     * \param v const El vector a multiplicar
     * \return Vector Resultante de la multiplicaci&oacute;n
     *
     */friend Vector operator* (double escalar, const Vector v);

    /** \brief M&eacute;todo que imprime un vector
     *
     * \param std::ostream &salida, recibe la salida
     * \param  const Vector v, recibe el vector a imprimir
     * \return Devuelve la salida creada
     *
     */
    friend std::ostream & operator<< (std::ostream &salida, const Vector v);

    /** \brief M&eacute;todo que recibe los componentes del vector
     *
     * \param std::istream &entrada, Recibe la entrada de los datos
     * \param Vector &v, Recibe el vector objeto donde se van a ingresar los componentes
     * \return Devuelve la entrada creada dentro del m&eacute;todo
     *
     */
    friend std::istream & operator >>  (std::istream &entrada, Vector &v);

public:

    //un constructor con un solo parametro es un operador de conversi&oacute;n, convierte el tipo de paramentro al tipo de la clase
    //nada mas funciona si creas el vector explicitamente, osea no jala si lo escribes de la forma determinada

    /** \brief Constructor explicito de la clase
     *
     * \param int dimension, es el tama&ntilde;o que tendr&aacute; el vector, predeterminado es 1
     * \param double valor, es el n&uacute;  mero con el que se rellenar&aacute; el vector, por determinado es 0
     *
     */
    explicit Vector(int dimension = 1, double valor = 0);

    /** \brief Es el constructor de copias de la clase
     *
     * \param v const Vector&, recibe el vector con el que se va a crear la copia
     *
     */
    Vector(const Vector &v);//constructor de copias

    /** \brief Destructor de la clase
     *
     *
     */
    ~Vector();

    /* los m&eacute;todos est&aacute;ticos pueden ser solamente accedidos por datos est&aacute;ticos
    los datos est&aacute;ticos son atributos de clase y no objeto

    todo m&eacute;todo no est&aacute;tico de una clase tiene acceso a un puntero de autoreferencia del objeto que le llame */

    /** \brief M&eacute;todo que sobrecarga el operador igual
     *
     * \param v const Vector&, recibe el vector el cual se va a copiar
     * \return Vector&
     *
     */
    Vector & operator=(const Vector &v);


    /** \brief M&eacute;todo que suma dos vectores
     *
     * \param v const Vector, vector con el que se va a sumar el objeto
     * \return Vector, vector resultante
     *
     */
    Vector operator+(const Vector v) const;//un m&eacute;todo constante puede ser aplicado a instancias constantes, se a&ntilde;ade const al final

    /** \brief M&eacute;todo que resta dos vectores
     *
     * \param v const Vector, vector con el que se va a restar el objeto
     * \return Vector, vector resultante
     *
     */
    Vector operator-(const Vector v) const;

    /** \brief M&eacute;todo que realiza el producto punto
     *
     * \param v const Vector, el vector con el que se realizar&aacute; el producto punto con el objeto
     * \return double, devuelve el resultado de la operaci&oacute;n
     *
     */
    double operator*(const Vector v)const;

    /** \brief M&eacute;todo que multiplica un vector con un escalar
     *
     * \param escalar double, escalar con el que se va a multiplicar el vector
     * \return Vector, devuelve el resultado de la operaci&oacute;n
     *
     */
    Vector operator*(double escalar)const;

    /** \brief M&eacute;todo que calcula la norma de un vector
     *
     * \return double, devuelve la norma
     *
     */
    double Norma() const;


    /** \brief M&eacute;todo para acceder a un componente del vector
     *
     * \param i int, n&uacute;  mero de donde esta el componente
     * \return double & operator, devuelve el componente
     *
     */
    double & operator [](int i);


private:
    int dim;
    double *componente;
    //metodos de utileria
    void EstablecerDim(int dimension);

};




#endif // VECTOR_HPP_INCLUDED
