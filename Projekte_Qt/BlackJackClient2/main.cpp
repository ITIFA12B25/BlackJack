#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    // Hauptfenster starten
    MainWindow w;
    w.show();
    return a.exec();
}

