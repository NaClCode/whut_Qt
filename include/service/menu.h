#ifndef MENU_H
#define MENU_H
#include<ui_menu.h>
#include<QPoint>
#include<QMouseEvent>
#include<QPaintEvent>
#include"menu/add.h"
#include"menu/query.h"
#include"menu/addmoney.h"
#include"menu/refund.h"
#include"menu/logon.h"
#include"menu/settle.h"
#include"menu/count.h"
#include"menu/welcome.h"
#include"menu/annul.h"
#include"menu/admin.h"
#include"include/model/model.h"
class Qadd;
class Qquery;
class Qaddmoney;
class Qrefund;
class Qlogon;
class Qsettle;
class Qcount;
class Qannul;
class Qadmin;
class QMenu : public QWidget {
    Q_OBJECT

public:
    QMenu(Model* model, QWidget* parent = nullptr);
    void exec();
    ~QMenu();
private:
    Ui::Form *ui;
    QTimer *timer;

    Qadd *qadd;
    Qquery *qquery;
    Qaddmoney *qaddmoney;
    Qrefund *qrefund;
    Qsettle *qsettle;
    Qlogon *qlogon;
    Qadmin *qadmin;
    Qannul *qannul;
    Qcount *qcount;
    Qwelcome *welcome;

    Model *model;

    void onTimeOut();
};
#endif // MENU_H
