#ifndef ADMIN_H
#define ADMIN_H
#include<ui_admin.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"count.h"
#include"include/service/menu/result.h"
class Qcount;
class Qadmin : public QDialog {
    Q_OBJECT

public:
    Qadmin(Model* model, QDialog* parent = nullptr);
    ~Qadmin();
private:
    Ui::admin *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
    void start_count();
};
#endif // LOGON_H
