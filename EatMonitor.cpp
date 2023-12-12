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
            file >> user_id;
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
            file << kcal << endl << protein << endl << fat << endl << carbs << endl << user.getId() << endl;
        }   
        file.close();
    }
}

void EatMonitor::daily_tab()
{
    system("cls");
    cout << "kcal: " << kcal << " (" << kcal - used_kcal << "left)" << endl;
    cout << "protein: " << protein << " (" << protein - used_protein << "left)" << endl;
    cout << "fat: " << fat << " (" << fat - used_fat << "left)" << endl;
    cout << "carbs: " << carbs << " (" << carbs - used_carbs << "left)" << endl << endl;
}

void products(EatMonitor *monitor)
{
    vector<Product> products;
    system("cls");
    cout << "0. Exit" << endl;
    cout << "1. Add new product" << endl;
    fstream file("products.txt", ios::in);
    if(file.is_open())
    {
        while(!file.eof())
        {
            string name{};
            int kcal{}, protein{}, fat{}, carbs{}, user_id{};
            file >> name; if(name == "") break;
            file >> kcal;
            file >> protein;
            file >> fat;
            file >> carbs;
            file >> user_id;
            if(user_id == monitor->user_id) products.push_back(Product(name, kcal, protein, fat, carbs));
    }
    file.close();
    int i = 2;
    for (auto product : products)
    {
        cout << i++ << ". " << product.name << endl;
    }
    }
    int choiceProduct{};
    string p_name{};
    int p_kcal{}, p_protein{}, p_fat{}, p_carbs{};
    cin >> choiceProduct;
    switch (choiceProduct)
    {
    case 1:
        file.open("products.txt", ios::app);
        cout << endl << "Enter a product's name (without space): ";
        cin >> p_name;
        cout << "kcal: ";
        cin >> p_kcal;
        cout << endl << "protein: ";
        cin >> p_protein;
        cout << endl << "fat: ";
        cin >> p_fat;
        p_carbs = (p_kcal - p_protein*4 - p_fat*9)/4;
        products.push_back(Product(p_name, p_kcal, p_protein, p_fat, p_carbs));
        file << p_name << endl;
        file << p_kcal << endl;
        file << p_protein << endl;
        file << p_fat << endl;
        file << p_carbs << endl;
        file << monitor->user_id << endl;
        file.close();
        break;
    case 0:
        break;

    default:
        monitor->used_kcal += products[choiceProduct-2].kcal;
        monitor->used_protein += products[choiceProduct-2].protein;
        monitor->used_fat += products[choiceProduct-2].fat;
        monitor->used_carbs += products[choiceProduct-2].carbs;
        break;
    }

}