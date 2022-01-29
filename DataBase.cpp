#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;

stack<string> name;
stack<long int> admNo;
stack<string> course;
stack<int> year;
stack<string> sector;

class manage
{

public:
    string nam;
    long int adm;
    string cor;
    int yr;
    string itrf;

    void insertedData(manage &data, string n, long int a, string c, int y, string i);
    void insertData(manage &data);
    void updateData(manage data);
    void deleteData(manage &data);
    void display();
    void desireData(manage data);
};

void manage::insertedData(manage &data, string n, long int a, string c, int y, string i)
{
    data.nam = n;
    name.push(data.nam);

    data.adm = a;
    admNo.push(data.adm);

    data.cor = c;
    course.push(data.cor);

    data.yr = y;
    year.push(data.yr);

    data.itrf = i;
    sector.push(data.itrf);

    return;
}

void manage::insertData(manage &data)
{
    system("cls");
    string str = "Enter the following data :";
    cout << "                    ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }

    cout << "\n\nName : ";
    cin.ignore();
    getline(cin, data.nam);
    name.push(data.nam);

    cout << "\nAdmission Number : ";
    cin >> data.adm;
    admNo.push(data.adm);

    cout << "\nCourse : ";
    cin.ignore();
    getline(cin, data.cor);
    course.push(data.cor);

    cout << "\nCollege Year : ";
    cin >> data.yr;
    year.push(data.yr);

    cout << "\nInterest Field : ";
    cin.ignore();
    getline(cin, data.itrf);
    sector.push(data.itrf);
}

void displayUpdateName(long int ad)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    stack<int> temp;
    int i = 1;
    string correctName;
    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        if (a.top() == ad)
        {

            cout << "\nThe wrong data : \n\n";
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
            break;
        }
        temp.push(i);
        i++;
        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();
    }
    cout << endl
         << endl;
    n = name;

    stack<int> temp3 = temp;
    cout << "Enter the Correct Course Name : ";

    cin.ignore();
    getline(cin, correctName);

    while (!temp.empty())
    {
        temp.pop();
        n.pop();
    }
    stack<string> temp2;

    while (name.top() != n.top() || !temp3.empty())
    {
        temp2.push(name.top());
        temp3.pop();
        name.pop();
    }
    name.pop();
    name.push(correctName);
    while (!temp2.empty())
    {
        name.push(temp2.top());
        temp2.pop();
    }

    cout << "\n\n              Thank you for updating the data.. \n\n\n\n";
    system("pause");
    return;
}

void updateName(manage data)
{
    system("cls");
    stack<long int> a = admNo;
    stack<int> temp1;
    stack<long int> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!a.empty())
    {
        temp1.push(i);
        temp2.push(a.top());
        cout << "   (" << i << ") " << a.top() << endl;
        a.pop();
        i++;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            updateName(data);

        else
            data.updateData(data);
    }

    displayUpdateName(temp2.top());
}

void displayUpdateAdm(string nm)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    stack<int> temp;
    int i = 1;
    long int correctAdm;
    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        if (n.top() == nm)
        {

            cout << "\nThe wrong data : \n\n";
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
            break;
        }
        temp.push(i);
        i++;
        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();
    }
    cout << endl
         << endl;
    a = admNo;

    cout << "Enter the Correct Admission No. : ";
    cin >> correctAdm;
    while (!temp.empty())
    {
        temp.pop();
        a.pop();
    }

    while (admNo.top() != a.top())
    {
        temp.push(admNo.top());
        admNo.pop();
    }
    admNo.pop();
    admNo.push(correctAdm);
    while (!temp.empty())
    {
        admNo.push(temp.top());
        temp.pop();
    }

    cout << "\n\n              Thank you for updating the data.. \n\n\n\n";
    system("pause");
    return;
}

