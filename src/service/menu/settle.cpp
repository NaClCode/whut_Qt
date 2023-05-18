#include "include/service/menu/settle.h"
#include"include/model/node/card.h"
#include"include/global.h"
#include"include/service/tool.h"
Qsettle::Qsettle(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::settle), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qsettle::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qsettle::exit);
};

Qsettle::~Qsettle(){
    delete ui;
};

void Qsettle::main(){
    Result ret(this);
    if (ui->password->text().size() > 9 || ui->aName->text().size() > 18)   ret.Input_over_len();
    else{
         Card card(ui->aName->text().toUtf8().data(), ui->password->text().toUtf8().data());
         if(!model->cardlist.get(card))  ret.id_error();
         else if(!card.get_nStatus()) ret.settle_error();
         else{
             int status;
             time_t stime = card.get_time(), etime = time(NULL);
             float money = (etime - stime) * price;
             float balance = r(card.get_Balance() - money);
             model->cardlist.set(card, 0, balance, money);
             if(balance >= 0){
                 status = 1;
                 ret.success(balance);
             }else{
                 status = 2;
                 ret.money_less_error();
             }
             Billing billing(1, status, balance, money * -1, ui->aName->text().toUtf8().data());
             model->billinglist.setfAmount(money);
             model->billinglist.add(billing);

         }
         if(!model->cardlist.save() || !model->billinglist.save()) ret.save_error();
         exit();
    }
}

void Qsettle::exit(){
    ui->password->clear();
    ui->aName->clear();
    emit exit_signal();
}
