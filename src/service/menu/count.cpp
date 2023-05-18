#include "include/service/menu/count.h"
#include"include/model/node/card.h"
#include"include/service/menu/datetime.h"
#include<QDebug>
Qcount::Qcount(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::count),
model(model), types(0), count_card(new Qcount_card(model)), count_time(new Qcount_time(model)), count_total(new Qcount_total(model)){
    ui->setupUi(this);

    ui->count_time->setChecked(0);
    ui->count_card->setChecked(0);
    ui->count_total->setChecked(0);

    connect(ui->count_time, &QRadioButton::pressed, [=](){types = 0;});
    connect(ui->count_card, &QRadioButton::pressed, [=](){types = 1;});
    connect(ui->count_total, &QRadioButton::pressed, [=](){types = 2;});

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qcount::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qcount::exit);

    connect(this, &Qcount::start_card, [=]{count_card->show(); this->setHidden(true);});
    connect(this, &Qcount::start_time, [=]{count_time->show(); this->setHidden(true);});
    connect(this, &Qcount::start_total, [=]{count_total->show(); this->setHidden(true);});

    connect(count_total, &Qcount_total::exit_signal, [=]{count_total->setHidden(true); this->show();});
    connect(count_time, &Qcount_time::exit_signal, [=]{count_time->setHidden(true); this->show();});
    connect(count_card, &Qcount_card::exit_signal, [=]{count_card->setHidden(true); this->show();});

};

Qcount::~Qcount(){
    delete ui;
    delete count_card;
    delete count_time;
    delete count_total;
};

void Qcount::exit(){
    emit exit_signal();
};

void Qcount::main(){
    switch (types) {
        case 0: emit start_time();break;
        case 1: emit start_card(); break;
        case 2: emit start_total();break;
    }
}

Qcount_time::Qcount_time(Model *model, QDialog *parent):
QDialog(parent), ui(new Ui::count_time), model(model), time_start(new Qdate_time), time_end(new Qdate_time){
    ui->setupUi(this);
    ui->time_start->setDateTime(QDateTime::currentDateTime());
    ui->time_end->setDateTime(QDateTime::currentDateTime());
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qcount_time::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qcount_time::exit);
    connect(ui->start, &QPushButton::pressed, [=]{
        time_start->show();
    });
    connect(ui->end, &QPushButton::pressed, [=]{
        time_end->show();
    });
    connect(time_start, &Qdate_time::ret_time, this, [=](time_t t){
        ui->time_start->setDateTime(QDateTime::fromTime_t(t));
    });
    connect(time_end, &Qdate_time::ret_time, this, [=](time_t t){
        ui->time_end->setDateTime(QDateTime::fromTime_t(t));
    });
};

void Qcount_time::exit(){
    emit exit_signal();
}

void Qcount_time::show(){
    ui->time_start->setDateTime(QDateTime::currentDateTime());
    ui->time_end->setDateTime(QDateTime::currentDateTime());
    ui->listWidget->clear();
    this->setHidden(false);
}

void Qcount_time::main(){
    ui->listWidget->clear();
    vector<string> ret = model->billinglist.get(ui->time_start->dateTime().toTime_t(),
                                                ui->time_end->dateTime().toTime_t());
    QListWidgetItem* item = new QListWidgetItem[ret.size() + 1];
    item[0].setText(QString("种类\t状态\t卡号\t余额\t变化\t操作时间"));
    ui->listWidget->addItem(item);
    for(int i = 1;i <= (int)ret.size(); i++){
        item[i].setText(QString(ret[i - 1].c_str()));
        ui->listWidget->addItem(item + i);
    }
    this->setHidden(false);
}

Qcount_time::~Qcount_time(){
    delete ui;
    delete time_end;
    delete time_start;
};

Qcount_card::Qcount_card(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::count_card), model(model){
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qcount_card::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qcount_card::exit);
};

void Qcount_card::main(){
    ui->listWidget->clear();
    vector<string> ret = model->billinglist.get(ui->aName->text().toUtf8().data());
    QListWidgetItem* item = new QListWidgetItem[ret.size() + 1];
    item[0].setText(QString("种类\t状态\t卡号\t余额\t变化\t操作时间"));
    ui->listWidget->addItem(item);
    for(int i = 1;i <= (int)ret.size(); i++){
        item[i].setText(QString(ret[i - 1].c_str()));
        ui->listWidget->addItem(item + i);
    }
    this->setHidden(false);
}

void Qcount_card::exit(){

    emit exit_signal();
}

void Qcount_card::show(){
    ui->listWidget->clear();
    ui->aName->clear();
    this->setHidden(false);
}

Qcount_card::~Qcount_card(){
    delete ui;
};

Qcount_total::Qcount_total(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::count_total), model(model){
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &Qcount_total::exit);
    ui->lcdNumber->setSmallDecimalPoint(true);
    ui->lcdNumber->display(model->billinglist.getfAmount());
};

Qcount_total::~Qcount_total(){
    delete ui;
};

void Qcount_total::exit(){
    emit exit_signal();
}

void Qcount_total::show(){
    this->setHidden(false);
    ui->lcdNumber->display(model->billinglist.getfAmount());
}
