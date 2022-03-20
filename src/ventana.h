#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include "qlabel.h"
#include "logica.h"
#include "arbol.h"
#include "QTimer"

namespace Ui {
class ventana;
}

class ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventana(QWidget *parent = 0);
    ~ventana();

    void cargar_jugadores();

    void actualizarComboBoxJugador();

    void recorrerArbol(Nodo_Binario * padre);

    void crearArchivo(string val, string name);

    int obtenerY(string id);

    void actualizarComboBoxMovimiento();

    int obtenerPieza(string id);

    string obtenerPieza1(string id);

    void cargarTablero();
private slots:
    void on_cargarjugador_clicked();

    void on_eliminar_clicked();

    void on_pushButton_clicked();

    void on_rbtnTop_clicked();

    void on_rbtnArbol_clicked();

    void on_rbtnLineacion_clicked();

    void on_rbtnTablero_clicked();

    void on_cmbTipo_activated(const QString &arg1);

    void on_mover_clicked();

    void on_iniciarjuego_clicked();

    void on_combPieza_activated(const QString &arg1);

    void on_combFila_activated(const QString &arg1);

    void on_combColumna_activated(const QString &arg1);

    void on_combNivel_activated(const QString &arg1);

private:
    Ui::ventana *ui;
    Arbol * tree;
    Logica * logica;
    bool isTurnoNegro;
    Constante cnt;

    string jugador1;
    string jugador2;

    QLabel ** level1[8];
    QLabel ** level2[8];
    QLabel ** level3[8];

    QLabel *f11[8];
    QLabel *f21[8];
    QLabel *f31[8];
    QLabel *f41[8];
    QLabel *f51[8];
    QLabel *f61[8];
    QLabel *f71[8];
    QLabel *f81[8];

    QLabel *f12[8];
    QLabel *f22[8];
    QLabel *f32[8];
    QLabel *f42[8];
    QLabel *f52[8];
    QLabel *f62[8];
    QLabel *f72[8];
    QLabel *f82[8];

    QLabel *f13[8];
    QLabel *f23[8];
    QLabel *f33[8];
    QLabel *f43[8];
    QLabel *f53[8];
    QLabel *f63[8];
    QLabel *f73[8];
    QLabel *f83[8];

    int x;
    int y;
    int z;
    int p;
};

#endif // VENTANA_H
