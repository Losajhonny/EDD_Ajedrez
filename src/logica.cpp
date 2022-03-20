#include "logica.h"
#include "stdlib.h"
#include "time.h"

Logica::Logica()
{
    matriz = new Ortogonal();
    crearNiveles();
}

void Logica::crearNiveles()
{
    cNivel_0();
    cNivel_1();
    cNivel_2();
}

void Logica::cNivel_0()
{
    for(int i = 1; i <= 8; i++){
        matriz->agregar(i, cnt.G, 0, new Pieza(cnt.PEON, cnt.NEGRO));
        matriz->agregar(i, cnt.B, 0, new Pieza(cnt.PEON, cnt.BLANCO));

        if(i == 1 || i == 8){
            matriz->agregar(i, cnt.H, 0, new Pieza(cnt.CABALLO, cnt.NEGRO));
            matriz->agregar(i, cnt.A, 0, new Pieza(cnt.CABALLO, cnt.BLANCO));
        }else if(i == 2 || i == 7){
            matriz->agregar(i, cnt.H, 0, new Pieza(cnt.ALFIL, cnt.NEGRO));
            matriz->agregar(i, cnt.A, 0, new Pieza(cnt.ALFIL, cnt.BLANCO));
        }else if(i == 3 || i == 6){
            matriz->agregar(i, cnt.H, 0, new Pieza(cnt.TORRE, cnt.NEGRO));
            matriz->agregar(i, cnt.A, 0, new Pieza(cnt.TORRE, cnt.BLANCO));
        }else if(i == 4){
            matriz->agregar(i, cnt.H, 0, new Pieza(cnt.REY, cnt.NEGRO));
            matriz->agregar(i, cnt.A, 0, new Pieza(cnt.REY, cnt.BLANCO));
        }else if(i == 5){
            matriz->agregar(i, cnt.H, 0, new Pieza(cnt.DAMA, cnt.NEGRO));
            matriz->agregar(i, cnt.A, 0, new Pieza(cnt.DAMA, cnt.BLANCO));
        }
    }
}

void Logica::cNivel_1()
{
    for(int i = 1; i <= 8; i++){
        if(i >= 1 && i <= 3){
            matriz->agregar(i, cnt.B, 1, new Pieza(cnt.PEON, cnt.BLANCO));
        }else if(i >= 6 && i <= 8){
            matriz->agregar(i, cnt.G, 1, new Pieza(cnt.PEON, cnt.NEGRO));
        }

        if(i == 1){
            matriz->agregar(i, cnt.A, 1, new Pieza(cnt.CABALLO, cnt.BLANCO));
        }else if(i == 2){
            matriz->agregar(i, cnt.A, 1, new Pieza(cnt.ALFIL, cnt.BLANCO));
        }else if(i == 3){
            matriz->agregar(i, cnt.A, 1, new Pieza(cnt.TORRE, cnt.BLANCO));
        }else if(i == 6){
            matriz->agregar(i, cnt.H, 1, new Pieza(cnt.TORRE, cnt.NEGRO));
        }else if(i == 7){
            matriz->agregar(i, cnt.H, 1, new Pieza(cnt.ALFIL, cnt.NEGRO));
        }else if(i == 8){
            matriz->agregar(i, cnt.H, 1, new Pieza(cnt.CABALLO, cnt.NEGRO));
        }
    }
}

void Logica::cNivel_2()
{
    for(int i = 1; i <= 8; i++){
        if(i >= 1 && i <= 3){
            matriz->agregar(i, cnt.G, 2, new Pieza(cnt.PEON, cnt.NEGRO));
        }else if(i >= 6 && i <= 8){
            matriz->agregar(i, cnt.B, 2, new Pieza(cnt.PEON, cnt.BLANCO));
        }

        if(i == 1){
            matriz->agregar(i, cnt.H, 2, new Pieza(cnt.CABALLO, cnt.NEGRO));
        }else if(i == 2){
            matriz->agregar(i, cnt.H, 2, new Pieza(cnt.ALFIL, cnt.NEGRO));
        }else if(i == 3){
            matriz->agregar(i, cnt.H, 2, new Pieza(cnt.TORRE, cnt.NEGRO));
        }else if(i == 6){
            matriz->agregar(i, cnt.A, 2, new Pieza(cnt.TORRE, cnt.BLANCO));
        }else if(i == 7){
            matriz->agregar(i, cnt.A, 2, new Pieza(cnt.ALFIL, cnt.BLANCO));
        }else if(i == 8){
            matriz->agregar(i, cnt.A, 2, new Pieza(cnt.CABALLO, cnt.BLANCO));
        }
    }
}

string Logica::mostrarN0()
{
    NodoEncabezado * temp = matriz->vertical->primero;
    Nodo * tmpy = 0;

    string info = "NIVEL 0\n\n";

    while(temp != 0){
        tmpy = temp->acceso;

        while (tmpy != 0) {
            if(tmpy->existe){
                info += to_string(tmpy->x) + "," + to_string(tmpy->y) + "," + to_string(tmpy->z) + "   ";
            }
            tmpy = tmpy->siguiente;
        }
        info += "\n";
        temp = temp->siguiente;
    }

    return info;
}

string Logica::mostrarN1()
{
    NodoEncabezado * temp = matriz->vertical->primero;
    Nodo * aux = 0;

    string info = "NIVEL 1\n\n";

    while(temp != 0){
        Nodo * tmp = temp->acceso;

        while(tmp != 0){
            aux = tmp;

            int zz = 0;

            while(aux != 0 && zz < 1){
                aux = aux->zarriba;
                zz++;
            }

            if(aux != 0){
                if(aux->existe){
                    info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "   ";
                }
                aux = 0;
            }
            tmp = tmp->siguiente;
        }

        info += "\n";
        temp = temp->siguiente;
    }
    return info;
}

string Logica::mostrarN2()
{
    NodoEncabezado * temp = matriz->vertical->primero;
    Nodo * aux;

    string info = "NIVEL 2\n\n";

    while(temp != 0){
        Nodo * tmp = temp->acceso;

        while(tmp != 0){
            aux = tmp;

            int zz = 0;

            while(aux != 0 && zz < 2){
                aux = aux->zarriba;
                zz++;
            }

            if(aux != 0){
                if(aux->existe){
                    info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "   ";
                }
                aux = 0;
            }
            tmp = tmp->siguiente;
        }
        info += "\n";
        temp = temp->siguiente;
    }
    return info;
}

string Logica::recorridoGeneral()
{
    string info;
    info += mostrarN0();
    info += "\n";
    info += mostrarN1();
    info += "\n";
    info += mostrarN2();

    return info;
}

