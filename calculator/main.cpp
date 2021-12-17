#include <QApplication>
#include <QDialog>
#include "count.h"
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    Counter *c=new Counter;
    c->show();
    return app.exec();
}