void updateAdm(manage data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;
    stack<string> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!n.empty())
    {
        temp1.push(i);
        temp2.push(n.top());
        cout << "   (" << i << ") " << n.top() << endl;
        n.pop();
        i++;
        flag = i;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            updateAdm(data);

        else
            data.updateData(data);
    }

    displayUpdateAdm(temp2.top());
}

void displayUpdateCourse(string nm)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    stack<int> temp;
    int i = 1;
    string correctCourse;
    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        if (n.top() == nm)
        {

            cout << "\nThe wrong data : \n\n";
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
            break;
        }
        temp.push(i);
        i++;
        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();
    }
    cout << endl
         << endl;
    c = course;
    stack<int> temp3 = temp;
    cout << "Enter the Correct Course Name : ";

    cin.ignore();
    getline(cin, correctCourse);

    while (!temp.empty())
    {
        temp.pop();
        c.pop();
    }
    stack<string> temp2;

    while (course.top() != c.top() || !temp3.empty())
    {
        temp2.push(course.top());
        temp3.pop();
        course.pop();
    }
    course.pop();
    course.push(correctCourse);
    while (!temp2.empty())
    {
        course.push(temp2.top());
        temp2.pop();
    }

    cout << "\n\n              Thank you for updating the data.. \n\n\n\n";
    system("pause");
    return;
}

void updateCourse(manage data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;
    stack<string> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!n.empty())
    {
        temp1.push(i);
        temp2.push(n.top());
        cout << "   (" << i << ") " << n.top() << endl;
        n.pop();
        i++;
        flag = i;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            updateCourse(data);

        else
            data.updateData(data);
    }

    displayUpdateCourse(temp2.top());
}

void displayUpdateYear(string nm)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    stack<int> temp;
    int i = 1;
    int correctYear;
    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        if (n.top() == nm)
        {

            cout << "\nThe wrong data : \n\n";
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
            break;
        }
        temp.push(i);
        i++;
        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();
    }
    cout << endl
         << endl;
    y = year;
    stack<int> temp3 = temp;
    cout << "Enter the Correct Graduation Year : ";

    cin >> correctYear;

    while (!temp.empty())
    {
        temp.pop();
        y.pop();
    }
    stack<int> temp2;

    while (year.top() != y.top() || !temp3.empty())
    {
        temp2.push(year.top());
        temp3.pop();
        year.pop();
    }
    year.pop();
    year.push(correctYear);
    while (!temp2.empty())
    {
        year.push(temp2.top());
        temp2.pop();
    }

    cout << "\n\n              Thank you for updating the data.. \n\n\n\n";
    system("pause");
    return;
}

void updateYear(manage data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;
    stack<string> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!n.empty())
    {
        temp1.push(i);
        temp2.push(n.top());
        cout << "   (" << i << ") " << n.top() << endl;
        n.pop();
        i++;
        flag = i;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            updateYear(data);

        else
            data.updateData(data);
    }

    displayUpdateYear(temp2.top());
}

void displayUpdateField(string nm)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    stack<int> temp;
    int i = 1;
    string correctField;
    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        if (n.top() == nm)
        {

            cout << "\nThe wrong data : \n\n";
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
            break;
        }
        temp.push(i);
        i++;
        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();
    }
    cout << endl
         << endl;
    s = sector;
    stack<int> temp3 = temp;
    cout << "Enter the Correct Interest Field : ";

    cin.ignore();
    getline(cin, correctField);

    while (!temp.empty())
    {
        temp.pop();
        s.pop();
    }
    stack<string> temp2;

    while (sector.top() != s.top() || !temp3.empty())
    {
        temp2.push(sector.top());
        temp3.pop();
        sector.pop();
    }
    sector.pop();
    sector.push(correctField);
    while (!temp2.empty())
    {
        sector.push(temp2.top());
        temp2.pop();
    }

    cout << "\n\n              Thank you for updating the data.. \n\n\n\n";
    system("pause");
    return;
}

