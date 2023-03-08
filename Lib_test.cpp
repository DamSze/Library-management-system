#include "Library.h"
#define TEST_STAGE 2
int main()
{
    #if TEST_STAGE==1

    Library A= Library("Warsaw");

    //adding worker
    A.addWorker("Damian",1000);
    if(A.getWorkerSize()!=0)
    cerr<<"MINIMAL SALARY IS 2200";
    A.addWorker("Damian",4000);
    if(A.getWorkerSize()!=1)
    cerr<<"ERROR SIZE SHOULD BE 1";
    
    A.addWorker("Bob",2345);
    //deleting worker
    A.deleteWorker(1001);
    if(A.getWorkerSize()!=1)
    cerr<<"ERROR SIZE SHOULD BE 1";
    A.addWorker("Kuba",4600);
    A.addWorker("Alex",7500);
    A.addWorker("Nguyen",2834.6);
    A.addWorker("Mateusz",3900);
    A.addWorker("Patryk",3100);
    A.addWorker("Ola",3100);
    A.addWorker("Jan",3284.5);
    //checking specifications
    if(A.getWorkerSize()!=5)
    cerr<<"5 IS MAXIMUM WORKER SIZE";
    
    //adding book
    A.Blist.addBook("Harry Potter","J.K.Rowling",Fantasy);
    if(A.Blist.getBookSize()!=1)
    cerr<<"ERROR SIZE OF BOOK LIST SHOULD BE 1";
    //deleting book
    A.Blist.deleteBook(20000);
    if(A.Blist.getBookSize()!=0)
    cerr<<"ERROR BOOK LIST SHOULD BE EMPTY";
    A.Blist.addBook("Harry Potter","J.K.Rowling",Fantasy);
    A.Blist.addBook("Stsar","Thomas",Science_Fiction);
    A.Blist.addBook("Tom Holl","gvfds",Fantasy);
    A.Blist.addBook("BBBB","AAA",Horror);
    A.Blist.addBook("Angels and Demons","Dan Brown",Adventure);
    A.Blist.addBook("Fifty Shades Freed","Random House",Romance);
    A.Blist.addBook("Eclipse","E.L.James",Science_Fiction);
    A.Blist.addBook("Billy Connolly","Stephenie Meyer",Biography);
    A.Blist.addBook("The Alchemist","Paulo Coelho",Fantasy);
    A.Blist.addBook("A Tale of Two Cities","Charles Dickens",Historical_Fiction);
    A.Blist.addBook("Dune","Frank Herbert",Science_Fiction);
    A.Blist.addBook("Fear of Flying","Erica Jong",Romance);
    A.Blist.addBook("Jaws","Peter Benchley",Thriller);
    A.Blist.addBook("Gone Girl","Gillian Flynn",Thriller);
    A.Blist.addBook("The Da Vinci Code","Dan Brown",Thriller);

    //adding customer

    A.addCustomer("Alex",13);
    if(A.getCustomerSize()!=0)
    cerr<<"ERROR CUSTOMER MUST BE OLDER THAN 15";
    A.addCustomer("Alex",16);
    if(A.getCustomerSize()!=1)
    cerr<<"ERROR CUSTOMER NOT ADDED";
    //deleting customer
    A.deleteCustomer(10000);
    if(A.getCustomerSize()!=0)
    cerr<<"ERROR CUSTOMER NOT DELETED";
    A.addCustomer("Piotr",18);
    A.addCustomer("Tomasz",21);
    A.addCustomer("Bill",17);
    A.addCustomer("Piotr",17);
    
    //borowing books
    A.borrowBook(10000,"Harry Potter");
    if(A.findCustomer(10000)->booksBorrowed()!=1)
    cerr<<"ERROR BOOK NOT BORROWED";
    A.borrowBook(10000,"Harry Potter");
    //borrowing same book twice
    if(A.findCustomer(10000)->booksBorrowed()!=1)
    cerr<<"ERROR NOT AVAILABLE BOOK CANNOT BE BORROWED";

    A.borrowBook(10000,"Eclipse");
    if(A.findCustomer(10000)->booksBorrowed()!=2)
    cerr<<"ERROR BOOK NOT BORROWED";

    //returning book
    A.returnBook(10000,"Eclipse");
    if(A.findCustomer(10000)->booksBorrowed()!=1)
    cerr<<"ERROR BOOK NOT RETURNED";
    
    //checking specifications
    A.borrowBook(10000,"The Da Vinci Code");
    A.borrowBook(10000,"A Tale of Two Cities");
    if(A.findCustomer(10000)->booksBorrowed()!=2)
    cerr<<"ERROR CUSTOMER CAN HAVE MAX 2 BOOKS AT THE TIME";
    //borrowing book for customer ot of range, shouldn't break program
    A.borrowBook(10004,"Dune");
    #endif

    #if TEST_STAGE ==2

    Library B= Library("London");
    B.addWorker("Kuba",4600);
    B.addWorker("Alex",7500);
    B.addWorker("Nguyen",2834.6);
    B.addWorker("Mateusz",3900);
    B.addWorker("Patryk",3100);
    B.addWorker("Ola",3100);
    B.addWorker("Jan",3284.5);

    B.Blist.addBook("Harry Potter","J.K.Rowling",Fantasy);
    B.Blist.addBook("Stsar","Thomas",Science_Fiction);
    B.Blist.addBook("Tom Holl","gvfds",Fantasy);
    B.Blist.addBook("BBBB","AAA",Horror);
    B.Blist.addBook("Angels and Demons","Dan Brown",Adventure);
    B.Blist.addBook("Fifty Shades Freed","Random House",Romance);
    B.Blist.addBook("Eclipse","E.L.James",Science_Fiction);
    B.Blist.addBook("Billy Connolly","Stephenie Meyer",Biography);
    B.Blist.addBook("The Alchemist","Paulo Coelho",Fantasy);
    B.Blist.addBook("A Tale of Two Cities","Charles Dickens",Historical_Fiction);
    B.Blist.addBook("Dune","Frank Herbert",Science_Fiction);
    B.Blist.addBook("Fear of Flying","Erica Jong",Romance);
    B.Blist.addBook("Jaws","Peter Benchley",Thriller);
    B.Blist.addBook("Gone Girl","Gillian Flynn",Thriller);
    B.Blist.addBook("The Da Vinci Code","Dan Brown",Thriller);
    B.Blist.addBook("TestBook","Dan Brown",Horror);

    B.addCustomer("Piotr",18);
    B.addCustomer("Tomasz",21);
    B.addCustomer("Bill",17);
    B.addCustomer("Piotr",17);

    B.borrowBook(10000,"The Da Vinci Code");
    B.borrowBook(10000,"A Tale of Two Cities");
    B.returnBook(10000,"A Tale of Two Cities");
    B.borrowBook(10000,"A Tale of Two Cities");
    B.borrowBook(10001,"BBBB");
    B.borrowBook(10002,"The Alchemist");
    B.borrowBook(10002,"Fifty Shades Freed");
    B.findCustomer(10000)->print_history();
    cout<<endl<<endl<<endl;
    cout<<B;
    cout<<endl<<endl<<"Genre print test"<<endl;
    B.Blist.printGenre(Fantasy);
    cout<<endl<<endl<<"Author print test"<<endl;
    B.Blist.printAuthor("Dan Brown");


    B.saveToFile();
    #endif


}