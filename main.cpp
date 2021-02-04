#include "ingrediente.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ingredienti w;
    w.show();
    return a.exec();
}
