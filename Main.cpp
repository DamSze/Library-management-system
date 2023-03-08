#include"Library.h"


int main()
{
    Library A=Library("Warsaw");
    A.addWorker("Damian",1304);
    A.deleteWorker(1000);
    A.addWorker("Damian",1360);
    A.addWorker("Bob",4972);
    A.deleteWorker(1003);
    A.Blist.addBook("Harry Potter","J.K.Rowling",Fantasy);
    A.Blist.addBook("Stsar","Gerald",Science_Fiction);
    A.Blist.addBook("Tom Holl","gvfds",Fantasy);
    A.Blist.addBook("BBBB","AAA",Horror);
    A.Blist.addBook("Angels and Demons","Dan Brown",Adventure);
    A.Blist.addBook("Twilight","Stephenie Meyer",Romance);
   // A.Blist.printGenre(Fantasy);
    A.addCustomer("Tomek",19);
    A.addCustomer("Janek",21);
    //A.deleteCustomer(10000);
    A.addCustomer("Robert",18);
    A.addCustomer("Bob",19);
    A.borrowBook(10000,20000);
    A.borrowBook(10000,"Tom Holl");
    A.borrowBook(10001,"Angels and Demons");
    A.returnBook(10000,20000);
    A.borrowBook(10003,"Twilight");
    A.returnBook(10001,"Angels and Demons");
    A.borrowBook(10000,"BBBB");
    A.borrowBook(10000,"Angels and Demons");
    A.returnBook(10000,"BBBB");
    A.borrowBook(10000,"Twilight");
    A.addCustomer("Kuba",16);
    cout<<A;
    A.saveToFile();

   
   

}