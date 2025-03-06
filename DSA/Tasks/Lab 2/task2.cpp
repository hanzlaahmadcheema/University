#include <iostream>
using namespace std;


class CustomerData {
protected:
    int customerNumber;
    string customerName;
    string address;
    bool mailingList;

public:
    
    CustomerData() : customerNumber(0), customerName(""), address(""), mailingList(false) {}

    
    CustomerData(int number, string name, string addr, bool mailList) 
        : customerNumber(number), customerName(name), address(addr), mailingList(mailList) {}

    virtual void display() const {
        cout << "Customer Number: " << customerNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << address << endl;
        cout << "Mailing List: " << (mailingList ? "Yes" : "No") << endl;
    }
};


class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;

public:
    
    PreferredCustomer() : CustomerData(), purchasesAmount(0.0), discountLevel(0.0) {}

    
    PreferredCustomer(int number, string name, string addr, bool mailList, double purchases)
        : CustomerData(number, name, addr, mailList) {
        setPurchasesAmount(purchases);
    }

    void setPurchasesAmount(double amount) {
        if (amount < 0) {
            cout << "Invalid purchase amount! Cannot be negative.\n";
            return;
        }
        purchasesAmount = amount;
        updateDiscountLevel();
    }

    void updateDiscountLevel() {
        if (purchasesAmount >= 2000)
            discountLevel = 10.0;
        else if (purchasesAmount >= 1500)
            discountLevel = 7.0;
        else if (purchasesAmount >= 1000)
            discountLevel = 6.0;
        else if (purchasesAmount >= 500)
            discountLevel = 5.0;
        else
            discountLevel = 0.0;
    }

    void display() const override {
        CustomerData::display();
        cout << "Total Purchases: $" << purchasesAmount << endl;
        cout << "Discount Level: " << discountLevel << "%" << endl;
        cout << "Discount Amount: $" << (purchasesAmount * (discountLevel / 100)) << endl;
    }
};


int main() {
    int number;
    string name, address;
    bool mailingList;
    double purchases;

    cout << "Enter Customer Number: ";
    cin >> number;
    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Customer Address: ";
    getline(cin, address);
    cout << "Is the customer on the mailing list? (1 for Yes, 0 for No): ";
    cin >> mailingList;
    cout << "Enter Total Purchases Amount: ";
    cin >> purchases;

    PreferredCustomer customer(number, name, address, mailingList, purchases);

    cout << "\n Customer Details \n";
    customer.display();

    return 0;
}
