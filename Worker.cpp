#include"Worker.h"
int Worker::id_ref=1000;
Worker::Worker(const string& name,const float& salary)
{
    this->name=name;
    this->salary=salary;
    this->id=id_ref;
    id_ref++;
}
Worker::Worker(const string& name,const float& salary,const int& id)
{
    this->name=name;
    this->salary=salary;
    this->id=id;
}
Worker::~Worker()
{

}
float Worker::getSalary()
{
    return this->salary;
}
int Worker::getId()
{
    return this->id;
}
string Worker::getName()
{
    return this->name;
}
void Worker::setSalary(float& salary)
{
    this->salary=salary;
}
ostream& operator<<(ostream& os, const Worker& worker)
{
    os<<"["<<worker.id<<"]  "<<setw(20)<<worker.name<<setw(20)<<worker.salary<<" zl";
    return os;
}