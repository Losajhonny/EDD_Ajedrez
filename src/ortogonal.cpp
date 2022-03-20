#include "ortogonal.h"

bool Encabezado::isEmpty()
{
    if(primero == 0)
        return true;
    return false;
}

void Encabezado::add(NodoEncabezado *nuevo)
{
    if(isEmpty()){
        primero = nuevo;
        ultimo = primero;
    }else{
        if(nuevo->id < primero->id){
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        }else if(nuevo->id > ultimo->id){
            nuevo->anterior = ultimo;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }else{
            NodoEncabezado * temp = primero;
            NodoEncabezado * aux;

            while(temp->id < nuevo->id){
                temp = temp->siguiente;
            }

            aux = temp->anterior;
            if(aux != 0){
                aux->siguiente = nuevo;
            }
            if(temp != 0){
                temp->anterior = nuevo;
            }
            if(temp == primero){
                primero = temp->anterior;
            }
            nuevo->siguiente = temp;
            nuevo->anterior = aux;
        }
    }
}

NodoEncabezado *Encabezado::buscar(int id)
{
    NodoEncabezado * temp = primero;

    while(temp != 0){
        if(temp->id == id)
            return temp;
        temp = temp->siguiente;
    }
    return 0;
}

void Encabezado::deleteEncabezado(int id)
{
    NodoEncabezado * temp = primero;
    while(temp != 0){
        if(temp->id == id){
            NodoEncabezado * ant = temp->anterior;
            NodoEncabezado * sig = temp->siguiente;

            if(ant != 0){
                ant->siguiente = sig;
            }
            if(sig != 0){
                sig->anterior = ant;
            }
            temp = 0;
            delete temp;
            break;
        }
        temp = temp->siguiente;
    }
}

string Encabezado::recorrer()
{
    NodoEncabezado * temp = primero;
    string info;

    while(temp != 0){
        info += to_string(temp->id) + "\n";
        temp = temp->siguiente;
    }

    return info;
}

Ortogonal::Ortogonal()
{
    horizontal = new Encabezado();
    vertical = new Encabezado();
}

void Ortogonal::agregar(int x, int y, int z, Pieza *p)
{
    agregar(x, y, z, p, true);
}

// Valido solo para que z este en los valores [0 <= z <= 2]

void Ortogonal::agregar(int x, int y, int z, Pieza *p, bool existe)
{
    NodoEncabezado * tempx = horizontal->buscar(x);
    NodoEncabezado * tempy = vertical->buscar(y);

    if(tempx == 0){
        NodoEncabezado * n = new NodoEncabezado(x);
        horizontal->add(n);
        tempx = n;
    }
    if(tempy == 0){
        NodoEncabezado * nl = new NodoEncabezado(y);
        vertical->add(nl);
        tempy = nl;
    }

    Nodo * busqueda = existeXY(tempx->acceso, y);
    Nodo * nuevo;// = new Nodo(x, y, z, existe, p);

    if(busqueda == 0){
        // ingresear los temporales en orden
        if(z == 0){
            nuevo = new Nodo(x, y, z, existe, p);
            enlaceInicio(nuevo, tempx, tempy, x, y);
        }else if(z == 1){
            agregar(x, y, z-1, 0, false);
            agregar(x, y, z, p, true);
        }else if(z == 2){
            agregar(x, y, z-2, 0, false);
            agregar(x, y, z-1, 0, false);
            agregar(x, y, z, p, true);
        }
    }else{
        Nodo * auxx = 0; // es el acceso en x desde un nivell cualquiera
        Nodo * auxy = 0; // `` ``   ``   `` y  ``   ``   ``      ``

        Nodo * nodoz = existeXYZ(tempx->acceso, y, z);

        if(nodoz == 0){ // si no existe entonces crear nodo y enlazar en todas
            // sus direcciones.

            if(z == 2){
                nodoz = existeXYZ(tempx->acceso, y, z-1);
                if(nodoz == 0){
                    agregar(x, y, z-1, p, false);
                }
            }

            nuevo = new Nodo(x, y, z, existe, p);
            //auxx = buscarNodo(tempx, z, true);
            //auxy = buscarNodo(tempy, z, false);

            //enlazar(nuevo, auxx, auxy, x, y);
            enlazar(nuevo, tempx, tempy, x, y, z);

            while(busqueda->zarriba != 0){
                busqueda = busqueda->zarriba;
            }

            busqueda->zarriba = nuevo;
            nuevo->zabajo = busqueda;
        }else{
            nodoz->existe = existe;
            nodoz->p = p;
        }
    }
}

