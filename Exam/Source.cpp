#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int userInput;
bool imortal = true;

struct delo
{
    string name;
    string prior;
    string ops;
};

void showCases(delo* d, int size)
{
    int iName = 0;
    int iPrior = 0;
    int iOps = 0;
    ifstream out("Affairs.txt");
    string str, trash;
    if (out.peek() != EOF)
    {
        while (getline(out, str))
        {
            if (str.find("Name") == 0)
            {
                d[iName].name = str;
                cout << endl << d[iName].name << endl;;
                iName++;
            }
            else if (str.find("Priority") == 0)
            {
                d[iPrior].prior = str;
                cout << d[iPrior].prior << endl;
                iPrior++;
            }
            else if (str.find("Description") == 0)
            {
                d[iOps].ops = str;
                cout << d[iOps].ops << endl;
                iOps++;
            }  
        }
    }
    else
    {
        cout << "No cases yet!" << endl;
    }
    out.close();
}

void addCase(delo* d, int constSize)
{
    int userInput = 0;
    string trash;
    cout << endl;
    ofstream out("Affairs.txt", ios::app);
    cout << "How many cases do you want to create: ";
    cin >> userInput;
    for (int i = 0; i < userInput; i++)
    {
        cout << endl;
        cout << "Enter the name of the task: ";
        cin >> d[i].name;
        out << "Name: " << d[i].name;
        cout << "Enter the job priority (from 1 to 5 where 1 is the highest priority!): ";
        cin >> d[i].prior;
        out << "\nPriority\t: " << d[i].prior;
        cout << "Enter a job description: ";
        getline(cin, trash);
        getline(cin, d[i].ops);
        out << "\nDescription\t: " << d[i].ops << endl;
    }
    out.close();
}

int sizeDelo(delo* d, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (d[i].name == " ")
        {
            return i;
        }
    }
    return 0;
}

void deleteCase(delo* d, int size)
{
    string userInput;
    int indexDeleteName;
    cout << endl << "Enter case name: ";
    cin >> userInput;
    for (int i = 0; i < size; i++)
    {
        if (d[i].name == ("Name: "+userInput))
        {
            indexDeleteName = i;
            break;
        }
    }
    fstream out;
    out.open("Affairs.txt");
    for (int i = 0; i < size; i++)
    {
        if (i != indexDeleteName)
        {
            if (d[i].name != " ")
            {
                out << d[i].name << endl;
                out << d[i].prior << endl;
                out << d[i].ops << endl << endl;
            }
        }
        else
        {
            continue;
        }
    }
    out.close();
}
void changeCase(delo * d, int size)
{
    string userInput;
    string trash;
    int indexDeleteName;
    cout << endl << "Enter case name: ";
    cin >> userInput;
    for (int i = 0; i < size; i++)
    {
        if (d[i].name == ("Name: " + userInput))
        {
            indexDeleteName = i;
            break;
        }
    }
    fstream out;
    out.open("Affairs.txt");
    for (int i = 0; i < size; i++)
    {
        if (i != indexDeleteName)
        {
            if (d[i].name != " ")
            {
                out << d[i].name << endl;
                out << d[i].prior << endl;
                out << d[i].ops << endl << endl;
            }
        }
        else
        {
            cout << endl << "Enter the name of the task: ";
            cin >> d[i].name;
            out << "Name: " << d[i].name;
            cout << "Enter the job priority (from 1 to 5 where 1 is the highest priority!): ";
            cin >> d[i].prior;
            out << "\nPriority\t: " << d[i].prior;
            cout << "Enter a job description: ";
            getline(cin, trash);
            getline(cin, d[i].ops);
            out << "\nDescription\t: " << d[i].ops << endl;
        }
    }
    out.close();
}
int main()
{
    const int sizeStruct = 100;
    delo d[sizeStruct]{};
    int size = sizeDelo(d, sizeStruct);
    while (imortal)
    {
        cout << "================================"<< endl;
        cout << "\tMENU"<< endl;
        cout << "View a list of all cases - 1" << endl; 
        cout << "Add case - 2" << endl;
        cout << "Change case - 3" << endl; 
        cout << "Delete case - 4" << endl;
        cout << "Exit - 5" << endl;
        cout << "================================" << endl;
        cout << "Choose an action: ";
        cin >> userInput;
        for (size_t i = 0; i < 100; i++)
        {
            cout << "\n";
        }
        switch (userInput)
        {
        case 1:
            showCases(d, sizeStruct);
            break;
        case 2:
            addCase(d, sizeStruct);
            break;
        case 3:
            showCases(d, sizeStruct);
            changeCase(d, sizeStruct);
            break;
        case 4:
            showCases(d, sizeStruct);
            deleteCase(d, sizeStruct);
            break;
        case 5:
            imortal = false;
            break;
        }
    }
}