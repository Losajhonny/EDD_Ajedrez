#include "ventana.h"
#include "ui_ventana.h"
#include "QFileDialog"
#include "fstream"
#include "cstring"
#include "thread"
#include "chrono"

ventana::ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventana)
{
    ui->setupUi(this);
    ui->mover->setEnabled(false);
    tree = new Arbol();
    logica = new Logica();
    isTurnoNegro = false;

    //NIVEL 1
    f11[0] = ui->H1_1;  f21[0] = ui->G1_1;  f31[0] = ui->F1_1;  f41[0] = ui->E1_1;
    f11[1] = ui->H2_1;  f21[1] = ui->G2_1;  f31[1] = ui->F2_1;  f41[1] = ui->E2_1;
    f11[2] = ui->H3_1;  f21[2] = ui->G3_1;  f31[2] = ui->F3_1;  f41[2] = ui->E3_1;
    f11[3] = ui->H4_1;  f21[3] = ui->G4_1;  f31[3] = ui->F4_1;  f41[3] = ui->E4_1;
    f11[4] = ui->H5_1;  f21[4] = ui->G5_1;  f31[4] = ui->F5_1;  f41[4] = ui->E5_1;
    f11[5] = ui->H6_1;  f21[5] = ui->G6_1;  f31[5] = ui->F6_1;  f41[5] = ui->E6_1;
    f11[6] = ui->H7_1;  f21[6] = ui->G7_1;  f31[6] = ui->F7_1;  f41[6] = ui->E7_1;
    f11[7] = ui->H8_1;  f21[7] = ui->G8_1;  f31[7] = ui->F8_1;  f41[7] = ui->E8_1;

    f51[0] = ui->D1_1;  f61[0] = ui->C1_1;  f71[0] = ui->B1_1;  f81[0] = ui->A1_1;
    f51[1] = ui->D2_1;  f61[1] = ui->C2_1;  f71[1] = ui->B2_1;  f81[1] = ui->A2_1;
    f51[2] = ui->D3_1;  f61[2] = ui->C3_1;  f71[2] = ui->B3_1;  f81[2] = ui->A3_1;
    f51[3] = ui->D4_1;  f61[3] = ui->C4_1;  f71[3] = ui->B4_1;  f81[3] = ui->A4_1;
    f51[4] = ui->D5_1;  f61[4] = ui->C5_1;  f71[4] = ui->B5_1;  f81[4] = ui->A5_1;
    f51[5] = ui->D6_1;  f61[5] = ui->C6_1;  f71[5] = ui->B6_1;  f81[5] = ui->A6_1;
    f51[6] = ui->D7_1;  f61[6] = ui->C7_1;  f71[6] = ui->B7_1;  f81[6] = ui->A7_1;
    f51[7] = ui->D8_1;  f61[7] = ui->C8_1;  f71[7] = ui->B8_1;  f81[7] = ui->A8_1;

    level1[0] = f11;    level1[4] = f51;
    level1[1] = f21;    level1[5] = f61;
    level1[2] = f31;    level1[6] = f71;
    level1[3] = f41;    level1[7] = f81;
    //NIVEL 2
    f12[0] = ui->H1_2;  f22[0] = ui->G1_2;  f32[0] = ui->F1_2;  f42[0] = ui->E1_2;
    f12[1] = ui->H2_2;  f22[1] = ui->G2_2;  f32[1] = ui->F2_2;  f42[1] = ui->E2_2;
    f12[2] = ui->H3_2;  f22[2] = ui->G3_2;  f32[2] = ui->F3_2;  f42[2] = ui->E3_2;
    f12[3] = ui->H4_2;  f22[3] = ui->G4_2;  f32[3] = ui->F4_2;  f42[3] = ui->E4_2;
    f12[4] = ui->H5_2;  f22[4] = ui->G5_2;  f32[4] = ui->F5_2;  f42[4] = ui->E5_2;
    f12[5] = ui->H6_2;  f22[5] = ui->G6_2;  f32[5] = ui->F6_2;  f42[5] = ui->E6_2;
    f12[6] = ui->H7_2;  f22[6] = ui->G7_2;  f32[6] = ui->F7_2;  f42[6] = ui->E7_2;
    f12[7] = ui->H8_2;  f22[7] = ui->G8_2;  f32[7] = ui->F8_2;  f42[7] = ui->E8_2;

    f52[0] = ui->D1_2;  f62[0] = ui->C1_2;  f72[0] = ui->B1_2;  f82[0] = ui->A1_2;
    f52[1] = ui->D2_2;  f62[1] = ui->C2_2;  f72[1] = ui->B2_2;  f82[1] = ui->A2_2;
    f52[2] = ui->D3_2;  f62[2] = ui->C3_2;  f72[2] = ui->B3_2;  f82[2] = ui->A3_2;
    f52[3] = ui->D4_2;  f62[3] = ui->C4_2;  f72[3] = ui->B4_2;  f82[3] = ui->A4_2;
    f52[4] = ui->D5_2;  f62[4] = ui->C5_2;  f72[4] = ui->B5_2;  f82[4] = ui->A5_2;
    f52[5] = ui->D6_2;  f62[5] = ui->C6_2;  f72[5] = ui->B6_2;  f82[5] = ui->A6_2;
    f52[6] = ui->D7_2;  f62[6] = ui->C7_2;  f72[6] = ui->B7_2;  f82[6] = ui->A7_2;
    f52[7] = ui->D8_2;  f62[7] = ui->C8_2;  f72[7] = ui->B8_2;  f82[7] = ui->A8_2;

    level2[0] = f12;    level2[4] = f52;
    level2[1] = f22;    level2[5] = f62;
    level2[2] = f32;    level2[6] = f72;
    level2[3] = f42;    level2[7] = f82;
    //NIVEL 3
    f13[0] = ui->H1_3;  f23[0] = ui->G1_3;  f33[0] = ui->F1_3;  f43[0] = ui->E1_3;
    f13[1] = ui->H2_3;  f23[1] = ui->G2_3;  f33[1] = ui->F2_3;  f43[1] = ui->E2_3;
    f13[2] = ui->H3_3;  f23[2] = ui->G3_3;  f33[2] = ui->F3_3;  f43[2] = ui->E3_3;
    f13[3] = ui->H4_3;  f23[3] = ui->G4_3;  f33[3] = ui->F4_3;  f43[3] = ui->E4_3;
    f13[4] = ui->H5_3;  f23[4] = ui->G5_3;  f33[4] = ui->F5_3;  f43[4] = ui->E5_3;
    f13[5] = ui->H6_3;  f23[5] = ui->G6_3;  f33[5] = ui->F6_3;  f43[5] = ui->E6_3;
    f13[6] = ui->H7_3;  f23[6] = ui->G7_3;  f33[6] = ui->F7_3;  f43[6] = ui->E7_3;
    f13[7] = ui->H8_3;  f23[7] = ui->G8_3;  f33[7] = ui->F8_3;  f43[7] = ui->E8_3;

    f53[0] = ui->D1_3;  f63[0] = ui->C1_3;  f73[0] = ui->B1_3;  f83[0] = ui->A1_3;
    f53[1] = ui->D2_3;  f63[1] = ui->C2_3;  f73[1] = ui->B2_3;  f83[1] = ui->A2_3;
    f53[2] = ui->D3_3;  f63[2] = ui->C3_3;  f73[2] = ui->B3_3;  f83[2] = ui->A3_3;
    f53[3] = ui->D4_3;  f63[3] = ui->C4_3;  f73[3] = ui->B4_3;  f83[3] = ui->A4_3;
    f53[4] = ui->D5_3;  f63[4] = ui->C5_3;  f73[4] = ui->B5_3;  f83[4] = ui->A5_3;
    f53[5] = ui->D6_3;  f63[5] = ui->C6_3;  f73[5] = ui->B6_3;  f83[5] = ui->A6_3;
    f53[6] = ui->D7_3;  f63[6] = ui->C7_3;  f73[6] = ui->B7_3;  f83[6] = ui->A7_3;
    f53[7] = ui->D8_3;  f63[7] = ui->C8_3;  f73[7] = ui->B8_3;  f83[7] = ui->A8_3;

    level3[0] = f13;    level3[4] = f53;
    level3[1] = f23;    level3[5] = f63;
    level3[2] = f33;    level3[6] = f73;
    level3[3] = f43;    level3[7] = f83;

    cargarTablero();
}

