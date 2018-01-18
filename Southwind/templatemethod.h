#ifndef TEMPLATEMETHOD_H_INCLUDED
#define TEMPLATEMETHOD_H_INCLUDED

#include <iostream>
#include <string>
#include "strategy.h"
#include <map>
#include <vector>


/**
Southwind trading company

*/

typedef map<string,vector<string>> TradeData;

class TraderCompany {
public:
    TraderCompany(Context* c);
    ~TraderCompany();
    int trade(vector<string>* preorder);
    virtual int takeOrder();
    virtual int prepareOrder();
    virtual int computePrice();
    virtual int doShipping();
    virtual int doConfirm();
    map<string,vector<string>>* getTraderdata();
    int doReport();
private:
    Context* _context;
    map<string,vector<string>>  * _tradedata;
    vector<string> _preorder;
};

TraderCompany::TraderCompany(Context* c){
    this->_context = c;
}
int TraderCompany::trade(vector<string> * preorder) {
    this->_preorder = preorder;
    this->takeOrder();
    this->prepareOrder();
    this->computePrice();
    this->doShipping();

    return this->doConfirm();

}
int TraderCompany::doConfirm() {
    cout << " Operation confirm!!";
    return this->doReport();
}
map<string,vector<string>>* TraderCompany::getTraderdata() {
    return this->_tradedata;
}

class Southwind: public TraderCompany {
public:
    Southwind(Context * c);
    ~Southwind();
    int trade(vector<string> * preorder);
    virtual int takeOrder();
    virtual int prepareOrder();
    virtual int computePrice();
    virtual int doShipping();
    virtual int doConfirm();
    int doReport();
private:
    Context* _context;
    map<string,vector<string>>  * _tradedata;
    vector<string> * _preorder;
};


#endif // TEMPLATEMETHOD_H_INCLUDED