void updateField(manage data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;
    stack<string> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!n.empty())
    {
        temp1.push(i);
        temp2.push(n.top());
        cout << "   (" << i << ") " << n.top() << endl;
        n.pop();
        i++;
        flag = i;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            updateField(data);

        else
            data.updateData(data);
    }

    displayUpdateField(temp2.top());
}

void exit3(manage data);

void manage ::updateData(manage data)
{
    int key;
    do
    {
        system("cls");
        cout << "\n        You want to change what :\n\n";
        cout << "          (1) Name\n";
        cout << "          (2) Admission No.\n";
        cout << "          (3) Course\n";
        cout << "          (4) Graduation Year\n";
        cout << "          (5) Interest Field\n";
        cout << "          (6) Back  \n\n";

        string str = "Press the key according to your Preference :";
        cout << "     ";
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            Sleep(10);
        }
        cout << "\n      ==> ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            updateName(data);
            break;

        case 2:
            system("cls");
            updateAdm(data);
            break;

        case 3:
            system("cls");
            updateCourse(data);
            break;

        case 4:
            system("cls");
            updateYear(data);
            break;

        case 5:
            system("cls");
            updateField(data);
            break;

        case 6:
            return;

        default:
            exit3(data);
        }
    } while (key != 6);
    return;
}

int position(string nm)
{
    stack<string> n = name;
    int count = 1;
    while (!n.empty())
    {
        if (n.top() == nm)
        {
            return count;
        }
        n.pop();
        count++;
    }
    return -1;
}

void exit2(manage data);

void manage::display()
{
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {

        cout << "Name : " << n.top() << endl;
        n.pop();

        cout << "Admission Number : " << a.top() << endl;
        a.pop();

        cout << "College Year : " << y.top() << endl;
        y.pop();

        cout << "Course : " << c.top() << endl;
        c.pop();

        cout << "Interest Field : " << s.top() << endl;
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
}

void displayDataCourse(string cor)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {
        if (c.top() == cor)
        {
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
        }

        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
    return;
}

void displayDataName(string nm)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {
        if (n.top() == nm)
        {
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
        }

        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
}

void displayDataAdm(long int ad)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {
        if (a.top() == ad)
        {
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
        }

        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
}

void displayDataYear(int yrr)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {
        if (y.top() == yrr)
        {
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
        }

        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
}

void displayDataField(string fld)
{
    system("cls");
    stack<string> n = name;
    stack<long int> a = admNo;
    stack<string> c = course;
    stack<int> y = year;
    stack<string> s = sector;

    while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
    {
        if (s.top() == fld)
        {
            cout << "Name : " << n.top() << endl;
            cout << "Admission Number : " << a.top() << endl;
            cout << "College Year : " << y.top() << endl;
            cout << "Course : " << c.top() << endl;
            cout << "Interest Field : " << s.top() << endl;
        }

        n.pop();
        a.pop();
        y.pop();
        c.pop();
        s.pop();

        cout << endl
             << endl;
    }

    system("pause");
}

void nameView(manage data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;    // used to store the serial number for further display purpose
    stack<string> temp2; // used to store the string ,respective to it's serial no. for display purpose
    int key;
    cout << "\nThe course fields through which u want to access the dataset : \n\n";
    int i = 1;
    bool flag;

    while (!n.empty())
    {
        string s1 = n.top();
        flag = true;
        n.pop();
        string s2;
        if (!n.empty())
        {
            s2 = n.top();
            flag = false;
        }

        if (s1 != s2 || flag == true)
        {
            cout << "  (" << i << ") " << s1 << endl;
            temp1.push(i);
            temp2.push(s1);
            i++;
        }
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty())
    {

        if (temp1.top() == key)
        {
            flag = true;
            break;
        }
        flag = false;
        temp1.pop();
        temp2.pop();
    }

    if (flag == false)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            nameView(data);

        else
            data.desireData(data);
    }
    displayDataName(temp2.top());
}

