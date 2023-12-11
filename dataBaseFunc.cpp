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

void load_exercises(vector<Exercise> &exercises)
{
    fstream file("exercise.txt", ios::in);
    if(file.is_open())
    {
        while(!file.eof())
        {
            string name;
            unsigned short int weight, num_reps;
            file >> name;
            file >> weight;
            file >> num_reps;
            exercises.push_back(Exercise(name, weight, num_reps));
        }
        file.close();
    }
}

void upload_exercise(vector<Exercise> &exercises, string p_name,
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
        Exercise exercise_add(name, weight, num_reps);
        exercises.push_back(exercise_add);

        fstream file("exercise.txt", ios::app);
        file << endl << exercise_add.get_name() << endl;
        file << exercise_add.get_weight() << endl;
        file << exercise_add.get_num_reps();
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
                }
            }
            file.close(); 
        }
    }
    
}