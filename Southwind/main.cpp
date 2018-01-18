#include <iostream>
#include "templatemethod.h"
#include <cstring>

using namespace std;

int main()
{
 const static vector<string> * catalog = {"Tablets offer", "SmartPhones offer", "Javas offer", "Androids offer", "Creatives offer"};
 const static vector<string>  * locations = {"KanbanCity","JustInTimeCity"};

  int status = -1;
  map<string,vector<string>> * tradingdata;
  Strategy * strategy = NULL;
  Context* context = NULL;
  TraderCompany* southwind = NULL;


  vector<string> * preorder = createPreOrder(catalog);
  string* location = getLocation(locations);

  if(location->compare(locations->at(0))== 0))
   /* we work with Kanban city */
    strategy = new KanbanStrategy();
   else
    strategy = new JustinStrategy();

   context = new Context(strategy);


   southwind = new Southwind(context);
   /* call to the template method */
   status = southwind->trade(preorder);


   tradingdata = southwind->getTraderdata();


   return status;






}



vector<string>* createPreOrder(vector<string>* catalog) {

 vector<int> * selecteds(-1,5);
 vector<string> * preOrder ;

 vector<string>::iterator it = catalog->begin();
 int i = 1;
 int j = 0;
 bool exit = false;

 cout << "Welcome to Southwind company please choose our offers : ";
 cout << endl << endl;
 cout << "Catalog :" << endl;
 while(it!= catalog->end()) {
    cout << "Number: " << i << " " << "Product: " << *it << "  " << endl;
    it++;
    i++;
 }

i = 100;
cout << "Choose your offers : (input correct offer's number (1-" << catalog->size() << ") or 0 number for exit) " << endl;

while(i!= 0 && !exit){
cout << "Offer's number: " << endl;
 cin >> i;

 if(i>0 && i< catalog->size())
    selecteds->push_back( i--);
 else{
    j++;
    cout << " Input number is incorrect (1-6)" << endl;
    i = 100;
   if(j==10){
    cout << "Too many incorrect input, exiting..." << endl;
    exit = true;
   }

 }

 it = selecteds->begin();
 while(it!= selecteds->end()){
    preOrder->push_back( catalog[ *(it++)]);

 }

    return preOrder;
}

string * getLocation( vector<string>* locations) {


 string * loc;

 vector<string>::iterator it = locations->begin();
 int i = 1;
 int j = 0;
 int k = 0;

 cout << "Welcome to Southwind, this are the possible locations:";
 cout << endl << endl;
 cout << "Location :" << endl;
 while(it!= locations->end()) {
    cout << "Number: " << i << " " << "Location : " << *it << "  " << endl;
    it++;
    i++;
 }

i = 100;

cout << "Choose your location : (input correct location's number (1-" << locations->size() << ") or 0 number for exit) " << endl;


while(i!= 0 && k>1){
cout<< "Location's number: " << endl;
 cin >> i;

 if(i>0 && i< locations->size()){
    selecteds->push_back( i--);
    k++;
 }
 else{
    j++;
    cout << " Input number is incorrect (1-" << localtions->size() << ")" << endl;
    i = 100;
   if(j==10){
    cout << "Too many incorrect input, exiting..." << endl;
    exit = true;
   }

 }

}

 it = selecteds->begin();
 while(it!= selecteds->end())
    *loc  =   locations[ *(it++)]);


    return loc;

}