void admView(manage data)
{
    system("cls");
    stack<long int> a = admNo;
    stack<int> temp1; // used to store the serial number for further display purpose
    stack<int> temp2;
    int key;
    cout << "\nThe course fields through which u want to access the dataset : \n\n";
    int i = 1;
    bool flag;

    while (!a.empty())
    {
        int s1 = a.top();
        flag = true;
        a.pop();
        int s2;
        if (!a.empty())
        {
            s2 = a.top();
            flag = false;
        }

        if (s1 != s2 || flag == true)
        {
            cout << "  (" << i << ") " << s1 << endl;
            temp1.push(i);
            temp2.push(s1);
            i++;
        }
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty())
    {

        if (temp1.top() == key)
        {
            flag = true;
            break;
        }
        flag = false;
        temp1.pop();
        temp2.pop();
    }

    if (flag == false)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            admView(data);

        else
            data.desireData(data);
    }
    displayDataAdm(temp2.top());
}

void courseView(manage data)
{
    system("cls");
    stack<string> c = course;
    stack<int> temp1;    // used to store the serial number for further display purpose
    stack<string> temp2; // used to store the string ,respective to it's serial no. for display purpose
    int key;
    cout << "\nThe course fields through which u want to access the dataset : \n\n";
    int i = 1;
    bool flag;

    while (!c.empty())
    {
        string s1 = c.top();
        flag = true;
        c.pop();
        string s2;
        if (!c.empty())
        {
            s2 = c.top();
            flag = false;
        }

        if (s1 != s2 || flag == true)
        {
            cout << "  (" << i << ") " << s1 << endl;
            temp1.push(i);
            temp2.push(s1);
            i++;
        }
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty())
    {

        if (temp1.top() == key)
        {
            flag = true;
            break;
        }
        flag = false;
        temp1.pop();
        temp2.pop();
    }

    if (flag == false)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            courseView(data);

        else
            data.desireData(data);
    }
    displayDataCourse(temp2.top());
}

void yearView(manage data)
{
    system("cls");
    stack<int> y = year;
    stack<int> temp1; // used to store the serial number for further display purpose
    stack<int> temp2;
    int key;
    cout << "\nThe course fields through which u want to access the dataset : \n\n";
    int i = 1;
    bool flag;

    while (!y.empty())
    {
        int s1 = y.top();
        flag = true;
        y.pop();
        int s2;
        if (!y.empty())
        {
            s2 = y.top();
            flag = false;
        }

        if (s1 != s2 || flag == true)
        {
            cout << "  (" << i << ") " << s1 << endl;
            temp1.push(i);
            temp2.push(s1);
            i++;
        }
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty())
    {

        if (temp1.top() == key)
        {
            flag = true;
            break;
        }
        flag = false;
        temp1.pop();
        temp2.pop();
    }

    if (flag == false)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            yearView(data);

        else
            data.desireData(data);
    }
    displayDataYear(temp2.top());
}

void fieldView(manage data)
{
    system("cls");
    stack<string> f = sector;
    stack<int> temp1;    // used to store the serial number for further display purpose
    stack<string> temp2; // used to store the string ,respective to it's serial no. for display purpose
    int key;
    cout << "\nThe course fields through which u want to access the dataset : \n\n";
    int i = 1;
    bool flag;

    while (!f.empty())
    {
        string s1 = f.top();
        flag = true;
        f.pop();
        string s2;
        if (!f.empty())
        {
            s2 = f.top();
            flag = false;
        }

        if (s1 != s2 || flag == true)
        {
            cout << "  (" << i << ") " << s1 << endl;
            temp1.push(i);
            temp2.push(s1);
            i++;
        }
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";

    cin >> key;

    while (!temp1.empty())
    {

        if (temp1.top() == key)
        {
            flag = true;
            break;
        }
        flag = false;
        temp1.pop();
        temp2.pop();
    }

    if (flag == false)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            fieldView(data);

        else
            data.desireData(data);
    }
    displayDataField(temp2.top());
}

