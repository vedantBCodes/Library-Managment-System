#include <iostream>
#include <fstream>
using namespace std;

// Global Variables and data structures
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
string bookName;
int currentBookIndex = 0;

class bookInfo
{
public:
    void previousFileData()
    {
        arr[currentBookIndex].BookID = 1;
        arr[currentBookIndex].BookName = "Murder!";
        arr[currentBookIndex].BookAuthor = "Arnold Bennett";
        arr[currentBookIndex].ISBN = "1-86092-012-8";
        arr[currentBookIndex].Copies = 10;
        currentBookIndex++;

        arr[currentBookIndex].BookID = 2;
        arr[currentBookIndex].BookName = "The Hostage";
        arr[currentBookIndex].BookAuthor = "C. S. Forester";
        arr[currentBookIndex].ISBN = "1-1-86092-012-8";
        arr[currentBookIndex].Copies = 5;
        currentBookIndex++;

        arr[currentBookIndex].BookID = 3;
        arr[currentBookIndex].BookName = "The Vampyre";
        arr[currentBookIndex].BookAuthor = "John Polidori";
        arr[currentBookIndex].ISBN = "1-86092-035-7";
        arr[currentBookIndex].Copies = 5;
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
        cout << "As an admin you have much more authority than a normal user" << endl << endl;
        cout << "You can add a new user to our library" << endl;
        cout << "You can add a new book into a library" << endl;
        cout << " You can see the book data" << endl;
        cout << "And you can also remove an existing book from a library" << endl;
        do
        {
            cout << "Please press a valid option:" << endl;
            cout << "1. add a new user" << endl;
            cout << "2. add a new book" << endl;
            cout << "3. display book data" << endl;
            cout << "4. to remove a book" << endl;
            cin >> adminCheck;
        } while (adminCheck > 4);
        return adminCheck;
    }
    void check(int adminCheck)
    {
        switch (adminCheck)
        {
        case 1:
        {
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
             cout<<"Here are the details of books currently available int the library"<<endl<<endl;
            bookInfo obj;
            obj.displayData();
        }
        break;

        case 4:
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
    bool searchBookByID(int id)
    {
        bool check = false;
        for (int i = 0; i < currentBookIndex; i++)
        {
            if (arr[i].BookID == id)
            {
                check = true;
                break;
            }
        }
        return check;
    }
    bool searchBookByName(string bookName)
    {
        bool check = false;
        for (int i = 0; i < currentBookIndex; i++)
        {
            if (arr[i].BookName == bookName)
            {
                check = true;
                break;
            }
        }
        return check;
    }

    void authority()
    {
        cout <<endl<< endl<<"As you are a regular user you have the following authority" << endl;
        cout << "you can search for a book " << endl;
        cout<<"you can see the book data"<<endl;
        cout << "you can borrow a book from a library and" << endl;
        cout << "you can also return a borrowed book to a library" << endl<<endl;
    }
    void check()
    {
        do
        {
            cout << endl<<"1. search for a book" << endl;
            cout << "2. Display book data" << endl;
            cout << "3. borrow a book" << endl;
            cout << "4. return a book" << endl;
            cout<<"5. Exit From the Library"<<endl;
            cout << "Choose a valid option : ";
            cin >> userCheck;
        
        switch (userCheck)
        {
        case 1:
        {
            int choice;
            cout << endl<<"So you want to search for a book" << endl;
            cout << "1.Search book using ID" << endl;
            cout << "2.Search book using Name" << endl;
            do
            {
                cout << "Enter your choice : ";
                cin >> choice;
            } while (choice >= 3);
            if (choice == 1)
            {
                cout << "Enter the ID of a book : ";
                cin >> bookId;
                bool check = searchBookByID(bookId);
                if (check == true)
                {
                    cout << "Book with ID " << bookId << " is available in the library";
                }
                else
                {
                    cout << "Book with ID " << bookId << " is not available in the library";
                }
            }
            else if (choice == 2)
            {
                cin.ignore();
                cout << "Enter the name of a book : ";
                getline(cin, bookName);
                bool check = searchBookByName(bookName);
                if (check == true)
                {
                    cout << bookName << " book is available in the library" << endl;
                    cout << "And there are " << arr[i].Copies << " copies of this book is available in our library" << endl;
                }
                else
                {
                    cout << bookName << " book is not available in the library";
                }
            }
        }
        break;

        case 2:
        {
            cout<<endl<<"Here are the details of books currently available int the library"<<endl<<endl;
            bookInfo obj;
            obj.displayData();
        }
        break;
        case 3:
        {
            int choice;
            cout << endl<<"So you want to borrow a book" << endl;
            cout << "1.Borrow book by entering book ID" << endl;
            cout << "2.Borrow book by entering book Name" << endl;
            do
            {
                cout << "Enter your choice : ";
                cin >> choice;
            } while (choice >= 3);
            if (choice == 1)
            {
                cout << "Enter the ID of a book : ";
                cin >> bookId;
                bool check = searchBookByID(bookId);
                if (check == true)
                {
                    cout << "Book with ID " << bookId << " is available in the library" << endl;
                    cout << "And there are " << arr[i].Copies << " copies of this book is available in our library" << endl;
                    cout << "Now you can borrow a book";
                }
                else
                {
                    cout << "Book with ID " << bookId << " is not available in the library" << endl;
                    cout << "so you cannot borrow it";
                }
            }
            else if (choice == 2)
            {
                cin.ignore();
                cout << "Enter the name of a book : ";
                getline(cin, bookName);
                bool check = searchBookByName(bookName);
                if (check == true)
                {
                    cout << bookName << " book is available in the library" << endl;
                    cout << "And there are " << arr[i].Copies << " copies of this book is available in our library" << endl;
                    cout << "Now you can borrow a book";
                }
                else
                {
                    cout << bookName << " book is not available in the library";
                    cout << "so you cannot borrow it";
                }
            }
        }
        break;

        case 4:
        {
            cout << endl<<"So you want to return a book" << endl;
            cout << "Enter a book id:";
            cin >> bookId;
        }
        break;

        case 5:
        {
            cout<<endl<<endl<<"Thank You !"<<endl;
            exit(0);
        }

        default:
        {
            cout << "Invalid option:" << endl;
            cout << "Please enter a valid option : ";
        }
        }
        } while (userCheck !=5);
    }
};
int main()
{
    cout << "Hello ! Welcome to the TMV Library" << endl;
    
    int check = 1, id;
    do
    {
        cout << "1. user" << endl;
        cout << "2. admin" << endl;
        cout << "Choose your rank : ";
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
                    cout << endl
                         << "Hello " << userName[i] << " ! Welcome to the library.";
                    // USER AUTHORITY
                    user objUser;
                    objUser.authority();
                    objUser.check();
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