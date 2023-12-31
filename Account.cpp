#include "headers.h"

int Account::number_of_users = 0;

void log_out()
{
    char choice;

    cout << "1. Log in" << endl;
    cout << "2. Sign in" << endl;

    choice = getch();

    if (choice == '1')
    {
        string email;
        bool found = false;
        cout << "Enter your email: ";
        cin >> email;;
        for (auto user:users)
        if (email == user.get_email())
        {
            found = true;
            string password;
            cout << "Enter password: ";
            cin >> password;
            if (password == user.get_password()) log_in(user);
            else cout << "Wrong password!" << endl;
            Sleep(1000);
            break;
        } else if(!found){
            cout << "User with this email does not exist" << endl;
            Sleep(1000);
            break;
        }
    }
    else if (choice == '2')
    {
        try{
            Account user = create_account();
            users.push_back(user);
            upload_to_data_base(user);
            log_in(user);
        }
        catch(...)
        {}

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
                display_exercises(user.getId());
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
        string name, surname, email, password, line;
        int userId;
        char sex;
        unsigned short int age, weight, height;
        try {
            cout << "Enter your name: ";
            getline(cin, name);
            cout << endl << "Enter your surname: ";
            getline(cin, surname);
            cout << endl << "Enter your email: ";
            getline(cin, email);
                bool email_check = false;
                for (int i = 0; i<email.length(); i++)
                {
                    if (email[i] == '@') email_check = true;
                }
                if (email_check == false) throw WrongInputException();
            cout << endl << "Create your password (password must be at least 8 characters): ";
            getline(cin, password);
            if (typeid(password) != typeid(string) || password.length() < 8) throw WrongInputException();
            cout << endl << "Enter your age: ";
            getline(cin, line);
            age = stoi(line);
            cout << endl << "Enter your weight: ";
            getline(cin, line);
            weight = stoi(line);
            cout << endl << "Enter your height: ";
            getline(cin, line);
            height = stoi(line);
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
        catch(...)
        {
            cout << endl << "You entered wrong data!" << endl;
            Sleep(1000);
            system("cls");
        }
    }

