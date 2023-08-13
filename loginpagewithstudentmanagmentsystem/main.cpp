#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
class Student
{
    string name, roll_no, semester, phone_no, email_id;

public:
    void menu();
    void insert();
    void display();
    void search();
};
void Student ::menu()
{
menustart:
    int choice;
    char x, y;
    system("cls");

    cout << "\t\t\t        _______________________________" << endl;
    cout << "\n\t\t\t        |  STUDENT MANAGEMENT SYSTEM  |" << endl;
    cout << "\t\t\t        _______________________________" << endl;

    cout << "\t\t\t  1.Enter New record " << endl;
    cout << "\t\t\t  2.Display record" << endl;
    cout << "\t\t\t  3.Search record" << endl;
    cout << "\t\t\t  4.Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "Do you want to insert more detail(Y/N)";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;

    case 2:
        display();
        break;

    case 3:
        do
        {
            search();
            cout << "\nDo you want to see the detail of more student(Y/N):";
            cin >> y;
        } while (y == 'Y' || y == 'y');
        break;

    case 4:
        exit(0);
        break;

    default:
        cout << "\t\t\t Invalid choice.... Please Try Again..";
    }
    getch();

    goto menustart;
}

void Student::insert()
{   char x;
    system("cls");
    fstream file;
    cout << "\n           _________________________________\n";
    cout << "                | Add Student Detail  | \n";
    cout << "\n           _________________________________\n";

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ROll NO. : ";
    cin >> roll_no;
    cout << "Enter Semester: ";
    cin >> semester;
    cout << "Enter Phoneno: ";
    cin >> phone_no;
    cout << "Enter Email ID: ";
    cin >> email_id;
    file.open("student1.txt", ios::app | ios::out);  //new data is added at the end of the file without affecting the existing data.
    file << " " << name << " " << roll_no << " " << semester << " " << phone_no << " " << email_id;
    file.close();
    cout<<"Do you want to insert the data of more student(Y/N): ";
    cin>>x;
    if (x=='Y'||x=='y')
    {
        insert();

    }

    else{
        menu();
    }

    
}
void Student ::display()
{

    system("cls");
    fstream file;
    cout << "        ___________________________\n";
    cout << "           |STUDENT RECORD TABLE|  \n";
    cout << "       ___________________________\n";
    file.open("student1.txt", ios::in);
    file >> name >> roll_no >> semester >> phone_no >> email_id;
    while (!file.eof())
    {
        cout << "\n\t\t  STUDENT NAME:  " << name;
        cout << "\n\t\t  STUDENT ROLL NO: " << roll_no;
        cout << "\n\t\t  STUDENT SEMESTER: " << semester;
        cout << "\n\t\t  STUDENT PHONE NO: " << phone_no;
        cout << "\n\t\t  STUDENT EMAIL ID: " << email_id;
        cout << endl;
        file >> name >> roll_no >> semester >> phone_no >> email_id;
    }
    file.close();
}
void Student::search()
{
    system("cls");
    fstream file;
    string roll;
    int found = 0;
    cout << "Enter the roll of the Student: ";
    cin >> roll;
    file.open("student1.txt", ios::in);
    file >> name >> roll_no >> semester >> phone_no >> email_id;
    while (!file.eof())
    {
        if (roll == roll_no)
        {
            cout << "\n\t\t  STUDENT NAME:  " << name;
            cout << "\n\t\t  STUDENT ROLL NO: " << roll_no;
            cout << "\n\t\t  STUDENT SEMESTER: " << semester;
            cout << "\n\t\t  STUDENT PHONE NO: " << phone_no;
            cout << "\n\t\t  STUDENT EMAIL ID: " << email_id;
            cout << endl;
            found++;
        }
        file >> name >> roll_no >> semester >> phone_no >> email_id;
    }
    if (found == 0)
    {
        cout << "\n\t\t\t   Invalid roll no.  \n ";
    }

    file.close();
}

void login();
void registration();
void forget();
int main()
{
    char a, b;
    std::cout << "Press S for student and T for teacher: ";
    cin >> a;

    if (a == 's' || a == 'S')
    {
        
            int c;
            std::cout << "\t\t\t__________________________________________________________________________\n\n";
            std::cout << "\t\t\t\t\t        WELCOME TO THE LOGIN PAGE             \n\n";
            std::cout << "\t\t\t\t\t | PRESS 1 TO LOGIN                   |" << endl;
            std::cout << "\t\t\t\t\t | PRESS 2 TO REGISTER                |" << endl;
            std::cout << "\t\t\t\t\t | PRESS 3 IF YOU FORGET YOUR PASSWORD|" << endl;
            std::cout << "\t\t\t\t\t | PRESS 4 TO EXIT                    |" << endl;
            std::cout << "\t\t\t__________________________________________________________________________\n\n\n";
            std::cout << " PLEASE ENTER YOUR CHOICE:      ";
            cin >> c;
            cout << endl;

            switch (c)
            {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forget();
                break;
            case 4:
                std::cout << "\t\t\t Thank you  \n\n";
                break;
            default:
                system("cls");
                std::cout << "\t\t\t Please select from the the option given above  \n " << endl;
                main();
            }
        
       
    }
    else if (a == 't' || a == 'T')
    {
        int d;
        std::cout << "\t\t\t _________________________________________________________________________\n";
        std::cout << "\t\t\t\t     WELCOME TO TEACHER LOGIN PAGE   \t\t\t\n";
        std::cout << "\t\t\t\t\t | PRESS 1 TO LOGIN                     |" << endl;
        std::cout << "\t\t\t\t\t | PRESS 2 TO REGISTER                  |" << endl;
        std::cout << "\t\t\t\t\t | PRESS 3 TO SEE  THE DETAIL OF STUDENT|" << endl;
        std::cout << "\t\t\t__________________________________________________________________________\n\n\n";
        std::cout << " PLEASE ENTER YOUR CHOICE:      ";
        cin >> d;
        std::cout << endl;

        switch (d)
        {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        default:
            std::cout << "Please select from the the option given above  \n " << endl;
        }
    }

     Student s1;
        s1.menu();
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t PLEASE ENTER THE USERNAME AND PASSWORD :" << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("student.txt"); // reads the data from file

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\n LOGIN SUCESSFULLY \n\n";
    }

    else
    {
        cout << "\n\n INCORRECT USERNAME OR PASSWORD \n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t  Enter the username: ";
    cin >> ruserId;

    cout << "\t\t\t  Enter the password: ";
    cin >> rpassword;

    ofstream f1("student.txt", ios::app); // write in the file
    f1 << ruserId << "  " << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t REGISTRATION IS SUCESSFULL!!  \n";
    main();
}

void forget()
{
    int option;
    system("cls");
    cout << "\t\t\t  You forget the password ? NO worries \n";
    cout << "Press 1 to search your id by username  " << endl;
    cout << "Press 2 to go back to the main menu   " << endl;
    cout << "\t\t\t    Enter the choice:  ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string luserId, lId, lpass;
        cout << "\t\t\t Enter the your last username you remember: ";
        cin >> luserId;

        ifstream f2("student.txt");
        while (f2 >> lId >> lpass)
        {
            if (lId == luserId)
            {
                count = 1;
            }
        }
        f2.close();

        if (count == 1)
        {
            cout << "\n\n\n  Your account is found!! \n";
            cout << "\n\n\n   Your password is: " << lpass << endl;
            main();
        }
        else
        {
            cout << "\n\n  Sorry!! Your account is not found!!";
        }
    }
    break;

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Please select from the the option given above  \n " << endl;
        forget();
    }
}
