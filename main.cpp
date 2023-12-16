/*
    sportMonitor by Kurzawa :)
*/


#include "headers.h"

vector<Account> users;

int main()
{
    load_data_from_base();

    while (true)
    {
        system("cls");
        log_out();
    }

    return 0;
}