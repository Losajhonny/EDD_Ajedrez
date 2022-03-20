#ifndef ORTOGONAL_H
#define ORTOGONAL_H

#include "string"
#include "pieza.h"

typedef struct NodoEncabezado NodoEncabezado;
typedef struct Nodo Nodo;
typedef struct Encabezado Encabezado;
typedef struct Ortogonal Ortogonal;

struct NodoEncabezado{
    NodoEncabezado * anterior; // arriba
    NodoEncabezado * siguiente; //abajo
    Nodo * acceso;

    int id;
    string nombre;

    NodoEncabezado(int id_):anterior(0), siguiente(0), acceso(0), id(id_){}

    ~NodoEncabezado(){}
};

struct Nodo{
    Nodo * anterior;
    Nodo * siguiente;
    Nodo * arriba;
    Nodo * abajo;

    Nodo * zarriba;
    Nodo * zabajo;

    bool existe;
    int x; // valor de [1-8]
    int y; // cod ascii [H-A][1-8]
    int z; // es el nivel max = 2 [0 1 2]

    Pieza * p;

    Nodo(int x_, int y_, int z_, bool existe_, Pieza * p_){
        anterior = 0; siguiente = 0; arriba = 0; abajo = 0;
        zarriba = 0; zabajo = 0; existe = existe_;
        x = x_;
        y = y_;
        z = z_;
        p = p_;
    }

    ~Nodo(){}

    void setPieza(Pieza * p_){
        p = p_;
    }
};

struct Encabezado{
    NodoEncabezado * primero;
    NodoEncabezado * ultimo;

    Encabezado():primero(0), ultimo(0){}

    ~Encabezado(){}

    bool isEmpty();

    void add(NodoEncabezado * nuevo);

    NodoEncabezado *buscar(int id);

    void deleteEncabezado(int id);

    string recorrer();
};

struct Ortogonal{
    Encabezado * horizontal;
    Encabezado * vertical;

    Ortogonal();

    ~Ortogonal(){}

    void agregar(int x, int y, int z, Pieza * p);

    void agregar(int x, int y, int z, Pieza * p, bool existe);

    void eliminar(int x, int y, int z);

    void eliminar(int x, int y, int z, bool eliminado);

    Nodo *existeXYZ(Nodo *tempx, int y, int z);

    Nodo *buscarNodo(NodoEncabezado * tempx, int z, bool isX);

    Nodo *verificarEncima(Nodo *tempy, int y);

    Nodo *verificarIzquierda(Nodo *tempx, int x);

    Nodo *verificarDerecha(Nodo *tempx, int x);

    Nodo *verificarAbajo(Nodo *tempy, int y);

    Nodo *existeXY(Nodo *tempx, int y);

    void enlazar(Nodo *nuevo, NodoEncabezado *xn, NodoEncabezado *yn, int x, int y, int z);

    void enlaceInicio(Nodo *nuevo, NodoEncabezado *xn, NodoEncabezado *yn, int x, int y);

    string recorrer();
};

#endif // ORTOGONAL_H