ventana::~ventana()
{
    delete ui;
}

void ventana::cargar_jugadores()
{
    delete tree;
    tree = new Arbol();

    QString nombre = QFileDialog::getOpenFileName(this, "Abrir archivo", "C://Users//jhonny//Desktop//");//C://");

        ifstream entrada;
        string linea, temp, nombre_j, pganadas, pperdidas;
        int cont = 0;

        entrada.open(nombre.toStdString().c_str());

        if(!entrada.fail()){

            while(getline(entrada, linea)){
                int i = 0;

                while(i < linea.length()){
                    if(linea[i] == 95){
                        if(cont == 0){
                            nombre_j = temp;
                        }else if(cont == 1){
                            pganadas = temp;
                        }else{
                            pperdidas = temp;
                        }
                        cont ++;
                        temp = "";
                    }else{
                        temp += linea[i];
                    }

                    if(i == linea.length()-1){
                        tree->agregar(new Nodo_Binario(nombre_j, atoi(pganadas.c_str()), atoi(pperdidas.c_str())));
                        temp = "";
                        break;
                    }
                    i += 1;
                }
                cont = 0;
            }
        }

        entrada.close();
}

void ventana::actualizarComboBoxJugador()
{
    ui->piezablanco->clear();
    ui->piezanegra->clear();
    recorrerArbol(tree->raiz);
}

