
<h1 align="center">

  Library management system C++
  <br>
</h1>

<h4 align="center">Task made for OOP classes at uni</h4>
<h4 align="center">Program simulating managing library system. It allows for operations on books and customers who might borrow them.</h4>

* There are some restrictions regarding the functioning of the library
  - maximum number of borrowed books by customers
  - maximum number of workers
  - minimum salary

* Book
  - stores: unique id, title, author, genre, availability status
  - get the number of borrowed books
  - adding/deleting book
  - finding by genre/author/title
  - borrowing/returning a book
  - printing info about the book
  
  * Customer
  - stores: name, unique id, age, borrowed books, history of borrowed books
  - adding/deleting customers
  - finding customers
  - get the number of borrowed books
  - printing customer's history
  
  * Worker
  - stores: unique id, salary, name
  - prints all info about the worker
  - adding/deleting workers
  - finding a worker
