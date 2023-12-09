#include "headers.h"

void log_out()
{
    char choice;

    cout << "1. Log in" << endl;
    cout << "2. Sign in" << endl;

    choice = getch();

    if (choice == '1')
    {
        string email;
        cout << "Enter your email: ";
        cin >> email;
        for (auto user:users)
        {
            if (email == user.get_email()) log_in(user);
        }
    }
    else if (choice == '2')
    {
        Account user = create_account();
        users.push_back(user);
        upload_to_data_base(user);
        log_in(user);

    }
}

void log_in(Account user)
    {
        char choice;

        cout << "You logged in";
        system("cls");
        cout << "Hello," << endl;
        cout << "1. View your diet" << endl;
        cout << "2. Training notepad" << endl;
        cout << "3 . Log out" << endl;

        choice = getch();

        switch (choice)
        {
        case '1':
        {
            EatMonitor monitor(user);
            monitor.daily_tab();
            break;
        }
        case '2':
            break;
        case '3':
            break;
        
        default:
            break;
        }
    }

    Account create_account()
    {
        string name, surname, email, password;
        int userId;
        char sex;
        unsigned short int age, weight, height;
        cout << "Enter your name: ";
        cin >> name;
        cout << endl << "Enter your surname: ";
        cin >> surname;
        cout << endl << "Enter your email: ";
        cin >> email;
        cout << endl << "Create your password: ";
        cin >> password;
        cout << endl << "Enter your age: ";
        cin >> age;
        cout << endl << "Enter your weight: ";
        cin >> weight;
        cout << endl << "Enter your height: ";
        cin >> height;
        cout << endl << "Chose your sex: M/F";
        while (true)
        {
            sex = getch();
            if (sex == 'M' || sex == 'm' || sex == 'F' || sex == 'f')
                break;
            else
            {
                    cout << endl << "Wrong key, please try again: M/F";
            }
                
        }
        system("cls");
        cout << "Your account was created";
        Sleep(3000);
        system("cls");

        Account user(name, surname, email, password, age, weight, height, sex);
        return user;
    }

