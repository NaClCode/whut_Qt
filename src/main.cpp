#include <QApplication>
#include"../include/service/menu.h"
#include"../include/model/model.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Model* m = new Model();
    QMenu w(m);
    w.exec();
    return a.exec();
}