void exit1(manage data);

void manage::desireData(manage data)
{

    int key;
    do
    {
        system("cls");
        cout << "\n         You want to access data through which field :\n\n";
        cout << "          (1) Name\n";
        cout << "          (2) Admission No.\n";
        cout << "          (3) Course\n";
        cout << "          (4) Graduation Year\n";
        cout << "          (5) Interest Field\n";
        cout << "          (6) Back  \n\n";

        string str = "Press the key according to your Preference :";
        cout << "     ";
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            Sleep(10);
        }
        cout << "\n      ==> ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            nameView(data);
            break;

        case 2:
            system("cls");
            admView(data);
            break;

        case 3:
            system("cls");
            courseView(data);
            break;

        case 4:
            system("cls");
            yearView(data);
            break;

        case 5:
            system("cls");
            fieldView(data);
            break;

        case 6:
            break;

        default:
            exit1(data);
        }
    } while (key != 6);
    return;
}

void exitMain();

int main()
{
    int key = 0;

    manage data;

    data.insertedData(data, "Shubham Kumar", 10211458, "BSc Computer Science", 1, "C++ Programming");
    data.insertedData(data, "Aditya", 10211453, "BSc Computer Science", 1, "C++ Programming");
    data.insertedData(data, "Kundan Mishra", 10211454, "BSc Computer Science", 1, "Blockchain");
    data.insertedData(data, "Kartikey", 10211451, "BSc Computer Science", 1, "Web Development");
    // try to write comman things in a continuous form like c++ for shubham and c++ for aditya

    do
    {
        system("cls");
        cout << "             ";
        string str = "============== Student Database Management System  ==============";
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            Sleep(5);
        }
        cout << "\n\n                     (1) Insert Data  \n";
        cout << "                     (2) Update Data  \n";
        cout << "                     (3) Delete Data  \n";
        cout << "                     (4) Retrieve All Database  \n";
        cout << "                     (5) Retrive  Data of some Desired Fields. \n";
        cout << "                     (6) Exit  \n\n";
        str.clear();
        str = "Press the key according to your Preference :";
        cout << "                     ";
        for (int i = 0; i < str.size(); i++)
        {
            cout << str[i];
            Sleep(10);
        }
        cout << "\n                  ==> ";

        cin >> key;

        switch (key)
        {
        case 1:
            system("cls");
            data.insertData(data);
            break;

        case 2:
            system("cls");
            data.updateData(data);
            break;

        case 3:
            system("cls");
            data.deleteData(data);
            break;

        case 4:
            system("cls");
            data.display();
            break;

        case 5:
            system("cls");
            data.desireData(data);
            break;

        case 6:
            system("cls");
            cout << "                      Thanks For Visiting Us !!\n\n";
            break;

        default:
            exitMain();
            return -1;
        }

    } while (key != 6);

    return 0;
}

void exitMain()
{
    char ch = 6;
    cout << "\n\n                    ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";
    cout << " Sorry, you take the wrong Input ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";

    cout << "\n\n                    Want to continue..... ?\n"
         << "                    Press 'y/Y' to continue or 'n/N' to exit :\n ";
    cout << "               ==> ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        main();

    else
        return;
}

void exit1(manage data)
{
    char ch = 6;
    cout << "\n\n                    ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";
    cout << " Sorry, you take the wrong Input ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";

    cout << "\n\n                    Want to continue..... ?\n"
         << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
    cout << "               ==> ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        data.desireData(data);

    else
        main();
}

void exit2(manage data)
{
    char ch = 6;
    cout << "\n\n                    ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";
    cout << " Sorry, you take the wrong Input ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";

    cout << "\n\n                    Want to continue..... ?\n"
         << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
    cout << "               ==> ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        data.deleteData(data);

    else
        main();
}

