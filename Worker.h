#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED
//#include"Library.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Worker
{
private:
    string name;
    float salary;
    int id;
    static int id_ref;//used to give unique id's
    //Library* library;

public:
    Worker(const string& name,const float& salary);//constructor assingns automatically unique id
    Worker(const string& name,const float& salary,const int& id);//constructor assingns unique id
    ~Worker();//destructor
    
    float getSalary();//returns salary
    void setSalary(float& salary);//sets salary of a worker
    int getId();
    string getName();
    void printWorker();//prints all information about the worker
    friend ostream& operator<<(ostream& os, const Worker& worker);
    
};

#endif// WORKER_H_INCLUDED