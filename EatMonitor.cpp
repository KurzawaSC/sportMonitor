#include "headers.h"

EatMonitor::EatMonitor(Account user)
{
    fstream file;
    file.open("eat.txt", ios::in);
    string line;
    bool find = false;
    while(!file.eof())
    {
        getline(file, line);
        if(line == user.getName())
        {
            file >> kcal;
            file >> protein;
            file >> fat;
            file >> carbs;
            file.close();
            find = true;
        }
    }
    if(!find)
    {
        cout << endl << "Enter your kcal/day: ";
        cin >> kcal;
        cout << endl << "How many protein you need?: ";
        cin >> protein;
        cout << endl << "How many fat you need?: ";
        cin >> fat;
        carbs = (kcal - protein*4 - fat*9)/4;
        system("cls");
        fstream file("eat.txt", ios::app);
        if(file.is_open())
        {
            file << user.getName() << endl;
            file << kcal << endl << protein << endl << fat << endl << carbs << endl;
        }   
        file.close();
    }
}

void EatMonitor::daily_tab()
{
    cout << "kcal: " << kcal << endl;
    cout << "protein: " << protein << endl;
    cout << "fat: " << fat << endl;
    cout << "carbs: " << carbs << endl << endl;
    while(getch() != 13);
}