string Logica::mnivel(int nivel)
{
    int y = 1;
    NodoEncabezado * tempy = matriz->vertical->primero;
    NodoEncabezado * tempu = 0; //uso externo
    Nodo * aux = 0;
    Nodo * ant = 0;
    string aux1;
    string aux2;

    string info = "digraph matriz{\n\tnode[shape=box, style=filled, color=Gray95];\n\tedge[color=black]; \n\trankdir=UD;";

    // Colocando encabezado horizontal x0 a x8

    info += "\n\n\t{rank=min;\"Matriz\";";

    tempu = matriz->horizontal->primero;
    while(tempu != 0){
        info += "\"" + to_string(tempu->id) + "\";";
        tempu = tempu->siguiente;
    }
    //for(int x = 1; x <= 8; x++){
    //    info += "\"" + to_string(x) + "\";";
    //}
    info += "};\n\n";

    // Colocando y0 ... yn con con los nodos siguiente ejemplo
    // y1 -> x,y="1,1" <-> x,y="2,1" <-> x,y="3,1" ..... <-> x,y="xn,yn"

    while(y <= 8){
        //info += "\t{rank=same;\"" + obtenerEjeY(y) + "\";";
        if(tempy != 0){
            info += "\t{rank=same;\"" + obtenerEjeY(tempy->id) + "\";";
            if(tempy->id == y){

                if(nivel == 1 || nivel == 2){
                    aux = matriz->buscarNodo(tempy, nivel, false);
                }else{
                    aux = tempy->acceso;
                }

                while(aux != 0){
                    if(aux->existe){
                        info += "\"" + obtenerEjeY(tempy->id) + to_string(aux->x) + " ";
                        if(aux->p != 0){
                            info += aux->p->obtenerPieza() + "\\n" + aux->p->color + "\";";
                        }else{
                            info += "\";";
                        }
                    }
                    aux = aux->siguiente;
                }
                tempy = tempy->siguiente;
            }
        }
        info += "};\n";
        y++;
    }
    info += "\n";

    // Colocando enlaces de los encabezados a los nodos accesos

    tempy = matriz->vertical->primero;
    aux = 0;

    while(tempy != 0){
        if(nivel == 1 || nivel == 2){
            aux = matriz->buscarNodo(tempy, nivel, false);
        }else{
            aux = tempy->acceso;
        }
        while(aux != 0){
            if(aux->existe){
                info += "\t\"" + obtenerEjeY(tempy->id) + "\"->\"" + obtenerEjeY(tempy->id) + to_string(aux->x) + " ";
                if(aux->p != 0){
                    info += aux->p->obtenerPieza() + "\\n" + aux->p->color + "\";";
                }else{
                    info += "\";";
                }
                info += "\n";
                break;
            }
            aux = aux->siguiente;
        }
        tempy = tempy->siguiente;
    }

    tempy = matriz->horizontal->primero; // ahora se transforma en tempx;
    aux = 0;

    while(tempy != 0){
        if(nivel == 1 || nivel == 2){
            aux = matriz->buscarNodo(tempy, nivel, true);
        }else{
            aux = tempy->acceso;
        }
        while(aux != 0){
            if(aux->existe){
                info += "\t\"" + to_string(tempy->id) + "\"->\"" + obtenerEjeY(aux->y) + to_string(aux->x) + " ";
                if(aux->p != 0){
                    info += aux->p->obtenerPieza() + "\\n" + aux->p->color + "\";";
                }else{
                    info += "\";";
                }
                info += "\n";
                break;
            }

            aux = aux->abajo;
        }
        tempy = tempy->siguiente;
    }
    info += "\n";

    //Colocando enlaces en pos X de los nodos de la matriz

    tempy = matriz->vertical->primero;
    aux = 0;

    while(tempy != 0){
        if(nivel == 1 || nivel == 2){
            aux = matriz->buscarNodo(tempy, nivel, false);
        }else{
            aux = tempy->acceso;
        }
        ant = aux;
        if(aux != 0){
            aux = aux->siguiente;
        }

        while(aux != 0){
            if(ant->existe){
                if(aux->existe){
                    aux1 = "\"" + obtenerEjeY(tempy->id) + to_string(ant->x) + " ";
                    if(ant->p != 0){
                        aux1 += ant->p->obtenerPieza() + "\\n" + ant->p->color + "\"";
                    }else{
                        aux1 += "\"";
                    }

                    aux2 = "\""+ obtenerEjeY(tempy->id) + to_string(aux->x) + " ";
                    if(aux->p != 0){
                        aux2 += aux->p->obtenerPieza() + "\\n" + aux->p->color + "\"";
                    }else{
                        aux2 += "\"";
                    }

                    info += "\t" + aux1 + "->" + aux2 + "\n";
                    info += "\t" + aux2 + "->" + aux1 + "\n";

                    ant = aux;
                }
            }else{
                ant = aux;
            }
            aux = aux->siguiente;
        }
        tempy = tempy->siguiente;
    }
    info += "\n";

    //Colocando enlaces en pos Y de los nodos de la matriz

    tempy = matriz->horizontal->primero; // Ahora recorrer desde encabezado x despues en y
    aux = 0;

    while(tempy != 0){
        if(nivel == 1 || nivel == 2){
            aux = matriz->buscarNodo(tempy, nivel, true);
        }else{
            aux = tempy->acceso;
        }
        ant = aux;
        if(aux != 0){
            aux = aux->abajo;
        }

        while(aux != 0){
            if(ant->existe){
                if(aux->existe){
                    aux1 = "\""+ obtenerEjeY(ant->y) + to_string(tempy->id) + " ";
                    if(ant->p != 0){
                        aux1 += ant->p->obtenerPieza() + "\\n" + ant->p->color + "\"";
                    }else{
                        aux1 += "\"";
                    }

                    aux2 = "\"" + obtenerEjeY(aux->y) + to_string(tempy->id) + " ";
                    if(aux->p != 0){
                        aux2 += aux->p->obtenerPieza() + "\\n" + aux->p->color + "\"";
                    }else{
                        aux2 += "\"";
                    }

                    info += "\t" + aux1 + "->" + aux2 + "\n";
                    info += "\t" + aux2 + "->" + aux1 + "\n";

                    ant = aux;
                }
            }else{
                ant = aux;
            }
            aux = aux->abajo;
        }
        tempy = tempy->siguiente;
    }
    info += "\n";

    //Colocando enlaces en los encabezados

    //info += "\t\"Matriz\"->\"1\";\n";
    //anterior = 1;

    //for(int x = 2; x <= 8; x++){
    //    info += "\t\"" + to_string(anterior) + "\"->\"" + to_string(x) + "\";\n";
    //    anterior = x;
    //}

    tempy = matriz->horizontal->primero;
    NodoEncabezado * nAnt = tempy;
    if(nAnt != 0){
        info += "\t\"Matriz\"->\"" + to_string(nAnt->id) + "\";\n";
    }
    tempy = tempy->siguiente;

    while(tempy != 0){
        info += "\t\"" + to_string(nAnt->id) + "\"->\"" + to_string(tempy->id) + "\";\n";
        nAnt = tempy;
        tempy = tempy->siguiente;
    }
    info += "\n";

    //info += "\t\"Matriz\"->\"H\"[rankdir=UD];\n";
    //anterior = 1;

    //for(int y = 2; y <= 8; y++){
    //    info += "\t\"" + obtenerEjeY(anterior) + "\"->\"" + obtenerEjeY(y) + "\"[rankdir=UD];\n";
    //    anterior = y;
    //}

    tempy = matriz->vertical->primero;
    nAnt = tempy;
    if(nAnt != 0){
        info += "\t\"Matriz\"->\"" + obtenerEjeY(nAnt->id) + "\"[rankdir=UD];\n";
    }
    tempy = tempy->siguiente;

    while(tempy != 0){
        info += "\t\"" + obtenerEjeY(nAnt->id) + "\"->\"" + obtenerEjeY(tempy->id) + "\"[rankdir=UD];\n";
        nAnt = tempy;
        tempy = tempy->siguiente;
    }

    info += "}";
    return info;
}

