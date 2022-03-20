#ifndef ARBOL_H
#define ARBOL_H

using namespace std;

#include "ortogonal.h"

typedef struct Nodo_Binario Nodo_Binario;
typedef struct Arbol Arbol;

struct Nodo_Binario{
    Nodo_Binario * izq;
    Nodo_Binario * der;

    string nombre;
    int p_ganadas;
    int p_perdidas;

    Nodo_Binario(string nombre_, int pg, int pp):izq(0), der(0), nombre(nombre_), p_ganadas(pg), p_perdidas(pp){}

    ~Nodo_Binario(){}
};

struct Arbol{
    Nodo_Binario * raiz;
    Encabezado * nE;

    Arbol():raiz(0){}

    ~Arbol(){}

    void agregar(Nodo_Binario * nuevo);

    void agregar(Nodo_Binario *nuevo, Nodo_Binario *temp);

    Nodo_Binario *buscar(string nombre);

    Nodo_Binario *buscar(string nombre, Nodo_Binario *padre);

    bool eliminar(string nombre);

    int buscarNodoHoja(Nodo_Binario * padre);

    int buscarNodoRama(Nodo_Binario * padre);

    int altura(Nodo_Binario * padre);

    Nodo_Binario *obtenerRemplazo(Nodo_Binario * aux);

    string mostrarArbol();

    string mostrarTop();

    void addinOrden(Nodo_Binario *padre);

    string preOrden(Nodo_Binario *padre);
};

#endif // ARBOL_H
