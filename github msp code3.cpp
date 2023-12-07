#include <iostream>
using namespace std;

#include <iostream>
#include <string>

// Function declaration
void GetPhoneNumbers(const string nameArr[], const string PhoneNumberArr[], int N, const string& name);

int main()
{
    int N;

    // Step 1: Input N
    cout << "Enter the number of entries (N): ";
    cin >> N;

    // Step 2: Declare arrays 'nameArr' and 'PhoneNumberArr'
    string nameArr[N];
    string PhoneNumberArr[N];

    // Step 3: Input names and phone numbers with a loop
    for (int i = 0; i < N; ++i)
    {
        cout << "Enter name for entry " << i + 1 << ": ";
        cin >> nameArr[i];

        cout << "Enter phone number for entry " << i + 1 << ": ";
        cin >> PhoneNumberArr[i];
    }

    // Step 4: Initialize counter i where i < N
    int i;

    // Step 5: Input name
    string inputName;

    // Step 6: Function call 'GetPhoneNumbers'
    do
    {
        cout << "\nEnter name to search for (or 'exit' to quit): ";
        cin >> inputName;

        if (inputName != "exit")
        {
            GetPhoneNumbers(nameArr, PhoneNumberArr, N, inputName);
        }

    } while (inputName != "exit");

    return 0;
}

// Step 6: Function definition 'GetPhoneNumbers'
void GetPhoneNumbers(const string nameArr[], const string PhoneNumberArr[], int N, const string& name)
{
    // Step 7: Is the phone number found?
    bool found = false;

    for (int i = 0; i < N; ++i)
    {
        if (nameArr[i] == name)
        {
            cout << "Phone number for " << name << ": " << PhoneNumberArr[i] << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Name not found. Please try again." << endl;
    }
}
