#ifndef _MODEL_
#define _MODEL_
#include"linklist/billinglist.h"
#include"linklist/cardlist.h"
#include"node/billing.h"
#include"node/card.h"
class Model
{
public:
    Cardlist cardlist;
    Billinglist billinglist;
};
#endif
