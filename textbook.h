#ifndef TEXTBOOK_H_INCLUDED
#define TEXTBOOK_H_INCLUDED
#include <string>
#include "booknode.h"

class TextbookNode:public BookNode {
private:
    string author;
    int edition;
    string isbn;
    type btype;

public:
    TextbookNode(string cauthor,int pedit,string cisbn,const string ptitle,int ptype,int pid =0,double cprice=0.0,int camount=0);
    TextbookNode(const string ptitle,int ptype,int cid, double cprice, int camount);

    string getAuthor() const;
    void setAuthor(string cauthor);

    int getEdition() const;
    void setEdition(int pedit);

    string getIsbn()const;
    void setIsbn(string cisbn);

    virtual type getBookType() const;
    virtual void setBookType(int);

    virtual void display();
    ~TextbookNode(){};

};



#endif // TEXTBOOK_H_INCLUDED
