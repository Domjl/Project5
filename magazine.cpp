#include <string>
#include "booknode.h"
#include "magazine.h"
#include <iostream>

MagazineNode::MagazineNode(int cissue,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
	setBookType(ptype);
        this->issue=cissue;
}

MagazineNode::MagazineNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
	setBookType(ptype);
        this->issue=0;
}

int MagazineNode::getIssue()const{
        return this->issue;
}
void MagazineNode::setIssue(int cissue){
        this->issue=cissue;
}

void MagazineNode::display(){
        BookNode::display();
        cout<<"Issue:  \t"<<getIssue()<<endl;
}

type MagazineNode::getBookType() const{
        return this->btype;
}
void MagazineNode::setBookType(int ptype){
        btype=BTYPE[ptype];
}
