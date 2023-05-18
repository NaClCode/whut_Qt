#include"include/service/menu.h"
#include"include/global.h"
#include<QTimer>
QMenu::QMenu(Model* model, QWidget *parent):
QWidget(parent), ui(new Ui::Form), timer(nullptr), model(model), qadd(new Qadd(model)), qannul(new Qannul(model)),
qaddmoney(new Qaddmoney(model)), qquery(new Qquery(model)), qrefund(new Qrefund(model)), qlogon(new Qlogon(model)),
qsettle(new Qsettle(model)), qadmin(new Qadmin(model)), qcount(new Qcount(model)){
    ui->setupUi(this);

    connect(ui->annul, &QPushButton::pressed, [=](){this->setHidden(true);qannul->show();});
    connect(qannul, &Qannul::exit_signal, [=](){qannul->setHidden(true);this->show();});

    connect(ui->add, &QPushButton::pressed, [=](){this->setHidden(true);qadd->show();});
    connect(qadd, &Qadd::exit_signal, [=](){qadd->setHidden(true);this->show();});

    connect(ui->query, &QPushButton::pressed, [=](){this->setHidden(true);qquery->show();});
    connect(qquery, &Qquery::exit_signal, [=](){qquery->setHidden(true);this->show();});

    connect(ui->addmoney, &QPushButton::pressed, [=](){this->setHidden(true);qaddmoney->show();});
    connect(qaddmoney, &Qaddmoney::exit_signal, [=](){qaddmoney->setHidden(true);this->show();});

    connect(ui->refund, &QPushButton::pressed, [=](){this->setHidden(true);qrefund->show();});
    connect(qrefund, &Qrefund::exit_signal, [=](){qrefund->setHidden(true);this->show();});

    connect(ui->logon, &QPushButton::pressed, [=](){this->setHidden(true);qlogon->show();});
    connect(qlogon, &Qlogon::exit_signal, [=](){qlogon->setHidden(true);this->show();});

    connect(ui->settle, &QPushButton::pressed, [=](){this->setHidden(true);qsettle->show();});
    connect(qsettle, &Qsettle::exit_signal, [=](){qsettle->setHidden(true);this->show();});

    connect(ui->count, &QPushButton::pressed, [=](){this->setHidden(true);qadmin->show();});
    connect(qadmin, &Qadmin::exit_signal, [=](){qadmin->setHidden(true);this->show();});
    connect(qadmin, &Qadmin::start_count, [=](){qcount->show();qadmin->close();});

    connect(qcount, &Qcount::exit_signal, [=](){qcount->setHidden(true);this->show();});
};

QMenu::~QMenu(){
    delete ui;
    delete qadd;
    delete qaddmoney;
    delete qlogon;
    delete qrefund;
    delete qsettle;
    delete qquery;
    delete qadmin;
    delete qannul;
}

void QMenu::onTimeOut(){
    welcome->close();
    this->show();
    timer->stop();
    delete timer;
    timer = nullptr;
    welcome = nullptr;
}

void QMenu::exec(){
    timer = new QTimer;
    timer->start(waitting);
    welcome = new Qwelcome;
    welcome->show();
    connect(timer,&QTimer::timeout, this, &QMenu::onTimeOut);
}
