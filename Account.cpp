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
            if (email == user.get_email())
            {
                string password;
                cout << "Enter password: ";
                cin >> password;
                if (password == user.get_password()) log_in(user);
                else cout << "Wrong password!" << endl;
                Sleep(1000);
                break;
            } else {
                cout << "User with this email does not exist" << endl;
                Sleep(1000);
                break;
            }
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
        while (true)
        {
            system("cls");
            cout << "Hello," << endl;
            cout << "1. View your diet" << endl;
            cout << "2. Training diary" << endl;
            cout << "3 . Log out" << endl;

            choice = getch();
            char choiceEat{};
            switch (choice)
            {
            case '1':
            {
                EatMonitor monitor(user);
                while(choiceEat != '2')
                {
                    monitor.daily_tab();
                    cout << "1. Add product" << endl;
                    cout << "2. Exit" << endl;

                    choiceEat = getch();
                    system("cls");
                    monitor.daily_tab();
                    switch (choiceEat)
                    {
                    case '1':
                        products(&monitor);
                        break;
                    
                    default:
                        break;
                    }
                }
                break;
            }
            case '2':
                display_exercises();
                break;
            case '3':
                break;
            
            default:
                break;
            }
            if(choice == '3') break;
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

