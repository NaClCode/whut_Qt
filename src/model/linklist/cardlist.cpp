#include"include/model/linklist/cardlist.h"
Cardlist::Cardlist():count(0){
    head = new Card();
	head->next = NULL;
    FILE* fp = fopen(path.c_str(), "rb");
    if(fp != NULL){
        Card node;
        while (!feof(fp)){
            fread(&node, sizeof(Card), 1, fp);
            add(node);
        }
        fclose(fp);
    }
    /*
    FILE* fp = fopen(path.c_str(), "rb");
    if(fp != NULL){
        Card card;
        while (!feof(fp)){
            fread(&node, sizeof(Card), 1, fp);
            add(card);
        }
        fclose(fp);
    }
    */
}

bool Cardlist::add(Card card){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check_name(card)) return false;
    }
    r = head;
    Card* n = new Card(card), *temp = r->next;
    r->next = n;
    n->next = temp;
    count++;
    return true;
    /*
    if(count <= MAX){
        cardlist[count] = card;
        count++;
        return true;
    }else{
        return false;
    }
    */
}

bool Cardlist::query(Card card){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)) return true;
    }
    return false;
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r.check(card)){
            return true;
        }
    }
    */
}

bool Cardlist::get(Card &card){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)){
            card = *r;
            return true;
        }
    }
    return false;
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r.check(card)){
            card = r.check(card);
            return true;
        }
    }
    */
}

bool Cardlist::del(Card &card){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)){
            Card* d = r;
            r = r->next;
            card = *d;
            delete d;
            count--;
            return true;
        }
    }
    return false;
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r = check(card)){
            for(int j = i;j < count;j++)
                card[j] = card[j+1];
            count--;
            return true;
        }
    }
    return false;
    */
}

bool Cardlist::set(Card card, int nStatus, float fBalance, float fTolalUse){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)){
            r->set(nStatus, fBalance, fTolalUse);
            return true;
        }
    }
    return false;
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r.check(card)){
            r.set(nStatus, fBalance, fTolalUse);
            return true;
        }
    }
    */
}
    
bool Cardlist::set_Balance(Card card, float fBalance){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)){
            r->set_Balance(fBalance);
            return true;
        }
    }
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r.check(card))
            r.set_Balance(fBalance);
        return true;
    }
    */
    return false;
}

bool Cardlist::set_nStatus(Card card, int nStatus){
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check(card)){
            r->set_nStatus(nStatus);
            return true;
        }
    }
    /*
    for(int i = 0;i < count;i++){
        r = cardlist[i];
        if(r.check(card))
            r.set_nStatus(nStatus);
        return true;
    }
    */
    return false;
}

int Cardlist::getcount(){
    return count;
}

Cardlist::~Cardlist(){
    Card* r = head;
    for (int i = 0; i < count; i++) {
        Card* d = r;
        r = r->next;
        delete[] d;
    }
}

bool Cardlist::save(){
    FILE* fp = fopen(path.c_str(), "wb");
    if(fp != NULL){
        Card* r = head;
        for(int i = 0;i < count;i++){
            r = r->next;
            //Card r = cardlist[i];
            fwrite(r, sizeof(Card), 1, fp);
        }
        fclose(fp);
    }
    return fp != NULL;
    
}

void Cardlist::setpath(string path){
    this->path = path;
}

string Cardlist::getpath(){
    return path;
}

bool Cardlist::querycard(char* aName, vector<string>& str, int type){
    str.clear();
    bool ret = false;
    Card* r = head;
    for(int i = 0;i < count;i++){
        r = r->next;
        if(r->check_name(aName, type)){
            str.push_back(r->to_string());
            ret = true;
        }
    }
    return ret;
}
