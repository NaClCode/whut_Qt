#include "include/service/menu/datetime.h"
#include<QDebug>
#include<QDateTime>
Qdate_time::Qdate_time(QDialog *parent): QDialog(parent), ui(new Ui::datetime){
    ui->setupUi(this);
    for(int i = 0;i < 60;i++){
        qDebug() << QString::number(i);
        ui->comboBox->addItem(QString::number(i));
        ui->comboBox_2->addItem(QString::number(i));
    }
    connect(ui->pushButton, &QPushButton::pressed, this, &Qdate_time::main);
};

Qdate_time::~Qdate_time(){
    delete ui;
};

void Qdate_time::main(){
    Result ret(this);
    time_t t = QDateTime::fromString(ui->calendarWidget->selectedDate().toString("yyyy:M:d") + ":" +
              ui->comboBox->currentText() + ":" +
              ui->comboBox_2->currentText(),
              "yyyy:M:d:h:m").toTime_t();
    emit ret_time(t);
    this->hide();
}

