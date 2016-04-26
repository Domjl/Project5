using namespace std;
#include <string>
#include <iostream>
#include "booknode.h"

int BookNode::usedId=0;
int BookNode::bookNo=0;

//BookNode constructor
BookNode::BookNode(const string ptitle, int pid,double cprice,int camount){
        this->title=ptitle;
        this->bookId=pid;
        usedId=this->bookId;
        bookNo+=1;
        this->price=cprice;
        this->amount=camount;
        next=NULL;
}

//get the book number
int BookNode::getBookNo(){
        return bookNo;
}

//set the BookNode title
void BookNode::setTitle(const string ptitle){
        this->title=ptitle;
}

//get the Book title
string BookNode::getTitle() const{
        return this->title;
}

//Set the Book ID to pid
void BookNode::setBookId(int pid){
        this->bookId=pid;
}

//Get the Book ID.
int BookNode::getBookId() const{
        return this->bookId;
}

//Set the Book price to cprice (input)
void BookNode::setPrice(double cprice){
        this->price=cprice;
}

//Get the Book's price
double BookNode::getPrice() const{
        return this->price;
}

//Set the number of books (amount)
void BookNode::setAmount(int camount){
        this->amount=camount;
}

//Get the number of books (amount)
int BookNode::getAmount() const{
        return this->amount;
}

//We purchased a book, in this case we have been told we can increment amount of books.
void BookNode::sold(){
        this->amount++;
}

//Display the BookNode's information to Cout. 
void BookNode::display(){
        cout<<"BookInfo"<<endl;
        cout<<"Type:   \t"<<getBookType()<<endl;
        cout<<"Title:  \t"<<getTitle()<<endl;
        cout<<"BookId: \t"<<getBookId()<<endl;
        cout<<"Price:  \t$"<<getPrice()<<endl;
        cout<<"Amount: \t"<<getAmount()<<endl;
}
