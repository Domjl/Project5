#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED
#include <string>
#include "booknode.h"

class MagazineNode:public BookNode{

private:
    int issue;
    type btype;

public:
    MagazineNode(int cissue,const string ptitle,int ptype,int pid =0,double cprice=0.0,int camount=0);
    MagazineNode(const string ptitle,int ptype,int pid, double cprice, int camount);

    int getIssue()const;
    void setIssue(int cissue);
    
    virtual type getBookType() const;
    virtual void setBookType(int);

    virtual void display();
    ~MagazineNode(){}
};


#endif // MAGAZINE_H_INCLUDED