string Logica::obtenerEjeY(int id)
{
    if(id == cnt.A){
        return "A";
    }else if(id == cnt.B){
        return "B";
    }else if(id == cnt.C){
        return "C";
    }else if(id == cnt.D){
        return "D";
    }else if(id == cnt.E){
        return "E";
    }else if(id == cnt.F){
        return "F";
    }else if(id == cnt.G){
        return "G";
    }else if(id == cnt.H){
        return "H";
    }else{
        return "";
    }
}

bool Logica::existeDama(int color)
{
    NodoEncabezado * tempy = matriz->vertical->primero;
    Nodo * temp = 0;
    Nodo * aux = 0;

    while(tempy != 0){
        temp = tempy->acceso;

        while(temp != 0){
            aux = temp;

            while(aux != 0){
                if(aux->existe){
                    if(aux->p->colors == color && aux->p->tipo == cnt.DAMA)
                        return true;
                }
                aux = aux->zarriba;
            }
            temp = temp->siguiente;
        }
        tempy = tempy->siguiente;
    }
    return false;
}

int Logica::noPiezas(int color)
{
    int no = 0;
    NodoEncabezado * tempy = matriz->vertical->primero;
    Nodo * temp = 0;
    Nodo * aux = 0;

    while(tempy != 0){
        temp = tempy->acceso;

        while(temp != 0){
            aux = temp;

            while(aux != 0){
                if(aux->existe){
                    if(aux->p->colors == color)
                        no += 1;
                }
                aux = aux->zarriba;
            }
            temp = temp->siguiente;
        }
        tempy = tempy->siguiente;
    }
    return no;
}

bool Logica::movimiento(int idcolor, int idPieza, int x, int y, int z)
{
    bool movimiento = false;
    if(idPieza == cnt.PEON){
        movimiento = moverPeon(idcolor, x, y, z);
    }else if(idPieza == cnt.ALFIL){
        movimiento = moverAlfil(idcolor, x, y, z);
    }else if(idPieza == cnt.CABALLO){
        movimiento = moverCaballo(idcolor, x, y, z);
    }else if(idPieza == cnt.TORRE){
        movimiento = moverTorre(idcolor, x, y, z);
    }else if(idPieza == cnt.REY){
        movimiento = moverRey(idcolor, x, y, z);
    }else if(idPieza == cnt.DAMA){
        movimiento = moverDama(idcolor, x, y, z);
    }
    return movimiento;
}

