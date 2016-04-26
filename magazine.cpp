#include <string>
#include "booknode.h"
#include "magazine.h"
#include <iostream>

//Constructor with ALL variables inputted. 
MagazineNode::MagazineNode(int cissue,const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
	setBookType(ptype);
        this->issue=cissue;
}

//Constructor only including variables needed for a BookNode
//Sets issue to a default 0.
MagazineNode::MagazineNode(const string ptitle,int ptype,int pid,double cprice,int camount):BookNode(ptitle,pid,cprice,camount){
	setBookType(ptype);
        this->issue=0;
}

//Get the Magazine's issue number
int MagazineNode::getIssue()const{
        return this->issue;
}
//Set the Magazine's issue number
void MagazineNode::setIssue(int cissue){
        this->issue=cissue;
}

//Display, Call the Book Node's diaplay and then send this class' unique characteristic to cout.
void MagazineNode::display(){
        BookNode::display();
        cout<<"Issue:  \t"<<getIssue()<<endl;
}

//Return the BookNode type
type MagazineNode::getBookType() const{
        return this->btype;
}
//Set the BookNode type
void MagazineNode::setBookType(int ptype){
        btype=BTYPE[ptype]; //predefined list.
}
