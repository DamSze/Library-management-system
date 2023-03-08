#include"Book.h"
int ListOfBooks::Book::id_ref=20000;
ListOfBooks::Book::Book(const string& author,const string& title,const Genre& genre)
{
    this->author=author;
    this->title=title;
    this->genre=genre;
    this->id=id_ref;
    id_ref++;
}
ListOfBooks::Book::Book(string author,string title,Genre genre,int id)
{
    this->author=author;
    this->title=title;
    this->genre=genre;
    this->id=id;
}
ListOfBooks::Book::~Book()
{

}
int ListOfBooks::Book::getId()
{
    return this->id;
}
bool ListOfBooks::Book::getAvaibility()
{
    return this->is_available;
}
string ListOfBooks::Book::getTitle()
{
    return this->title;
}
void ListOfBooks::Book::setAvaibility(const bool& value)
{
    this->is_available=value;
}
ListOfBooks::Book *ListOfBooks::findBook(const int &id)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].getId()==id)
        {
            return &(list[i]);
            break;
        }
    }
    return nullptr;
}
ostream& operator<<(ostream& os, const ListOfBooks::Book& book)
{
    os<<"["<<book.id<<"]    "<<setw(20)<<book.title<<setw(20)<<book.author;
    return os;
}
ListOfBooks::~ListOfBooks()
{
    
}
void ListOfBooks::addBook(const string& title,const string& author,const Genre& genre)
{
    if(book_free_id.size()!=0)
    {
        sort(book_free_id.begin(),book_free_id.end());
        list.push_back(Book(author,title,genre,book_free_id.front()));
        book_free_id.pop_back();
    }
    else
    list.push_back(Book(author,title,genre));
}
void ListOfBooks::deleteBook(const int& id)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].getId()==id)
        {
            book_free_id.push_back(id);
            list.erase(list.begin()+i);
            break;
        }
    }
}

bool ListOfBooks::findBookTitle(const string& title)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].title==title)
        {
            return true;
        }
    }
    return false;
}
bool ListOfBooks::findBookAuthor(const string& author)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].author==author)
        {
            return true;
        }
    }
    return false;
}
bool ListOfBooks::findBookGenre(const Genre& genre)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].genre==genre)
        {
            return true;
        }
    }
    return false;
}

bool ListOfBooks::check_books_avaibility(const int& id)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].getId()==id)
        {
            if(list[i].is_available==1)
            return true;
            else
            return false;
        }
    }
    return false;
}
bool ListOfBooks::check_books_avaibility(const string& title)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].title==title)
        {
            if(list[i].is_available==1)
            return true;
            else
            return false;
        }
    }
    return false;
}
void ListOfBooks::printGenre(const Genre& genre)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].genre==genre)
        {
            cout<<list[i]<<endl;
        }
    }
}
void ListOfBooks::printAuthor(const string& author)
{
    for(int i=0;i<list.size();i++)
    {
        if(list[i].author==author)
        {
            cout<<list[i]<<endl;
        }
    }
}

int ListOfBooks:: getBookSize()
{
    return this->list.size();
}