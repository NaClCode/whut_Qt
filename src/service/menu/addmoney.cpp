#include"include/service/menu/addmoney.h"
#include"include/model/node/card.h"
#include"include/service/tool.h"
Qaddmoney::Qaddmoney(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::addmoney), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qaddmoney::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qaddmoney::exit);
};

Qaddmoney::~Qaddmoney(){
    delete ui;
};

void Qaddmoney::main(){
    bool ok;
    float fBalance = ui->fBalance->text().toFloat(&ok), aBalance;
    Result ret(this);
    if (ui->password->text().size() > 9 || ui->aName->text().size() > 18) ret.Input_over_len();
    else if (!ok) ret.Input_no_num();
    else if(fBalance <= 0) ret.Input_less_zero();
    else{
         Card card(ui->aName->text().toUtf8().data(), ui->password->text().toUtf8().data());
         if(model->cardlist.get(card)){
             aBalance = r(card.get_Balance() + fBalance);
             model->cardlist.set_Balance(card, aBalance);
             Billing billing(2, 1, aBalance, fBalance, ui->aName->text().toUtf8().data());
             model->billinglist.add(billing);
             ret.success(aBalance);
         }else ret.id_error();
         if(!model->cardlist.save() || !model->billinglist.save()) ret.save_error();
         exit();
    }
}

void Qaddmoney::exit(){
    ui->password->clear();
    ui->aName->clear();
    ui->fBalance->clear();
    emit exit_signal();
}
