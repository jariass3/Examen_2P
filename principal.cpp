#include "principal.h"
#include "ui_principal.h"

#include <QDebug>
#include <QDate>
#include <QFileDialog>
#include <QTableWidget>
#include <QStringList>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->cmdAnadir, SIGNAL(released()), this, SLOT(mostrarTarea()));
       connect(ui->actionSalir, SIGNAL(triggered(bool)),
                  this, SLOT(close()));
    inicializarDatos();
}

Principal::~Principal()
{
    delete ui;
}


void Principal::inicializarDatos()
{
    m_tareas.append(new Tarea(1,"Universidad"));
    m_tareas.append(new Tarea(2,"Personal"));
    m_tareas.append(new Tarea(3,"Familiar"));
    inicializarWidgets();
}

void Principal::inicializarWidgets()
{
    for(int i = 0; i < m_tareas.length(); ++i){
        ui->inTipo->addItem(m_tareas.at(i)->tipo());
        // Colocar cabecera en la tabla
        QStringList cabecera = {"Tarea", "Fecha","Tipo","Prioridad"};
        ui->outDetalle->setColumnCount(4);
        ui->outDetalle->setHorizontalHeaderLabels(cabecera);

    }

}

void Principal::mostrarTarea()
{
    QString prioridad;

    if(ui->inp_Alta->isChecked()){
        prioridad = "Prioridad Alta";
    }
    if (ui->inp_Media->isChecked()){
        prioridad = "Prioridad Media";
    }
    if(ui->inp_Baja->isChecked()){
        prioridad = "Prioridad Baja";
    }

    QString nombre = ui->inTarea->text();
    QDate fecha = ui->inFecha->date();
    int index = ui->inTipo->currentIndex();
    //Obteniendo datos desde la interfaz
    Tarea *p = m_tareas.at(index);
    int posicion = ui->outDetalle->rowCount();

    ui->outDetalle->insertRow(posicion);
    ui->outDetalle->setItem(posicion,0,new QTableWidgetItem(QString(nombre)));
    ui->outDetalle->setItem(posicion,1,new QTableWidgetItem(fecha.toString()));
    ui->outDetalle->setItem(posicion,2,new QTableWidgetItem(p->tipo()));
    ui->outDetalle->setItem(posicion,3,new QTableWidgetItem(QString(prioridad)));

    if(ui->inp_Alta->isChecked()){
        for(int i=0;i<4;i++){
            QColor col(Qt::red);
            ui->outDetalle->item(posicion,i)->setBackgroundColor(col);
        }
    }
    if (ui->inp_Media->isChecked()){
        for(int i=0;i<4;i++){
            QColor col1(Qt::yellow);
            ui->outDetalle->item(posicion,i)->setBackgroundColor(col1);
        }
    }
     if(ui->inp_Baja->isChecked()){
         for(int i=0;i<4;i++){
            QColor col2(Qt::green);
            ui->outDetalle->item(posicion,i)->setBackgroundColor(col2);
       }
    }
}



void Principal::on_cmdAnadir_clicked()
{
    QString fileName=("E:/Qt/QtProyects/examen_arias_joel/Examen_2P_JoelArias/Tareas.txt");
    QFile data(fileName);
    if(data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream salir(&data);
        QStringList Lista;
        for (int columna = 0; columna < ui->outDetalle->columnCount(); ++columna){
            Lista << "\" " + ui->outDetalle->horizontalHeaderItem(columna)->data(Qt::DisplayRole).toString() + "\" ";
        }
        salir << Lista.join(";") << "\n";
        for (int fila = 0; fila < ui->outDetalle->rowCount(); ++fila) {
         Lista.clear();
         for (int columna = 0; columna < ui->outDetalle->columnCount(); ++columna){
             QTableWidgetItem*  item = ui->outDetalle->item(fila,columna);
             if(!item || item->text().isEmpty()){
                 ui->outDetalle->setItem(fila,columna,new QTableWidgetItem("0"));
             }
             Lista << "\" " + ui->outDetalle->item(fila, columna)->text() + "\" " ;
         }
         salir << Lista.join(";") + "\n";
        }
        ui->statusbar->showMessage("Los Datos estan en: " + fileName,5060);
        data.close();

    }

}



void Principal::on_actionFinalizar_triggered()
{
       int e = ui->outDetalle->currentRow();
       ui->outDetalle->removeRow(e);
}