bool Logica::moverPeon(int idcolor, int x, int y, int z)
{
    bool mov = false; bool bencontrado = false;
    NodoEncabezado * tempx = 0;
    Pieza * punteroPieza = 0;
    Nodo * busqueda = 0;
    Nodo * destino = 0;
    int xb = 0;
    int yb = 0;

    tempx = matriz->horizontal->buscar(x);
    if(tempx != 0){
        destino = matriz->existeXYZ(tempx->acceso, y, z);
    }

    if(!bencontrado){
        xb = x-1;
        yb = y-1;

        tempx = matriz->horizontal->buscar(xb);
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                    bencontrado = true;
                }
            }
        }

        if(!bencontrado){
            xb = x+1;
            yb = y-1;

            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }
                }
            }
        }

        if(bencontrado){
            xb = busqueda->x;
            yb = busqueda->y;
            punteroPieza = busqueda->p;
        }

        if(bencontrado){
            if(idcolor == cnt.NEGRO){//MOVER INCLINADO NEGRO
                bool sePuedeMover = false;
                if(busqueda->y != cnt.G){
                    Nodo * tb = 0;
                    if(z == 0){
                        tb = busqueda->zarriba;
                        while(tb != 0){
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                    break;
                                }
                            }
                            tb = tb->zarriba;
                        }
                    }else if(z == 2){
                        tb = busqueda->zabajo;
                        while(tb != 0){
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                    break;
                                }
                            }
                            tb = tb->zabajo;
                        }
                    }else if(z == 1){
                        tb = busqueda->zabajo;
                        if(tb->existe){
                            if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                sePuedeMover = true;
                            }
                        }
                        if(!sePuedeMover){
                            tb = busqueda->zarriba;
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                }
                            }
                        }
                    }

                    if(sePuedeMover){
                        if(destino != 0){
                            if(!destino->existe){
                                //SE PUEDE MOVER
                                matriz->eliminar(x, y, z);
                                matriz->eliminar(xb, yb, z);
                                matriz->agregar(x, y, z, punteroPieza);
                                mov = true;
                            }
                        }else{
                            // SE PUEDE MOVER
                            matriz->eliminar(xb, yb, z);
                            matriz->agregar(x, y, z, punteroPieza);
                            mov = true;
                        }
                    }
                }
                if(!sePuedeMover){
                    bencontrado = false;
                }
            }else if(idcolor == cnt.BLANCO){//CAPTURAR NEGRO
                if(destino != 0){
                    if(destino->existe){
                        if(destino->p->colors != idcolor){
                            //SE PUEDE CAPTURAR
                            matriz->eliminar(x, y, z);
                            matriz->eliminar(xb, yb, z);
                            matriz->agregar(x, y, z, punteroPieza);
                            mov = true;
                        }else{
                            bencontrado = false;
                        }
                    }else{
                        bencontrado = false;
                    }
                }else{
                    bencontrado = false;
                }
            }
        }
    }

    if(!bencontrado){
        xb = x;
        yb = y-1;

        tempx = matriz->horizontal->buscar(xb);
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                    bencontrado = true;
                }
            }
        }

        if(bencontrado){
            xb = busqueda->x;
            yb = busqueda->y;
            punteroPieza = busqueda->p;
        }

        if(bencontrado){
            if(idcolor == cnt.NEGRO){//MOVER HACIA EL FRENTE
                if(destino != 0){
                    if(!destino->existe){
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }else{
                        bencontrado = false;
                    }
                }else{
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }
        }
    }

    if(!bencontrado){
        xb = x-1;
        yb = y+1;

        tempx = matriz->horizontal->buscar(xb);
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                    bencontrado = true;
                }
            }
        }

        if(!bencontrado){
            xb = x+1;
            yb = y+1;

            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }
                }
            }
        }

        if(bencontrado){
            xb = busqueda->x;
            yb = busqueda->y;
            punteroPieza = busqueda->p;
        }

        if(bencontrado){
            if(idcolor == cnt.NEGRO){//CAPTURAR BLANCO
                if(destino != 0){
                    if(destino->existe){
                        if(destino->p->colors != idcolor){
                            //SE PUEDE CAPTURAR
                            matriz->eliminar(x, y, z);
                            matriz->eliminar(xb, yb, z);
                            matriz->agregar(x, y, z, punteroPieza);
                            mov = true;
                        }else{
                            bencontrado = false;
                        }
                    }else{
                        bencontrado = false;
                    }
                }else{
                    bencontrado = false;
                }
            }else if(idcolor == cnt.BLANCO){//MOVER INCLINADO BLANCO
                bool sePuedeMover = false;
                if(busqueda->y != cnt.B){
                    Nodo * tb = 0;
                    if(z == 0){
                        tb = busqueda->zarriba;
                        while(tb != 0){
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                    break;
                                }
                            }
                            tb = tb->zarriba;
                        }
                    }else if(z == 2){
                        tb = busqueda->zabajo;
                        while(tb != 0){
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                    break;
                                }
                            }
                            tb = tb->zabajo;
                        }
                    }else if(z == 1){
                        tb = busqueda->zabajo;
                        if(tb->existe){
                            if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                sePuedeMover = true;
                            }
                        }
                        if(!sePuedeMover){
                            tb = busqueda->zarriba;
                            if(tb->existe){
                                if(tb->p->tipo == cnt.PEON && tb->p->colors == idcolor){
                                    sePuedeMover = true;
                                }
                            }
                        }
                    }

                    if(sePuedeMover){
                        if(destino != 0){
                            if(!destino->existe){
                                //SE PUEDE MOVER
                                matriz->eliminar(x, y, z);
                                matriz->eliminar(xb, yb, z);
                                matriz->agregar(x, y, z, punteroPieza);
                                mov = true;
                            }
                        }else{
                            // SE PUEDE MOVER
                            matriz->eliminar(xb, yb, z);
                            matriz->agregar(x, y, z, punteroPieza);
                            mov = true;
                        }
                    }
                }

                if(!sePuedeMover){
                    bencontrado = false;
                }
            }
        }
    }

    if(!bencontrado){
        xb = x;
        yb = y+1;

        tempx = matriz->horizontal->buscar(xb);
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.PEON && busqueda->p->colors == idcolor){
                    bencontrado = true;
                }
            }
        }

        if(bencontrado){
            xb = busqueda->x;
            yb = busqueda->y;
            punteroPieza = busqueda->p;
        }

        if(bencontrado){
            if(idcolor == cnt.BLANCO){//MOVER HACIA EL FRENTE
                if(destino != 0){
                    if(!destino->existe){
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }else{
                        bencontrado = false;
                    }
                }else{
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }
        }
    }

    if(mov){ //SIGINIFICA QUE LA PIEZA SE MOVIO EN ALGUN LUGAR DEL TABLERO
        tempx = matriz->horizontal->buscar(x);
        if(tempx != 0){
            destino = matriz->existeXYZ(tempx->acceso, y, z);
        }

        if(destino != 0){
            if(destino->existe){
                if((destino->y == cnt.A && destino->p->colors == idcolor && idcolor == cnt.NEGRO)
                        || (destino->y == cnt.H && destino->p->colors == idcolor && idcolor == cnt.BLANCO)){
                    //PROMOCION DE LA PIEZA NEGRA
                    srand(time(NULL));
                    int posy = 1 + rand()%(9-1);
                    int posx = 1 + rand()%(9-1);

                    if(z == 0 || z == 1){
                        while(posy == 0 || posy == cnt.A || posy == cnt.H){
                            posy = 1 + rand()%(9-1);
                            posx = 1 + rand()%(9-1);
                            // verificar si existe pieza

                            NodoEncabezado * auxposx = matriz->horizontal->buscar(posx);
                            Nodo * auxverificar = 0;

                            if(auxposx != 0){
                                if(z == 0){
                                    auxverificar = matriz->existeXYZ(auxposx->acceso, posy, 1);
                                }else{
                                    auxverificar = matriz->existeXYZ(auxposx->acceso, posy, 2);
                                }
                            }

                            if(auxverificar != 0){
                                if(auxverificar->existe){
                                    posy = 0;
                                    posx = 0;
                                }
                            }
                        }

                        matriz->eliminar(destino->x, destino->y, z);
                        if(z == 0){
                            matriz->agregar(posx, posy, 1, punteroPieza);
                        }else if(z == 1){
                            matriz->agregar(posx, posy, 2, punteroPieza);
                        }

                    }else if(z == 2){
                        while(posy == 0 || posy == cnt.A || posy == cnt.H){
                            posy = 1 + rand()%(9-1);
                            posx = 1 + rand()%(9-1);
                            // verificar si existe pieza

                            NodoEncabezado * auxposx = matriz->horizontal->buscar(posx);
                            Nodo * auxverificar = 0;

                            if(auxposx != 0){
                                auxverificar = matriz->existeXYZ(auxposx->acceso, posy, 0);
                            }

                            if(auxverificar != 0){
                                if(auxverificar->existe){
                                    posy = 0;
                                    posx = 0;
                                }
                            }
                        }

                        punteroPieza = 0;
                        delete punteroPieza;

                        int idPieza = 1 + rand()%(7-1);

                        while(idPieza == cnt.DAMA){
                            idPieza = 1 + rand()%(7-1);
                        }

                        punteroPieza = new Pieza(idPieza, idcolor);

                        matriz->eliminar(destino->x, destino->y, z);
                        matriz->agregar(posx, posy, 0, punteroPieza);
                    }
                }
            }
        }
    }

    return mov;
}

bool Logica::moverCaballo(int idcolor, int x, int y, int z)
{
    bool mov = false;
    return mov;
}

