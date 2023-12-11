#include "headers.h"

void display_exercises()
{
    vector<Exercise> exercises;
    load_exercises(exercises);
    cout << exercises[0].get_name()<< endl;
    char choice_exercise{};
    int i =1;
    while(true)
    {
        bool end = false;
        system("cls");
        cout << "1. Show exercises" << endl;
        cout << "2. Update your progress" << endl;
        cout << "3. Add new exercise" << endl;
        cout << "4. Exit" << endl;

        choice_exercise = getch();
        switch (choice_exercise)
        {
        case '1':
            i = 1;
            system("cls");
            cout << "0. Exit" << endl;
            for(auto exercise : exercises)
            {
                if (exercise.get_name() != "")
                {
                    cout << i++ << ". " << exercise.get_name() << "- Weight: " << exercise.get_weight() << 
                            " Reps: " << exercise.get_num_reps() << endl;
                }
            }
            while(getch() != '0');
            break;

        case '2':
            i = 1;
            system("cls");
            cout << "0. Exit" << endl;
            for(auto exercise : exercises)
            {
                if (exercise.get_name() != "")
                {
                    cout << i++ << ". " << exercise.get_name() << "- Weight: " << exercise.get_weight() << 
                            " Reps: " << exercise.get_num_reps() << endl;
                }
            }

            unsigned short int ex;
            cin >> ex;
            if(ex == 0) {}
            else {
                string nameEx;
                fstream file("exercise.txt", ios::in | ios::out);
                if(file.is_open())
                {
                    while(!file.eof())
                    {
                        getline(file, nameEx);
                        if(nameEx == exercises[ex-1].get_name())
                        {
                            system("cls");
                            unsigned short int weight, num_reps;
                            cout << "Enter weight: ";
                            cin >> weight;
                            cout << "Enter number of reps: ";
                            cin >> num_reps;
                            exercises[ex-1].set_weight(weight);
                            exercises[ex-1].set_num_reps(num_reps);
                            file.close();
                            file.open("exercise.txt", ios::out | ios::trunc);
                            upload_exercise(exercises, exercises[ex-1].get_name());
                        }
                    }
                }
                file.close();
                cout << "Done" << endl;
                Sleep(500);
            }
            break;

        case '3':
            upload_exercise(exercises);
            break;

        case '4':
            end = true;
            break;
        
        default:
            break;
        }
        if(end) break;
    }
}