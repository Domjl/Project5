#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include "booknode.h"
#include "textbook.h"
#include "magazine.h"
#include "fiction.h"
#define MAX_LINE 2048
using namespace std;

struct CartNode{
    BookNode* item;
    CartNode* next;
    CartNode(BookNode* item){
        this->item=item;
        next=NULL;
    }

};

BookNode* head=NULL;
CartNode* cart=NULL;
BookNode *readData();
void writeData(BookNode* node);
void displayCatalog(BookNode* node);
void addToCatalog(string title,int ptype, int id, double price, int amount,  BookNode* node);
BookNode* search(BookNode* node, int bookId);
void removeFromCatalog(BookNode* &node, int bookId);
void destroyCatlog(BookNode* & node);
void mostPop(BookNode* node);
void displayCart(CartNode* node);
void addToCart(CartNode* &node,BookNode* item,BookNode* head);
void destroyCart(CartNode* &node);
void checkOut(CartNode* & node);
void insert();
void remove();
void add();
void branching(char c);
void menu();
int main()
{
    char ch;
    cout<<"WELCOME TO BOOK SHOPPING\n";
    cout<<"********************************************************\n";
    head = readData();
    do{
        menu();
        cin>>ch;
        ch=tolower(ch);
        branching(ch);
    }while(ch!='q');
    writeData(head);
    destroyCatlog(head);
    if(!cart){
        destroyCart(cart);
    }
    return 0;
}

void displayCart(CartNode* node){
    double totalprice=0;
    CartNode* temp=node;
    cout<<"Items in the Cart:\n";
    while(temp!=NULL){
        cout<<"------------------------------\n";
        cout<<temp->item->getTitle()<<endl;
        cout<<"BookId "<<temp->item->getBookId()<<endl;
        cout<<"Price $"<<temp->item->getPrice()<<endl;
        totalprice+=temp->item->getPrice();
        temp=temp->next;
    }
    cout<<fixed<<setprecision(2);
    cout<<endl<<"The total price is $"<<totalprice<<"."<<endl;
}

void addToCart(CartNode* &node,BookNode* item,BookNode* head){
    if(!node){
        node=new CartNode(item);
    }else{
        CartNode* temp=node;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new CartNode(item);
    }
    displayCart(node);
    cout<<endl;
    mostPop(head);
}

void destroyCart(CartNode* &node){
    CartNode* temp=node;
    while(temp!=NULL){
        temp=temp->next;
        delete node;
        node=NULL;
        node=temp;
    }
}

void checkOut(CartNode* & node){
    double totalprice=0;
    if(!node){
        cout<<"No book is in the cart!\n";
        return;
    }else{
        CartNode* temp=node;
        cout<<"SAlE"<<endl;
        while(temp!=NULL){
            cout<<temp->item->getTitle()<<endl;
            temp->item->sold();
            totalprice+=temp->item->getPrice();
            temp=temp->next;
        }
        cout<<fixed<<setprecision(2);
        cout<<"Regular Total:\t"<<totalprice<<endl;
        cout<<"Tax:          \t"<<0.09*totalprice<<endl;
        cout<<"Total:        \t"<<(1+0.09)*totalprice<<endl;
        destroyCart(node);

    }
}

void mostPop(BookNode* node){
}

void menu(){
    cout<<endl<<endl<<"MENU"<<endl;
    cout<<"----"<<endl;
    cout<<"i: Insert a new book in the catalog."<<endl;
    cout<<"d: Display books in the catalog."<<endl;
    cout<<"r: Remove a book from the catalog."<<endl;
    cout<<"a: Add an item to the shopping cart."<<endl;
    cout<<"c: Checkout your shopping cart."<<endl;
    cout<<"q: Quit the program."<<endl;
    cout<<endl<<"Please your choice(i,d,r,a,c,q)--->"<<endl;

}

