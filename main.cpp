#include <iostream>
#include <fstream>
using namespace std;

// Global Variables and data structures
// BookID      BookName        BookAuthor         ISBN            Copies
int i, j, k;
struct books
{
    int BookID;
    string BookName;
    string BookAuthor;
    string ISBN;
    int Copies;
};
struct books arr[10];

struct users
{
    string name;
    string email;
    int id;
};
string userName[10] = {"vedant", "suraj", "vinod", "ritesh"};
int userID[10] = {123, 234, 345, 456}, userCount = 4, idStartIndex = 4;
string userEmail[10] = {"bvedant@gmail.com", "bsuraj@gmail.com", "yvinod@gmail.com", "dritesh@gmail.com"};
int adminID = 321;
char currentBookNumber = '4';
int currentBookId = 4;
string adminName = "Rahul";
int bookId;
int currentBookIndex=0;
class bookInfo
{
public:
    void previousFileData()
    {
        arr[currentBookIndex].BookID=1;
        arr[currentBookIndex].BookName="Murder!";
        arr[currentBookIndex].BookAuthor="Arnold Bennett";
        arr[currentBookIndex].ISBN="1-86092-012-8";
        arr[currentBookIndex].Copies=10;
        currentBookIndex++;

        arr[currentBookIndex].BookID=2;
        arr[currentBookIndex].BookName="The Hostage";
        arr[currentBookIndex].BookAuthor="C. S. Forester";
        arr[currentBookIndex].ISBN="1-1-86092-012-8";
        arr[currentBookIndex].Copies=5;
        currentBookIndex++;

        arr[currentBookIndex].BookID=3;
        arr[currentBookIndex].BookName="The Vampyre";
        arr[currentBookIndex].BookAuthor="John Polidori";
        arr[currentBookIndex].ISBN="1-86092-035-7";
        arr[currentBookIndex].Copies=5;
        currentBookIndex++;


    }
    void setData()
    {
        cout << "Enter the book ID:";
        cin >> arr[currentBookIndex].BookID;
        cout << "Enter the book name:";
        cin >> arr[currentBookIndex].BookName;
        cout << "Enter ISBN number:";
        cin >> arr[currentBookIndex].BookAuthor;
        cout << "Enter the number of copies:";
        cin >> arr[currentBookIndex].Copies;
        ofstream out;
        out.open("file.txt", ios::app);
        out << "book ID:";
        out << arr[currentBookIndex].BookID << endl;
        out << "book name:";
        out << arr[currentBookIndex].BookName << endl;
        out << "ISBN number:";
        out << arr[currentBookIndex].BookAuthor << endl;
        out << "Number of copies:";
        out << arr[currentBookIndex].Copies << endl;
        out << endl;
        currentBookIndex++; 
    }
    void displayData()
    {
        string str;
        ifstream in;
        in.open("books.txt");
        while (in.eof() == 0)
        {
            getline(in, str);
            cout << str << endl;
        }
        in.close();
    }
};
class admin
{
private:
    int adminCheck;
    string newBookInfo[10];

public:
    int authority()
    {
        cout << "As an admin you have much more authority than a normal user" << endl;
        cout << "You can add a new user to our library" << endl;
        cout << "You can add a new book into a library" << endl;
        cout << "And you can also remove an existing book from a library" << endl;
        do
        {
            cout << "Please press a valid option:" << endl;
            cout << "1. add a new user" << endl;
            cout << "2. add a new book" << endl;
            cout << "3. to remove a book" << endl;
            cin >> adminCheck;
        } while (adminCheck > 3);
        return adminCheck;
    }
    void check(int adminCheck)
    {
        switch (adminCheck)
        {
        case 1:
        {
            // cout << "So you want to add a new user" << endl;
            // cout << "Enter his/her  Name:";
            // cin >> userName[userCount];
            // cout << "Enter his/her email:";
            // cin >> userEmail[userCount];
            // userID[userCount] = (((idStartIndex + 1) * 100) + ((idStartIndex + 2) * 10) + ((idStartIndex + 3) * 1));
            // cout << "His/her new userID is " << userID[userCount];
            // userCount++;
            // idStartIndex++;
            users u;
            cout << "So you want to add a new user" << endl;
            cout << "Enter his/her  Name:";
            cin >> u.name;
            cout << "Enter his/her email:";
            cin >> u.email;
            userID[userCount] = (((idStartIndex + 1) * 100) + ((idStartIndex + 2) * 10) + ((idStartIndex + 3) * 1));
            cout << "His/her new userID is " << userID[userCount];
            u.id = userID[userCount];
            userCount++;
            idStartIndex++;
            ofstream out2;
            out2.open("users.txt", ios::app); // append mode
            out2 << u.id;
            out2 << "\t\t\t";
            out2 << u.name;
            out2 << "\t\t\t";
            out2 << u.email;
            out2.close();
        }
        break;

        case 2:
        {
            cout << "So you want to add a new book" << endl;
            // newBookInfo[0] = currentBookNumber;
            // cout << "Enter the name of the book : ";
            // cin >> newBookInfo[1];
            // cout << "Enter the name of the author of the book : ";
            // cin >> newBookInfo[2];
            // cout << "Enter the ISBN code of the book : ";
            // cin >> newBookInfo[3];
            // cout << "Enter the number of copies you want to add : ";
            // cin >> newBookInfo[4];
            // ofstream out;
            // out.open("books.txt", ios::app); // append mode
            // for (i = 0; i < 5; i++)
            // {
            //     out << newBookInfo[i] << "\t\t\t";
            // }
            // cout<<endl;
            // out.close();
            books b;
            b.BookID = currentBookId;
            currentBookId++;
            cout << "Enter the name of the book : ";
            cin >> b.BookName;
            cout << "Enter the name of the author of the book : ";
            cin >> b.BookAuthor;
            cout << "Enter the ISBN code of the book : ";
            cin >> b.ISBN;
            cout << "Enter the number of copies you want to add : ";
            cin >> b.Copies;
            ofstream out;
            out.open("books.txt", ios::app); // append mode
            out << b.BookID;
            out << "\t\t\t";
            out << b.BookName;
            out << "\t\t\t";
            out << b.BookAuthor;
            out << "\t\t\t";
            out << b.ISBN;
            out << "\t\t\t";
            out << b.Copies;
            out.close();
        }
        break;

        case 3:
        {
            cout << "So you want to remove a book from the library" << endl;
            cout << "Enter the ID of the book you want to remove : ";
            cin >> bookId;
        }
        break;
        default:
        {
            cout << "Invalid option:" << endl;
            cout << "Please enter a valid option : ";
        }
        }
    }
};
class user
{
private:
    int userCheck;

public:
    bool searchForABook(int id)
    {
        bool check = false;
        for(int i=0;i<currentBookIndex;i++)
        {
            if(arr[i].BookID==id)
            {
                check=true;
            }
        }
        return check;
    }

