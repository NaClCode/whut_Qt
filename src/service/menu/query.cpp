#include "../../../include/service/menu/query.h"
#include"include/model/node/card.h"
#include<QListView>
 #include<QListWidgetItem>
Qquery::Qquery(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::query), model(model), types(2){
    ui->setupUi(this);
    ui->querybig->setChecked(0);
    ui->querysmall->setChecked(0);
    connect(ui->querybig, &QRadioButton::pressed, [=](){types = 2;});
    connect(ui->querysmall, &QRadioButton::pressed, [=](){types = 1;});
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qquery::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qquery::exit);
};

Qquery::~Qquery(){
    delete ui;
};

void Qquery::main(){
    Result ret(this);
    if (ui->aName->text().size() > 18) ret.Input_over_len();
    else{
        ui->listWidget->clear();
        vector<string> str;
        model->cardlist.querycard(ui->aName->text().toUtf8().data(), str, types);
        QListWidgetItem* item = new QListWidgetItem[str.size() + 1];
        item[0].setText(QString("卡号\t状态\t余额\t累计\t次数\t上次使用时间\t\t开卡时间\t\t\t结束时间"));
        ui->listWidget->addItem(item);
        for(int i = 1;i <= (int)str.size(); i++){
            item[i].setText(QString(str[i - 1].c_str()));
            ui->listWidget->addItem(item + i);
        }
    }
    this->setHidden(false);
}

void Qquery::exit(){
    emit exit_signal();
}

void Qquery::show(){
    ui->listWidget->clear();
    ui->aName->clear();
    this->setHidden(false);
}