void branching(char c){
    switch(c){
        case 'i': insert();break;
        case 'd': displayCatalog(head);break;
        case 'r': remove(); break;
        case 'a': add();break;
        case 'c': checkOut(cart);break;
        case 'q': cout << endl << "@Exiting the program..............." << endl;
                  cin.get();	//type any key.
                  break;
        default: cout<<endl<<"Invalid input."<<endl;
            cout<<"Try again...."<<endl;
    }
}

void insert(){
    string title;
    double price;
    int type, id, amount;
    cin.ignore();// it is called after enter i, which is given by cin
    cout<<"Enter the title of the book\n";
    getline(cin,title);
    cout<<"Enter the type of the book\n";
    cout<<"0:Magazine\n";
    cout<<"1:Ficition\n";
    cout<<"2:Textbook\n";
    cin>>type;
    cin.ignore();

    cout<<"Enter the id of the book\n";
    cin >> id;
    cout<<"Enter the price of the book\n";
    cin>>price;
    cout << "Enter the amount of the book\n";
    cin >> amount;

    addToCatalog(title, type, id, price, amount, head);
}

void remove(){
    int id;
    cout<<"Enter the id of the book you are going to remove\n";
    cin>>id;
    removeFromCatalog(head,id);
}

void add(){
    int id;
    BookNode* item;
    cout<<"Enter the id of the book you are going to purchase\n";
    cin>>id;
    item=search(head,id);
    if( item == NULL )
    {
	cout << "The book is not in the catalog" << endl;
	return;
    }
    addToCart(cart,item,head);
}


BookNode * readData(){
    ifstream fin("booklist.txt");
    if(!fin) exit(-1);
    char line[MAX_LINE];
    BookNode* head=NULL; 
    while(!fin.eof() && fin.getline(line, MAX_LINE)) {
	if( strlen(line ) == 0 ) continue;

        int type=atoi(line);
        fin.getline(line,MAX_LINE);
        string title(line);
        fin.getline(line,MAX_LINE);
        int bookId=atoi(line);
        fin.getline(line,MAX_LINE);
        double price=atof(line);
        fin.getline(line,MAX_LINE);
        int amount=atoi(line);
        if(type==0){
            fin.getline(line,MAX_LINE);
            int issue=atoi(line);
            MagazineNode* newnode=new MagazineNode(issue,title,type,bookId,price,amount);
	    newnode->next = head;
	    head = newnode;
        }else if(type==1){
            fin.getline(line,MAX_LINE);
            string cauthor(line);
            FictionNode* newnode=new FictionNode(cauthor,title,type,bookId,price,amount);
	    newnode->next = head;
	    head = newnode;
        }else{
            fin.getline(line,MAX_LINE);
            string author(line);
            fin.getline(line,MAX_LINE);
            int edition=atoi(line);
            fin.getline(line,MAX_LINE);
            string isbn(line);
            TextbookNode* newnode= new TextbookNode(author,edition,isbn,title,type,bookId,price,amount);
	    newnode->next = head;
	    head = newnode;
        }
    }
    fin.close();
    return head;
}

void writeData(BookNode* node){
    BookNode* ptr=node;
    ofstream fout("booklist.txt");
    if(!fout) exit(-1);
    if(!ptr){
        cout<<"No book in the category list.\n";
        return;
    }
    while(ptr!=NULL){
        fout<<ptr->getBookType()<<endl;
        fout<<ptr->getTitle()<<endl;
        fout<<ptr->getBookId()<<endl;
        fout<<ptr->getPrice()<<endl;
        fout<<ptr->getAmount()<<endl;
        
        if(ptr->getBookType()==2){
            fout<<static_cast<TextbookNode*>(ptr)->getAuthor()<<endl;
            fout<<static_cast<TextbookNode*>(ptr)->getEdition()<<endl;
            fout<<static_cast<TextbookNode*>(ptr)->getIsbn()<<endl<<endl;

        }else if(ptr->getBookType()==1){
            fout<<static_cast<FictionNode*>(ptr)->getAuthor()<<endl<<endl;
        }else{
            fout<<static_cast<MagazineNode*>(ptr)->getIssue()<<endl<<endl;
        }
        ptr=ptr->next;
    }
    fout.close();
}

