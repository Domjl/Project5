using namespace std;
#include <string>
#include <iostream>

#include "booknode.h"

int BookNode::usedId=0;
int BookNode::bookNo=0;

BookNode::BookNode(const string ptitle, int pid,double cprice,int camount){
        this->title=ptitle;
        this->bookId=pid;
        usedId=this->bookId;
        bookNo+=1;
        this->price=cprice;
        this->amount=camount;
        next=NULL;
}


int BookNode::getBookNo(){
        return bookNo;
}

void BookNode::setTitle(const string ptitle){
        this->title=ptitle;
}

string BookNode::getTitle() const{
        return this->title;
}

void BookNode::setBookId(int pid){
        this->bookId=pid;
}

int BookNode::getBookId() const{
        return this->bookId;
}

void BookNode::setPrice(double cprice){
        this->price=cprice;
}

double BookNode::getPrice() const{
        return this->price;
}

void BookNode::setAmount(int camount){
        this->amount=camount;
}

int BookNode::getAmount() const{
        return this->amount;
}

void BookNode::sold(){
        this->amount++;
}

void BookNode::display(){
        cout<<"BookInfo"<<endl;
        cout<<"Type:   \t"<<getBookType()<<endl;
        cout<<"Title:  \t"<<getTitle()<<endl;
        cout<<"BookId: \t"<<getBookId()<<endl;
        cout<<"Price:  \t$"<<getPrice()<<endl;
        cout<<"Amount: \t"<<getAmount()<<endl;
}
