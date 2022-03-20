#ifndef PIEZA_H
#define PIEZA_H

#include "constante.h"

struct Pieza{
    int tipo;
    string color;
    int colors;
    string path;
    Constante cnt;

    Pieza(int tipo_, int color_);

    void asignarPath();

    string obtenerPieza();

    ~Pieza(){}
};

#endif // PIEZA_H
