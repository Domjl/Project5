#include <string>
#include "booknode.h"
#include "fiction.h"
#include <iostream>


FictionNode::FictionNode(string cauthor,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author=cauthor;
}

FictionNode::FictionNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
    setBookType(ptype);
        this->author="";
}

string FictionNode::getAuthor()const{
        return this->author;
}
void FictionNode::setAuthor(string cauthor){
        this->author=cauthor;
}

void FictionNode::display(){
        BookNode::display();
        cout<<"Author:  \t"<<getAuthor()<<endl;
}

type FictionNode::getBookType() const{
        return this->btype;
}
void FictionNode::setBookType(int ptype){
        btype=BTYPE[ptype];
}