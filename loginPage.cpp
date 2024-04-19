#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<conio.h>
#include <regex>
using namespace std;


class login_system
{

protected:
	    void waiting()
    {
        for(int i = 0; i < 10; i++)
        {
            Sleep(200);
            cout<<"..";
        }
    }
    string fname, password, name, pass, date, month, year, email, number;
public:
    void homepage();
    void menu();
    void details();
    void modify();
    void change_password();
    void delete_account();
    void exit();
};

class CreateAcc:public login_system{
	public:
	void create();
};
class LoginPage:public login_system{
public:
	void login();
};

class ListAccount:public login_system{
public:
	void listacc();
};

class SearchAccount:public login_system{
public:
	void searchacc();
};

void login_system::homepage()
{
        system("cls");
        cout<<"\n\t    _____________________________________________________________________________________________"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |\t\t             Welcome To My App: CREATE, LOGIN & AUTHENTICATION                  |"<<endl;
        cout<<"\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                HOMEPAGE              |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. Create Account                     |";
        cout<<"\n\t\t\t\t\t|2. Login                              |";
        cout<<"\n\t\t\t\t\t|3. List of All Accounts               |";
        cout<<"\n\t\t\t\t\t|4. Search Account By Name             |";
        cout<<"\n\t\t\t\t\t|5. Exit                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;
        char x;
        cout<<"\t\t\t\t\t-> ";
        cin>>x;
       if (x == '1') {
    CreateAcc acc;
    acc.create();
}

    else if (x == '2') {
        LoginPage log;
        log.login();
    }
    else if (x == '3') {
			ListAccount l1;
	        l1.listacc();

    }
    else if (x == '4') {
       SearchAccount s1;
       s1.searchacc();
    }
    else if(x == '5')
        {
            _exit(0);
        }
    else {
        cout << "\t\t\t\t\tInvalid Parameter, Try Again.";
        Sleep(636);
        homepage();
    }
}


