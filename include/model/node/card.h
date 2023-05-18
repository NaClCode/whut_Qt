#ifndef _CARD_
#define _CARD_
#include<time.h>
#include<string.h>
#include<utility>
#include<string>
#include<sstream>
using namespace std;
const int TIME = 31536000; //有效期
class Card{
private:
    char aName[19];
    char aPwd[9];
    int nStatus;//0未上机, 1上机
    time_t tStart;
    time_t tEnd;
    float fTotalUse;
    time_t tLast;
    int nUseCount;
    float fBalance;
public:
    Card* next = nullptr;
    Card();
    Card(Card &card);
    Card(char* aName, char* aPwd, float fBalance);
    Card(char* aName, char* aPwd);
    string to_string();
    float get_Balance();
    int get_nStatus();
    time_t get_time();
    void set(int nStatus, float fBalance, float fTolalUse);
    void set_Balance(float aBalance);
    void set_nStatus(int nStatus);
    bool check(Card card);
    bool check_name(Card card);
    bool check_name(char* name, int types);
    Card& operator= (Card card);
};

#endif