void ventana::recorrerArbol(Nodo_Binario *padre)
{
    if(padre != 0){
        recorrerArbol(padre->izq);
        ui->piezablanco->addItem(QString::fromStdString(padre->nombre));
        ui->piezanegra->addItem(QString::fromStdString(padre->nombre));
        recorrerArbol(padre->der);
    }
}

void ventana::crearArchivo(string val, string name)
{
    ofstream archivo;
    string nombre = "C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//dot//" + name + ".dot";

    archivo.open(nombre.c_str());

    if(!archivo.fail()){
        archivo << val << endl;
    }

    archivo.close();

    string crear = "C://release//bin//dot.exe -Tpng " + nombre + " -o C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//imgdot//" + name + ".png";
    system(crear.c_str());
}

int ventana::obtenerY(string id)
{
    if(strcmp(id.c_str(), "A") == 0){
        return cnt.A;
    }else if(strcmp(id.c_str(), "B") == 0){
        return cnt.B;
    }else if(strcmp(id.c_str(), "C") == 0){
        return cnt.C;
    }else if(strcmp(id.c_str(), "D") == 0){
        return cnt.D;
    }else if(strcmp(id.c_str(), "E") == 0){
        return cnt.E;
    }else if(strcmp(id.c_str(), "F") == 0){
        return cnt.F;
    }else if(strcmp(id.c_str(), "G") == 0){
        return cnt.G;
    }else if(strcmp(id.c_str(), "H") == 0){
        return cnt.H;
    }else{
        return -1;
    }
}

void ventana::actualizarComboBoxMovimiento()
{
    string pieza = ui->combPieza->currentText().toStdString().c_str();
    y = obtenerY(ui->combFila->currentText().toStdString());
    x = atoi(ui->combColumna->currentText().toStdString().c_str());
    z = atoi(ui->combNivel->currentText().toStdString().c_str())-1;
    p = obtenerPieza(pieza);

    string mov;
    mov = obtenerPieza1(pieza) + "-" + to_string(z+1) + "-" + ui->combFila->currentText().toStdString() + to_string(x);

    ui->txtMov->setText(QString::fromStdString(mov));
}

int ventana::obtenerPieza(string id)
{
    if(strcmp(id.c_str(), "Peon") == 0 || strcmp(id.c_str(), "P") == 0){
        return cnt.PEON;
    }else if(strcmp(id.c_str(), "Caballo") == 0 || strcmp(id.c_str(), "C") == 0){
        return cnt.CABALLO;
    }else if(strcmp(id.c_str(), "Alfil") == 0 || strcmp(id.c_str(), "A") == 0){
        return cnt.ALFIL;
    }else if(strcmp(id.c_str(), "Torre") == 0 || strcmp(id.c_str(), "T") == 0){
        return cnt.TORRE;
    }else if(strcmp(id.c_str(), "Rey") == 0 || strcmp(id.c_str(), "R") == 0){
        return cnt.REY;
    }else if(strcmp(id.c_str(), "Dama") == 0 || strcmp(id.c_str(), "D") == 0){
        return cnt.DAMA;
    }else{
        return -1;
    }
}

