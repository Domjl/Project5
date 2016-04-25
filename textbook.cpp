#include <string>
#include "booknode.h"
#include "textbook.h"
#include <iostream>

TextbookNode::TextbookNode(string cauthor, int pedit, string cisbn,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author = cauthor;
        this->edition = pedit;
        this->isbn = cisbn;
}

TextbookNode::TextbookNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author = "";
        this->edition = 0;
        this->isbn = "";
}

string TextbookNode::getAuthor()const{
        return this->author;
}
void TextbookNode::setAuthor(string cauthor){
        this->author=cauthor;
}

int TextbookNode::getEdition()const{
        return this->edition;
}
void TextbookNode::setEdition(int pedit){
        this->edition=pedit;
}

string TextbookNode::getIsbn()const{
        return this->isbn;
}
void TextbookNode::setIsbn(string cisbn){
        this->isbn=cisbn;
}

//might need to change to line by line cout.
void TextbookNode::display(){
        BookNode::display();
        cout<<"Author:  \t"<<getAuthor()
        	<<"\nEdition: \t"<<getEdition()
        	<<"\nISBN: \t"<<getIsbn()<<endl;
}

type TextbookNode::getBookType() const{
        return this->btype;
}
void TextbookNode::setBookType(int ptype){
        btype=BTYPE[ptype];
}