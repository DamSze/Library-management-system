#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include"Book.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
class Customer
{
private:
    int id;
    int age;
    static int id_ref;//used to give unique id's
    string name;
    vector<ListOfBooks::Book*> borrowed;//size of this must be lower than
    vector<string> history;
public:
    
    Customer(const string& name,const int& age);//constructor
    Customer(const string& name,const int& age,const int& id);
    ~Customer();//destructor
    int get_id();//rerurns id
    int get_age();//returns age
    string get_name();//returns name
    int booksBorrowed();//rerurns number of borrowed books
    void print_history();
    friend ostream& operator<<(ostream& os, const Customer& customer);
    friend class Library;
};


#endif//CUSTOMER_H_INCLUDED
