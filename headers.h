#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <limits>


#ifndef _headers_H_
#define _headers_H_


using namespace std;

class Account;
class EatMonitor;
class Exercise;
class WrongInputException;
void upload_to_data_base(Account user);
void load_data_from_base();
void products(EatMonitor *monitor);
void load_exercises(vector<Exercise> &exercises, int user_id);
void upload_exercise(vector<Exercise> &exercises, int user_id, string p_name = "empty",
                            unsigned short int p_weight = 1, unsigned short int p_num_reps = 1);
void display_exercises(int user_id);

class WrongInputException {};

class Account
{
private:
    string name, surname, email, password;
    int userId{};
    char sex;
    unsigned short int age, weight, height;
    static int number_of_users;

public:
    Account(string nameI, string surnameI, string emailI, string passwordI, unsigned int ageI, 
                    unsigned int weightI, unsigned int heightI, unsigned int sexI): name(nameI), surname(surnameI),
                    email(emailI), password(passwordI), age(ageI), weight(weightI), height(heightI), sex(sexI) {
                        userId = ++number_of_users;
                    };
    string get_email() {return email;}
    string get_password() {return password;}
    string getName() {return name;}
    int getId() {return userId;}


    friend void upload_to_data_base(Account user);
    friend void load_data_from_base();
};

class EatMonitor
{
    private:
        int used_kcal{}, used_protein{}, used_fat{}, used_carbs{}, user_id{};
    protected:
        int kcal, protein, fat, carbs;
    
    public:
        EatMonitor() {};
        EatMonitor(Account user);
        void daily_tab();

    friend void products(EatMonitor *monitor);
};

class Product: public EatMonitor {
    protected:
        string name;
    public:
        Product(string p_name, int p_kcal, int p_protein, int p_fat, int p_carbs) {
            name = p_name;
            kcal = p_kcal;
            protein = p_protein;
            fat = p_fat;
            carbs = p_carbs;
        }

        friend void products(EatMonitor *monitor);
};

class Exercise {
    private:
        string name;
        unsigned short int weight{}, num_reps{};
        int user_id{};
    public:
        Exercise(string p_name, unsigned short int p_weight, unsigned short int p_num_reps, int p_user_id): name(p_name),
                    weight(p_weight), num_reps(p_num_reps), user_id(p_user_id) {};

        void set_weight(unsigned short int p_weight) {weight = p_weight;}
        void set_num_reps(unsigned short int p_num_reps) {num_reps = p_num_reps;}

        string get_name() {return name;}
        unsigned short int get_weight() {return weight;}
        unsigned short int get_num_reps() {return num_reps;}
};

extern vector<Account> users;

Account create_account();
void log_in(Account user);
void log_out();


#endif