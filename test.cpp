#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <tuple> 

using namespace std;

class OrderBook {
public :
void add(int order_id, char side, double price, int size);
void modify(int order_id, int new_size);
void remove(int order_id);
double get_price(char side, int level);
int get_size(char side, int level);

void print();

private:
unordered_map<int,tuple<char,double, int>> orders;

//unordered_map<int,pair<double, int>> ordersS; 
};

void OrderBook::add(int order_id, char side, double price, int size){
     orders[order_id]=make_tuple(side, price,size);
//if (side == 'B')
//    ordersB[order_id]=make_pair(price,size);
//else if (side =='S')
 //   ordersS[order_id]=make_pair(price,size);
}

void OrderBook::modify(int order_id, int new_size){
      tuple<char,double, int> data = orders[order_id];
      get<2>(data) = new_size;
      orders[order_id]=data;
}

double get_price(char side, int level){
return 100;
}

int get_size(char side, int level){
return 80;
}

void OrderBook::print(){
      for (auto e : orders){  
    
      cout<<"order "<<e.first<<",";
      cout<<get<0>(e.second)<<",";
      cout<<get<1>(e.second)<<",";
      cout<<get<2>(e.second)<<"\n";
     }
}


class Order{
};

void execute(OrderBook& ob, char* str){
char * pch;
  pch = strtok (str," ");
  while (pch != NULL)
  {
    if (strcmp(pch, "add")==0) {
         pch = strtok (NULL, " ");
        int order_id = stoi(pch);
        //cout<<"order"<<order_id;
        pch = strtok (NULL, " ");
        char side = pch[0];
        pch = strtok (NULL, " "); 
        double price = stod(pch);
        pch = strtok (NULL, " ");
       int size = stoi(pch);
       pch = strtok (NULL, " ");
      ob.add(order_id,side,price,size);
      ob.print();
      }
     else if (strcmp(pch, "modify")==0) {
         pch = strtok (NULL, " ");
        int order_id = stoi(pch);        
        pch = strtok (NULL, " ");
       int size = stoi(pch);
       pch = strtok (NULL, " ");
      ob.modify(order_id,size);
      ob.print();
      }
    else if (strcmp(pch, "get")==0) {
         pch = strtok (NULL, " ");
         if (strcmp(pch, "price")==0) {
             pch = strtok (NULL, " ");
             char side = pch[0];        
             pch = strtok (NULL, " ");
             int level = stoi(pch);
       
             double p = ob.get_price(side,level);
              cout<<p;
          }
         else if (strcmp(pch, "size")==0) {
             pch = strtok (NULL, " ");
             char side = pch[0];        
             pch = strtok (NULL, " ");
             int level = stoi(pch);       
             double p = ob.get_price(side,level);
              cout<<p;
          }

        int order_id = stoi(pch);        
        pch = strtok (NULL, " ");
       int size = stoi(pch);
       pch = strtok (NULL, " ");
      ob.modify(order_id,size);
      ob.print();
      }
  }
}


int main()
{
  OrderBook ob;

  char str[] ="add 1 B 45.2 100";
  execute(ob, str);
  char str1[] ="modify 1 5";
  execute(ob, str1);
  char str2[] ="get price B 1 //this returns 45.2";
  execute(ob, str2);
  return 0;
}
