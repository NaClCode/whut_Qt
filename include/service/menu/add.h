#ifndef ADD_H
#define ADD_H
#include<ui_add.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qadd : public QDialog {
    Q_OBJECT

public:
    Qadd(Model *model, QDialog* parent = nullptr);
    ~Qadd();

private:
    Ui::add *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // ADD_H
