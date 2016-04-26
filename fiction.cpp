#include <string>
#include "booknode.h"
#include "fiction.h"
#include <iostream>

//Constructor with ALL variables inputted. 
FictionNode::FictionNode(string cauthor,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author=cauthor;
}

//Constructor only including variables needed for a BookNode
//Sets author to default of empty.
FictionNode::FictionNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author="";
}

//Get the FictionNode Author.
string FictionNode::getAuthor()const{
        return this->author;
}
//Set the FictionNode author.
void FictionNode::setAuthor(string cauthor){
        this->author=cauthor;
}

//Display, Call the Book Node's diaplay and then send this class' unique characteristic to cout.
void FictionNode::display(){
        BookNode::display();
        cout<<"Author:  \t"<<getAuthor()<<endl;
}

//Return the BookNode type
type FictionNode::getBookType() const{
        return this->btype;
}
//Set the BookNode type
void FictionNode::setBookType(int ptype){
        btype=BTYPE[ptype];  //predefined list.
}
