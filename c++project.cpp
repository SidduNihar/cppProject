#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits> // Include the <limits> header for numeric_limits

using namespace std;

class Bank
{
private:
    int total;
    struct person
    {
        string name, ID, address;
        long long contact; // Use long long to store 10-digit phone numbers
        float cash;        // Use float for storing money amount
    } person[100];

public:
    Bank()
    {
        total = 0;
    }

    void choice();
    void perData();
    void show();
    void update();
    void search();
    void transactions();
    void del();
};

int main()
{
    Bank b;
    b.choice();
    return 0;
}

void Bank::choice()
{
    char ch;
    while (1)
    {
        cout << "\n\nPRESS..!!" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of an existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove an existing account" << endl;
        cout << "7. Exit" << endl;
        ch = getch();
        system("CLS");
        switch (ch)
        {
        case '1':
            Bank::perData();
            break;
        case '2':
            if (total == 0)
            {
                cout << "No data is entered" << endl;
            }
            else
            {
                Bank::show();
            }
            break;
        case '3':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                Bank::update();
            break;
        case '4':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                Bank::search();
            break;
        case '5':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                Bank::transactions();
            break;
        case '6':
            if (total == 0)
                cout << "No data is entered" << endl;
            else
                Bank::del();
            break;
        case '7':
            exit(0);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}

void Bank::perData()
{
    cout << "Enter data of person " << total + 1 << endl;
    cout << "Enter name: ";
    cin.ignore(); // Clear any previous input
    getline(cin, person[total].name);
    cout << "ID: ";
    cin >> person[total].ID;
    bool isUnique = true;
    for (int i = 0; i < total; i++)
    {
        if (person[total].ID == person[i].ID)
        {
            isUnique = false;
            break;
        }
    }
    if (!isUnique)
    {
        cout << "ID must be unique. This ID already exists." << endl;
        return;
    }
    cout << "Address: ";
    cin.ignore();
    getline(cin, person[total].address);
    cout << "Contact (10-digit phone number): ";
    cin >> person[total].contact;
    while (cin.fail() || person[total].contact < 1000000000 || person[total].contact > 9999999999)
    {
        cout << "Invalid phone number. Please enter a 10-digit phone number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Corrected line
        cin >> person[total].contact;
    }
    cout << "Total Cash: ";
    cin >> person[total].cash;
    while (person[total].cash < 100)
    {
        cout << "Minimum balance requirement: 100 rupees. Please enter a higher amount." << endl;
        cin >> person[total].cash;
    }
    total++;
}

void Bank::show()
{
    for (int i = 0; i < total; i++)
    {
        cout << "Data of person " << i + 1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "Contact: " << person[i].contact << endl;
        cout << "Cash: " << person[i].cash << " rupees" << endl;
    }
}

void Bank::update()
{
    cout << "Enter ID of the person whose data you want to update" << endl;
    cin >> person[total].ID;
    int foundIndex = -1;
    for (int i = 0; i < total; i++)
    {
        if (person[i].ID == person[total].ID)
        {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1)
    {
        cout << "No such record found" << endl;
        return;
    }
    cout << "Previous data" << endl;
    cout << "Data of person " << foundIndex + 1 << endl;
    cout << "Name: " << person[foundIndex].name << endl;
    cout << "ID: " << person[foundIndex].ID << endl;
    cout << "Address: " << person[foundIndex].address << endl;
    cout << "Contact: " << person[foundIndex].contact << endl;
    cout << "Cash: " << person[foundIndex].cash << " rupees" << endl;
    cout << "\nEnter new data" << endl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, person[foundIndex].name);
    cout << "ID: ";
    cin >> person[foundIndex].ID;
    bool isUnique = true;
    for (int i = 0; i < total; i++)
    {
        if (i != foundIndex && person[foundIndex].ID == person[i].ID)
        {
            isUnique = false;
            break;
        }
    }
    if (!isUnique)
    {
        cout << "ID must be unique. This ID already exists." << endl;
        return;
    }
    cout << "Address: ";
    cin.ignore();
    getline(cin, person[foundIndex].address);
    cout << "Contact (10-digit phone number): ";
    cin >> person[foundIndex].contact;
    while (cin.fail() || person[foundIndex].contact < 1000000000 || person[foundIndex].contact > 9999999999)
    {
        cout << "Invalid phone number. Please enter a 10-digit phone number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Corrected line
        cin >> person[foundIndex].contact;
    }
    cout << "Total Cash: ";
    cin >> person[foundIndex].cash;
    while (person[foundIndex].cash < 100)
    {
        cout << "Minimum balance requirement: 100 rupees. Please enter a higher amount." << endl;
        cin >> person[foundIndex].cash;
    }
}

void Bank::search()
{
    cout << "Enter ID of the person whose data you want to search" << endl;
    cin >> person[total].ID;
    int foundIndex = -1;
    for (int i = 0; i < total; i++)
    {
        if (person[i].ID == person[total].ID)
        {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1)
    {
        cout << "No such record found" << endl;
        return;
    }
    cout << "Name: " << person[foundIndex].name << endl;
    cout << "ID: " << person[foundIndex].ID << endl;
    cout << "Address: " << person[foundIndex].address << endl;
    cout << "Contact: " << person[foundIndex].contact << endl;
    cout << "Cash: " << person[foundIndex].cash << " rupees" << endl;
}

void Bank::transactions()
{
    float cash;
    char ch;
    cout << "Enter ID of the person for the transaction" << endl;
    cin >> person[total].ID;
    int foundIndex = -1;
    for (int i = 0; i < total; i++)
    {
        if (person[i].ID == person[total].ID)
        {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1)
    {
        cout << "No such record found" << endl;
        return;
    }
    cout << "Name: " << person[foundIndex].name << endl;
    cout << "Address: " << person[foundIndex].address << endl;
    cout << "Contact: " << person[foundIndex].contact << endl;
    cout << "\nExisting Cash: " << person[foundIndex].cash << " rupees" << endl;
    cout << "Press 1 to deposit" << endl;
    cout << "Press 2 to withdraw" << endl;
    ch = getch();
    switch (ch)
    {
    case '1':
        cout << "How much cash do you want to deposit?" << endl;
        cin >> cash;
        person[foundIndex].cash += cash;
        cout << "Your new cash is " << person[foundIndex].cash << " rupees" << endl;
        break;
    case '2':
    back:
        cout << "How much cash do you want to withdraw?" << endl;
        cin >> cash;
        if (cash > person[foundIndex].cash)
        {
            cout << "Insufficient balance. Your existing balance is " << person[foundIndex].cash << " rupees" << endl;
            goto back;
        }
        person[foundIndex].cash -= cash;
        cout << "Your new cash is " << person[foundIndex].cash << " rupees" << endl;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}

void Bank::del()
{
    char ch;
    int foundIndex = -1; // Declare foundIndex here to avoid the error

    cout << "Press 1 to remove a specific record" << endl;
    cout << "Press 2 to remove all records" << endl;
    ch = getch();
    switch (ch)
    {
    case '1':
        cout << "Enter ID of the person whose data you want to remove" << endl;
        cin >> person[total].ID;
        for (int i = 0; i < total; i++)
        {
            if (person[i].ID == person[total].ID)
            {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex == -1)
        {
            cout << "No such record found" << endl;
            return;
        }
        for (int j = foundIndex; j < total - 1; j++)
        {
            person[j] = person[j + 1];
        }
        total--;
        cout << "Your required data is deleted" << endl;
        break;
    case '2':
        total = 0;
        cout << "All records are deleted" << endl;
        break;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}
