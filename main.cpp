#include "mainwindow.h"
#include <QApplication>
#include "OSG.h"

int main(int argc, char *argv[])
{
    OSG ::osgInit(argc,argv);
    QApplication app(argc, argv);

    OpenSGGraphicsView view;
    view.show();

    tests(&view);

    return app.exec();
}
