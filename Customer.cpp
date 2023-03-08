#include"Customer.h"
int Customer::id_ref=10000;
Customer::Customer(const string& name,const int& age)
{
    this->name=name;
    this->age=age;
    this->id=id_ref;
    id_ref++;
}
Customer::Customer(const string& name,const int& age,const int& id)
{
    this->name=name;
    this->age=age;
    this->id=id;
}
Customer::~Customer()
{

}
int Customer::get_id()
{
    return this->id;
}
int Customer::get_age()
{
    return this->age;
}
string Customer::get_name()
{
    return this->name;
}
int Customer::booksBorrowed()
{
    return this->borrowed.size();
}
void Customer::print_history()
{
    for(int i=0;i<history.size();i++)
    {
        cout<<i+1<<" "<<history[i]<<"\n";
    }
}
ostream& operator<<(ostream& os, const Customer& customer)
{
    os<<"["<<customer.id<<"]    "<<setw(20)<<customer.name<<setw(20)<<customer.age;
    if(customer.borrowed.size())
    for(int i=0;i<customer.borrowed.size();i++)
    {
        os<<setw(20)<<customer.borrowed[i]->getId()<<" "<<customer.borrowed[i]->getTitle();
    }
    return os;
}