/*

Mini Project

NAME: Sejal Chaudhari
ROLL NUMBER: 2323

*/

#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include<iostream>
using namespace std;


//Class holds information about the book and is node element for Inventory linked list
class Book
{

    string title,author,genre;
    int bookID,total,issued;
    Book *prev;
    Book *next;

    //Constructor
    Book(){
        title="";
        author="";
        genre="";
        bookID=0;
        total=0; //Total copies of book present in library
        issued=0; //Number of copies that have been issued to students
        prev=NULL;
        next=NULL;
    }
    friend class Inventory;
    friend class LibrarySystem;

};

//Doubly linked list for Book nodes
class Inventory
{
    //head of Inventory list
    Book *head;

    //constructor
    Inventory(){
        head=NULL;
    }

    //Function to add new record to inventory
    //Time complexity is 0(n)
    void addBook(int bookID){
        /* create a new Book node and accept book information from user and append to inventory */
        Book *newnode;
        Book *temp;
        //create new Book node
        newnode= new Book();

        //Input information from user and store in Book node fields
        newnode->bookID=bookID;
        cout<<"Enter the title of book: "<<endl;
        cout<<"====>  ";
        cin.ignore();
        getline(cin, newnode->title, '\n');

        cout<<"Enter the author of book: "<<endl;
        cout<<"====>  ";
        getline(cin,newnode->author, '\n');

        cout<<"Enter the genre of book: "<<endl;
        cout<<"====>  ";
        getline(cin,newnode->genre, '\n');

        cout<<"Enter how many copies of this title are being added to inventory: "<<endl;
        cout<<"====>  ";
        cin>>newnode->total;

        if(head==NULL)
        {
            //if first node being attached
        	head=newnode;
		}
		else //subsequent node
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
    }

    //Function searches for Book node based on bookID and returns pointer to node
    //Time complexity is O(n)
    Book* searchBook(int bookID){
        /* searches for book based on bookID and returns pointer to Book node */
        int id=bookID; //assign parameter to variable

        Book* temp;
        temp=head;

            //Traverse until end of list or node is found
			while((temp!=NULL)&&(temp->bookID!=id))
			{
				temp=temp->next;
            }

            //return pointer to node
             return temp;
    }

    //function to delete node based on book ID
    //Uses searchBook() function internally
    //time complexity is O(n)
    bool deleteBook(int bookID){
        /* searches for book based on bookID and deletes the Book node */

        Book* temp=searchBook(bookID);
        if(temp==NULL)
            return false;
        else
            {

              if((temp==head)&&(temp->next==NULL)) // if single node present in list
              {
               head=NULL;
               delete temp;
              }
             else if(temp==head)        //If first node from list to be deleted
             {
               head=temp->next;
               head->prev=NULL;
               delete temp;
             }
             else if(temp->next==NULL)   //if last node to be deleted
             {
                (temp->prev)->next=NULL;
                delete temp;
             }
             else                         //any other node
             {
               (temp->prev)->next=temp->next;
               (temp->next)->prev=temp->prev;
               delete temp;  //delete node to free memory
             }


            }
        return true;
    }

    //Function to check if such a node exists
    //time complexity is O(n)
    //Internally uses searchBook() function
    bool bookExists(int bookID){
        /* traverse list and return true if book with given ID exists else return false.*/
        Book* temp=searchBook(bookID);   // call searchBook() function
        if(temp==NULL)
            return false;
        else
            return true;
    }

    //checks if copy of a given book is available to be issued from the library
    //Time complexity is O(n)
    //Internally uses searchBook() function
    bool copyAvailable(int bookID)
    {
        Book* temp=searchBook(bookID);     // call searchBook() function
        if(temp->total==temp->issued)
            return false;
        else
            return true;

    }

    //checks if copy of a given book is available to be issued from the library and increments issued book count
    //Time complexity is O(n)
    //Internally uses searchBook() function
    bool incrementCount(int bookID){
        /* if copies of given bookID are available to be issued it increments issued count and returns true.
        if copies not available returns false.*/
        Book* temp=searchBook(bookID);   // call searchBook() function
        if(temp->total==temp->issued)
            return false;
        else
            temp->issued++;
            return true;
    }

    //checks if any copies have been issued  and decrements issued book count
    //Time complexity is O(n)
    //Internally uses searchBook() function
     bool decrementCount(int bookID){
        Book* temp;
        temp=searchBook(bookID);   // call searchBook() function
        if(temp==NULL || temp->issued==0)
            return false;
        else
            temp->issued--;
        return true;
    }

     //Function to traverse through list and display information stored in book node
    //Time complexity is O(n)
    void display(){
        Book* temp;
        temp=head;

        while(temp!=NULL)
        {
        cout<<"\n\nTitle: "<<endl;
        cout<<temp->title<<endl;
        cout<<"Author: "<<endl;
        cout<<temp->author<<endl;
        cout<<"Genre: "<<endl;
        cout<<temp->genre<<endl;
        cout<<"BookID: "<<endl;
        cout<<temp->bookID<<endl;
        cout<<"Total number of copies in the library : "<<endl;
        cout<<temp->total<<endl;
        cout<<"Total number of copies currently issued to students : "<<endl;
        cout<<temp->issued<<endl;

        cout<<"========================================================================"<<endl;

        temp=temp->next;

        }

    }

    //Checks if inventory list is empty
    //Time complexity is O(1)
    bool isEmpty(){
        if(head==NULL)  // if head is NULL
            return true;
        else
            return false;
    }

    friend class LibrarySystem;


};

#endif // INVENTORY_H_INCLUDED
