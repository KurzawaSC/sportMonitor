#include "headers.h"

using namespace std;

class Account
{
    private:
        string name, surname, email, password;
        int userId;
        char sex;
        unsigned short int age, weight, height;
        EatMonitor eatMonitor();

    public:
        Account()
        {
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
        }
};

class EatMonitor
{
    private:
        int kcal, protein, fat, carbs;
    
    public:
        EatMonitor()
        {
            cout << endl << "Enter your kcal/day: ";
            cin >> kcal;
            cout << endl << "How many protein you need?: ";
            cin >> protein;
            cout << endl << "How many fat you need?: ";
            cin >> fat;
            carbs = (kcal - (protein*4 + fat*9));
            system("cls");
        }
        void daily_tab()
        {
            cout << "kcal: " << kcal << endl;
            cout << "protein: " << protein << endl;
            cout << "fat: " << fat << endl;
            cout << "carbs: " << carbs << endl << endl;
        }
};

void log_out(vector<Account> users)
{
    int i = 0;

    while (true)
    {
        char choice;

        cout << "1. Log in" << endl;
        cout << "2. Sign in" << endl;

        choice = getch();

        if (choice == '1')
        {
            log_in(users[i]);
        }
        else if (choice == '2')
        {
            users[i] = Account();
            log_in(users[i]);
        }

        i++;
    }
    
}

void log_in(Account user)
    {
        cout << "You loged in";
    }