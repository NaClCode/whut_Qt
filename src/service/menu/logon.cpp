#include "include/service/menu/logon.h"
#include"include/model/node/card.h"
Qlogon::Qlogon(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::logon), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qlogon::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qlogon::exit);
};

Qlogon::~Qlogon(){
    delete ui;
};

void Qlogon::main(){
    Result ret(this);
    if (ui->password->text().size() > 9 || ui->aName->text().size() > 18)   ret.Input_over_len();
    else{
         Card card(ui->aName->text().toUtf8().data(), ui->password->text().toUtf8().data());
         if(!model->cardlist.get(card))  ret.id_error();
         else if(card.get_nStatus()) ret.logon_error();
         else if(card.get_Balance() <= 0) ret.money_less_error();
         else{
             Billing billing(0, 1, card.get_Balance(), 0, ui->aName->text().toUtf8().data());
             model->billinglist.add(billing);
             model->cardlist.set_nStatus(card, 1);
             ret.success(card.get_Balance());
         }
         if(!model->cardlist.save() || !model->billinglist.save()) ret.save_error();
         exit();
    }
}

void Qlogon::exit(){
    ui->password->clear();
    ui->aName->clear();
    emit exit_signal();
}
