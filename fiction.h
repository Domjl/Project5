#ifndef FICTION_H_INCLUDED
#define FICTION_H_INCLUDED
#include <string>
#include "booknode.h"

class FictionNode:public BookNode{

private:
    string author;
    type btype;


public:
    FictionNode(string cauthor,const string ptitle,int ptype,int pid =0,double cprice=0.0,int camount=0);
    FictionNode(const string ptitle,int ptype,int cid, double cprice, int camount);

    string getAuthor()const;
    void setAuthor(string cauthor);

    virtual type getBookType() const;
    virtual void setBookType(int);

    virtual void display();   
    ~FictionNode(){}
};


#endif // FICTION_H_INCLUDED