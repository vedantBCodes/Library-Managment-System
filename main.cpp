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
struct books arr[100]; // Array of structures

struct users
{
    string name;
    string email;
    int id;
};
string userName[50];
int userID[50];
string userEmail[50];
int userListIndex;
int adminID = 321;
char currentBookNumber = '4';
int currentBookId = 4;
string adminName = "Rahul";
int bookId;
string bookName;
int currentBookIndex = 0;
int index2;
class userInfo
{
private:
public:
    void userList()
    {
        userListIndex = 0;
        ifstream in;
        in.open("userInfo.txt");
        while (in.eof() == 0)
        {
            in.ignore();
            in >> userName[userListIndex] >> userID[userListIndex] >> userEmail[userListIndex];
            userListIndex++;
        }
    }
    void detailsOfUsers()
    {
         cout << endl
                     << "Here are the details of all the users" << endl;
                cout << endl;
                for (int i = 0; i < userListIndex - 1; i++)
                {
                    cout << "User Name : " << userName[i] << endl;
                    cout << "User Email : " << userEmail[i] << endl;
                    cout << "User ID : " << userID[i] << endl;
                    cout << endl;
                }

    }
};

class bookInfo
{
public:
    void previousFileData()
    {
        index2 = 0;
        ifstream in;
        in.open("books2.txt");
        while (in.eof() == 0)
        {
            in >> arr[index2].BookID >> arr[index2].BookName >> arr[index2].BookAuthor >> arr[index2].ISBN >> arr[index2].Copies;
            index2++;
        }
        in.close();
    }
    void displayDataUsingStructure()
    {
        for (int i = 0; i < index2 - 1; i++)
        {
            cout << "ID : " << arr[i].BookID << endl;
            cout << "Name : " << arr[i].BookName << endl;
            cout << "Author : " << arr[i].BookAuthor << endl;
            cout << "ISBN : " << arr[i].ISBN << endl;
            cout << "Copies : " << arr[i].Copies << endl
                 << endl;
        }
    }
    void detailsOfABook(int i) // i-Array Index
    {
        cout << "Book ID : " << arr[i].BookID << endl;
        cout << "Book Name : " << arr[i].BookName << endl;
        cout << "Book Author : " << arr[i].BookAuthor << endl;
        cout << "ISBN Number : " << arr[i].ISBN << endl;
        cout << "Number of copies : " << arr[i].Copies << endl;
        cout << endl;
    }
    void saveDataInFile()
    {
        ofstream out;
        out.open("books2.txt", ios::out);
        {
            for (int i = 0; i < index2 - 1; i++)
            {
                out << arr[i].BookID << " ";
                out << arr[i].BookName << " ";
                out << arr[i].BookAuthor << " ";
                out << arr[i].ISBN << " ";
                out << arr[i].Copies << " ";
                out << endl;
            }
        }
        out.close();
    }
};
class homeMenu
{
public:
    void menuList();
};
class admin
{
private:
    int adminCheck;
    string newBookInfo[10];

public:
    bool searchBookByID(int id)
    {
        bool check = false;
        for (j = 0; j < index2 - 1; j++)
        {
            if (arr[j].BookID == id)
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
        for (j = 0; j < index2 - 1; j++)
        {
            if (arr[j].BookName == bookName)
            {
                check = true;
                break;
            }
        }
        return check;
    }
    void authority()
    {
        cout << endl
             << endl
             << "As an admin you have much more authority than a normal user" << endl
             << endl;
        cout << "You can add a new user to our library" << endl;
        cout << "You can add a new book into a library" << endl;
        cout << "You can see the book data" << endl;
        cout << "And you can also remove an existing book from a library" << endl;
    }
    void check()
    {
        do
        {
            cout << endl
                 << endl;
            cout << "1. add a new user" << endl;
            cout << "2. display user details" << endl;
            cout << "3. display book data" << endl;
            cout << "4. add a new book" << endl;
            cout << "5. to remove a book" << endl;
            cout << "6. Go to Home menu" << endl;
            cout << "7. Exit from the library" << endl;
            cout << "Choose a valid option : ";
            cin >> adminCheck;

            switch (adminCheck)
            {
            case 1:
            {
                cout << endl
                     << "So you want to add a new user" << endl;
                cout << "Enter his/her  Name:";
                cin >> userName[userListIndex];
                cout << "Enter his/her email:";
                cin >> userEmail[userListIndex];
                userID[userListIndex] = (((userListIndex)*100) + ((userListIndex + 1) * 10) + ((userListIndex + 2) * 1));
                cout << "The new userID of " << userName[userListIndex] << " is : " << userID[userListIndex];
                ofstream out2;
                out2.open("userInfo.txt", ios::app); // append mode
                out2 << userName[userListIndex] << " ";
                out2 << userID[userListIndex] << " ";
                out2 << userEmail[userListIndex] << endl;
                out2.close();
                userListIndex++;
            }
            break;

            case 2:
            {
               userInfo obj;
               obj.userList();
               obj.detailsOfUsers();
            }
            break;

            case 3:
            {
                cout << endl
                     << "Here are the details of books currently available int the library" << endl
                     << endl;
                bookInfo obj;
                obj.previousFileData();
                obj.displayDataUsingStructure();
            }
            break;

            case 4:
            {
                cout << "NOTE-Enter the book name and author name in snake case without using space " << endl;
                cout << "Enter the book ID:";
                cin >> arr[index2].BookID;
                cout << "Enter the book name:";
                cin >> arr[index2].BookName;
                cout << "Enter the Author name :";
                cin >> arr[index2].BookAuthor;
                cout << "Enter the ISBN number : ";
                cin >> arr[index2].ISBN;
                cout << "Enter the number of copies:";
                cin >> arr[index2].Copies;
                ofstream out;
                out.open("books2.txt", ios::app);
                out << arr[index2].BookID << " ";
                out << arr[index2].BookName << " ";
                out << arr[index2].BookAuthor << " ";
                out << arr[index2].ISBN << " ";
                out << arr[index2].Copies << " " << endl;
                out.close();
            }
            break;

            case 5:
            {
                int choice;
                cout << endl
                     << "So you want to remove a book" << endl;
                cout << "1.Remove book by entering book ID" << endl;
                cout << "2.Remove book by entering book Name" << endl;
                do
                {
                    cout << "Enter a valid choice : ";
                    cin >> choice;
                } while (choice >= 3);
                if (choice == 1)
                {
                    cout << "Enter the ID of a book : ";
                    cin >> bookId;
                    bool check = searchBookByID(bookId);
                    if (check == true)
                    {
                        char ch;
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(j);
                        do
                        {
                            cout << " Do you want to remove this book (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book removed successfully !" << endl;
                                for (int i = j; i < index2 - 1; i++)
                                {
                                    arr[i].BookID = arr[i + 1].BookID;
                                    arr[i].BookName = arr[i + 1].BookName;
                                    arr[i].BookAuthor = arr[i + 1].BookAuthor;
                                    arr[i].ISBN = arr[i + 1].ISBN;
                                    arr[i].Copies = arr[i + 1].Copies;
                                }
                                index2--;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
                    }
                    else
                    {
                        cout << "Book with ID " << bookId << " is not available in the library" << endl;
                        cout << "so you cannot remove it";
                    }
                }
                else if (choice == 2)
                {
                    cin.ignore();
                    cout << "NOTE-Always enter the book name in snake case without using space " << endl;
                    cout << "Enter the name of a book : ";
                    getline(cin, bookName);
                    bool check = searchBookByName(bookName);
                    if (check == true)
                    {
                        char ch;
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(i);

                        do
                        {
                            cout << " DO you still want to remove it (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book Removed Successfully !" << endl;
                                for (int i = j; i < index2 - 1; i++)
                                {
                                    arr[i].BookID = arr[i + 1].BookID;
                                    arr[i].BookName = arr[i + 1].BookName;
                                    arr[i].BookAuthor = arr[i + 1].BookAuthor;
                                    arr[i].ISBN = arr[i + 1].ISBN;
                                    arr[i].Copies = arr[i + 1].Copies;
                                }
                                index2--;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
                    }
                    else
                    {
                        cout << bookName << " book is not available in the library" << endl;
                        cout << "so you cannot remove it";
                    }
                }
            }
            break;

            case 6:
            {
                homeMenu obj3;
                obj3.menuList();
            }
            break;

            case 7:
            {
                cout << endl
                     << endl
                     << "Thank You !" << endl;
                exit(0);
            }
            break;

            default:
            {
                cout << "Invalid option:" << endl;
                cout << "Please enter a valid option : ";
            }
            }
        } while (adminCheck != 6);
    }
};
class user
{
private:
    int userCheck, i;

public:
    bool searchBookByID(int id)
    {
        bool check = false;
        for (i = 0; i < index2 - 1; i++)
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
        for (i = 0; i < index2 - 1; i++)
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
        cout << endl
             << endl
             << "As you are a regular user you have the following authority" << endl;
        cout << "you can search for a book " << endl;
        cout << "you can see the book data" << endl;
        cout << "you can borrow a book from a library and" << endl;
        cout << "you can also return a borrowed book to a library" << endl;
    }
    void check()
    {
        do
        {
            cout << endl
                 << endl;
            cout << "1. search for a book" << endl;
            cout << "2. Display book data" << endl;
            cout << "3. borrow a book" << endl;
            cout << "4. return a book" << endl;
            cout << "5. Go to Home menu" << endl;
            cout << "6. Exit From the Library" << endl;
            cout << "Choose a valid option : ";
            cin >> userCheck;

            switch (userCheck)
            {
            case 1:
            {
                int choice;
                cout << endl
                     << "So you want to search for a book" << endl;
                cout << "1.Search book using ID" << endl;
                cout << "2.Search book using Name" << endl;
                do
                {
                    cout << "Enter a valid choice : ";
                    cin >> choice;
                } while (choice >= 3);
                if (choice == 1)
                {
                    cout << "Enter the ID of a book : ";
                    cin >> bookId;
                    bool check = searchBookByID(bookId);
                    if (check == true)
                    {
                        cout << endl
                             << "Book with ID " << bookId << " is available in the library" << endl;
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(i);
                    }
                    else
                    {
                        cout << "Book with ID " << bookId << " is not available in the library";
                    }
                }
                else if (choice == 2)
                {
                    cin.ignore();
                    cout << "NOTE-Always enter the book name in snake case without using space " << endl;
                    cout << "Enter the name of a book : ";
                    getline(cin, bookName);
                    bool check = searchBookByName(bookName);
                    if (check == true)
                    {
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(i);
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
                cout << endl
                     << "Here are the details of books currently available int the library" << endl
                     << endl;
                bookInfo obj;
                obj.previousFileData();
                obj.displayDataUsingStructure();
            }
            break;
            case 3:
            {
                int choice;
                cout << endl
                     << "So you want to borrow a book" << endl;
                cout << "1.Borrow book by entering book ID" << endl;
                cout << "2.Borrow book by entering book Name" << endl;
                do
                {
                    cout << "Enter a valid choice : ";
                    cin >> choice;
                } while (choice >= 3);
                if (choice == 1)
                {
                    cout << "Enter the ID of a book : ";
                    cin >> bookId;
                    bool check = searchBookByID(bookId);
                    if (check == true)
                    {
                        char ch;
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(i);
                        do
                        {
                            cout << " DO you still want to borrow it (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book Borrowed" << endl;
                                arr[i].Copies--;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
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
                    cout << "NOTE-Always enter the book name in snake case without using space " << endl;
                    cout << "Enter the name of a book : ";
                    getline(cin, bookName);
                    bool check = searchBookByName(bookName);
                    if (check == true)
                    {
                        char ch;
                        cout << endl
                             << "Here are the details of the book : " << endl;
                        bookInfo obj;
                        obj.detailsOfABook(i);

                        do
                        {
                            cout << " DO you still want to borrow it (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book Borrowed" << endl;
                                arr[i].Copies--;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
                    }
                    else
                    {
                        cout << bookName << " book is not available in the library" << endl;
                        cout << "so you cannot borrow it";
                    }
                }
            }
            break;

            case 4:
            {
                int choice;
                cout << endl
                     << "So you want to return a book" << endl;
                cout << "1.Return book by entering book ID" << endl;
                cout << "2.Return book by entering book Name" << endl;
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
                        char ch;
                        cout << "There are already " << arr[i].Copies << " copies of this book are available in our library" << endl;

                        do
                        {
                            cout << " DO you still want to return it (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book Returned successfully" << endl;
                                arr[i].Copies++;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
                    }
                    else
                    {
                        cout << "There are no copies of the book with ID " << bookId << endl
                             << endl;
                        cout << "So You have to enter the whole details of that book" << endl;
                        cout << "NOTE-Always enter the book name and author name in snake case without using space " << endl
                             << endl;
                        arr[index2].BookID = bookId;
                        cout << "Enter the book name:";
                        cin >> arr[index2].BookName;
                        cout << "Enter the Author name :";
                        cin >> arr[index2].BookAuthor;
                        cout << "Enter the ISBN number : ";
                        cin >> arr[index2].ISBN;
                        arr[index2].Copies = 1;
                        ofstream out;
                        out.open("books2.txt", ios::app);
                        out << arr[index2].BookID << " ";
                        out << arr[index2].BookName << " ";
                        out << arr[index2].BookAuthor << " ";
                        out << arr[index2].ISBN << " ";
                        out << arr[index2].Copies << " " << endl;
                        out.close();
                        index2++;
                    }
                }
                else if (choice == 2)
                {
                    cin.ignore();
                    cout << "NOTE-Always enter the book name in snake case without using space " << endl;
                    cout << "Enter the name of a book : ";
                    getline(cin, bookName);
                    bool check = searchBookByName(bookName);
                    if (check == true)
                    {
                        char ch;
                        cout << "There are already " << arr[i].Copies << " copies of this book are available in our library" << endl;

                        do
                        {
                            cout << " DO you still want to return it (y/n) : ";
                            cin >> ch;
                            if (ch == 'y')
                            {
                                cout << endl
                                     << "Book Returned successfully" << endl;
                                arr[i].Copies++;
                                bookInfo obj;
                                obj.saveDataInFile();
                            }
                            else if (ch != 'n')
                            {
                                cout << "Invalid option" << endl;
                            }
                        } while ((ch != 'y') && (ch != 'n'));
                    }
                    else
                    {

                        cout << "There are no copies of the book with name " << bookName << endl
                             << endl;
                        cout << "So You have to enter the whole details of that book" << endl;
                        cout << "NOTE-Always enter the book name and author name in snake case without using space " << endl;
                        arr[index2].BookName = bookName;
                        cout << "Enter the book ID:";
                        cin >> arr[index2].BookID;
                        cout << "Enter the Author name :";
                        cin >> arr[index2].BookAuthor;
                        cout << "Enter the ISBN number : ";
                        cin >> arr[index2].ISBN;
                        arr[index2].Copies = 1;
                        ofstream out;
                        out.open("books2.txt", ios::app);
                        out << arr[index2].BookID << " ";
                        out << arr[index2].BookName << " ";
                        out << arr[index2].BookAuthor << " ";
                        out << arr[index2].ISBN << " ";
                        out << arr[index2].Copies << " " << endl;
                        out.close();
                        index2++;
                    }
                }
            }
            break;

            case 5:
            {
                homeMenu obj3;
                obj3.menuList();
            }
            break;

            case 6:
            {
                cout << endl
                     << endl
                     << "Thank You !" << endl;
                exit(0);
            }
            break;

            default:
            {
                cout << "Invalid option:" << endl;
                cout << "Please enter a valid option : ";
            }
            }
        } while (userCheck != 6);
    }
};
void homeMenu::menuList()
{
    int check = 1, id;
    do
    {
        cout << endl;
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
                for (i = 0; i < userListIndex; i++)
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
                         << "ID varified" << endl;
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
                    cout << "Please enter a valid userID : ";
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
                    cout << endl
                         << "ID varified" << endl;
                    cout << "Hello " << adminName << " ! Welcome to the library." << endl;
                    // ADMIN AUTHORITY
                    admin objAdmin;
                    objAdmin.authority();
                    objAdmin.check();
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
}
int main()
{
    cout << "Hii ! Welcome to the TMV Library" << endl;
    bookInfo obj;
    obj.previousFileData();
    userInfo obj2;
    obj2.userList();
    homeMenu obj3;
    obj3.menuList();
    return 0;
}