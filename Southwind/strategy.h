#ifndef STRATEGY_H_INCLUDED
#define STRATEGY_H_INCLUDED
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef map<string, vector<string>> * TradeData;

class Strategy {
public:
 Strategy();
 ~Strategy();
 virtual int create(vector<string> * input);
 virtual int prepare();
 virtual int ship();
 virtual int confirm();
 map<string,vector<string>> * getData();
private:
    map<string,vector<string>> * _data;
};


class JustinStrategy: public Strategy {

};

class KanbanStrategy: public Strategy {


};


class Context {
public:
    Context(Strategy * s);
    ~Context();
    virtual int createOrder(vector<string> * input);
    virtual int prepareOrder();
    virtual int ship();
    virtual int confirm();
    map<string,vector<string>> * getOrder();
private:
    Strategy * _strategy;
    map<string,vector<string>>* _order;

};



#endif // STRATEGY_H_INCLUDED
