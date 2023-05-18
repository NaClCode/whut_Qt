#ifndef QUERY_H
#define QUERY_H
#include<ui_query.h>
#include<QRadioButton>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
class Qquery : public QDialog {
    Q_OBJECT

public:
    Qquery(Model* model, QDialog* parent = nullptr);
    ~Qquery();
    void show();

private:
    Ui::query *ui;
    Model *model;

    int types;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};
#endif // QUERY_H
