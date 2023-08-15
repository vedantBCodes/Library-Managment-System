#include <iostream>
#include <fstream>
using namespace std;

// Global Variables and data structures

int i, j, k;
string userName[10] = {"vedant", "suraj", "vinod", "ritesh"};
int userID[10] = {123, 234, 345, 456}, userCount = 4, idStartIndex = 4;
string userEmail[10] = {"bvedant@gmail.com", "bsuraj@gmail.com", "yvinod@gmail.com", "dritesh@gmail.com"};
int adminID = 321;
char currentBookNumber = '4';
string adminName = "Rahul";
char bookId;

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
            cout << "Press 1 to add a new user" << endl;
            cout << "Press 2 to add a new book" << endl;
            cout << "Press 3 to remove a book" << endl;
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
            cout << "So you want to add a new user" << endl;
            cout << "Enter his/her  Name:";
            cin >> userName[userCount];
            cout << "Enter his/her email:";
            cin >> userEmail[userCount];
            userID[userCount] = (((idStartIndex + 1) * 100) + ((idStartIndex + 2) * 10) + ((idStartIndex + 3) * 1));
            cout << "His/her new userID is " << userID[userCount];
            userCount++;
            idStartIndex++;
        }
        break;

        case 2:
        {
            cout << "So you want to add a new book" << endl;
            newBookInfo[0] = currentBookNumber;
            cout << "Enter the name of the book : ";
            cin >> newBookInfo[1];
            cout << "Enter the name of the author of the book : ";
            cin >> newBookInfo[2];
            cout << "Enter the ISBN code of the book : ";
            cin >> newBookInfo[3];
            cout << "Enter the number of copies you want to add : ";
            cin >> newBookInfo[4];
            ofstream out;
            out.open("books.txt", ios::app); // append mode
            for (i = 0; i < 5; i++)
            {
                out << newBookInfo[i] << "\t\t\t";
            }
            out.close();
        }
        break;

        case 3:
        {
            cout << "So you want to remove a book from the library" << endl;
            cout << "Enter the ID of the book you want to remove : ";
            cin>>bookId;
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
    int accessibility()
    {
        cout << "As an user you have not that much authority like an admin" << endl;
        cout << "But you can borrow a book from a library and" << endl;
        cout << "you can return a borrowed book to a library" << endl;
        do
        {
            cout << "Please press a valid option:" << endl;
            cout << "Press 1 to borrow a book" << endl;
            cout << "Press 2 to return a book" << endl;
            cin >> userCheck;
        } while (userCheck > 2);
        return userCheck;
    }
    void check(int adminCheck)
    {
        switch (adminCheck)
        {
        case 1:
        {
            cout << "So you want to borrow a book" << endl;
            cout << "Enter a book id:";
            cin >> bookId;
        }
        break;

        case 2:
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
    string str;
    cout << "hello ! Welcome to the Library" << endl;
    cout << "Here are the list of all the books available in the librabry" << endl;
    ifstream in;
    in.open("books.txt");
    while (in.eof() == 0)
    {
        getline(in, str);
        cout << str << endl;
    }
    in.close();
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
                    admin objUser;
                    int adminCheck = objUser.authority();
                    objUser.check(adminCheck);
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