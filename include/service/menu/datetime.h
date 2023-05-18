#ifndef DATETIME_H
#define DATETIME_H
#include<ui_datetime.h>
#include<time.h>
#include"include/service/menu/result.h"
class Qdate_time : public QDialog {
    Q_OBJECT

public:
    Qdate_time(QDialog* parent = nullptr);
    ~Qdate_time();

private:
    Ui::datetime *ui;

signals:
    void ret_time(time_t t);

public slots:
    void main();

};
#endif // DATETIME_H
