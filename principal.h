#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <tarea.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

public slots:
    void mostrarTarea();

private slots:
    void on_cmdAnadir_clicked();

private:
    Ui::Principal *ui;
    QList<Tarea *> m_tareas;

    void inicializarDatos();
    void inicializarWidgets();


};
#endif // PRINCIPAL_H
