#include"include/model/linklist/billinglist.h"
#include<stdlib.h>
#include<iostream>
Billinglist::Billinglist():count(0),fAmount(0){
    head = new Billing();
    head->next = NULL;
    FILE* fp = fopen(path.c_str(), "rb");
    fread(&fAmount, sizeof(float), 1, fp);
    if(fp != NULL){
        Billing node;
        while (!feof(fp)){
            fread(&node, sizeof(Billing), 1, fp);
            add(node);
        }
        fclose(fp);
    }
}

bool Billinglist::add(Billing billing){
    if(query(billing)) return false;
    {
        count++;
        Billing* r = head;
        Billing* n = new Billing(billing), *temp = r->next;
        r->next = n;
        n->next = temp;
        return true;
    }
}

bool Billinglist::query(Billing billing){
    Billing* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(billing)) return true;
    }
    return false;
}

vector<string> Billinglist::get(time_t tStart, time_t tEnd){
    vector<string> list;
    Billing* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check_time(tStart, tEnd)){
            list.push_back(r->to_string());
        };
    }
    return list;
}

vector<string> Billinglist::get(char* aName){
    vector<string> list;
    Billing* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check_name(aName)){
            list.push_back(r->to_string());
        };
    }
    return list;
}

bool Billinglist::del(Billing billing){
    Billing* r = head;
    bool ret = false;
    for(int i = 0;i < count;i++){
        r = r->next;
        ret = r->check(billing);
        if(ret) break;
    }
    Billing* d = r->next;
    r->next = r->next->next;
    delete d;
    count--;
    return ret;
}

int Billinglist::getcount(){
    return count;
}

float Billinglist::getfAmount(){
    return int(fAmount * 100) / 100.0;
}

void Billinglist::setfAmount(float fAmount){
    this->fAmount += fAmount;
}
   
Billinglist::~Billinglist(){
    Billing* r = head;
    for (int i = 0; i < count; i++) {
        Billing* d = r;
        r = r->next;
        delete d;
    }
}

bool Billinglist::save(){
    FILE* fp = fopen(path.c_str(), "wb");
    if(fp != NULL){
        Billing* r = head;
        fwrite(&fAmount, sizeof(float), 1, fp);
        for(int i = 0;i < count;i++){
            r = r->next;
            fwrite((r), 1, sizeof(Billing), fp);
        }
        fclose(fp);
    }
    return fp != NULL;
}

string Billinglist::getpath(){
    return path;
}

void Billinglist::setpath(string path){
    this->path = path;
}
