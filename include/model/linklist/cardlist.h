#ifndef _cardlist_
#define _cardlist_
#include"include/model/node/card.h"
#include"include/global.h"
#include<stdlib.h>
#include<vector>
//#define MAX 1000
using namespace std;
class Cardlist{
private:
    string path = cardlist_path;
    //Card cardlist[MAX];
    Card* head;
    int count;
public:
    Cardlist();
    bool add(Card card);
    bool query(Card card);
    bool get(Card &card);
    bool querycard(char* aName, vector<string>& str, int type);
    string getpath();
    bool del(Card &card);
    bool set(Card card, int nStatus, float fBalance, float fTolalUse);
    bool set_Balance(Card card, float Balance);
    bool set_nStatus(Card card, int nStatus);
    void setpath(string path);
    bool save();
    int getcount();
    ~Cardlist();
};
#endif

