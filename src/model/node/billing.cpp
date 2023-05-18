#include"include/model/node/billing.h"
#include<string.h>
#include<time.h>
#include<iomanip>

Billing::Billing():type(0), nStatus(0), fBalance(0), t(0), fMoney(0){
}

Billing::Billing(int type, int nStatus, float fBalance, float fMoney, char* card):
type(type), nStatus(nStatus), fBalance(fBalance), fMoney(fMoney), t(time(NULL)){
    strcpy(this->card, card);
}

Billing::Billing(Billing& billing):type(billing.type), nStatus(billing.nStatus),
fBalance(billing.fBalance), fMoney(billing.fMoney), t(billing.t){
    strcpy(card, billing.card);
}

Billing& Billing::operator=(Billing billing){
    type = billing.type;
    nStatus = billing.nStatus;
    fBalance = billing.fBalance;
    t = billing.t;
    fMoney = billing.fMoney;
    strcpy(card, billing.card);
    return *this;
}

bool Billing::check_time(time_t tStart, time_t tEnd){
    return tStart <= t && t <= tEnd;
}

bool Billing::check_name(char* aName){
    return !strcmp(aName, this->card) && strlen(card) == strlen(aName);
}

string Billing::to_string(){
    stringstream ss;
    char time[20];
    strftime(time, 20, "%Y-%m-%d %H:%M:%S", localtime(&this->t));
    switch (type){
        case 0: ss << "上机";break;
        case 1: ss << "下机";break;
        case 2: ss << "充钱"; break;
        case 3: ss << "退钱";break;
    }
    switch (nStatus){
        case 1: ss << "\t" << "已结算"; break;
        case 2: ss << "\t" << "未结算"; break;
    }
    ss << "\t" << card;
    ss << "\t" << fixed << setprecision(2) << fBalance;
    ss << "\t" << fixed << setprecision(2) << fMoney;
    ss << "\t" << time;
    
    return ss.str();
}

bool Billing::check(Billing billing){
    return (billing.t == this->t) && !strcmp(billing.card, this->card);
}
