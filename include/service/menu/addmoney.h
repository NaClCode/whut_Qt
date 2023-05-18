#ifndef ADDMONEY_H
#define ADDMONEY_H
#include<ui_addmoney.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qaddmoney : public QDialog {
    Q_OBJECT

public:
    Qaddmoney(Model* model, QDialog* parent = nullptr);
    ~Qaddmoney();
private:
    Ui::addmoney *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // ADDMONEY_H