void exit3(manage data)
{
    char ch = 6;
    cout << "\n\n                    ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";
    cout << " Sorry, you take the wrong Input ";
    for (int i = 0; i < 5; i++)
        cout << ch << " ";

    cout << "\n\n                    Want to continue..... ?\n"
         << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
    cout << "               ==> ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        data.updateData(data);

    else
        main();
}

void deletionConfirm(string nm)
{
    system("cls");
    stack<string> n;
    stack<long int> a;
    stack<string> c;
    stack<int> y;
    stack<string> s;

    stack<int> temp;
    int i = 1;
    string confirm;
    while (!name.empty() && !admNo.empty() && !year.empty() && !course.empty() && !sector.empty())
    {

        if (name.top() == nm)
        {
            cout << "\nThe data u want to delete : \n\n";
            cout << "Name : " << name.top() << endl;
            cout << "Admission Number : " << admNo.top() << endl;
            cout << "College Year : " << year.top() << endl;
            cout << "Course : " << course.top() << endl;
            cout << "Interest Field : " << sector.top() << endl;

            break;
        }
        temp.push(i);
        i++;
        n.push(name.top());
        a.push(admNo.top());
        c.push(course.top());
        y.push(year.top());
        s.push(sector.top());

        name.pop();
        admNo.pop();
        year.pop();
        course.pop();
        sector.pop();
    }
    cout << endl
         << endl;
    string nn = name.top();
    long int aa = admNo.top();
    string cc = course.top();
    int yy = year.top();
    string ss = sector.top();

    name.pop();
    admNo.pop();
    year.pop();
    course.pop();
    sector.pop();

    cout << "\n\nEnter confirm/Confirm to delete the student data or decline your choice by writing anything : \n";
    cout << "=> ";
    cin.ignore();
    getline(cin, confirm);
    if (confirm == "Confirm" || confirm == "confirm")
    {
        while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
        {
            name.push(n.top());
            admNo.push(a.top());
            year.push(y.top());
            course.push(c.top());
            sector.push(s.top());

            n.pop();
            a.pop();
            y.pop();
            c.pop();
            s.pop();
        }
    }

    else
    {

        name.push(nn);
        admNo.push(aa);
        year.push(yy);
        course.push(cc);
        sector.push(ss);

        while (!n.empty() && !a.empty() && !y.empty() && !c.empty() && !s.empty())
        {
            name.push(n.top());
            admNo.push(a.top());
            year.push(y.top());
            course.push(c.top());
            sector.push(s.top());

            n.pop();
            a.pop();
            y.pop();
            c.pop();
            s.pop();
        }

        return;
    }
}

void manage::deleteData(manage &data)
{
    system("cls");
    stack<string> n = name;
    stack<int> temp1;
    stack<string> temp2;
    int key;
    cout << "\nWhich student data, u want to update : \n\n";
    int i = 1;
    int flag;
    while (!n.empty())
    {
        temp1.push(i);
        temp2.push(n.top());
        cout << "   (" << i << ") " << n.top() << endl;
        n.pop();
        i++;
        flag = i;
    }
    cout << endl
         << endl;
    string str = "Press the key according to your Preference :";
    cout << "     ";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
        Sleep(10);
    }
    cout << "\n      ==> ";
    cin >> key;

    while (!temp1.empty() && !temp2.empty())
    {

        if (temp1.top() == key)
        {
            flag = 1;
            break;
        }
        flag = 2;
        temp1.pop();
        temp2.pop();
    }

    if (flag == 2)
    {
        char ch = 6;
        cout << "\n\n                    ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";
        cout << " Sorry, you take the wrong Input ";
        for (int i = 0; i < 5; i++)
            cout << ch << " ";

        cout << "\n\n                    Want to continue..... ?\n"
             << "                    Press 'y/Y' to continue or 'n/N' to back :\n ";
        cout << "               ==> ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
            data.deleteData(data);

        else
            main();
    }

    deletionConfirm(temp2.top());
}