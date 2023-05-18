#ifndef _BILLING_
#define _BILLING_
#include<time.h>
#include<string>
#include<sstream>
using namespace std;
class Billing
{
private:
    int type;//类型, 0上机, 1下机, 2充钱, 3退钱
    int nStatus; //0未结算, 1结算
    float fBalance;//当前操作后的余额
    time_t t;//操作时间
    float fMoney;//当前操作用了多少钱
    char card[19];//卡号
public:
    Billing* next = nullptr;
    Billing();
    Billing(Billing& billing);
    Billing(int type, int nStatus, float fBalance, float fMoney, char* card);
    Billing& operator = (Billing billing);
    bool check_time(time_t tStart, time_t tEnd);
    bool check_name(char* aName);
    bool check(Billing billing);
    string to_string();
};
#endif