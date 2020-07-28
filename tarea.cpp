#include "tarea.h"

Tarea::Tarea(QObject *parent) : QObject(parent)
{
    m_codigo = 0;
    m_tipo = "";
    //m_fecha = "";
}

Tarea::Tarea(int codigo,QString tipo)
{
    m_codigo = codigo;
    m_tipo = tipo;

}

int Tarea::codigo() const
{
    return m_codigo;
}

QString Tarea::tipo() const
{
    return m_tipo;
}



