/*

Mini Project
NAME: Sejal Chaudhari
ROLL NUMBER: 2323
C NUMBER: C22019221325

*/

#ifndef LIBRARYCLASSSYSTEM_H_INCLUDED
#define LIBRARYCLASSSYSTEM_H_INCLUDED

#include<iostream>
#include "Inventory.h"
#include "StudentList.h"
using namespace std;

//uses objects of Inventory class and StudentList class to implement functions
class LibrarySystem
{
    Inventory* inv=new Inventory();      //Inventory object
    StudentList* isl= new StudentList(); //StudentList object for holding list of students to whom books have been issued
    StudentList* wtl=new StudentList();  //StudentList object for holding list of students waiting for availability of copies of particular book

    public:

    //constructor
    LibrarySystem()
    {
        cout<<"*****   New Library Management System is being created.    *****"<<endl;
    }

    /* Add record of new book to inventory */
    //Time complexity of operation is O(n)
    void addRecord()
    {
        int b;

        cout<<"Enter Book Information: "<<endl;
        cout<<"========================================================================"<<endl;
        cout<<"Enter Book ID: "<<endl;
        cout<<"====>  ";
        cin>>b;
        if(inv->bookExists(b))
           cout<<"***  Book with entered Book ID already exists. Please enter a unique book ID. ***"<<endl;
        else
        {
            inv->addBook(b);
            cout<<"***  Book with entered book ID "<<b<<" has been added to Inventory.  ***"<<endl;
        }
    }

    /* Delete record of book from inventory */
    //Time complexity of operation is O(n)
    void delRecord()
    {
        int b;

        cout<<"Enter Book ID of Book to be deleted"<<endl;
        cout<<"====>  ";
        cin>>b;

        bool success=inv->deleteBook(b);
        if(success)
           cout<<"***  Record of book with entered Book ID "<<b<<" has been deleted  ***"<<endl;
        else
           cout<<"***  Book with entered book ID "<<b<<" does not exist in the Inventory.  ***"<<endl;
    }

    /* Display Inventory */
    //Time complexity of operation is O(n)
    void displayInventory()
    {
       if(inv->isEmpty())
           cout<<"***  Inventory is empty.  ***"<<endl;

        else
            inv->display(); //call display function of inventory class
    }

    //Issue copy of a book to student
     //Time complexity of operation is O(n)
    void issue()
    {

        int b;
        int r;
        cout<<"Enter Student roll number: "<<endl;
        cout<<"====>  ";
        cin>>r;

        cout<<"Enter Book ID of copy to be issued: "<<endl;
        cout<<"====>  ";
        cin>>b;
        if(inv->bookExists(b))   //check if such a book exists in inventory
        {
            /*read student information from user using function from StudentList class*/
             Student* temp1;
             temp1=isl->searchByRoll(r);
             Student* temp2;
             temp2=wtl->searchByRoll(r);

            if(inv->copyAvailable(b)) //check if copies of book are available to be issued
            {
                if((temp1==NULL)&&(temp2==NULL))
                {
                 isl->addNode(r,b);  //add student to issued list
                 inv->incrementCount(b); //increment issued book count in inventory
                 cout<<"*** A copy of book with bookID "<<b<<" has been issued to the student. ***"<<endl;
                }
                else
                    cout<<"*** Student has already issued a book from the library, or is on the waiting list for another book; cannot issue another book. *** "<<endl;
            }
            else
            {
                cout<<"***  Copy of required book is not currently available.  *** "<<endl;
                if((temp1==NULL)&&(temp2==NULL))
                {
                 wtl->addNode(r,b);  //add student to waiting list
                 cout<<"***  Student has been added to waiting list.  ***"<<endl;
                }
                else
                    cout<<"*** Student is already on the waiting list for a book, cannot be added to the waiting list for another book.  *** "<<endl;
            }
        }
        else
            cout<<"***  Enter valid Book ID.  ***"<<endl;
    }

    //Time complexity of operation is O(n)
    //Accept returned copy of a book from student
    void returnCopy()
    {

        int r;
        cout<<"Enter roll number of student who is returning the copy "<<endl;
        cin>>r;

        int b=isl->delNode(r);  //call delete function of issue list

        if(b==0)  //because return value of delNode() is bookID which has been initialized to 0.
            cout<<"***  No copy has been issued to this student. Enter valid student roll number  *** "<<endl;
        else
            {
               Student* temp;
               temp=wtl->removeNode(b); //remove student from waiting list for matching book ID
               if(temp!=NULL)
               {
                   isl->addNode(temp); //add student removed from waiting list to issue list
                   cout<<"*** Copy with book ID "<<b<<" has been returned and issued to a student from the waiting list. ***"<<endl;
               }
               else
               {

                   if(inv->decrementCount(b)) //decrement count of issued copies
                     cout<<"***  Copy with book ID "<<b<<" has been returned to the library.  ***"<<endl;
                   else
                      cout<<"***  Return operation was unsuccessful. Please try again.  ***"<<endl;

               }

            }

    }

    //function to display list of students who have issued books from library
    //time complexity of operation is O(n)
    void displayISL()
    {
        if(isl->isEmpty())
             cout<<"Issue List is empty "<<endl;
         else
            isl->displayList(); //call display of issue list
    }
    //function to display list of students who are waiting for copies from library
    //time complexity of operation is O(n)
    void displayWTL()
    {
        if(wtl->isEmpty())
             cout<<"Waiting List is empty "<<endl;
         else
            wtl->displayList();  //call display of waiting list
    }

    //function to display student information based on roll number form issue list
    //time complexity of operation is O(n)
    void searchStudent()
    {
        int r;
        cout<<"Enter roll number of student "<<endl;
        cin>>r;
        isl->displayStudent(r); //call issue list function
         cout<<"========================================================================"<<endl;
    }

    //function to display book information based on book ID from issue list
    //time complexity of operation is O(n)
    void searchBookID()
    {
        int b;
        cout<<"Enter Book ID: "<<endl;
        cin>>b;

        isl->displayByBook(b);  //call issue list function
         cout<<"========================================================================"<<endl;

    }
};

#endif // LIBRARYCLASSSYSTEM_H_INCLUDED
