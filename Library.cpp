#include"Library.h"

Library::Library(const string& city)
{
    this->city=city;
}
Library::~Library()
{
    
}
void Library::addWorker(const string& name, const float& salary)
{
    if(getWorkerSize()>=MAXWORKERS||salary<MINSALARY)
    {
        //there can be up to MAXWORKERS in a single library and salary cannot be lower than minsalary
    }
    else
    {
        if(worker_free_id.size()!=0)
        {
            sort(worker_free_id.begin(),worker_free_id.end());
            worker.push_back(Worker(name,salary,worker_free_id.front()));
            worker_free_id.pop_back();
        }
        else
        worker.push_back(Worker(name,salary));
    }
    
}
void Library::deleteWorker(const int& id)
{
    for(int i=0;i<worker.size();i++)
    {
        if(worker[i].getId()==id)
        {
            worker_free_id.push_back(id);
            worker.erase(worker.begin()+i);
            break;
        }
    }
}
bool Library::findWorker(const int& id)
{
    for(int i=0;i<worker.size();i++)
    {
        if(worker[i].getId()==id)
        {
            return true;
        }
    }
    return false;
}
void Library::addCustomer(const string& name,const int& age)
{
    if(age>15)
    {
        if(customer_free_id.size()!=0)
        {
            sort(customer_free_id.begin(),customer_free_id.end());
            customer.push_back(Customer(name,age,customer_free_id.front()));
            customer_free_id.pop_back();
        }
        else
        customer.push_back(Customer(name,age));
    }
    
}
void Library::deleteCustomer(const int& id)
{
    for(int i=0;i<customer.size();i++)
    {
        if(customer[i].get_id()==id)
        {
            customer_free_id.push_back(id);
            customer.erase(customer.begin()+i);
            break;
        }
    }
}
Customer* Library::findCustomer(const int& id)
{
    for(int i=0;i<customer.size();i++)
    {
        if(customer[i].get_id()==id)
        {
            return &(customer[i]);
        }
    }
    return nullptr;
}
void Library::borrowBook(const int& customer_id,const int& book_id)
{
    Customer *customer1;
    customer1=findCustomer(customer_id);
    if(customer1==nullptr||customer1->borrowed.size()>=2)
    {
        //customer can have MAXBOOKS books at the same time
    }
    else
    {
        for(int i=0;i<Blist.list.size();i++)
        {
            if(Blist.list[i].getId()==book_id)
            {
                if(Blist.list[i].getAvaibility()!=0)
                {
                    customer1->borrowed.push_back(&(Blist.list[i]));
                    Blist.list[i].setAvaibility(false);
                    customer1->history.push_back(Blist.list[i].getTitle());
                }
                break;
            }
        }
    }
    
}
void Library::borrowBook(const int& customer_id,const string&title)
{
    Customer *customer1;
    customer1=findCustomer(customer_id);
    if(customer1==nullptr||customer1->borrowed.size()>=MAXBOOKS)
    {
        //customer can have MAXBOOKS books at the same time
    }
    else
    {
        for(int i=0;i<Blist.list.size();i++)
        {
            if(Blist.list[i].getTitle()==title)
            {
                if(Blist.list[i].getAvaibility()!=0)
                {
                    customer1->borrowed.push_back(&(Blist.list[i]));
                    Blist.list[i].setAvaibility(false);
                    customer1->history.push_back(Blist.list[i].getTitle());
                    break;
                }
            }
        }
    }
    
}
void Library::returnBook(const int& customer_id,const int& book_id)
{
    Customer *customer1;
    customer1=findCustomer(customer_id);
    if(customer1!=nullptr)
    {
        for(int i=0;i<Blist.list.size();i++)
        {
            if(Blist.list[i].getId()==book_id)
            {
                for(int j=0;j<customer1->borrowed.size();j++)
                {
                    if(customer1->borrowed[j]->getId()==book_id)
                    {
                        Blist.list[i].setAvaibility(true);
                        customer1->borrowed.erase((customer1->borrowed.begin())+j);
                        break;
                    }
                }
            }
        }
    }
    
}
void Library::returnBook(const int& customer_id,const string& title)
{
    Customer *customer1;
    customer1=findCustomer(customer_id);
    if(customer1!=nullptr)
    {
        for(int i=0;i<Blist.list.size();i++)
        {
            if(Blist.list[i].getTitle()==title)
            {
                for(int j=0;j<customer1->borrowed.size();j++)
                {
                    if(customer1->borrowed[j]->getTitle()==title)
                    {
                        Blist.list[i].setAvaibility(true);
                        customer1->borrowed.erase((customer1->borrowed.begin())+j);
                        break;
                    }
                }
                break;
            }
        }
    }
    
}

int Library:: getWorkerSize()
{
    return this->worker.size();
}
int Library:: getCustomerSize()
{
    return this->customer.size();
}

ostream& operator<<(ostream&os,const Library& lib)
{
    os<<endl<<setw(30)<<"WORKERS"<<endl;
    os<<"ID"<<setw(25)<<"NAME"<<setw(25)<<"SALARY"<<endl;
    for(int i=0;i<lib.worker.size();i++)
    {
        os<<lib.worker[i]<<"\n";
    }
     os<<endl<<setw(30)<<"BOOKS"<<endl;
    os<<"ID"<<setw(25)<<"TITLE"<<setw(25)<<"AUTHOR"<<endl;
    for(int i=0;i<lib.Blist.list.size();i++)
    {
        os<<lib.Blist.list[i]<<"\n";
    }
    os<<endl<<setw(30)<<"CUSTOMERS"<<endl<<endl;
    os<<"ID"<<setw(25)<<"NAME"<<setw(25)<<"AGE"<<setw(24)<<"BOOK1"<<setw(33)<<"BOOK2"<<endl;
    for(int i=0;i<lib.customer.size();i++)
    {
        os<<lib.customer[i]<<"\n";
    }
    return os;

}

void Library::saveToFile()
{
    ofstream outdata;
    string filename=this->city;
    filename.append(".txt");
    outdata.open(filename);
    //saving worker
    for(int i=0;i<worker.size();i++)
    {
        outdata<<worker[i].getId()<<';'<<worker[i].getName()<<';'<<worker[i].getSalary();
        if(i!=worker.size()-1)
        outdata<<';';
    }outdata<<endl;
    //saving BookList

    for(int i=0;i<this->Blist.list.size();i++)
    {
        outdata<<this->Blist.list[i].getId()<<';'<<this->Blist.list[i].getTitle()<<';'<<this->Blist.list[i].author<<';'<<this->Blist.list[i].genre<<';'<<this->Blist.list[i].getAvaibility();
        if(i!=this->Blist.list.size()-1)
        outdata<<';';
    }outdata<<endl;


    //saving customer
    for(int i=0;i<customer.size();i++)
    {
        outdata<<customer[i].get_id()<<';'<<customer[i].get_name()<<';'<<customer[i].get_age()<<';';
        switch(customer[i].borrowed.size())
        {
            case 0:
            outdata<<'0'<<';';
            outdata<<'0';
            break;
            case 1:
            outdata<<customer[i].borrowed[0]->getId()<<';';
            outdata<<'0';
            break;
            case 2:
            outdata<<customer[i].borrowed[0]->getId()<<';';
            outdata<<customer[i].borrowed[1]->getId();
            break;
        }
        if(i!=customer.size()-1)
        outdata<<';';
    }outdata<<endl;

}