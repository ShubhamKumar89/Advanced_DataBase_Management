#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
unsigned choice;
fstream file;

void enter()
{
    system("cls");
    cout << "    ======= ADD DATA ======= \n\n";
    cout << "\nHOW MANY STUDENTS DO YOU WANT TO ENTER ? " << endl;
    cin >> choice;

    for (int i = 1; i <= choice; i++)
    {
        cout << "\nENTER THE DATA OF STUDENT " << i << endl
             << endl;
        cout << "ENTER NAME     : ";
        cin >> arr1[i];
        cout << "ENTER ROLL NO  : ";
        cin >> arr2[i];
        cout << "ENTER COURSE   : ";
        cin >> arr3[i];
        cout << "ENTER EMAIL-ID : ";
        cin >> arr4[i];
        cout << "ENTER CONTACT  : ";
        cin >> arr5[i];
        file.open("input.txt", ios::app | ios::out);
        // file<<"NAME      ROLLNO      COURSE      CLASS      CONTACT\n";

        file << arr1[i] << "      " << arr2[i] << "      " << arr3[i] << "      " << arr4[i] << "      " << arr5[i] << endl;
        file.close();
    }
}

void show()
{
    system("cls");
    cout << "            =======  SHOWING STUDENT DETAILS  =======\n\n";
    if (choice == 0)
    {
        cout << "    NO DATA ENTERED!!!!!" << endl
             << endl;
    }
    else
    {
        for (int i = 1; i <= choice; i++)
        {
            cout << "\n======== STUDENT " << i << " ========\n"
                 << endl;
            cout << "NAME       : " << arr1[i] << endl;
            cout << "ROLL NO    : " << arr2[i] << endl;
            cout << "COURSE     : " << arr3[i] << endl;
            cout << "Email-ID   : " << arr4[i] << endl;
            cout << "CONTACT    : " << arr5[i] << endl
                 << endl;
        }
    }
    system("pause");
}

void search()
{
    bool flag = false;
    system("cls");
    cout << "            =======  SHOWING STUDENT DETAILS  =======\n\n";
    if (choice == 0)
    {
        cout << "    NO DATA ENTERED !!\n\n";
        cout << endl
             << endl;
        system("pause");
        return;
    }
    string rollno;

    cout << "ENTER THE ROLL NO YOU WANT TO SEARCH FOR THE RECORD : ";
    cin >> rollno;
    cout << "\n\n       SEARCHING THE DATA";

    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(200);
    }

    cout << "\n\n    AFTER SEARCHING WE GET : " << endl
         << endl;
    for (int i = 1; i <= choice; i++)
    {
        if (rollno == arr2[i])
        {

            cout << "NAME       : " << arr1[i] << endl;
            cout << "ROLL NO    : " << arr2[i] << endl;
            cout << "COURSE     : " << arr3[i] << endl;
            cout << "Email-ID   : " << arr4[i] << endl;
            cout << "CONTACT    : " << arr5[i] << endl
                 << endl;
            flag = true;
        }
    }

    if (!flag)
        cout << "\n       DATA NOT FOUND\n";

    cout << endl
         << endl;
    system("pause");
}

void update()
{
    system("cls");
    cout << "            =======  UPDATE STUDENT DETAILS  =======\n\n"
         << endl;
    if (choice == 0)
    {
        cout << "    NO DATA ENTERED !!\n\n";
        cout << endl
             << endl;
        system("pause");
        return;
    }

    fstream file2;
    string rollno;
    int match = 0;

    file.open("input.txt", ios::in);
    if (file.bad())
    {
        cout << "\n\t\t NO DATA FOUND...."; // id data not found then this message shown there
        file.close();
        return;
    }
    else
    {
        cout << "\n ENTER THE STUDENT'S ROLL NO. YOU WISH TO EDIT : ";
        cin >> rollno;
        file2.open("Record.txt", ios::app | ios::out);
        for (int i = 1; i <= choice; i++)
        {
            if (rollno == arr2[i])
            {
                cout << "\n======== DATA OF THE STUDENT YOU WANT TO UPDATE : "
                     << " ========\n"
                     << endl;
                cout << "NAME       : " << arr1[i] << endl;
                cout << "ROLL NO    : " << arr2[i] << endl;
                cout << "COURSE     : " << arr3[i] << endl;
                cout << "Email-ID   : " << arr4[i] << endl;
                cout << "CONTACT    : " << arr5[i] << endl
                     << endl;

                cout << "\n ENTER STUDENT NAME : ";
                cin >> arr1[i];
                cout << "\n ENTER ROLL NO      : ";
                cin >> arr2[i];
                cout << "\n ENTER COURSE       : ";
                cin >> arr3[i];
                cout << "\n ENTER EMAIL-ID     : ";
                cin >> arr4[i];
                cout << "\n ENTER CONTACT NO.  : ";
                cin >> arr5[i];

                match++;
            }
            file2 << " " << arr1[i] << " " << arr2[i] << " " << arr3[i] << " " << arr4[i] << " " << arr5[i] << "\n";
        }

        if (match == 0)
        {
            cout << "\n\n\t\t STUDENT NOT FOUND. INVALID INPUT !\n";
            cout << endl
                 << endl;
            system("pause");
            return;
        }
        else
        {
            cout << "\n\n      DATA UPDATED !\n";
        }

        file2.close();
        file.close();

        remove("input.txt");
        rename("Record.txt", "input.txt");
    }
    cout << endl
         << endl;
    system("pause");
}

