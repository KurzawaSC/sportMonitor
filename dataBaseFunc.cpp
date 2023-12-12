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

        file >> name; if(name == "") break;
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

void load_exercises(vector<Exercise> &exercises, int user_id)
{
    fstream file("exercise.txt", ios::in);
    if(file.is_open())
    {
        while(!file.eof())
        {
            string name;
            unsigned short int weight, num_reps;
            int l_user_id;
            file >> name; if(name == "") break;
            file >> weight;
            file >> num_reps;
            file >> l_user_id;
            if(l_user_id == user_id) exercises.push_back(Exercise(name, weight, num_reps, l_user_id));
        }
        file.close();
    }
}

void upload_exercise(vector<Exercise> &exercises, int user_id, string p_name,
                            unsigned short int p_weight, unsigned short int p_num_reps)
{
    string name;
    unsigned short int weight, num_reps;
    if(p_name == "empty")
    {
        cout << "Enter the name of exercise: ";
        cin >> name;
        cout << "Enter weight: ";
        cin >> weight;
        cout << "Enter number of reps: ";
        cin >> num_reps;
        Exercise exercise_add(name, weight, num_reps, user_id);
        exercises.push_back(exercise_add);

        fstream file("exercise.txt", ios::app);
        file << exercise_add.get_name() << endl;
        file << exercise_add.get_weight() << endl;
        file << exercise_add.get_num_reps() << endl;
        file << user_id << endl;
        file.close(); 
    } else
    {
        fstream file("exercise.txt", ios::app);
        if(file.is_open())
        {
            for(auto exercise : exercises)
            {
                if(exercise.get_name() != "")
                {
                    file << exercise.get_name() << endl;
                    file << exercise.get_weight() << endl;
                    file << exercise.get_num_reps() << endl;
                    file << user_id << endl;
                }
            }
            file.close(); 
        }
    }
    
}