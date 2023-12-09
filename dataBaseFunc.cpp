#include "headers.h"

void load_data_from_base()
{
    ifstream file("users.txt");
    while(true)
    {
        string name{}, surname{}, email{}, password{};
        int userId{};
        char sex{};
        unsigned short int age{}, weight{}, height{};

        file >> name; if(!name.length()) break;
        file >> surname;
        file >> email;
        file >> password;
        file >> age;
        file >> weight;
        file >> height;
        file >> sex;
        users.push_back(Account(name, surname, email, password, age, weight, height, sex));
    }
    file.close();
}

void upload_to_data_base(Account user)
{
    ofstream file("users.txt", ios::app);
    file << user.name << endl;
    file << user.surname << endl;
    file << user.email << endl;
    file << user.password << endl;
    file << user.age << endl;
    file << user. weight << endl;
    file << user.height << endl;
    file << user.sex << endl;
    file.close();
}
