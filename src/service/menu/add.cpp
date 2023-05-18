#include "include/service/menu/add.h"
#include"include/model/node/card.h"
#include"include/service/tool.h"
Qadd::Qadd(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::add), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qadd::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qadd::exit);
};

Qadd::~Qadd(){
    delete ui;
};

void Qadd::main(){
    bool ok;
    float fBalance = ui->fBalance->text().toFloat(&ok);
    Result ret(this);
    if (ui->password->text().size() > 9 || ui->aName->text().size() > 18)   ret.Input_over_len();
    else if (!ok)   ret.Input_no_num();
    else if(fBalance <= 0) ret.Input_less_zero();
    else{
         Card card(ui->aName->text().toUtf8().data(), ui->password->text().toUtf8().data(), r(fBalance));
         if(model->cardlist.add(card))  ret.success(card.get_Balance());
         else ret.repeat_error();
         if(!model->cardlist.save()) ret.save_error();
         exit();
    }
}

void Qadd::exit(){
    ui->password->clear();
    ui->aName->clear();
    ui->fBalance->clear();
    emit exit_signal();
}