bool Logica::moverTorre(int idcolor, int x, int y, int z)
{
    bool mov = false; bool bencontrado = false;
    NodoEncabezado * tempx = 0;
    Pieza * punteroPieza = 0;
    Nodo * destino = 0;
    Nodo * busqueda = 0;
    int xb =0;
    int yb = 0;

    tempx = matriz->horizontal->buscar(x);

    if(tempx != 0){
        destino = matriz->existeXYZ(tempx->acceso, y, z);
    }

    if(!bencontrado){
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, y, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.TORRE && idcolor == busqueda->p->colors){
                    bencontrado = true;
                }else{
                    busqueda = 0;
                    bencontrado = false;
                }
            }
        }
    }

    if(!bencontrado){
        int xb = x-1;
        int yb = y-1;

        while(xb >= 1 && yb >= cnt.H){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.TORRE && idcolor == busqueda->p->colors){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb--; yb--;
        }
    }

    if(!bencontrado){
        xb = x+1;
        yb = y-1;

        while(xb <= 8 && yb >= cnt.H){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.TORRE && idcolor == busqueda->p->colors){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb ++; yb --;
        }
    }

    if(!bencontrado){
        xb = x-1;
        yb = y+1;

        while(xb >= 1 && yb <= cnt.A){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.TORRE && idcolor == busqueda->p->colors){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb --; yb ++;
        }
    }

    if(!bencontrado){
        xb = x+1;
        yb = y+1;

        while(xb <= 8 && yb <= cnt.A){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.TORRE && idcolor == busqueda->p->colors){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb ++; yb ++;
        }
    }

    if(bencontrado){
        xb = busqueda->x;
        yb = busqueda->y;
        punteroPieza = busqueda->p;

        if(busqueda != destino){
            if(destino != 0){
                if(destino->existe){
                    if((destino->p->colors == cnt.NEGRO && idcolor == cnt.BLANCO) ||
                            (destino->p->colors == cnt.BLANCO && idcolor == cnt.NEGRO)){
                        //SI SON DIFERENTES EJEMPLO --NEGRO - BLANCO-- ó --BLANCO - NEGRO-- CAPTURAR
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }
                }else{
                    matriz->eliminar(x, y, z);
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }else{
                //SI NO EXISTE NINGUNA PIEZA EN DESTINO ENTONCES SOLO MOVER
                matriz->eliminar(x, y, z);
                matriz->eliminar(xb, yb, z);
                matriz->agregar(x, y, z, punteroPieza);
                mov = true;
            }
        }else{
            //PROMOCION DE LA TORRE
            if(busqueda != 0){
                Nodo * temp = 0;
                bencontrado = false;

                temp = busqueda->arriba;
                while(temp != 0){
                    if(temp->existe){
                        if(temp->p->tipo == cnt.TORRE && temp->p->colors == idcolor){
                            bencontrado = true;
                            break;
                        }
                    }
                    temp = temp->arriba;
                }

                if(!bencontrado){
                    temp = busqueda->anterior;

                    while(temp != 0){
                        if(temp->existe){
                            if(temp->p->tipo == cnt.TORRE && temp->p->colors == idcolor){
                                bencontrado = true;
                                break;
                            }
                        }
                        temp = temp->anterior;
                    }
                }

                if(!bencontrado){
                    temp = busqueda->siguiente;
                    while(temp != 0){
                        if(temp->existe){
                            if(temp->p->tipo == cnt.TORRE && temp->p->colors == idcolor){
                                bencontrado = true;
                                break;
                            }
                        }
                        temp = temp->siguiente;
                    }
                }

                if(!bencontrado){
                    temp = busqueda->abajo;
                    while(temp != 0){
                        if(temp->existe){
                            if(temp->p->tipo == cnt.TORRE && temp->p->colors == idcolor){
                                bencontrado = true;
                                break;
                            }
                        }
                        temp = temp->abajo;
                    }
                }

                if(bencontrado){

                    if(z == 0){
                        temp = busqueda;
                        if(temp->zarriba != 0){
                            if(!temp->zarriba->existe){
                                matriz->eliminar(x, y, z);
                                matriz->eliminar(x, y, z+1);
                                matriz->agregar(x, y, z+1, punteroPieza);
                                mov = true;
                            }
                        }else{
                            matriz->eliminar(x, y, z);
                            //matriz->eliminar(x, y, z+1);
                            matriz->agregar(x, y, z+1, punteroPieza);
                            mov = true;
                        }
                    }else if(z == 2){
                        temp = busqueda;
                        if(temp->zabajo != 0){
                            if(!temp->zabajo->existe){
                                matriz->eliminar(x, y, z);
                                matriz->eliminar(x, y, z-1);
                                matriz->agregar(x, y, z-1, punteroPieza);
                                mov = true;
                            }
                        }else{
                            matriz->eliminar(x, y, z);
                            //matriz->eliminar(x, y, z-1);
                            matriz->agregar(x, y, z-1, punteroPieza);
                            mov = true;
                        }
                    }else if(z == 1){
                        bool esabajo = false;
                        temp = busqueda;
                        if(temp->zabajo != 0){
                            if(!temp->zabajo->existe){
                                matriz->eliminar(x, y, z);
                                matriz->eliminar(x, y, z-1);
                                matriz->agregar(x, y, z-1, punteroPieza);
                                esabajo = true;
                                mov = true;
                            }
                        }else{
                            matriz->eliminar(x, y, z);
                            matriz->agregar(x, y, z-1, punteroPieza);
                            esabajo = true;
                            mov = true;
                        }

                        if(!esabajo){
                            if(temp->zarriba != 0){
                                if(!temp->zarriba->existe){
                                    matriz->eliminar(x, y, z);
                                    matriz->eliminar(x, y, z+1);
                                    matriz->agregar(x, y, z+1, punteroPieza);
                                    mov = true;
                                }
                            }else{
                                matriz->eliminar(x, y, z);
                                matriz->agregar(x, y, z+1, punteroPieza);
                                mov = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return mov;
}

bool Logica::moverAlfil(int idcolor, int x, int y, int z)
{
    bool mov = false; bool bencontrado = false;
    NodoEncabezado * tempx = 0;
    Pieza * punteroPieza = 0;
    Nodo * destino = 0;
    Nodo * busqueda = 0;
    int xb =0;
    int yb = 0;

    tempx = matriz->horizontal->buscar(x);

    if(tempx != 0){
        destino = matriz->existeXYZ(tempx->acceso, y, z);
    }

    if(!bencontrado){
        // xb = x; yb = y;
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, y, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.ALFIL && idcolor == busqueda->p->colors){
                    bencontrado = true;
                }else{
                    busqueda = 0;
                    bencontrado = false;
                }
            }
        }
    }

    if(!bencontrado){
        //RECORRER HACIA ARRIBA
        xb = x;
        yb = y-1;

        while(yb >= cnt.H){
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.ALFIL && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            yb --;
        }
    }

    if(!bencontrado){
        //RECORRER HACIA LA DERECHA
        xb = x-1;
        yb = y;

        while(xb >= 1){
            tempx = matriz->horizontal->buscar(xb);

            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.ALFIL && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb--;
        }
    }

    if(!bencontrado){
        //RECORRER HACIA LA IZQUIERDA
        xb = x+1;
        yb = y;

        while(xb <= 8){
            tempx = matriz->horizontal->buscar(xb);

            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.ALFIL && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb++;
        }
    }

    if(!bencontrado){
        //RECORRER HACIA ABAJO
        xb = x;
        yb = y+1;
        tempx = matriz->horizontal->buscar(xb);

        while(yb <= cnt.A){
           if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.ALFIL && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            yb++;
        }
    }

    if(bencontrado){
        xb = busqueda->x;
        yb = busqueda->y;
        punteroPieza = busqueda->p;

        if(busqueda != destino){
            if(destino != 0){
                if(destino->existe){
                    if((destino->p->colors == cnt.NEGRO && idcolor == cnt.BLANCO) ||
                            (destino->p->colors == cnt.BLANCO && idcolor == cnt.NEGRO)){
                        //SI SON DIFERENTES EJEMPLO --NEGRO - BLANCO-- ó --BLANCO - NEGRO-- CAPTURAR
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }
                }else{
                    //SI NO EXISTE NINGUNA PIEZA EN DESTINO ENTONCES SOLO MOVER
                    matriz->eliminar(x, y, z);
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }else{
                //SI NO EXISTE NINGUNA PIEZA EN DESTINO ENTONCES SOLO MOVER
                matriz->eliminar(xb, yb, z);
                matriz->agregar(x, y, z, punteroPieza);
                mov = true;
            }
        }else{
            // PROMOCION ALFIL
            xb = x;
            yb = y;
            tempx = matriz->horizontal->buscar(xb);

            bool hayAlfilDiagonal = false;
            Nodo * alfild = 0;

            //if(tempx != 0){
            //}
            while(yb >= cnt.H && xb >= 1){
                xb -= 1;
                yb -= 1;
                tempx = matriz->horizontal->buscar(xb);
                if(tempx != 0){
                    alfild = matriz->existeXYZ(tempx->acceso, yb, z);
                }else{
                    alfild = 0;
                }
                if(alfild != 0){
                    if(alfild->existe){
                        if(alfild->p->tipo == cnt.ALFIL && alfild->p->colors == idcolor){
                            hayAlfilDiagonal = true;
                            break;
                        }
                    }
                }
            }

            if(!hayAlfilDiagonal){
                xb = x;
                yb = y;
                while(yb >= cnt.H && xb <= 8){
                    xb += 1;
                    yb -= 1;
                    tempx = matriz->horizontal->buscar(xb);
                    if(tempx != 0){
                        alfild = matriz->existeXYZ(tempx->acceso, yb, z);
                    }else{
                        alfild = 0;
                    }
                    if(alfild != 0){
                        if(alfild->existe){
                            if(alfild->p->tipo == cnt.ALFIL && alfild->p->colors == idcolor){
                                hayAlfilDiagonal = true;
                                break;
                            }
                        }
                    }
                }
            }

            if(!hayAlfilDiagonal){
                xb = x;
                yb = y;
                while(yb <= cnt.A && xb >= 1){
                    xb -= 1;
                    yb += 1;
                    tempx = matriz->horizontal->buscar(xb);
                    if(tempx != 0){
                        alfild = matriz->existeXYZ(tempx->acceso, yb, z);
                    }else{
                        alfild = 0;
                    }
                    if(alfild != 0){
                        if(alfild->existe){
                            if(alfild->p->tipo == cnt.ALFIL && alfild->p->colors == idcolor){
                                hayAlfilDiagonal = true;
                                break;
                            }
                        }
                    }
                }
            }

            if(!hayAlfilDiagonal){
                xb = x;
                yb = y;
                while(yb <= cnt.A && xb <= 8){
                    xb += 1;
                    yb += 1;
                    tempx = matriz->horizontal->buscar(xb);
                    if(tempx != 0){
                        alfild = matriz->existeXYZ(tempx->acceso, yb, z);
                    }else{
                        alfild = 0;
                    }
                    if(alfild != 0){
                        if(alfild->existe){
                            if(alfild->p->tipo == cnt.ALFIL && alfild->p->colors == idcolor){
                                hayAlfilDiagonal = true;
                                break;
                            }
                        }
                    }
                }
            }

            Nodo * nocupado = 0;
            tempx = matriz->horizontal->buscar(x);

            if(hayAlfilDiagonal){
                int zmov = -1;
                if(tempx != 0){
                    if(z == 0){
                        nocupado = matriz->existeXYZ(tempx->acceso, y, z+1);
                        zmov = z+1;
                    }else if(z == 2){
                        nocupado = matriz->existeXYZ(tempx->acceso, y, z-1);
                        zmov = z-1;
                    }else if(z == 1){
                        nocupado = matriz->existeXYZ(tempx->acceso, y, z-1);
                        zmov = z-1;
                        if(nocupado == 0){
                            nocupado = matriz->existeXYZ(tempx->acceso, y, z+1);
                            zmov = z+1;
                        }
                    }
                }
                if(zmov != -1){
                    if(nocupado != 0){
                        if(!nocupado->existe){
                            //SI NO EXISTE ENTONCES SE PUEDE MOVER
                            matriz->eliminar(x, y, z);
                            matriz->eliminar(x, y, zmov);
                            matriz->agregar(x, y, zmov, punteroPieza);
                            mov = true;
                        }
                    }else{
                        //COMO ESE NODO NO ESTA OCUPADO ENTONCES SE PUEDE MOVER
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, zmov, punteroPieza);
                        mov = true;
                    }
                }
            }
        }
    }
    return mov;
}

bool Logica::moverRey(int idcolor, int x, int y, int z)
{
    bool mov = false; bool bencontrado = false;
    NodoEncabezado * tempx = 0;
    Pieza * punteroPieza = 0;
    Nodo * destino = 0;
    Nodo * busqueda = 0;
    int xb =0;
    int yb = 0;

    tempx = matriz->horizontal->buscar(x);
    if(tempx != 0){
        destino = matriz->existeXYZ(tempx->acceso, y, z);
    }
    //VERIFICANDO SI ESTA EN LA MISMA POSICION
    if(!bencontrado){
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, y, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.REY && idcolor == busqueda->p->colors){
                    bencontrado = true;
                }else{
                    busqueda = 0;
                    bencontrado = false;
                }
            }
        }
    }

    //VERIFICANDO DIAGONAL HACIA ARRIBA IZQUIERDA
    if(!bencontrado){
        xb = x-1;
        yb = y-1;

        while(xb >= 1 && yb >= cnt.H){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb--; yb--;
        }
    }

    //VERIFICANDO HACIA ARRIBA DEL NODO DESTINO
    if(!bencontrado){
        xb = x;
        yb = y-1;
        tempx = matriz->horizontal->buscar(xb);

        while(yb >= cnt.H){
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            yb--;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ARRIBA DERECHA
    if(!bencontrado){
        xb = x+1;
        yb = y-1;

        while(xb <= 8 && yb >= cnt.H){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb++; yb--;
        }
    }

    //VERIFICANDO HACIA LA DERECHA
    if(!bencontrado){
        xb = x-1;
        yb = y;

        while(xb >= 1){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb--;
        }
    }

    //VERIFICANDO HACIA LA IZQUIERDA
    if(!bencontrado){
        xb = x+1;
        yb = y;

        while(xb <= 8){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb++;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ABAJO IZQUIERDA
    if(!bencontrado){
        xb = x-1;
        yb = y+1;

        while(xb >= 1 && yb <= cnt.A){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb--; yb++;
        }
    }

    //VERIFICANDO HACIA ABAJO
    if(!bencontrado){
        xb = x;
        yb = y+1;

        while(yb <= cnt.A){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            yb++;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ABAJO DERECHA
    if(!bencontrado){
        xb = x+1;
        yb = y+1;

        while(xb <= 8 && yb <= cnt.A){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.REY && busqueda->p->colors == idcolor){
                        bencontrado = true;
                    }else{
                        busqueda = 0;
                        bencontrado = false;
                    }
                    break;
                }
            }
            xb++; yb++;
        }
    }

    if(bencontrado){
        xb = busqueda->x;
        yb = busqueda->y;
        punteroPieza = busqueda->p;
    }

    //ANALIZANDO EL MOVIMIENTO
    if(bencontrado){
        if(busqueda != destino){
            if(destino != 0){
                if(destino->existe){
                    if((destino->p->colors == cnt.NEGRO && idcolor == cnt.BLANCO) ||
                            (destino->p->colors == cnt.BLANCO && idcolor == cnt.NEGRO)){
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }
                }else{
                    matriz->eliminar(x, y, z);
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }else{
                //SI NO EXISTE ENTONCES SOLO MOVER
                matriz->eliminar(xb, yb, z);
                matriz->agregar(x, y, z, punteroPieza);
                mov = true;
            }
        }else{
            //ANALIZAR PROMOCION -- MOV HACIA ARRIBA O ABAJO
            if(z == 0){
                if(busqueda->zarriba != 0){
                    if(!busqueda->zarriba->existe){
                        matriz->eliminar(x, y, 1);
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, 1, punteroPieza);
                        mov = true;
                    }
                }else{
                    matriz->eliminar(x, y, z);
                    matriz->agregar(x, y, 1, punteroPieza);
                    mov = true;
                }
            }else if(z == 2){
                if(busqueda->zabajo != 0){
                    if(!busqueda->zabajo->existe){
                        matriz->eliminar(x, y, 1);
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, 1, punteroPieza);
                        mov = true;
                    }
                }else{
                    matriz->eliminar(x, y, z);
                    matriz->agregar(x, y, 1, punteroPieza);
                    mov = true;
                }
            }else if(z == 1){
                Nodo * btemp = busqueda->zabajo;
                bool permitirMov = false;
                int zmov = z;

                if(btemp != 0){
                    if(!btemp->existe){
                        permitirMov = true;
                        zmov = 0;
                    }
                }else{
                    permitirMov = true;
                    zmov = 0;
                }

                if(!permitirMov){
                    btemp = busqueda->zarriba;

                    if(btemp != 0){
                        if(!btemp->existe){
                            permitirMov = true;
                            zmov = 2;
                        }
                    }else{
                        permitirMov = true;
                        zmov = 2;
                    }
                }

                if(permitirMov){
                    matriz->eliminar(x, y, zmov);
                    matriz->eliminar(x, y, z);
                    matriz->agregar(x, y, zmov, punteroPieza);
                    mov = true;
                }
            }
        }
    }
    return mov;
}

bool Logica::moverDama(int idcolor, int x, int y, int z)
{
    bool mov = false; bool bencontrado = false;
    NodoEncabezado * tempx = 0;
    Pieza * punteroPieza = 0;
    Nodo * destino = 0;
    Nodo * busqueda = 0;
    int xb =0;
    int yb = 0;
    int noMax = 0;

    tempx = matriz->horizontal->buscar(x);
    if(tempx != 0){
        destino = matriz->existeXYZ(tempx->acceso, y, z);
    }
    //VERIFICANDO SI ESTA EN LA MISMA POSICION
    if(!bencontrado){
        if(tempx != 0){
            busqueda = matriz->existeXYZ(tempx->acceso, y, z);
        }
        if(busqueda != 0){
            if(busqueda->existe){
                if(busqueda->p->tipo == cnt.DAMA && idcolor == busqueda->p->colors){
                    bencontrado = true;
                }
            }
        }
    }

    //VERIFICANDO DIAGONAL HACIA ARRIBA IZQUIERDA
    if(!bencontrado){
        xb = x-1;
        yb = y-1;

        while(xb >= 1 && yb >= cnt.H && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb--; yb--; noMax++;
        }
    }

    //VERIFICANDO HACIA ARRIBA DEL NODO DESTINO
    if(!bencontrado){
        noMax = 0;
        xb = x;
        yb = y-1;
        tempx = matriz->horizontal->buscar(xb);

        while(yb >= cnt.H && noMax < 2){
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            yb--; noMax++;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ARRIBA DERECHA
    if(!bencontrado){
        noMax = 0;
        xb = x+1;
        yb = y-1;

        while(xb <= 8 && yb >= cnt.H && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb++; yb--; noMax++;
        }
    }

    //VERIFICANDO HACIA LA DERECHA
    if(!bencontrado){
        noMax = 0;
        xb = x-1;
        yb = y;

        while(xb >= 1 && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb--; noMax++;
        }
    }

    //VERIFICANDO HACIA LA IZQUIERDA
    if(!bencontrado){
        noMax = 0;
        xb = x+1;
        yb = y;

        while(xb <= 8 && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb++; noMax++;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ABAJO IZQUIERDA
    if(!bencontrado){
        noMax = 0;
        xb = x-1;
        yb = y+1;

        while(xb >= 1 && yb <= cnt.A && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb--; yb++; noMax++;
        }
    }

    //VERIFICANDO HACIA ABAJO
    if(!bencontrado){
        noMax = 0;
        xb = x;
        yb = y+1;

        while(yb <= cnt.A && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            yb++; noMax++;
        }
    }

    //VERIFICANDO DIAGONAL HACIA ABAJO DERECHA
    if(!bencontrado){
        noMax = 0;
        xb = x+1;
        yb = y+1;

        while(xb <= 8 && yb <= cnt.A && noMax < 2){
            tempx = matriz->horizontal->buscar(xb);
            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->tipo == cnt.DAMA && busqueda->p->colors == idcolor){
                        bencontrado = true;
                        break;
                    }
                }
            }
            xb++; yb++; noMax++;
        }
    }

    if(bencontrado){
        xb = busqueda->x;
        yb = busqueda->y;
        punteroPieza = busqueda->p;
    }

    //ANALIZANDO EL MOVIMIENTO
    if(bencontrado){
        if(busqueda != destino){
            if(destino != 0){
                if(destino->existe){
                    if((destino->p->colors == cnt.NEGRO && idcolor == cnt.BLANCO) ||
                            (destino->p->colors == cnt.BLANCO && idcolor == cnt.NEGRO)){
                        //CAPTURAR
                        matriz->eliminar(x, y, z);
                        matriz->eliminar(xb, yb, z);
                        matriz->agregar(x, y, z, punteroPieza);
                        mov = true;
                    }
                }else{//SOLO MOVER
                    matriz->eliminar(x, y, z);
                    matriz->eliminar(xb, yb, z);
                    matriz->agregar(x, y, z, punteroPieza);
                    mov = true;
                }
            }else{
                //SI NO EXISTE ENTONCES SOLO MOVER
                matriz->eliminar(xb, yb, z);
                matriz->agregar(x, y, z, punteroPieza);
                mov = true;
            }
        }else{
            //ANALIZAR PROMOCION -- MOV HACIA ARRIBA O ABAJO
            bencontrado = false;
            int xxb = x-1;
            int yyb = y-1;

            tempx = matriz->horizontal->buscar(xxb);

            if(tempx != 0){
                busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
            }
            if(busqueda != 0){
                if(busqueda->existe){
                    if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                        bencontrado = true;
                    }
                }
            }

            if(!bencontrado){
                xxb = x;
                yyb = y-1;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }

            }

            if(!bencontrado){
                xxb = x+1;
                yyb = y-1;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }
            }

            if(!bencontrado){
                xxb = x-1;
                yyb = y;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }
            }

            if(!bencontrado){
                xxb = x+1;
                yyb = y;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }

            }

            if(!bencontrado){
                xxb = x-1;
                yyb = y+1;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }

            }

            if(!bencontrado){
                xxb = x;
                yyb = y+1;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }
            }

            if(!bencontrado){
                xxb = x+1;
                yyb = y+1;

                tempx = matriz->horizontal->buscar(xxb);

                if(tempx != 0){
                    busqueda = matriz->existeXYZ(tempx->acceso, yyb, z);
                }
                if(busqueda != 0){
                    if(busqueda->existe){
                        if(busqueda->p->colors == idcolor && busqueda->p->tipo == cnt.REY){
                            bencontrado = true;
                        }
                    }
                }

            }

            if(bencontrado){
                //SE PUEDE MOVER HACIA ARRIBA O ABAJO
                if(z == 0){
                    busqueda = 0;
                    tempx = matriz->horizontal->buscar(x);
                    if(tempx != 0){
                        busqueda = matriz->existeXYZ(tempx->acceso, y, z);
                    }

                    if(busqueda->zarriba != 0){
                        if(!busqueda->existe){
                            matriz->eliminar(x, y, z);
                            matriz->eliminar(x, y, 1);
                            matriz->agregar(x, y, 1, punteroPieza);
                            mov = true;
                        }
                    }else{
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, 1, punteroPieza);
                        mov = true;
                    }
                }else if(z == 2){
                    busqueda = 0;
                    tempx = matriz->horizontal->buscar(x);
                    if(tempx != 0){
                        busqueda = matriz->existeXYZ(tempx->acceso, y, z);
                    }

                    if(busqueda->zabajo != 0){
                        if(!busqueda->existe){
                            matriz->eliminar(x, y, z);
                            matriz->eliminar(x, y, 1);
                            matriz->agregar(x, y, 1, punteroPieza);
                            mov = true;
                        }
                    }else{
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, 1, punteroPieza);
                        mov = true;
                    }
                }else if(z == 1){
                    busqueda = 0;
                    tempx = matriz->horizontal->buscar(x);
                    if(tempx != 0){
                        busqueda = matriz->existeXYZ(tempx->acceso, y, z);
                    }

                    Nodo * btemp = busqueda->zabajo;
                    bool permitirMov = false;
                    int zmov = z;

                    if(btemp != 0){
                        if(!btemp->existe){
                            permitirMov = true;
                            zmov = 0;
                        }
                    }else{
                        permitirMov = true;
                        zmov = 0;
                    }

                    if(!permitirMov){
                        btemp = busqueda->zarriba;

                        if(btemp != 0){
                            if(!btemp->existe){
                                permitirMov = true;
                                zmov = 2;
                            }
                        }else{
                            permitirMov = true;
                            zmov = 2;
                        }
                    }

                    if(permitirMov){
                        matriz->eliminar(x, y, zmov);
                        matriz->eliminar(x, y, z);
                        matriz->agregar(x, y, zmov, punteroPieza);
                        mov = true;
                    }
                }
            }
        }
    }
    return mov;
}

