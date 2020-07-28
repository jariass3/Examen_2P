#include "principal.h"

#include <QApplication>

#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traducir;
 // Solicito al usuario que seleccione un idioma del programa
    QStringList idiomas;
    idiomas << "Español" << "Ingles";
    QString idiomaSelec = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);

  // Dependiendo del idioma que elija se cargara el archivo de traducción (.qm)
    if(idiomaSelec == "Español"){
        traducir.load(":/Examen_2P_JoelArias_es_EC.qm");
    }else if( idiomaSelec == "Ingles"){
        traducir.load(":/Examen_2P_JoelArias_en_US.qm");
    }
   // Si es diferente de español, se instala la traducción en la aplicación
        if (idiomaSelec != "Español"){
            a.installTranslator(&traducir);
        }



    Principal w;
    w.show();
    return a.exec();
}
