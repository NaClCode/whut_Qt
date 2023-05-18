#include "include/service/menu/admin.h"
#include"include/model/node/card.h"
#include"include/global.h"
#include"include/service/menu/count.h"
Qadmin::Qadmin(Model *model, QDialog *parent): QDialog(parent), ui(new Ui::admin), model(model){
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Qadmin::main);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Qadmin::exit);
};

Qadmin::~Qadmin(){
    delete ui;
};

void Qadmin::main(){
    Result ret(this);
    if(ui->password->text() == QString(admin_password.c_str()) && ui->aName->text() == QString(admin_name.c_str())){
         emit start_count();
    }else{
         Result ret(this);
         ret.admin_error();
    }
    ui->password->clear();
    ui->aName->clear();
}

void Qadmin::exit(){
    ui->password->clear();
    ui->aName->clear();
    emit exit_signal();
}
