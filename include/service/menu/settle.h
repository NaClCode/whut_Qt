#ifndef SETTLE_H
#define SETTLE_H
#include<ui_settle.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qsettle : public QDialog {
    Q_OBJECT

public:
    Qsettle(Model* model, QDialog* parent = nullptr);
    ~Qsettle();

private:
    Ui::settle *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // SETTLE_H