string ventana::obtenerPieza1(string id)
{
    if(strcmp(id.c_str(), "Peon") == 0){
        return "P";
    }else if(strcmp(id.c_str(), "Caballo") == 0){
        return "C";
    }else if(strcmp(id.c_str(), "Alfil") == 0){
        return "A";
    }else if(strcmp(id.c_str(), "Torre") == 0){
        return "T";
    }else if(strcmp(id.c_str(), "Rey") == 0){
        return "R";
    }else if(strcmp(id.c_str(), "Dama") == 0){
        return "D";
    }else{
        return "";
    }
}

void ventana::cargarTablero()
{
    //LIMPIAR TODOS LOS LABEL NIVEL 1
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QPixmap pix("");
            level1[i][j]->setPixmap(pix);
        }
    }

    NodoEncabezado * tempy = 0;
    tempy = logica->matriz->vertical->buscar(1);

    while(tempy != 0){
        Nodo *acceso = tempy->acceso;

        while(acceso != 0){
            if(acceso->existe){
                QPixmap qp(acceso->p->path.c_str());
                level1[acceso->y-1][acceso->x-1]->setPixmap(qp);
            }
            acceso = acceso->siguiente;
        }

        tempy = tempy->siguiente;
    }

    //LIMPIAR TODOS LOS LABEL NIVEL 2
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QPixmap pix("");
            level2[i][j]->setPixmap(pix);
        }
    }

    tempy = logica->matriz->vertical->buscar(1);

    while(tempy != 0){
        Nodo *acceso = logica->matriz->buscarNodo(tempy, 1, false);

        while(acceso != 0){
            if(acceso->existe){
                QPixmap qp(acceso->p->path.c_str());
                level2[acceso->y-1][acceso->x-1]->setPixmap(qp);
            }
            acceso = acceso->siguiente;
        }

        tempy = tempy->siguiente;
    }

    //LIMPIAR TODOS LOS LABEL NIVEL 3
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            QPixmap pix("");
            level3[i][j]->setPixmap(pix);
        }
    }

    tempy = logica->matriz->vertical->buscar(1);

    while(tempy != 0){
        Nodo *acceso = logica->matriz->buscarNodo(tempy, 2, false);

        while(acceso != 0){
            if(acceso->existe){
                QPixmap qp(acceso->p->path.c_str());
                level3[acceso->y-1][acceso->x-1]->setPixmap(qp);
            }
            acceso = acceso->siguiente;
        }

        tempy = tempy->siguiente;
    }
}

void ventana::on_cargarjugador_clicked()
{
    cargar_jugadores();
    actualizarComboBoxJugador();
}

void ventana::on_eliminar_clicked()
{
    QString delete_ = ui->txtEliminar->text();
    string t = delete_.toStdString();

    if(t != ""){
        tree->eliminar(t);
    }
}

