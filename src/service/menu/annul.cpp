#include "include/service/menu/annul.h"
#include"include/model/node/card.h"
Qannul::Qannul(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::annul), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qannul::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qannul::exit);
};

Qannul::~Qannul(){
    delete ui;
};

void Qannul::main(){
    Result ret(this);
    if (ui->password->text().size() > 9 || ui->aName->text().size() > 18)   ret.Input_over_len();
    else{
         Card card(ui->aName->text().toUtf8().data(), ui->password->text().toUtf8().data());
         if(!model->cardlist.get(card))  ret.id_error();
         else if(card.get_nStatus()) ret.logon_error();
         else if(card.get_Balance() <= 0) ret.money_less_error();
         else{
             ret.refund(card.get_Balance());
             model->cardlist.del(card);
         }
         if(!model->cardlist.save() || !model->billinglist.save()) ret.save_error();
         exit();
    }
}

void Qannul::exit(){
    ui->password->clear();
    ui->aName->clear();
    emit exit_signal();
}
