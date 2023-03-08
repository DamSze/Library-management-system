#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include"Worker.h"
#include"Book.h"
#include"Customer.h"
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>
using namespace std;

#define MAXBOOKS 2
#define MAXWORKERS 5
#define MINSALARY 2200

class Library
{
private:
    string city;
    vector<Worker> worker;
    vector<int> worker_free_id;
    vector<Customer> customer;
    vector<int>customer_free_id;

public:
    ListOfBooks Blist;
    Library(const string& city);//Creates Library with given city
    ~Library();//destructor
    void addWorker(const string& name,const float& salary);
    //creates worker with given name and salary
    //gives him unique ID with number 2 at the beginning
    //increase number_of_workers
    void deleteWorker(const int& id);
    //removes worker from workers list
    //decrement number_of_workers
    bool findWorker(const int& id);
    //returns true if worker is found
    
    void addCustomer(const string& name,const int& age);
    //creates customer with given name and age
    //gives him unique ID with number 2 at the beginning
    //increase number_of_customers
    void deleteCustomer(const int& id);
    //removes customer from customers list
    //decrement number_of_customers
    
    Customer* findCustomer(const int& id);
    void borrowBook(const int& customer_id,const int& book_id);
    void borrowBook(const int& customer_id,const string&title);
    
    void returnBook(const int& customer_id,const int& book_id);
    
    void returnBook(const int& customer_id,const string& title);
    //disconnect Book from Customer
    //change book's avaibility to True
    int getWorkerSize();
    int getCustomerSize();
    void saveToFile();

    friend ostream& operator<<(ostream&os,const Library& lib);
    //It will print all data collected for the library
    //Firstly it will print name of the city
    //Then it will print all data about workers
    //Then it will print all data about customers
    //Then it will print all data about books
};

#endif // LIBRARY_H_INCLUDED