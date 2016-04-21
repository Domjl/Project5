#ifndef _BOOKNODE_H_
#define _BOOKNODE_H_

#include <string>

class BookNode {
public:

	typedef enum type {
        magazine = 1, fiction = 2, thesis = 3
    } BookType;

	BookNode(const std::string &, int = 0, double = 0.0, int = 0, int = 1);
	virtual ~BookNode() {};

	void setTitle( const std::string & ); // set title
	std::string getTitle() const; // return title

	void setBookId( int ); // set bookID
	int getBookId() const; // return bookID

	void setPrice( double ); // set price
	double getPrice() const; // return price

	void setAmount( int ); // set amount
	int getAmount() const; // return amount

	virtual void setBookType( int ) = 0; // set book type
	virtual int getBooktype() const = 0; // get booktype

	virtual void print();
	void sold();

	BookNode *next;

private:
	std::string title;
	int bookId;
	double price;
	int amount;

	BookType booktype;
};
