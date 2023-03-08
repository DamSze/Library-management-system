#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
enum Genre
{
    Fantasy,Science_Fiction,Historical_Fiction,Biography,Romance,Horror,Suspense,Adventure,Thriller
};
class ListOfBooks
{
    private:
    vector<int> book_free_id;
    class Book
    {
        private:

        string title;
        string author;
        bool is_available=true;
        int id;//created automatically when Book is created
        Genre genre;
        static int id_ref;//used to give unique id's
        //Customer* customer
        public:

        Book(const string& author,const string& title,const Genre& genre);
        //gives it unique ID with number 3 at the beginning
        Book(string author,string title,Genre genre,int id);
        ~Book();//destructor
        int getId();//returns id of a book
        bool getAvaibility();
        string getTitle();
        void printBook();//prints all information about a book
        void setAvaibility(const bool& value);
        friend class ListOfBooks;
        friend class Library;
        friend ostream& operator<<(ostream& os, const ListOfBooks::Book& book);
    };
    public:
    ~ListOfBooks();
    vector<Book> list;
    void addBook(const string& title,const string& author,const Genre& genre);
    //adds new book to the list
    //maintaines alphabetical order of title
    //gives it unique ID with number 1 at the beginning
    //increase number_of_books
    void deleteBook(const int& id);
    //deletes book by id

    bool findBookTitle(const string& title);
    //returns true if the book was found or false otherwise
    bool findBookGenre(const Genre& genre);
    bool findBookAuthor(const string& author);
    bool check_books_avaibility(const int& id);//returns true if book is available
    bool check_books_avaibility(const string& title);//returns true if book is available
    void printGenre(const Genre& genre);
    void printAuthor(const string&Author);
    int getBookSize();
    ListOfBooks::Book* findBook(const int& id);

   friend ostream& operator<<(ostream& os, const ListOfBooks::Book& book);
   friend class Customer;
   friend class Library;
};




#endif//BOOK_H_INCLUDED