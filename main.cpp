#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString::fromUtf8("Sudoku"));
    w.show();



    return a.exec();
}