//boton de mostrar reportes
void ventana::on_pushButton_clicked()
{
    if(ui->rbtnTablero->isChecked()){
        int val = atoi(ui->cmbnivelt->currentText().toStdString().c_str())-1;
        crearArchivo(logica->mnivel(val), "matriz");
        QPixmap qp("C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//imgdot//matriz.png");
        ui->img->setPixmap(qp);
    }else if(ui->rbtnLineacion->isChecked()){
        //obtener nivel
        string obn = ui->cmbNivel->currentText().toStdString();
        int level = atoi(obn.c_str())-1;

        //obtener tipo
        string tipo = ui->cmbTipo->currentText().toStdString();
        bool isfila = false;
        if(strcmp(tipo.c_str(), "Fila") == 0){
            isfila = true;
        }else{
            isfila = false;
        }

        //obtener id
        int id = 0;
        if(level == 0){
            ui->img->setScaledContents(false);
        }else{
            ui->img->setScaledContents(false);
        }
        if(isfila){
            id = obtenerY(ui->cmbID->currentText().toStdString());
        }else{
            id = atoi(ui->cmbID->currentText().toStdString().c_str());
        }
        crearArchivo(logica->lineacion(isfila, level, id), "reportelineacion");
        QPixmap qp("C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//imgdot//reportelineacion.png");
        ui->img->setPixmap(qp);
    }else if(ui->rbtnArbol->isChecked()){
        crearArchivo(tree->mostrarArbol(), "reportearbol");
        ui->etivalHojas->setText(QString::fromStdString(to_string(tree->buscarNodoHoja(tree->raiz))));
        ui->etivalRamas->setText(QString::fromStdString(to_string(tree->buscarNodoRama(tree->raiz))));
        ui->etivalAltura->setText(QString::fromStdString(to_string(tree->altura(tree->raiz))));

        QPixmap qp("C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//imgdot//reportearbol.png");
        ui->img->setPixmap(qp);
    }else if(ui->rbtnTop->isChecked()){
        crearArchivo(tree->mostrarTop(), "reportetop");

        QPixmap qp("C://Users//jhonny//Desktop//EDD_vacas_//[EDD]Proyect1_201325583//imgdot//reportetop.png");
        ui->img->setPixmap(qp);
    }
}

void ventana::on_rbtnTop_clicked()
{
    ui->etivalAltura->setText("");
    ui->etivalHojas->setText("");
    ui->etivalRamas->setText("");
    ui->img->setScaledContents(false);
}

void ventana::on_rbtnArbol_clicked()
{
    ui->img->setScaledContents(false);
}

void ventana::on_rbtnLineacion_clicked()
{
    ui->etivalAltura->setText("");
    ui->etivalHojas->setText("");
    ui->etivalRamas->setText("");
    ui->img->setScaledContents(false);
}

void ventana::on_rbtnTablero_clicked()
{
    ui->etivalAltura->setText("");
    ui->etivalHojas->setText("");
    ui->etivalRamas->setText("");
    ui->img->setScaledContents(true);
}

void ventana::on_cmbTipo_activated(const QString &arg1)
{
    string d = ui->cmbTipo->currentText().toStdString();
    if(strcmp(d.c_str(), "Fila") == 0){
        ui->cmbID->clear();
        for(int i = 1; i <= 8; i++){
            d = logica->obtenerEjeY(i);
            ui->cmbID->addItem(QString::fromStdString(d));
        }
    }else{
        ui->cmbID->clear();
        for(int i = 1; i <= 8; i++){
            ui->cmbID->addItem(QString::fromStdString(to_string(i)));
        }
    }
}

