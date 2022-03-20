#include "cstring"
#include "string"
#include "arbol.h"

void Arbol::agregar(Nodo_Binario *nuevo)
{
    if(raiz == 0){
        raiz = nuevo;
    }else{
        agregar(nuevo, raiz);
    }
}

void Arbol::agregar(Nodo_Binario *nuevo, Nodo_Binario *temp)
{
    //string namen = nuevo->nombre;
    //string namet = temp->nombre;

    int dnuevo = nuevo->nombre[0];
    int dtemp = temp->nombre[0];

    if(dnuevo < dtemp){
        if(temp->izq != 0){
            agregar(nuevo, temp->izq);
        }else{
            temp->izq = nuevo;
        }
    }else{
        if(temp->der != 0){
            agregar(nuevo, temp->der);
        }else{
            temp->der = nuevo;
        }
    }
}

Nodo_Binario *Arbol::buscar(string nombre)
{
    int dno = nombre[0];
    int draiz = 0;

    if(raiz != 0){
        draiz = raiz->nombre[0];
    }

    if(raiz == 0){
        return 0;
    }else if(strcmp(raiz->nombre.c_str(), nombre.c_str()) == 0){
        return raiz;
    }else if(dno > draiz){
        return buscar(nombre, raiz->der);
    }else{
        return buscar(nombre, raiz->izq);
    }
}

Nodo_Binario *Arbol::buscar(string nombre, Nodo_Binario *padre)
{
    int dno = nombre[0];
    int draiz = 0;

    if(padre != 0){
        draiz = padre->nombre[0];
    }

    if(padre == 0){
        return 0;
    }else if(strcmp(padre->nombre.c_str(), nombre.c_str()) == 0){
        return padre;
    }else if(dno > draiz){
        return buscar(nombre, padre->der);
    }else{
        return buscar(nombre, padre->izq);
    }
}

bool Arbol::eliminar(string nombre)
{
    Nodo_Binario * aux = raiz;
    Nodo_Binario * padre = 0;
    bool isHijoIzq = true;

    int ncomp = nombre[0];

    if(raiz != 0){
        int naux = aux->nombre[0];

        while(strcmp(aux->nombre.c_str(), nombre.c_str()) != 0){
            padre = aux;
            if(ncomp < naux){
                isHijoIzq = true;
                aux = aux->izq;
            }else{
                isHijoIzq = false;
                aux = aux->der;
            }
            if(aux == 0){
                return false;
            }
        }

        if(aux->izq == 0 && aux->der == 0){
            if(aux == raiz){
                raiz = 0;
            }else if(isHijoIzq){
                padre->izq = 0;
            }else{
                padre->der = 0;
            }
        }else if(aux->der == 0){
            if(aux == raiz){
                raiz = aux->izq;
            }else if(isHijoIzq){
                padre->izq = aux->izq;
            }else{
                padre->der = aux->izq;
            }
        }else if(aux->izq == 0){
            if(aux == raiz){
                raiz = aux->der;
            }else if(isHijoIzq){
                padre->izq = aux->der;
            }else{
                padre->der = aux->izq;
            }
        }else{
            Nodo_Binario * reemplazo = obtenerRemplazo(aux);
            if(aux == raiz){
                raiz = reemplazo;
            }else if(isHijoIzq){
                padre->izq = reemplazo;
            }else{
                padre->der = reemplazo;
            }
            reemplazo->izq = aux->izq;
        }
        return true;
    }
    return false;
}

int Arbol::buscarNodoHoja(Nodo_Binario *padre)
{
    int id = 0;
    if(padre != 0){
        if(padre->izq == 0 && padre->der == 0){
            id += 1;
        }
        id += buscarNodoHoja(padre->izq);
        id += buscarNodoHoja(padre->der);
    }
    return id;
}

int Arbol::buscarNodoRama(Nodo_Binario *padre)
{
    int id = 0;
    if(padre != 0){
        id += buscarNodoRama(padre->izq);
        if(padre->izq != 0 || padre->der != 0){
            id += 1;
        }
        id += buscarNodoRama(padre->der);
    }
    return id;
}

int Arbol::altura(Nodo_Binario *padre)
{
    if(padre != 0){
        return (1 + max(altura(padre->izq), altura(padre->der)));
    }
    return 0;
}

Nodo_Binario *Arbol::obtenerRemplazo(Nodo_Binario *aux)
{
    Nodo_Binario * rempadre = aux;
    Nodo_Binario * remplazo = aux;

    Nodo_Binario * auxiliar = aux->der;

    while(auxiliar != 0){
        rempadre = remplazo;
        remplazo = auxiliar;
        auxiliar = auxiliar->izq;
    }

    if(remplazo != aux->der){
        rempadre->izq = remplazo->der;
        remplazo->der = aux->der;
    }
    return remplazo;
}

string Arbol::mostrarArbol()
{
    string info = "digraph reportearbol{\n";
    info += preOrden(raiz);
    info += "}";
    return info;
}

string Arbol::mostrarTop()
{
    string info = "digraph reportetop{\n";
    info += "graph [pad=\"0.5\", nodesep=\"0.3\", ranksep=\"0.1\"];\n";
    nE = new Encabezado();
    addinOrden(raiz);

    NodoEncabezado * temp = nE->ultimo;

    int top = 0;
    while(temp != 0 && top < 10){
        info += to_string(top) + "[label=\"" + temp->nombre + "\t" + to_string(temp->id) + "\"];\n";
        top ++;
        temp = temp->anterior;
    }

    temp = nE->ultimo;
    top = 1;
    int ant = 0;
    while(temp != 0 && top < 10){
        info += to_string(ant) + "->" + to_string(top) + ";\n";
        ant = top;
        top ++;
        temp = temp->anterior;
    }

    info += "}";

    nE = 0;
    delete nE;

    return info;
}

void Arbol::addinOrden(Nodo_Binario *padre)
{
    if(padre != 0){
        NodoEncabezado * nuevo = new NodoEncabezado(padre->p_ganadas);
        nuevo->nombre = padre->nombre;

        nE->add(nuevo);
        addinOrden(padre->izq);
        addinOrden(padre->der);
    }
}

string Arbol::preOrden(Nodo_Binario *padre)
{
    string info;

    if(padre != 0){
        if(padre->izq != 0){
            info += padre->nombre + "->" + padre->izq->nombre + ";\n";
        }
        if(padre->der != 0){
            info += padre->nombre + "->" + padre->der->nombre + ";\n";
        }
        info += preOrden(padre->izq);
        info += preOrden(padre->der);
    }

    return info;
}
