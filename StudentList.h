/*

Mini Project
NAME: Sejal Chaudhari
ROLL NUMBER: 2323
C NUMBER: C22019221325

*/

#ifndef STUDENTLIST_H_INCLUDED
#define STUDENTLIST_H_INCLUDED

#include<iostream>
using namespace std;

//Class holds information about the student and is node element for Student linked lists for issued books and waiting list
class Student
{
    string name, email, contact;
    int rollNum, bookID ;

    Student* next;
    Student* prev;

    Student()    //Initialize values
    {
        name="";
        email="";
        contact="";
        rollNum=0;
        bookID=0;
        next=NULL;
        prev=NULL;
    }

    friend class StudentList;
    friend class LibrarySystem;
};

class StudentList
{

    Student* head;

    StudentList()
    {
        head=NULL;
    }

    //function to append node at end
    //Time complexity of function is O(n)
    void addNode(int roll,int book)
    {

        Student* newnode;
        Student* temp;
        newnode=new Student();

    /*Read student information from user and store in newly created Student Node*/

         cout<<"========================================================================"<<endl;

        cout<<"Enter name of the student: "<<endl;
        cout<<"====>  ";
        cin.ignore();
        getline(cin, newnode->name, '\n');

        cout<<"Enter email of the student: "<<endl;
        cout<<"====>  ";
        //cin.ignore();
        getline(cin, newnode->email, '\n');

        cout<<"Enter contact information: "<<endl;
        cout<<"====>  ";
        //cin.ignore();
        getline(cin, newnode->contact, '\n');

         cout<<"========================================================================"<<endl;

        newnode->bookID=book;
        newnode->rollNum=roll;

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

    //Time complexity of function is O(n)
    //Overloaded function to append student node to list with Student* input parameter
    void addNode(Student* n)
    {
        /*Add Student node passed as argument to end of list. It will already hold student information*/

        Student* temp;
        temp=head;
        if(head==NULL)
        {
            //if first node being attached
        	head=n;
		}
		else //subsequent node
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			n->prev=temp;
		}
    }

    //Time complexity of function is O(n)
    //function to search for student node based on student roll number
    Student* searchByRoll(int roll)
    {
        /*Traverse through list and compare Student rollNum with roll number passed as argument.
          Return pointer to the Student Node that matches based on rollNum.*/
          Student* temp;
          temp=head;

          while((temp!=NULL)&&(temp->rollNum!=roll))  //traverse until node not found
          {
              temp=temp->next;
          }
          return temp;
    }

    //Function to check if list is empty
    //Time complexity of function is O(1)
    bool isEmpty()
    {
        if(head==NULL)
            return true;
        else
            return false;
    }

    //Function to delete node based on roll number
    //Time complexity of function is O(n)
    //Uses searchByroll internally
    int delNode(int roll)
    {
        /*Delete node. Use searchByRoll(int roll) internally to find node matching roll number passed as argument.
         Returns bookID of node that has just been deleted. Returns 0 if no node with entered roll number existed. */
        Student* temp;
        temp=searchByRoll(roll);  //call searchByRoll
        int bookID=0;
        if(temp!=NULL)   // if node exists
        {
          bookID= temp->bookID;

          if((temp==head)&&(temp->next==NULL))
          {
            head=NULL;
          }
          else if(temp==head)
          {
             head=temp->next;
             head->prev=NULL;
          }
          else if(temp->next==NULL)
          {
            (temp->prev)->next=NULL;
          }
          else
          {
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
          }
      }
        delete temp;    //delete node to free memory
        return bookID;   // return value of book id
    }

    //function to display list
    //Time complexity of function is O(n)
    void displayList()
    {
        /*Traverse through list and display information from each Student node*/
        Student *temp;
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            cout<<"========================================================================"<<endl;
        	cout<<"Name of the student: "<<endl;
            cout<<temp->name<<endl;
            cout<<"Email of the student: "<<endl;
            cout<<temp->email<<endl;
            cout<<"Contact information: "<<endl;
            cout<<temp->contact<<endl;
            cout<<"Student roll number: "<<endl;
            cout<<temp->rollNum<<endl;
            cout<<"BookID of the book: "<<endl;
            cout<<temp->bookID<<endl;
            cout<<"========================================================================"<<endl;
		}
    }

    //Function to display information of particular student roll number from list
    //Time complexity of function is O(n)
    void displayStudent(int roll)
    {
        /*Use searchByRoll(int roll) function to search for node based on roll number argument.
        Display information stored in that node*/
        Student *temp;
        temp=searchByRoll(roll);
        if(temp!=NULL)
        {
        	cout<<"Name of the student: "<<endl;
            cout<<temp->name<<endl;
            cout<<"Email of the student: "<<endl;
            cout<<temp->email<<endl;
            cout<<"Contact information: "<<endl;
            cout<<temp->contact<<endl;
            cout<<"Student roll number: "<<endl;
            cout<<temp->rollNum<<endl;
            cout<<"BookID of the book: "<<endl;
            cout<<temp->bookID<<endl;
		}
		else
		{
			cout<<"No book has been issued to student with entered roll number, enter a valid one"<<endl;
		}
    }

    //function to display students who have issued copies of given book id
    void displayByBook(int book)
    {
        /*Traverse through list.
         Display information from student nodes whose bookID field matches the bookID passed as argument*/
         Student *temp;
          cout<<"BookID of the book: "<<endl;
          cout<<book<<endl;
          cout<<"List of students who have issued this book: "<<endl;

         for(temp=head;temp!=NULL;temp=temp->next)
         {
         	if(temp->bookID==book)
         	{
            cout<<"Name of the student: "<<endl;
            cout<<temp->name<<endl;
            cout<<"Email of the student: "<<endl;
            cout<<temp->email<<endl;
            cout<<"Contact information: "<<endl;
            cout<<temp->contact<<endl;
            cout<<"Student roll number: "<<endl;
            cout<<temp->rollNum<<endl;
			}
		 }
    }

    //function to search based on bookID of issued book
    //Time complexity of function is O(n)
     Student* searchByBook(int book)
    {
        /*Traverse through list and compare Node bookID with bookID passed as argument.
          Return pointer to the Student Node that matches based on bookID.*/
          Student *temp;
          temp= head;

          while((temp!=NULL)&&(temp->bookID!=book))
          {
              temp=temp->next;
          }
          return temp;
    }

    //function to remove first node from list with matching bookID and return pointer
    //Time complexity of function is O(n)
    //use searchByBook internally
    Student* removeNode(int bookID)
    {
        /*Search list based on bookID and return Student pointer.
        Use searchByBook(int bookID) function internally.
        This student node pointer will be appended to IssueList later */
        Student* temp;
        temp=searchByBook(bookID);
        if(temp!=NULL)
        {
             if((temp==head)&&(temp->next==NULL))
             {
                head=NULL;
             }
             else if(temp==head)
             {
                head=temp->next;
                head->prev=NULL;
             }
             else if(temp->next==NULL)
             {
                (temp->prev)->next=NULL;
             }
             else
             {
               (temp->prev)->next=temp->next;
               (temp->next)->prev=temp->prev;
             }
             temp->next=NULL;
             temp->prev=NULL;
		}

        return temp;  //return pointer to node
    }

    friend class LibrarySystem;
};


#endif // STUDENTLIST_H_INCLUDED
