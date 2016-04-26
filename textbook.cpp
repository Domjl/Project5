#include <string>
#include "booknode.h"
#include "textbook.h"
#include <iostream>

//Constructor with ALL variables inputted. 
TextbookNode::TextbookNode(string cauthor, int pedit, string cisbn,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author = cauthor;
        this->edition = pedit;
        this->isbn = cisbn;
}

//Constructor only including variables needed for a BookNode
//Sets edition to a default 0, author to empty, isbn to empty.
TextbookNode::TextbookNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author = "";
        this->edition = 0;
        this->isbn = "";
}

//get the TextbookNode author
string TextbookNode::getAuthor()const{
        return this->author;
}
//Set the TextbookNode author
void TextbookNode::setAuthor(string cauthor){
        this->author=cauthor;
}

//get the TextbookNode edition
int TextbookNode::getEdition()const{
        return this->edition;
}
//get the TextbookNode edition
void TextbookNode::setEdition(int pedit){
        this->edition=pedit;
}

//get the TextbookNode isbn
string TextbookNode::getIsbn()const{
        return this->isbn;
}
//get the TextbookNode isgn
void TextbookNode::setIsbn(string cisbn){
        this->isbn=cisbn;
}

//Display, Call the Book Node's diaplay and then send this class' unique characteristic to cout.
void TextbookNode::display(){
        BookNode::display();
        cout<<"Author:  \t"<<getAuthor()
        	<<"\nEdition: \t"<<getEdition()
        	<<"\nISBN: \t"<<getIsbn()<<endl;
}

//Return the BookNode type
type TextbookNode::getBookType() const{
        return this->btype;
}
//Set the BookNode type
void TextbookNode::setBookType(int ptype){
        btype=BTYPE[ptype];  //predefined list.
}