void deleterecord()
{
    system("cls");
    cout << "           ======  DELETE STUDENT DETAILS  ======\n\n"
         << endl;
    if (choice == 0)
    {
        cout << "    NO DATA ENTERED !!\n\n";
        cout << endl
             << endl;
        system("pause");
        return;
    }

    fstream file1;
    string roll;
    int idx;
    int match = 0;

    file.open("input.txt", ios::in);
    if (file.bad())
    {
        cout << "\n\n\t\t DATA NOT FOUND.\n";
        file.close();
        return;
    }
    else
    {
        cout << "\n ENTER THE STUDENT'S ROLL NO. YOU WANT TO DELETE : ";
        cin >> roll;
        file1.open("Record.txt", ios::app | ios::out);
        for (int i = 1; i <= choice; i++)
        {
            if (roll == arr2[i])
            {
                cout << "\n======== DATA OF THE STUDENT YOU WANT TO DELETE : "
                     << " ========\n"
                     << endl;
                cout << "NAME       : " << arr1[i] << endl;
                cout << "ROLL NO    : " << arr2[i] << endl;
                cout << "COURSE     : " << arr3[i] << endl;
                cout << "Email-ID   : " << arr4[i] << endl;
                cout << "CONTACT    : " << arr5[i] << endl
                     << endl;
                idx = i;
                match++;
                continue;
            }
            file1 << " " << arr1[i] << " " << arr2[i] << " " << arr3[i] << " " << arr4[i] << " " << arr5[i] << "\n";
        }

        if (match == 0)
        {
            cout << "\n\n\t\t SORRY. RECORD NOT FOUND. \n";
            cout << endl
                 << endl;
            system("pause");
            return;
        }
        else
        {
            for (int i = idx; i <= choice - 1; i++)
            {
                swap(arr1[idx], arr1[idx + 1]);
                swap(arr2[idx], arr2[idx + 1]);
                swap(arr3[idx], arr3[idx + 1]);
                swap(arr4[idx], arr4[idx + 1]);
                swap(arr5[idx], arr5[idx + 1]);
            }
            choice--;
            cout << "\n\n\t\t DELETED SUCCESSFULLY.\n";
        }

        file1.close();
        file.close();
        remove("input.txt");
        rename("Record.txt", "input.txt");
    }
    cout << endl
         << endl;
    system("pause");
}

int main()
{
    int value;
    while (true)
    {
        system("cls");
        cout << "              ==============  STUDENT DATABASE MANAGEMENT SYSTEM  ==============\n\n";
        cout << "                          ---------------------- " << endl;
        cout << "                          | CHOOSE YOUR OPTION |  " << endl;
        cout << "                          ---------------------- " << endl;
        cout << "                         PRESS 1 TO ENTER DATA" << endl;
        cout << "                         PRESS 2 TO SHOW DATA" << endl;
        cout << "                         PRESS 3 TO SEARCH DATA" << endl;
        cout << "                         PRESS 4 TO UPDATE DATA" << endl;
        cout << "                         PRESS 5 TO DELETE DATA" << endl;
        cout << "                         PRESS 6 TO EXIT " << endl;
        cout << "\n               ENTER ==> ";
        cin >> value;

        switch (value)
        {
        case 1:
            enter();
            break;

        case 2:

            show();
            break;

        case 3:
            search();
            break;

        case 4:
            update();
            break;

        case 5:
            deleterecord();
            break;

        case 6:
            cout << "\n\n                         PROGRAM ENDED !!!\n\n\n\n";
            return 0;

        default:
            cout << "\n\n           INVALID INPUT!!\n           PROGRAM TERMINATED!!\n\n"
                 << endl;
            return 0;
        }
    }
    return 0;
}