    int authority()
    {
        cout << "As an user you have not that much authority like an admin" << endl;
        cout << "But you can search for a book " << endl;
        cout << "you can borrow a book from a library and" << endl;
        cout << "you can also return a borrowed book to a library" << endl;
        do
        {
            cout << "Please press a valid option:" << endl;
            cout << "1. search for a book" << endl;
            cout << "2. borrow a book" << endl;
            cout << "3. return a book" << endl;
            cin >> userCheck;
        } while (userCheck > 2);
        return userCheck;
    }
    void check(int userCheck)
    {
        switch (userCheck)
        {
        case 1:
        {
            cout << "So you want to search for a book" << endl;
            cout << "Enter the ID of a book : ";
            cin >> bookId;
            bool check = searchForABook(bookId);
            if (check == true)
            {
                cout << "Book with ID " << bookId << " is available in the library";
            }
            else
            {
                cout << "Book with ID " << bookId << " is not available in the library";
            }
        }
        break;
        case 2:
        {
            cout << "So you want to borrow a book" << endl;
            cout << "Enter a book id:";
            cin >> bookId;
            bool check = searchForABook(bookId);
            if (check == true)
            {
                cout << "Book with ID " << bookId << " is available in the library" << endl;
                cout << "Now you can borrow a book";
            }
            else
            {
                cout << "As book with ID " << bookId << " is not available in the library" << endl;
                cout << "you cannot borrow it";
            }
        }
        break;

        case 3:
        {
            cout << "So you want to return a book" << endl;
            cout << "Enter a book id:";
            cin >> bookId;
        }
        break;

        default:
        {
            cout << "Invalid option:" << endl;
            cout << "Please enter a valid option : ";
        }
        }
    }
};
int main()
{
    cout << "hello ! Welcome to the Library" << endl;
    cout << "Here are the list of all the books available in the librabry" << endl;
    bookInfo objBookInfo;
    objBookInfo.previousFileData();
    objBookInfo.displayData();
    int check = 1, id;
    cout << "Are you a regular user or an admin ." << endl;
    do
    {
        cout << "press 1 if you are a user" << endl;
        cout << "press 2 if you are an admin" << endl;
        cin >> check;
        switch (check)
        {
        case 1:
        {
            bool checkForUserId = false;
            cout << "So you are a user:" << endl;
            cout << "Please enter your userID to varify : ";
            do
            {
                cin >> id;
                for (i = 0; i < userCount; i++)
                {
                    checkForUserId = false;
                    if (id == userID[i])
                    {
                        checkForUserId = true;
                        break;
                    }
                }
                if (checkForUserId == true)
                {
                    cout << "Hello " << userName[i] << " ! Welcome to the library.";
                    // USER AUTHORITY
                    user objUser;
                    int userCheck = objUser.authority();
                    objUser.check(userCheck);
                }
                else
                {
                    cout << "Invalid userID" << endl;
                    cout << "Please enter a valis userID";
                }
            } while (checkForUserId == false);
        }
        break;
        case 2:
        {
            cout << "So you are an admin:" << endl;
            cout << "Please enter your adminID to varify : ";
            do
            {
                cin >> id;
                if (id == adminID)
                {
                    cout << "Hello " << adminName << " ! Welcome to the library." << endl;
                    // ADMIN AUTHORITY
                    admin objAdmin;
                    int adminCheck = objAdmin.authority();
                    objAdmin.check(adminCheck);
                }
                else
                {
                    cout << "Invalid adminID" << endl;
                    cout << "Please enter a valid adminID : " << endl;
                }
            } while (id != adminID);
        }
        break;
        default:
            cout << "Invalid Option" << endl;
            cout << "Please enter a valid option" << endl;
        }
    } while (check >= 3);

    return 0;
}