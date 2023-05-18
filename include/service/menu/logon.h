#ifndef LOGON_H
#define LOGON_H
#include<ui_logon.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qlogon : public QDialog {
    Q_OBJECT

public:
    Qlogon(Model* model, QDialog* parent = nullptr);
    ~Qlogon();

private:
    Ui::logon *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // LOGON_H
