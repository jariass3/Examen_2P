#ifndef TAREA_H
#define TAREA_H

#include <QObject>

class Tarea : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int codigo READ codigo)
    Q_PROPERTY(QString tipo READ tipo)

public:
    explicit Tarea(QObject *parent = nullptr);
    Tarea(int codigo, QString tipo);

    int codigo() const;
    QString tipo() const;

signals:

private:
    int m_codigo;
    QString m_tipo;
};

#endif // TAREA_H