string Logica::lineacion(bool isFila, int z, int dato)
{
    string info = "digraph reportelineacion{\n";
    NodoEncabezado * temp = 0;
    Nodo * aux = 0;
    // Si es fila o columna isFila
    // dato es cual posicion es
    if(isFila){
        info += "rankdir=LR;\n";
        temp = matriz->vertical->buscar(dato);
        if(temp != 0){
            aux = matriz->buscarNodo(temp, z, false);
        }
        int size = 0;

        while(aux != 0){
            if(aux->existe){
                info += to_string(size) + "[label=\"" + aux->p->obtenerPieza() + "\\n" + aux->p->color + "\"];\n";
                size += 1;
            }
            aux = aux->siguiente;
        }
        int sizeant = 0;
        int sizeactual = 1;
        while(sizeactual < size){
            info += to_string(sizeant) + "->" + to_string(sizeactual) + ";\n";
            info += to_string(sizeactual) + "->" + to_string(sizeant) + ";\n";
            sizeant ++;
            sizeactual ++;
        }
    }else{
        temp = matriz->horizontal->buscar(dato);
        if(temp != 0){
            aux = matriz->buscarNodo(temp, z, true);
        }

        int size = 0;

        while(aux != 0){
            info += to_string(size) + "[label=\"" + aux->p->obtenerPieza() + "\\n" + aux->p->color + "\"];\n";
            size += 1;
            aux = aux->abajo;
        }
        int sizeant = 0;
        int sizeactual = 1;
        while(sizeactual < size){
            info += to_string(sizeant) + "->" + to_string(sizeactual) + ";\n";
            info += to_string(sizeactual) + "->" + to_string(sizeant) + ";\n";
            sizeant ++;
            sizeactual ++;
        }
    }
    info += "}";
    return info;
}
