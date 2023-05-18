#ifndef COUNT_H
#define COUNT_H
#include<ui_count.h>
#include<ui_count_card.h>
#include<ui_count_time.h>
#include<ui_count_total.h>
#include"include/model/model.h"
#include"include/service/menu.h"
#include"include/service/menu/result.h"
#include"include/service/menu/datetime.h"
class Qcount;
class Qcount_card : public QDialog {
    Q_OBJECT

public:
    Qcount_card(Model* model, QDialog* parent = nullptr);
    ~Qcount_card();
    void show();

private:
    Ui::count_card *ui;
    Model *model;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};

class Qcount_time : public QDialog {
    Q_OBJECT

public:
    Qcount_time(Model* model, QDialog* parent = nullptr);
    ~Qcount_time();
    void show();

private:
    time_t t;
    Ui::count_time *ui;
    Model *model;
    Qdate_time* time_start, *time_end;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
};

class Qcount_total : public QDialog {
    Q_OBJECT

public:
    Qcount_total(Model* model, QDialog* parent = nullptr);
    ~Qcount_total();
    void show();

private:
    Ui::count_total *ui;
    Model *model;

signals:
    void exit_signal();

private slots:
    void exit();
};

class Qcount : public QDialog {
    Q_OBJECT

public:
    Qcount(Model* model, QDialog* parent = nullptr);
    ~Qcount();

private:
    Ui::count *ui;
    Model *model;
    Qcount_card* count_card;
    Qcount_time* count_time;
    Qcount_total* count_total;
    int types;

private slots:
    void main();
    void exit();

signals:
    void exit_signal();
    void start_card();
    void start_total();
    void start_time();
};
#endif // COUNT_H
