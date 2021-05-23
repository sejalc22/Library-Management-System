/*

Mini Project
NAME: Sejal Chaudhari
ROLL NUMBER: 2323
C NUMBER: C22019221325

Topic:
LIBRARY MANAGEMENT SYSTEM TO IMPLEMENT OPERATIONS LIKE ISSUING, ACCEPTING RETURNS OF BOOKS, AND MANAGING INVENTORY OF LIBRARY BY ADDITION AND DELETION OF STOCK, ALSO MAINTAINING THE ISSUE AND WAITING LISTS.

Data Structure: DOUBLY LINKED LIST

Team members:
Sejal Chaudhari (2323)
Ishani (2309)
Anshika (2307)
Shivani (2310)

*/


#include<iostream>
#include "LibraryClassSystem.h"

using namespace std;



int main()
{
    LibrarySystem sys;
    int choice;
    char ans;

  do
 {

     cout<<"========================================================================"<<endl;
     cout<<"========================================================================"<<endl;
     cout<<"\n*******  MENU FOR OPERATIONS   *******"<<endl;
     cout<<"Enter: "<<endl;
     cout<<"1. Add record of new book to inventory"<<endl;
     cout<<"2. Delete record of book from inventory"<<endl;
     cout<<"3. Display inventory"<<endl;
     cout<<"4. Issue copy of a book to student"<<endl;
     cout<<"5. Accept returned copy of a book from student"<<endl;
     cout<<"6. Display IssueList"<<endl;
     cout<<"7. Display WaitingList"<<endl;
     cout<<"8. Display student information from IssueList based on student roll number"<<endl;
     cout<<"9. Display list of students who have issued copies of a particular book.\n"<<endl;

     cout<<"========================================================================"<<endl;
     cout<<"========================================================================"<<endl;
     cout<<"\nEnter your choice: "<<endl;
     cout<<"====>";
     cin>>choice;

     switch(choice)
     {
     case 1:
        /* Add record of new book to inventory */
        sys.addRecord();
        break;

     case 2:
        /* Delete record of book from inventory */
        sys.delRecord();
        break;


     case 3:
        /* Display Inventory */
        sys.displayInventory();
        break;


    case 4:
        /* Issue copy of a book to student */
        sys.issue();
        break;

    case 5:
        /* Accept returned copy of a book from student */
        sys.returnCopy();
        break;

    case 6:
         /* Display IssueList */
        sys.displayISL();
        break;

    case 7:
        /* Display WaitingList */
        sys.displayWTL();
         break;

    case 8:
        /* Display student information from IssueList based on student roll number */
        sys.searchStudent();
        break;

    case 9:
        /* Display list of students who have issued copies of given bookID */
        sys.searchBookID();
        break;

    case 10:
        system("cls");
        break;

    default:
        cout<<"Enter a valid choice."<<endl;

   }

      cout<<"\n\nDo you want to continue? Enter Y for yes."<<endl;
      cout<<"====>  ";
      cin>>ans;

 }while((ans=='y')||(ans=='Y'));

  return 0;
}


/*

Sample Output (database already added):

Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>3


Title:
Operating Systems
Author:
william Stallings
Genre:
Computer Science
BookID:
1111
Total number of copies in the library :
2
Total number of copies currently issued to students :
0
========================================================================


Title:
Engineering Mathematics
Author:
B S Grewal
Genre:
Mathematics
BookID:
2222
Total number of copies in the library :
1
Total number of copies currently issued to students :
0
========================================================================


Title:
Geetanjali
Author:
Rabindranath Tagore
Genre:
Poetry
BookID:
3333
Total number of copies in the library :
1
Total number of copies currently issued to students :
0
========================================================================


Title:
Mrs. Dalloway
Author:
Virginia Woolf
Genre:
Fiction
BookID:
4444
Total number of copies in the library :
2
Total number of copies currently issued to students :
0
========================================================================


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>4
Enter Student roll number:
====>  12
Enter Book ID of copy to be issued:
====>  3333
========================================================================
Enter name of the student:
====>  sejal chaudhari
Enter email of the student:
====>  sejal@mail.com
Enter contact information:
====>  7685978473
========================================================================
*** A copy of book with bookID 3333 has been issued to the student. ***


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>6
========================================================================
Name of the student:
sejal chaudhari
Email of the student:
sejal@mail.com
Contact information:
7685978473
Student roll number:
12
BookID of the book:
3333
========================================================================


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>7
Waiting List is empty


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>4
Enter Student roll number:
====>  13
Enter Book ID of copy to be issued:
====>  3333
***  Copy of required book is not currently available.  ***
========================================================================
Enter name of the student:
====>  shivani
Enter email of the student:
====>  shivani@mail.com
Enter contact information:
====>  45657689
========================================================================
***  Student has been added to waiting list.  ***


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>5
Enter roll number of student who is returning the copy
12
*** Copy with book ID 3333 has been returned and issued to a student from the waiting list. ***


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>6
========================================================================
Name of the student:
shivani
Email of the student:
shivani@mail.com
Contact information:
45657689
Student roll number:
13
BookID of the book:
3333
========================================================================


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>7
Waiting List is empty


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>3


Title:
Operating Systems
Author:
william Stallings
Genre:
Computer Science
BookID:
1111
Total number of copies in the library :
2
Total number of copies currently issued to students :
0
========================================================================


Title:
Engineering Mathematics
Author:
B S Grewal
Genre:
Mathematics
BookID:
2222
Total number of copies in the library :
1
Total number of copies currently issued to students :
0
========================================================================


Title:
Geetanjali
Author:
Rabindranath Tagore
Genre:
Poetry
BookID:
3333
Total number of copies in the library :
1
Total number of copies currently issued to students :
1
========================================================================


Title:
Mrs. Dalloway
Author:
Virginia Woolf
Genre:
Fiction
BookID:
4444
Total number of copies in the library :
2
Total number of copies currently issued to students :
0
========================================================================


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>2
Enter Book ID of Book to be deleted
====>  1111
***  Record of book with entered Book ID 1111 has been deleted  ***


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>3


Title:
Engineering Mathematics
Author:
B S Grewal
Genre:
Mathematics
BookID:
2222
Total number of copies in the library :
1
Total number of copies currently issued to students :
0
========================================================================


Title:
Geetanjali
Author:
Rabindranath Tagore
Genre:
Poetry
BookID:
3333
Total number of copies in the library :
1
Total number of copies currently issued to students :
1
========================================================================


Title:
Mrs. Dalloway
Author:
Virginia Woolf
Genre:
Fiction
BookID:
4444
Total number of copies in the library :
2
Total number of copies currently issued to students :
0
========================================================================


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>4
Enter Student roll number:
====>  13
Enter Book ID of copy to be issued:
====>  3333
***  Copy of required book is not currently available.  ***
*** Student is already on the waiting list for a book, cannot be added to the waiting list for another book.  ***


Do you want to continue? Enter Y for yes.
====>  y
========================================================================
========================================================================

*******  MENU FOR OPERATIONS   *******
Enter:
1. Add record of new book to inventory
2. Delete record of book from inventory
3. Display inventory
4. Issue copy of a book to student
5. Accept returned copy of a book from student
6. Display IssueList
7. Display WaitingList
8. Display student information from IssueList based on student roll number
9. Display list of students who have issued copies of a particular book.

========================================================================
========================================================================

Enter your choice:
====>





*/
