#include "headers.h"

void display_exercises(int user_id)
{
    vector<Exercise> exercises;
    load_exercises(exercises, user_id);
    char choice_exercise{};
    int i =1;
    while(true)
    {
        bool end = false;
        system("cls");
        cout << "1. Show exercises" << endl;
        cout << "2. Update weight" << endl;
        cout << "3. Add new exercise" << endl;
        cout << "4. Exit" << endl;

        choice_exercise = getch();
        string line{};
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
                    cout << i++ << ". " << exercise.get_name() << " - Weight: " << exercise.get_weight() << 
                            " Reps: " << exercise.get_num_reps() << endl;
                }
            }
            while(getch() != '0');
            break;

        case '2':
            cin.sync();
            unsigned short int ex;
            int go_next;
            go_next = 0;
            while(go_next < 1)
            {
                i = 1;
                system("cls");
                cout << "0. Exit" << endl;
                for(auto exercise : exercises)
                {
                    if (exercise.get_name() != "")
                    {
                        cout << i++ << ". " << exercise.get_name() << " - Weight: " << exercise.get_weight() << 
                                " Reps: " << exercise.get_num_reps() << endl;
                    }
                }
                try{
                    go_next++;
                    getline(cin, line);
                    ex = stoi(line);
                }
                catch(...)
                {
                    go_next = 0;
                    cin.clear();
                    cout << endl << "You entered wrong data" << endl;
                    Sleep(1000);
                    system("cls");
                }
            }
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
                            unsigned short int weight{}, num_reps{};
                            go_next = 0;
                            while(go_next < 1)
                            {
                                try {
                                    go_next++;
                                    cout << "Enter weight: ";
                                    getline(cin, line);
                                    weight = stoi(line);
                                    cout << "Enter number of reps: ";
                                    getline(cin, line);
                                    num_reps = stoi(line);
                                    exercises[ex-1].set_weight(weight);
                                    exercises[ex-1].set_num_reps(num_reps);
                                    file.close();
                                    file.open("exercise.txt", ios::out | ios::trunc);
                                    upload_exercise(exercises, user_id, exercises[ex-1].get_name());
                                }
                                catch(...)
                                {
                                    go_next = 0;
                                    cout << endl << "You entered wrong data" << endl;
                                    Sleep(1000);
                                    system("cls");
                                }
                            }
                        }
                    }
                }
                file.close();
                cout << "Done" << endl;
                Sleep(500);
            }
            break;

        case '3':
            upload_exercise(exercises, user_id);
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