#include <iostream>
#include <QApplication>
#include "Service.h"
#include "Gui.h"
int main(int argc, char** argv) {
    QApplication a{argc, argv};
    Repo repo{"candidati.txt"};
    Service Srv{repo};
    Gui mainWindow{Srv};
    mainWindow.show();
    a.exec();
    cout << "pula";
    return 0;
}