void ventana::on_mover_clicked()
{
    string dato = ui->txtMov->text().toStdString() + "-";
    string lectura = "";

    for(int i = 0; i < dato.length(); i++){
        if(i == 1){//nombre de la piza
            p = obtenerPieza(lectura);
            lectura = "";
        }else if(i == 3){ // el nivel
            z = atoi(lectura.c_str())-1;
            lectura = "";
        }else if(i == 5){
            y = obtenerY(lectura);
            lectura = "";
        }else if(i == 6){
            x = atoi(lectura.c_str());
        }
        if(dato[i] == 45){
            i += 1;
        }
        lectura += dato[i];
    }

    if(isTurnoNegro){
        if(logica->movimiento(cnt.NEGRO, p, x, y, z)){
            isTurnoNegro = false;
            string movimientoT = ui->txtConsola->toPlainText().toStdString() + "\n" + jugador1 + ": " + ui->txtMov->text().toStdString();

            ui->txtConsola->setPlainText(QString::fromStdString(movimientoT));
            ui->etiTurno->setText(QString::fromStdString(jugador2) + " P: BLANCO");

            cargarTablero();
        }
    }else{
        if(logica->movimiento(cnt.BLANCO, p, x, y, z)){
            isTurnoNegro = true;
            string movimientoT = ui->txtConsola->toPlainText().toStdString() + "\n" + jugador2 + ": " + ui->txtMov->text().toStdString();
            ui->txtConsola->setPlainText(QString::fromStdString(movimientoT));
            ui->etiTurno->setText(QString::fromStdString(jugador1) + " P: NEGRO");

            cargarTablero();
        }
    }

    bool existeDamaBlanco = logica->existeDama(cnt.BLANCO);
    bool existeDamaNegro = logica->existeDama(cnt.NEGRO);

    if(!existeDamaBlanco){
        //ENTONCES FIN DE LA PARTIDA Y MOSTRAR GANADOR PIEZA NEGRA --MODIFICANDO EN EL ARBOL INFO--
        ui->mover->setEnabled(false);
        ui->iniciarjuego->setEnabled(true);
        string t = ui->txtConsola->toPlainText().toStdString() + "\n\n***************** WINNER ******************\n\n"
                +  "JUGADOR NEGRO: " + jugador1 + "\nGANADOR\n";
        ui->txtConsola->setPlainText(QString::fromStdString(t));

        Nodo_Binario * tj1 = tree->buscar(jugador1);
        Nodo_Binario * tj2 = tree->buscar(jugador2);
        tj1->p_ganadas = tj1->p_ganadas + 1;
        if(tj2->p_perdidas > 0){
            tj2->p_perdidas = tj2->p_perdidas - 1;
        }

        //SI HAY TIEMPO DETENER
    }
    if(!existeDamaNegro){
        //ENTONCES FIN DE LA PARTIDA Y MOSTRAR GANADOR PIEZA BLANCO --MODIFICANDO EN EL ARBOL INFO--
        ui->mover->setEnabled(false);
        ui->iniciarjuego->setEnabled(true);
        string t = ui->txtConsola->toPlainText().toStdString()+ "\n\n***************** WINNER ******************\n\n"
                + "JUGADOR BLANCO: " + jugador2 + "\nGANADOR\n";
        ui->txtConsola->setPlainText(QString::fromStdString(t));

        Nodo_Binario * tj1 = tree->buscar(jugador1);
        Nodo_Binario * tj2 = tree->buscar(jugador2);
        tj2->p_ganadas = tj2->p_ganadas + 1;
        if(tj1->p_perdidas > 0){
            tj1->p_perdidas = tj1->p_perdidas - 1;
        }

        //SI HAY TIEMPO DETENER
    }
}

void ventana::on_iniciarjuego_clicked()
{
    jugador1 = ui->piezanegra->currentText().toStdString();
    jugador2 = ui->piezablanco->currentText().toStdString();

    if(tree->raiz != 0){
        if(strcmp(jugador1.c_str(), jugador2.c_str()) == 0){
            ui->mover->setEnabled(false);
            ui->txtConsola->setPlainText("******** Eliga jugadores diferentes ********");
        }else{
            isTurnoNegro = true;
            ui->txtConsola->setPlainText("*********** Partida Iniciada ***********");
            ui->etiTurno->setText(QString::fromStdString(jugador1) + " P: NEGRO");

            if(ui->rbtnNormal->isChecked()){
                ui->iniciarjuego->setEnabled(false);
                ui->mover->setEnabled(true);
                ui->etiTiempo->setText("");

                delete logica;
                logica = new Logica();
                cargarTablero();
            }else if(ui->rbtnTiempo->isChecked()){
                ui->iniciarjuego->setEnabled(false);
                ui->mover->setEnabled(true);
                ui->etiTiempo->setText(ui->txtTiempo->text());

                delete logica;
                logica = new Logica();
                cargarTablero();

            }else{
                ui->mover->setEnabled(false);
                ui->txtConsola->setPlainText("******** Seleccione una modalidad de Juego ********");
            }
        }
    }else{
        ui->mover->setEnabled(false);
        ui->txtConsola->setPlainText("******** Ingrese jugadores antes de iniciar *******");
    }
}

void ventana::on_combPieza_activated(const QString &arg1)
{
    actualizarComboBoxMovimiento();
}

void ventana::on_combFila_activated(const QString &arg1)
{
    actualizarComboBoxMovimiento();
}

void ventana::on_combColumna_activated(const QString &arg1)
{
    actualizarComboBoxMovimiento();
}

void ventana::on_combNivel_activated(const QString &arg1)
{
    actualizarComboBoxMovimiento();
}