void Ortogonal::eliminar(int x, int y, int z)
{
    eliminar(x, y, z, false);
}

//false es por que no se ha eliminado el nodo
void Ortogonal::eliminar(int x, int y, int z, bool eliminado)
{
    if(z >= 0 && z <= 2){
        NodoEncabezado * tempx = horizontal->buscar(x);

        Nodo * xyz = existeXYZ(tempx->acceso, y, z);

        Nodo * narriba = 0;
        Nodo * nabajo = 0;
        Nodo * nizq = 0;
        Nodo * nder = 0;

        if(xyz != 0){
            narriba = xyz->arriba;
            nabajo = xyz->abajo;
            nizq = xyz->anterior;
            nder = xyz->siguiente;
        }

        if(xyz != 0){
            if(xyz->zarriba != 0){
                xyz->existe = false;
                xyz->p = 0;
            }else{
                if(!eliminado){
                    if(narriba != 0){
                        narriba->abajo = nabajo;
                    }
                    if(nabajo != 0){
                        nabajo->arriba = narriba;
                    }
                    if(nizq != 0){
                        nizq->siguiente = nder;
                    }
                    if(nder != 0){
                        nder->anterior = nizq;
                    }

                    if(xyz->zabajo != 0){
                        xyz->zabajo->zarriba = 0;
                    }

                    NodoEncabezado * tempy = vertical->buscar(y);

                    if(xyz == tempy->acceso){
                        tempy->acceso = tempy->acceso->siguiente;
                    }
                    if(xyz == tempx->acceso){
                        tempx->acceso = tempx->acceso->abajo;
                    }
                    if(tempy->acceso == 0){
                        vertical->deleteEncabezado(tempy->id);
                    }
                    if(tempx->acceso == 0){
                        horizontal->deleteEncabezado(tempx->id);
                    }

                    xyz = 0;
                    delete xyz;
                    eliminar(x, y, z-1, true);
                }else{
                    if(!xyz->existe){
                        eliminar(x, y, z, false);
                    }
                }
            }
        }
    }
}

Nodo *Ortogonal::existeXYZ(Nodo *tempx, int y, int z)
{
    Nodo * temp = tempx;

    while(temp != 0){
        if(temp->y == y){
            Nodo * tmp = temp;
            while(tmp != 0){
                if(tmp->z == z)
                    return tmp;
                tmp = tmp->zarriba;
            }
        }
        temp = temp->abajo;
    }
    return 0;
}

Nodo *Ortogonal::buscarNodo(NodoEncabezado *tempx, int z, bool isX)
{
    Nodo * tmpx = tempx->acceso;
    Nodo * auxx = 0;
    while (tmpx != 0) {
        auxx = tmpx;

        int zz = 0;
        while(auxx != 0 && zz < z){
            zz++;
            auxx = auxx->zarriba;
        }

        if(auxx != 0){
            break;
        }

        if(isX){
            tmpx = tmpx->abajo;
        }else{
            tmpx = tmpx->siguiente;
        }
    }
    return auxx;
}

// --------------------------FUNCIONA------------------------------

Nodo *Ortogonal::verificarEncima(Nodo *tempy, int y)
{
    Nodo * temp = tempy;
    int cont = y - 1;
    if(temp != 0){
        while(temp->abajo != 0){
            if(temp->abajo->y > cont){
                if(temp->y <= cont)
                    return temp;
                return 0;
            }
            temp = temp->abajo;
        }
        if(temp->y <= cont)
            return temp;
    }
    return 0;
}

Nodo *Ortogonal::verificarIzquierda(Nodo *tempx, int x)
{
    Nodo * temp = tempx;
    int cont = x-1;

    if(temp != 0){
        while(temp->siguiente != 0){
            if(temp->siguiente->x > cont){
                if(temp->x <= cont)
                    return temp;
                return 0;
            }
            temp = temp->siguiente;
        }
        if(temp->x <= cont)
            return temp;
    }
    return 0;
}

