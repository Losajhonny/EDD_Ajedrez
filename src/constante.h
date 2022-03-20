#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "string"
using namespace std;

struct Constante{
    // Representacion Piezas del tablero
    const int REY = 1;
    const int DAMA = 2;
    const int PEON = 3;
    const int CABALLO = 4;
    const int ALFIL = 5;
    const int TORRE = 6;

    //Representacion de H-A en numeros
    const int A = 8;
    const int B = 7;
    const int C = 6;
    const int D = 5;
    const int E = 4;
    const int F = 3;
    const int G = 2;
    const int H = 1;

    //Representacion de imagenes por color de piezas -PATH-
    const string PEON_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\peon_negro.png";
    const string PEON_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\peon_blanco.png";

    const string CABALLO_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\caballo_negro.png";
    const string CABALLO_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\caballo_blanco.png";

    const string ALFIL_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\alfil_negro.png";
    const string ALFIL_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\alfil_blanco.png";

    const string TORRE_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\torre_negro.png";
    const string TORRE_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\torre_blanco.png";

    const string REY_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\rey_negro.png";
    const string REY_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\rey_blanco.png";

    const string DAMA_NEGRO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\dama_negro.png";
    const string DAMA_BLANCO = "C:\\Users\\jhonny\\Desktop\\EDD_vacas_\\[EDD]Proyect1_201325583\\piezas\\dama_blanco.png";

    // Colores de las piezas
    const int NEGRO = 0;
    const int BLANCO = 1;
};

#endif // CONSTANTE_H
