#include <iostream>
using namespace std;

class CustomerData
{
private:
    int customerNumber;
    string customerName;
    string Address;
    bool mailingList;

public:
    int getcustomerNumber() { return customerNumber; }
    string getcustomerName() { return customerName; }
    string getAddress() { return Address; }
    bool getmailingList() { return mailingList; }

    void setcustomerNumber(int customerNumber) { this->customerNumber = customerNumber; }
    void setcustomerName(string customerName) { this->customerName = customerName; }
    void setAddress(string Address) { this->Address = Address; }
    void setmailingList(bool mailingList) { this->mailingList = mailingList; }
};

CustomerData customerData;

void displayMenu();
void getData();
void setData();

int main() {
    int choice;
    displayMenu();
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Oppening Menu..... \n";
        main();
        break;
    case 2:
        cout << "Setting Customer Data: \n";
        setData();
        main();
        break;
    case 3:
        cout << "Getting Customer Data: \n";
        getData();
        main();
        break;
    case 4:
        cout << "Exiting....";
        return 0;
        break;
    default:
        cout << "Invalid Choice" << endl;
        main();
        break;
    }
}

void displayMenu()
{
    cout << "1. Menu" << endl;
    cout << "2. Set Customer Data" << endl;
    cout << "3. Get Customer Data" << endl;
    cout << "4. Exit" << endl;
}

void getData()
{
    cout << "Customer Number: " << customerData.getcustomerNumber() << endl;
    cout << "Customer Name: " << customerData.getcustomerName() << endl;
    cout << "Customer Address: " << customerData.getAddress() << endl;
    cout << "Customer Mailing List: " << (customerData.getmailingList() ? "Yes" : "No") << endl;
}

void setData() {
    int customerNumber;
    string customerName;
    string Address;
    bool mailingList;
    int choice;

    cout << "Enter Customer Name" << endl;
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer Number" << endl;
    cin >> customerNumber;
    cout << "Enter Customer Address" << endl;
    cin.ignore();
    getline(cin, Address);
    cout << "Do you want to set mailing list for customer?\n1. Yes\n2. No" << endl;
    cin >> choice;
    if (choice == 1) {
        mailingList = true;
    }
    else {
        mailingList = false;
    }

    customerData.setcustomerNumber(customerNumber);
    customerData.setcustomerName(customerName);
    customerData.setAddress(Address);
    customerData.setmailingList(mailingList);
}