void CreateAcc::create() {
    system("cls");
    cout<<"\n\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t|                                        |";
    cout<<"\n\t\t\t\t|               Create Account           |"<<endl;
    cout<<"\t\t\t\t|________________________________________|"<<endl<<endl;

    regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    regex phone_pattern(R"([0-9]{10})");

    string tempName, tempPhone, tempEmail;
    while (true) {
        cout<<"\t\t\t\t\tEnter User_Name: "<<endl<<"\t\t\t\t\t";
        cin>>fname;

        fstream checkFile;
        checkFile.open("files", ios::in);
        bool usernameExists = false;
        while (checkFile >> tempName) {
            if (tempName == fname) {
                usernameExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (usernameExists) {
            cout<<"\n\t\t\t\t\tUsername already exists! Please choose a different username."<<endl;
            continue;
        } else {
            break;
        }
    }

    while (true) {
        cout<<endl<<"\t\t\t\t\tEnter your Contact Details: "<<endl<<"\t\t\t\t\tPhone Number : ";
        cin>>number;


        fstream checkFile;
        checkFile.open("files", ios::in);
        bool phoneExists = false;
        while (checkFile >> tempName >> tempPhone) {
            if (tempPhone == number) {
                phoneExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (phoneExists) {
            cout<<"\n\t\t\t\t\tPhone number already exists! Please enter a different phone number."<<endl;
            continue;
        } else {
            break;
        }
    }

    while (true) {
        cout<<endl<<"\t\t\t\t\tEnter Email Address: "<<endl<<"\t\t\t\t\t";
        cin>>email;


        fstream checkFile;
        checkFile.open("files", ios::in);
        bool emailExists = false;
        while (checkFile >> tempName >> tempPhone >> tempEmail) {
            if (tempEmail == email) {
                emailExists = true;
                break;
            }

            checkFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        checkFile.close();

        if (emailExists) {
            cout<<"\n\t\t\t\t\tEmail address already exists! Please enter a different email address."<<endl;
            continue;
        } else {
            break;
        }
    }

    cout<<endl<<"\t\t\t\t\tEnter your Date of Birth-"<<endl<<"\t\t\t\t\tDay :  ";
    cin>>date;
    cout<<"\t\t\t\t\tMonth : ";
    cin>>month;
    cout<<"\t\t\t\t\tYear :  ";
    cin>>year;

    while (true) {
        cout<<endl<<"\t\t\t\t\tEnter password: "<<endl<<"\t\t\t\t\t";
        char ch;
        password = "";
        ch = _getch();
        while (ch != 13) {
            if (ch == '\b') {
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                if (password.length() < 18) {
                    password.push_back(ch);
                    cout << '*';
                }
            }
            ch = _getch();
        }
        if(password.length() >= 8) {
            break;
        }
        cout<<endl<<"\t\t\t\tPlease enter the password greater than 8 characters!!!"<<endl;
    }

    fstream file;
    file.open("files", ios::app | ios::out);
    if(!file) {
        cout<<"\t\t\t\t\tRegistration failed"<<endl<<"Try again later"<<endl;
    } else {
        file<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        cout<<"\n\n\t\t\t\t\tAccount Created Successfully."<<endl<<"\n\t\t\t\t\t";
        file.close();
    }
    system("pause");
    login_system::homepage();
}void LoginPage::login(){
system("cls");
             cout<<"\n\t\t\t\t\t _______________________________________"<<endl;
            cout << "\t\t\t\t\t*                                      *" << endl;
            cout << "\t\t\t\t\t*            Welcome to MyApp          *" << endl;
            cout << "\t\t\t\t\t*                                      *" << endl;
            cout << "\t\t\t\t\t*              LOGIN PAGE              *" << endl;
            cout << "\t\t\t\t\t*______________________________________*" << endl << endl;
            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t\tError! File not found"<<endl;
                file.close();
                cout<<"\n\t\t\t\t\t\t";
                system("pause");
                file.close();
                homepage();
            }
            else
            {
                char ch;
                name = "";
                pass = "";
                int flag = 0;
                cout<<"\t\t\t\t\tEnter User_Name : ";
                cin>>name;
                cout<<"\t\t\t\t\tEnter Password : ";
                ch = _getch();
                while(ch != 13) {
                if(ch == '\b') {
                    if(!pass.empty()) {
                        cout<<"\b \b";
                        pass.pop_back();
                    }
                } else {
                    pass.push_back(ch);
                    cout<<'*';
                }
                ch = _getch();
            }
            file>>fname>>password>>number>>email>>date>>month>>year;
            while(!file.eof()) {
                if(name == fname && pass == password) {
                    flag = 1;
                    break;
                }
                file>>fname>>password>>number>>email>>date>>month>>year;
            }
                cout<<"\n\t\t\t\t\tVerifying User Data"<<endl<<"\t\t\t\t\t";
                waiting();
                if(flag == 1)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tLogin Successful";
                    file.close();
                    Sleep(789);
                    menu();
                }
                else if(flag == 0)
                {
                    cout<<endl<<endl<<"\t\t\t\t\tNo account exists with given credentials."<<endl;
                    cout<<"\n\t\t\t\t\t";
                    system("pause");
                    file.close();
                    homepage();
                }
            }
}


void ListAccount::listacc()
{
	int x = 1;
            system("cls");
            cout<<"\n\t\t\t\t\t _______________________________________"<<endl;
            cout << "\t\t\t\t\t*                                      *" << endl;
            cout << "\t\t\t\t\t*            Welcome to MyApp          *" << endl;
            cout << "\t\t\t\t\t*                                      *" << endl;
            cout << "\t\t\t\t\t*              LOGIN PAGE              *" << endl;
            cout << "\t\t\t\t\t*______________________________________*" << endl << endl;

            fstream file;
            file.open("files", ios::in);
            if(!file)
            {
                cout<<"\t\t\t\t\t Error! File not found"<<endl;
            }
            else
            {
                file>>fname>>password>>number>>email>>date>>month>>year;
                while(!file.eof())
                {
                    Sleep(66);
                    cout<<"\t\t\t\t\t\t ______________"<<endl;
                    cout<<"\t\t\t\t\t\t|              |"<<endl;
                    cout<<"\t\t\t\t\t\t|   ACCOUNT "<<x++<<"  |"<<endl;
                    cout<<"\t\t\t\t\t\t|______________|"<<endl;
                    cout<<endl<<"\t\t\t\t\t 1. User_name = "<<fname<<endl;
                    cout<<"\t\t\t\t\t 2. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t 3. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t 4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl;
                    cout<<"\t\t\t\t\t ------------------------------------"<<endl<<endl;
                    file>>fname>>password>>number>>email>>date>>month>>year;
                }
                cout<<"\t\t\t\t\t Reached at end of the File"<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t ";
            system("pause");
            homepage();
}

void SearchAccount::searchacc()
{
	 system("cls");
            cout<<"\n\t\t\t\t ___________________________________________\n";
            cout<<"\t\t\t\t|                                           |";
            cout<<"\n\t\t\t\t|                SEARCH ACCOUNT             |"<<endl;
            cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
            cout<<"\t\t\t\t\tEnter User_Name: ";
            cin>>name;
            int found = 0;
            fstream file;
            file.open("files", ios::in);
            file>>fname>>password>>number>>email>>date>>month>>year;
            while(!file.eof())
            {
                if(name == fname)
                {
                    Sleep(66);
                    cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<endl;
                    cout<<"\t\t\t\t\t2. Email = "<<email<<endl;
                    cout<<"\t\t\t\t\t3. Contact = "<<number<<endl;
                    cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
                    cout<<"\t\t\t\t\t------------------------------------"<<endl<<endl;
                    found++;
                }
                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            if(found == 0)
            {
                cout<<endl<<"\t\t\t\t\tNo account exist with ["<<name<<"] username ."<<endl<<endl;
            }
            file.close();
            cout<<"\t\t\t\t\t";
            system("pause");
            homepage();
}

void login_system::menu()
    {
        system("cls");
        cout<<"\n\t\t\t\t __________________________________________________\n";
        cout<<"\t\t\t\t|                                                  |";
        cout<<"\n\t\t\t\t|                 ACCOUNT MANAGMENT                |"<<endl;
        cout<<"\t\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tKindly select an option below:"<<endl<<endl;
        cout<<"\t\t\t\t\t1. Account Details"<<endl<<endl;
        cout<<"\t\t\t\t\t2. Modify Account"<<endl<<endl;
        cout<<"\t\t\t\t\t3. Change Password"<<endl<<endl;
        cout<<"\t\t\t\t\t4. Delete Account"<<endl<<endl;
        cout<<"\t\t\t\t\t5. Logout"<<endl;
        char option;
        cout<<endl<<"\t\t\t\t\t-> ";
        cin>>option;
        switch(option)
        {
        case '1':
            details();
            break;
        case '2':
            modify();
            break;
        case '3':
            change_password();
        case '4':
            delete_account();
        case '5':
            {
                cout<<"\n\t\t\t\t\tLogging Out . . ."<<endl<<"\t\t\t\t\t";
                waiting();
                homepage();
            }
        default:
            cout<<"\t\t\t\t\tInvalid Option\n\t\t\t\t\tTry Again."<<endl;
            Sleep(636);
            menu();
        }
    }
void login_system::details()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              ACCOUNT DETAILS              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file;
    file.open("files", ios::in);
    file>>fname>>password>>number>>email>>date>>month>>year;
    while(!file.eof())
    {
        if(name == fname && password == pass)
        {
            Sleep(66);
            cout<<endl<<"\t\t\t\t\t1. User_Name = "<<fname<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t2. Email = "<<email<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t3. Contact = "<<number<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t4. Date of Birth = "<<date<<"/"<<month<<"/"<<year<<endl<<endl;
            Sleep(66);
            cout<<"\t\t\t\t\t5. Account Password = "<<password<<endl<<endl;
            break;
        }
        file>>fname>>password>>number>>email>>date>>month>>year;
    }
    file.close();
    cout<<"\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::modify()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              MODIFY ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    fstream file, file1;
    file.open("files", ios::in);
    file1.open("modify", ios::app | ios::out);
    file>>fname>>password>>number>>email>>date>>month>>year;
    while(!file.eof())
    {
        if(name == fname && pass == password)
        {
            cout<<"\t\t\t\t\tEnter User_Name: "<<endl<<"\t\t\t\t\t";
            cin>>fname;
            cout<<endl<<"\t\t\t\t\tEnter your Date of Birth- "<<endl<<"\t\t\t\t\tDay :  ";
            cin>>date;
            cout<<"\t\t\t\t\tMonth : ";
            cin>>month;
            cout<<"\t\t\t\t\tYear :  ";
            cin>>year;
            cout<<endl<<"\t\t\t\t\tEnter your Contact Details: "<<endl<<"\t\t\t\t\tPhone Number : ";
            cin>>number;
            cout<<endl<<"\t\t\t\t\tEnter Email Address: "<<endl<<"\t\t\t\t\t";
            cin>>email;
            file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        else
        {
            file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
        }
        file>>fname>>password>>number>>email>>date>>month>>year;
    }
    cout<<endl<<"\t\t\t\t\tSaving new details, Please wait . . ."<<endl<<"\t\t\t\t\t";
    waiting();
    file.close();
    file1.close();
    remove("files");
    rename("modify", "files");
    cout<<endl<<"\n\t\t\t\t\tAccount Details Saved Successfully."<<endl;
    cout<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl<<"\n\t\t\t\t\t";
    system("pause");
    menu();
}
void login_system::change_password() {
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              CHANGE PASSWORD              |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    string oldpass, newpass, confirmpass;
    cout<<"\t\t\t\t\tEnter your Old Password: ";
    cin>>oldpass;
    if(oldpass == pass) {
        cout<<endl<<"\t\t\t\t\tEnter New Password: ";
        char ch;
        newpass = "";
        ch = _getch();
        while (ch != 13) {
            if (ch == '\b') {
                if (!newpass.empty()) {
                    cout << "\b \b";
                    newpass.pop_back();
                }
            } else {
                if (newpass.length() < 18) {
                    newpass.push_back(ch);
                    cout << '*';
                }
            }
            ch = _getch();
        }

        cout<<endl<<"\t\t\t\t\tConfirm New Password: ";
        ch = _getch();
        confirmpass = "";
        while (ch != 13) {
            if (ch == '\b') {
                if (!confirmpass.empty()) {
                    cout << "\b \b";
                    confirmpass.pop_back();
                }
            } else {
                if (confirmpass.length() < 18) {
                    confirmpass.push_back(ch);
                    cout << '*';
                }
            }
            ch = _getch();
        }

        if(newpass == oldpass) {
            cout<<endl<<"\t\t\t\t\tOld and New Password can't be the same.";
        } else if(confirmpass != newpass) {
            cout<<endl<<"\t\t\t\t\tError! Passwords do not match."<<endl<<"\t\t\t\t\tPlease try again.";
            Sleep(636);
            change_password();
        } else {
            fstream file, file1;
            file.open("files", ios::in);
            file1.open("modify", ios::app | ios::out);
            file>>fname>>password>>number>>email>>date>>month>>year;
            while(!file.eof()) {
                if(name == fname && pass == oldpass) {
                    file1<<fname<<" "<<newpass<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                } else {
                    file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
                }
                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            cout<<endl<<"\t\t\t\t\tChanging Password, Please wait . . ."<<endl<<"\t\t\t\t\t";
            waiting();
            cout<<endl<<"\n\t\t\t\t\tPassword changed successfully."<<endl;
            cout<<endl<<"\t\t\t\t\tChanges will be shown after Re-login."<<endl;
            file.close();
            file1.close();
            remove("files");
            rename("modify", "files");
        }
    } else {
        cout<<endl<<"\t\t\t\t\tError! Wrong Password"<<endl;
    }
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    menu();
}

void login_system::delete_account()
{
    system("cls");
    cout<<"\n\t\t\t\t ___________________________________________\n";
    cout<<"\t\t\t\t|                                           |";
    cout<<"\n\t\t\t\t|              DELETE ACCOUNT               |"<<endl;
    cout<<"\t\t\t\t|___________________________________________|"<<endl<<endl;
    cout<<"\t\t\t\t\tAre you sure want to delete account ?"<<endl;
    cout<<"\t\t\t\t\tThis action can't be undone!"<<endl;
    cout<<"\t\t\t\t\tY/N: ";
    char x;
    cin>>x;
    if(x == 'y' || x == 'Y')
    {
        fstream file, file1;
        file.open("files", ios::in);
        file1.open("modify", ios::app | ios::out);
        file>>fname>>password>>number>>email>>date>>month>>year;
        while(!file.eof())
        {
            if(name == fname && pass == password)
            {
//                file>>fname>>password>>number>>email>>date>>month>>year;
            }
            else
            {
                file1<<fname<<" "<<password<<" "<<number<<" "<<email<<" "<<date<<" "<<month<<" "<<year<<"\n";
            }
            file>>fname>>password>>number>>email>>date>>month>>year;
        }
        cout<<endl<<"\t\t\t\t\tDeleting Account . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        cout<<endl<<"\n\t\t\t\t\tAccount Deleted Successfully."<<endl;
        cout<<endl<<"\t\t\t\t\tLogging you out . . ."<<endl<<"\t\t\t\t\t";
        waiting();
        file.close();
        file1.close();
        remove("files");
        rename("modify", "files");
        homepage();
    }
    else if(x == 'N' || x == 'n')
    {
        cout<<endl<<"\t\t\t\t\tTaking you back to Main Menu"<<endl<<"\t\t\t\t\t";
        waiting();
        Sleep(636);
        menu();
    }
    else
    {
        cout<<"\t\t\t\t\tPlease select a valid option."<<endl;
        system("pause");
        delete_account();
    }
}



int main()
{
    login_system x;
    x.homepage();
    return 0;
}

