#ifndef BOOKNODE_H_INCLUDED
#define BOOKNODE_H_INCLUDED
using namespace std;
#include <string>
enum type {magazine=0,fiction=1,textbook=2};
const type BTYPE[3]={magazine,fiction,textbook};
const string STYPE[3]={"magazine","fiction","textbook"};

class BookNode{
private:
    string title;
    int bookId;
    double price;
    int amount;
    static int usedId;
    static int bookNo;

public:
    BookNode * next;
    BookNode(const string ptitle,int pid =0,double cprice=0.0,int camount=0);

    ~BookNode(){bookNo-=1;}
    static int getBookNo();
    void setTitle(const string ptitle);
    string getTitle() const;
    void setBookId(int pid);
    int getBookId() const;
    void setPrice(double cprice);
    double getPrice() const;
    void setAmount(int camount);
    int getAmount() const;
    virtual void setBookType(int) = 0;
    virtual type getBookType() const = 0;
    void sold();
    virtual void display();
};


#endif // BOOKNOTE_H_INCLUDED
