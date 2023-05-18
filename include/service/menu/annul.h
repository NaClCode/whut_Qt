#ifndef ANNUL_H
#define ANNUL_H
#include<ui_annul.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qannul : public QDialog {
    Q_OBJECT

public:
    Qannul(Model* model, QDialog* parent = nullptr);
    ~Qannul();

private:
    Ui::annul *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // ANNUL_H
