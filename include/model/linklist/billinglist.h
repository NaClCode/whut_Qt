#ifndef _BILLINGLIST_
#define _BILLINGLIST_
#include<vector>
#include<string>
#include"include/global.h"
#include"include/model/node/billing.h"
using namespace std;
class Billinglist
{
private:
    string path = billinglist_path;
    Billing* head;
    int count;
    float fAmount = 0;
public:
    Billinglist();
    bool add(Billing billing);
    bool query(Billing billing);
    vector<string> get(time_t tStart, time_t tEnd);
    vector<string> get(char* aName);
    bool del(Billing billing);
    int getcount();
    float getfAmount();
    string getpath();
    void setfAmount(float fAomunt);
    void setpath(string path);
    bool save();
    ~Billinglist();
};
#endif