void displayCatalog(BookNode* node){
    BookNode* temp=node;
    if(!node){
        cout<<"The catalog is empty!\n";
        return;
    }else{
        while(temp!=NULL){
            temp->display();
            cout<<endl;
            temp=temp->next;
        }
    }
}

void addToCatalog(string title,int ptype, int id, double price, int amount,  BookNode* node){
    BookNode* aptr=NULL,*ptr=node;
    if(ptype==0){
        MagazineNode* newnode= new MagazineNode(title,ptype,id,price,amount);
        aptr=newnode;
    }else if(ptype==1){
        FictionNode* newnode= new FictionNode(title,ptype,id,price,amount);
        aptr=newnode;
    }else if(ptype==2){
        TextbookNode* newnode= new TextbookNode(title,ptype,id,price,amount);
        aptr=newnode;
    }else{
        cout<<"Invalid input of the type of the book\n";
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=aptr;
}


BookNode* search(BookNode* node, int bookId){
    if(node==NULL) return NULL;
    BookNode* & ptr=node;
    while(ptr != NULL && ptr->getBookId()!=bookId){
        ptr=ptr->next;
    }
    return ptr;
}

void removeFromCatalog(BookNode* &node, int bookId){
    bool find=false;
    if(!node){
        cout<<"The Catalog is empty\n";
        return;
    }else if(node->getBookId()==bookId){
        BookNode* temp=node;
        node=node->next;
        delete temp;
        temp=NULL;
        find=true;
    }else{
        BookNode* ptr=node;
        while(ptr->next->getBookId()!=bookId){
            ptr=ptr->next;
        }
        BookNode* temp=ptr->next;
        ptr->next=ptr->next->next;
        delete temp;
        temp=NULL;
        find=true;
    }
    if(find){
        cout<<"Delete Successful!\n";
    }else{
        cout<<"Item not existed!\n";
    }


}

void destroyCatlog(BookNode* & node){
    if(!node)  return;
    else{
        BookNode* temp=node;
        while(temp!=NULL){
            temp=temp->next;
            delete node;
            node=NULL;
            node=temp;
        }
    }
}

/**
 * Purpose: sort.. that I believe based on my understanding of c++ will work.
 * with comments.. :D
 * 
 * @param *head pass in the current head of the list
 * @return returns the new head of the list.
 */
BookNode * sort(BookNode *head)       
{
	BookNode *newhead = nullptr;      // Head to be.
	BookNode *current = nullptr;      // Position place holder for where in the sorted list we are.

	while(head->next != nullptr)      // repeat until only head remains
	{
		BookNode *n = head;             // temp node for looping through
		BookNode *max = n;              // max node
		BookNode *maxParent = n;        // max node's parent

		while(n->next != nullptr)       // while has another node
		{
			if(n->next->getAmount() > n->getAmount()) // if the next node is larger than the current node
			{
				max = n->next;              // current max is the next node
				maxParent = n;              // current node is the max's parent 
			}
		}

                // remove the node - Delink the node from the link and relink the remaining list
		if(max == head)                 // if max is first element
		{
			head = head->next;            // set head to next node
		}
		else                            //
		{
			maxParent->next = max->next;  // max's parent's next == max's next node
		}
		max->next = nullptr;            // max's next beocmes null
		
		//Append the cut node to the new list.
		if(current == nullptr)          // if newhead hasn't beeen set yet
		{
		  newhead = max;                 // set a starting point
		  current = newhead;            // safety
		}
		else
		 {
		   current->next = max;         // next max is the max we found
		   current = max;                // move along in the sorted list
		 }
		 
		 /**
		  *  catch. if(current->next != nullptr) throw error;
		  */
		  
	}

	current->next = head;             // add the remaining value;
	//current = nullptr; 		 // might break things, my attempt to deallocate the "current" pointer.
	
	return newhead;                   // return the new list
}
