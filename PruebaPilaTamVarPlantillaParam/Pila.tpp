    #include <iostream>




//******************************************
template <typename Tipo, int cap>
Pila<Tipo, cap>::Pila(int tam):tope(-1){

}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Vaciar(){
    tope = -1;

}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Apilar(Tipo valor){
    if(EstaLlena()) throw "Esta pila esta llena...";
    ++tope;
    elementos[tope]=valor;
}

template <typename Tipo, int cap>
void Pila<Tipo, cap>::Desapilar(){
    if(EstaVacia()) throw "Esta pila esta vacia...";
    --tope;
}

template <typename Tipo, int cap>
Tipo Pila<Tipo, cap>::ObtenerTOPE() const {
    if(EstaVacia()) throw "Esta pila esta vacia...";
    return elementos[tope];

}

template <typename Tipo, int cap>
bool Pila<Tipo, cap>::EstaVacia() const{
    return tope==-1;
}

template <typename Tipo, int cap>
bool Pila<Tipo, cap>::EstaLlena() const{
    return tope==MAX_TAM-1;
}

//PARA PRUEBAS

template <typename Tipo, int cap>
void Pila<Tipo, cap>::imprimir() const{
    for(int i=0; i<=tope;i++){
        std::cout<<elementos[i];
        std::cout <<", ";

    }
    std::cout<<"\b\b <- TOPE"<<std::endl;
}

