#ifndef LOGICA_H
#define LOGICA_H

#include "ortogonal.h"
#include "constante.h"

struct Logica{
    Ortogonal * matriz;
    Constante cnt;

    Logica();

    ~Logica(){}

    void crearNiveles();

    void cNivel_0();

    void cNivel_1();

    void cNivel_2();

    string mostrarN0();

    string mostrarN1();

    string mostrarN2();

    string recorridoGeneral();

    bool movimiento(int idcolor, int idPieza, int x, int y, int z);

    bool moverPeon(int idcolor, int x, int y, int z); //--> FUNCION OK

    //-------PENDIENTE-----

    bool moverCaballo(int idcolor, int x, int y, int z);

    //-------END PENDIENTE----

    bool moverTorre(int idcolor, int x, int y, int z); //--> FUNCION OK

    bool moverAlfil(int idcolor, int x, int y, int z); //--> FUNCION OK

    bool moverRey(int idcolor, int x, int y, int z); //--> FUNCION OK

    bool moverDama(int idcolor, int x, int y, int z);//--> FUNCION OK

    string lineacion(bool isFila, int z, int dato);

    string mnivel(int nivel);

    string obtenerEjeY(int id);

    bool existeDama(int color);//REVISA EN LOS 3 TABLERO SI EXISTE LA DAMA DE ESE COLOR
    
    int noPiezas(int color);
};

#endif // LOGICA_H
