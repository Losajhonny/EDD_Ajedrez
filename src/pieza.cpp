#include "pieza.h"

Pieza::Pieza(int tipo_, int color_)
{
    tipo = tipo_;
    colors = color_;
    if(color_ == cnt.NEGRO){
        color = "black";
    }else if(color_ == cnt.BLANCO){
        color = "white";
    }
    asignarPath();
}

void Pieza::asignarPath()
{
    if(tipo == cnt.CABALLO && colors == cnt.BLANCO){
        path = cnt.CABALLO_BLANCO;
    }else if(tipo == cnt.CABALLO && colors == cnt.NEGRO){
        path = cnt.CABALLO_NEGRO;
    }else if(tipo == cnt.ALFIL && colors == cnt.BLANCO){
        path = cnt.ALFIL_BLANCO;
    }else if(tipo == cnt.ALFIL && colors == cnt.NEGRO){
        path = cnt.ALFIL_NEGRO;
    }else if(tipo == cnt.TORRE && colors == cnt.BLANCO){
        path = cnt.TORRE_BLANCO;
    }else if(tipo == cnt.TORRE && colors == cnt.NEGRO){
        path = cnt.TORRE_NEGRO;
    }else if(tipo == cnt.REY && colors == cnt.BLANCO){
        path = cnt.REY_BLANCO;
    }else if(tipo == cnt.REY && colors == cnt.NEGRO){
        path = cnt.REY_NEGRO;
    }else if(tipo == cnt.DAMA && colors == cnt.BLANCO){
        path = cnt.DAMA_BLANCO;
    }else if(tipo == cnt.DAMA && colors == cnt.NEGRO){
        path = cnt.DAMA_NEGRO;
    }else if(tipo == cnt.PEON && colors == cnt.BLANCO){
        path = cnt.PEON_BLANCO;
    }else if(tipo == cnt.PEON && colors == cnt.NEGRO){
        path = cnt.PEON_NEGRO;
    }
}

string Pieza::obtenerPieza()
{
    if(tipo == cnt.CABALLO){
        return "C";
    }else if(tipo == cnt.ALFIL){
        return "A";
    }else if(tipo == cnt.TORRE){
        return "T";
    }else if(tipo == cnt.REY){
        return "R";
    }else if(tipo == cnt.DAMA){
        return "D";
    }else if(tipo == cnt.PEON){
        return "P";
    }else{
        return "";
    }
}
