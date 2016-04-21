//
#include "BookNode.h"
//using namespace _;

  BookNode::BookNode(const string &title, int bookId, double price, int amount, int //BookType booktype)
  {
    this>title = title;
    this>bookId = bookId;
    this>price = price;
    this>amount = amount;
    //this>booktype = booktype;
  }
  
  BookNode::BookNode()
  {
    title = "";
    bookId = 0;
    price = 0.0;
    amount = 0;
    //booktype = ??;
  }
  
  void BookNode::setTitle(const string &title)
  {
    this>title = title;
  }
  string BookNode::getTitle()
  {
    return title;
  }
  
  void BookNode::setBookId(int Bookid)
  {
    this>BookId = BookId;
  }
  int BookNode::getId()
  {
    return BookId;
  }
  
  void BookNode::setPrice(double price)
  {
    this>price = price;
  }
  double BookNode::getPrice()
  {
    return price;
  }
  
  void BookNode::setAmount(int amount)
  {
    this>amount = amount;
  }
  int BookNode::getAmount()
  {
    return amount;
  }
  
  //
  //
  //BOOKTYPE
  //
  //
  
  void BookNode::print()
  {
    cout << "Book title: " << title
      << "\nBookID: " << bookId
      << "\nPrice: " << price
      << "\nAmount: " << amount;
      //BookType??
  }
