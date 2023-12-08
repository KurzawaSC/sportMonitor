#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>


#ifndef _headers_H_
#define _headers_H_



using namespace std;

class Account;
void upload_to_data_base(Account user);

class Account
{
private:
    string name, surname, email, password;
    int userId;
    char sex;
    unsigned short int age, weight, height;

public:
    Account(string nameI, string surnameI, string emailI, string passwordI, unsigned int ageI, 
                    unsigned int weightI, unsigned int heightI, unsigned int sexI): name(nameI), surname(surnameI),
                    email(emailI), password(passwordI), age(ageI), weight(weightI), height(heightI), sex(sexI) {};
    string get_email() {return email;}


    friend void upload_to_data_base(Account user);
};

class EatMonitor
{
    private:
        int kcal, protein, fat, carbs;
    
    public:
       // EatMonitor();
        void daily_tab();
};

static vector<Account> users;

Account create_account();
void log_in(Account user);
void log_out();
void load_to_data_base();

#endif