Nodo *Ortogonal::verificarDerecha(Nodo *tempx, int x)
{
    Nodo * temp = tempx;
    int cont = x;


    while(temp != 0){
        if(temp->x > cont){
            break;
        }
        temp = temp->siguiente;
    }
    return temp;
}

Nodo *Ortogonal::verificarAbajo(Nodo *tempy, int y)
{
    Nodo * temp = tempy;
    int cont = y;

    while(temp != 0){
        if(temp->y > cont){
            break;
        }
        temp = temp->abajo;
    }
    return temp;
}

Nodo *Ortogonal::existeXY(Nodo *tempx, int y)
{
    if(tempx != 0){
        Nodo * temp = tempx;
        while (temp != 0) {
            if(temp->y == y)
                return temp;
            temp = temp->abajo;
        }
    }
    return 0;
}

void Ortogonal::enlazar(Nodo *nuevo, NodoEncabezado *xn, NodoEncabezado *yn, int x, int y, int z)
{
    Nodo * auxx = buscarNodo(xn, z, true);
    Nodo * auxy = buscarNodo(yn, z, false);

    Nodo * encima = verificarEncima(auxx, y);
    Nodo * abajo = verificarAbajo(auxx, y);
    Nodo * izq = verificarIzquierda(auxy, x);
    Nodo * der = verificarDerecha(auxy, x);

    if(encima != 0){
        nuevo->arriba = encima;
        encima->abajo = nuevo;
    }
    if(abajo != 0){
        nuevo->abajo = abajo;
        abajo->arriba = nuevo;
    }
    if(izq != 0){
        nuevo->anterior = izq;
        izq->siguiente = nuevo;
    }
    if(der != 0){
        nuevo->siguiente = der;
        der->anterior = nuevo;
    }
}

void Ortogonal::enlaceInicio(Nodo *nuevo, NodoEncabezado *xn, NodoEncabezado *yn, int x, int y)
{
    Nodo * encima = verificarEncima(xn->acceso, y);
    Nodo * abajo = verificarAbajo(xn->acceso, y);
    Nodo * izq = verificarIzquierda(yn->acceso, x);
    Nodo * der = verificarDerecha(yn->acceso, x);

    if(encima != 0){
        nuevo->arriba = encima;
        encima->abajo = nuevo;
    }else{
        xn->acceso = nuevo;
    }
    if(abajo != 0){
        nuevo->abajo = abajo;
        abajo->arriba = nuevo;
    }
    if(izq != 0){
        nuevo->anterior = izq;
        izq->siguiente = nuevo;
    }else{
        yn->acceso = nuevo;
    }
    if(der != 0){
        nuevo->siguiente = der;
        der->anterior = nuevo;
    }
}

//-------------------------END FUNCIONA----------------------------

string Ortogonal::recorrer()
{
    NodoEncabezado * temp = vertical->primero;
    Nodo * aux;
    string info;

    while(temp != 0){
        aux = temp->acceso;
        while(aux != 0){
            if(aux->p != 0){
                char d = aux->p->tipo;
                info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "," + d
                        + "  ";
            }else{
                info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "   ";
            }
            aux = aux->siguiente;
        }
        info += "\n";
        temp = temp->siguiente;
    }
    info += "\n";
    temp = vertical->primero;

    while(temp != 0){
        if(temp->acceso != 0){
            aux = temp->acceso->zarriba;
            while(aux != 0){
                if(aux->p != 0){
                    char d = aux->p->tipo;
                    info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "," + d
                            + "  ";
                }else{
                    info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "   ";
                }
                aux = aux->siguiente;
            }
            info += "\n";
        }
        temp = temp->siguiente;
    }
    info += "\n";
    temp = vertical->primero;

    while(temp != 0){
        if(temp->acceso != 0){
            if(temp->acceso->zarriba != 0){
                aux = temp->acceso->zarriba->zarriba;
                while(aux != 0){
                    if(aux->p != 0){
                        char d = aux->p->tipo;
                        info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "," + d
                                + "  ";
                    }else{
                        info += to_string(aux->x) + "," + to_string(aux->y) + "," + to_string(aux->z) + "   ";
                    }
                    aux = aux->siguiente;
                }
                info += "\n";
            }
        }
        temp = temp->siguiente;
    }
    return info;
}
