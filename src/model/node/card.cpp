#include"include/model/node/card.h"
#include<iomanip>
Card::Card():fTotalUse(0), nStatus(0),tStart(0), tEnd(0), tLast(0), fBalance(0), nUseCount(0){};
        
Card::Card(Card &card):nStatus(card.nStatus), tStart(card.tStart), tEnd(card.tEnd),
fTotalUse(card.fTotalUse), tLast(card.tLast), nUseCount(card.nUseCount), fBalance(card.fBalance){
    strcpy(aName, card.aName);
    strcpy(aPwd, card.aPwd);
}

Card::Card(char* aName, char* aPwd, float fBalance):fBalance(fBalance), fTotalUse(0), nUseCount(0),
nStatus(0), tStart(time(NULL)), tEnd(time(NULL) + TIME), tLast(time(NULL)){
    strcpy(this->aName, aName);
    strcpy(this->aPwd, aPwd);
}

Card::Card(char* aName, char* aPwd):fBalance(0), fTotalUse(0), nUseCount(0),
nStatus(0), tStart(time(NULL)), tEnd(time(NULL)), tLast(time(NULL)){
    strcpy(this->aName, aName);
    strcpy(this->aPwd, aPwd);
}

string Card::to_string(){
    stringstream ss;
    ss << aName << "\t";
    char time[20], tStart[20], tEnd[20];
    switch (nStatus){
        case 0: ss << "未上机"; break;
        case 1: ss << "已上机"; break;
    }
    strftime(time, 20, "%Y-%m-%d %H:%M:%S", localtime(&tLast));
    strftime(tStart, 20, "%Y-%m-%d %H:%M:%S", localtime(&this->tStart));
    strftime(tEnd, 20, "%Y-%m-%d %H:%M:%S", localtime(&this->tEnd));
    ss << "\t" << fixed << setprecision(2) << fBalance;
    ss << "\t" << fixed << setprecision(2) << fTotalUse;
    ss << "\t" << nUseCount;
    ss << "\t" << time;
    ss << "\t" << tStart;
    ss << "\t" << tEnd;
    return ss.str();
}

float Card::get_Balance(){
    return fBalance;
}

int Card::get_nStatus(){
    return nStatus;
}

time_t Card::get_time(){
    return tLast;
}

void Card::set(int nStatus, float fBalance, float fTolalUse){
    this->nStatus = nStatus;
    this->fBalance = fBalance;
    this->fTotalUse += fTolalUse;
    this->tLast = time(NULL);
    this->nUseCount++;
}

void Card::set_Balance(float fBalance){
    this->fBalance = fBalance;
}

void Card::set_nStatus(int nStatus){
    this->nStatus = nStatus;
}

bool Card::check(Card card){
    return !strcmp(card.aName, this->aName) && !strcmp(card.aPwd, this->aPwd) && strlen(card.aName) == strlen(this->aName) && strlen(card.aPwd) == strlen(this->aPwd);
}

bool Card::check_name(Card card){
    return !strcmp(card.aName, this->aName) && strlen(card.aName) == strlen(this->aName);
}

Card& Card::operator=(Card card){
    strcpy(aName, card.aName);
    strcpy(aPwd, card.aPwd);
    fBalance = card.fBalance;
    fTotalUse = card.fTotalUse;
    nStatus = card.nStatus;
    nUseCount = card.nUseCount;
    tEnd = card.tEnd;
    tLast = card.tLast;
    tStart = card.tStart;
    return *this;
}

bool Card::check_name(char* name, int types){
    switch (types){
        case 1:{
            return !strcmp(name, this->aName) && strlen(name) == strlen(this->aName);
        }break;
        case 2:{
            return strstr(this->aName, name) != NULL;
        }break;
    }
    return false;
}
