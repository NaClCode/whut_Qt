#ifndef REFUND_H
#define REFUND_H
#include<ui_refund.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qrefund : public QDialog {
    Q_OBJECT

public:
    Qrefund(Model* model, QDialog* parent = nullptr);
    ~Qrefund();
private:
    Ui::refund *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // REFUND_H
