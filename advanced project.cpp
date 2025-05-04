#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Public variables
class Account {
public:
    string name;
    string iban;
    double balance;

    Account(string n, string i, double b) {
        name = n;
        iban = i;
        balance = b;
    }
    
   // Function to set the person's data
    void set_name(string n) {
        name = n;
    }

    string get_name() {
        return name;
    }

    void set_balance(double b) {
        balance = b;
    }

    double get_balance() {
        return balance;
    }

    // Function to deposit the amount 
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount." << endl;
            return;
        }

        balance += amount;
        cout << "$" << amount << " has been deposited." << endl;
    }

    // Function to withdraw the amount
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "not enough balance." << endl;
            return;
        }

        if (amount <= 0) {
            cout << "Invalid amount." << endl;
            return;
        }

        balance -= amount;
        cout << "$" << amount << " has been withdrawn." << endl;
    }

    void display_balance() {
        cout << "Your current balance is $" << balance << endl;
    }

    // Function to show the balance amount
    void print() {
        cout << "Name: " << name << endl;
        cout << "IBAN: " << iban << endl;
    }
};

int main() {
    
    Account accounts[] = {
        Account("Rahaf Banat", "SA13678587458744", 35100.0),
        Account("Taif Alsulami", "SA23335857458794", 33300.0),
        Account("Dalia Guail", "SA53335757458333", 22000.0),
        Account("Laila Alsulami", "SA93335857458969", 10000.0),
        Account("Reyouf Fawaz", "SA23335227456789", 50000.0),
        Account("Duaa Ahmad", "SA100358572345",600.0),
        Account("Fidaa Abed", "SA23335857458794",70000.0),
        Account("Roaa Ali", "SA6633357576458388", 133.0),
        Account("Mohammed Banat", "SA443679052458744",89100.0),
        Account("Fawaz Tail", "SA66333510107456778", 89300.0),
        Account("Enas Abdulziz", "SA66333510107456778", 100000.0),
        Account("Sara Mohammed", "SA30302488576458309", 443.0),
    };

    cout << "Welcome to AFYZ Bank ATM." << endl;

    cout << "Please select an account:" << endl;
    
    /*  a for loop to prints the index number 
    and the name of the account using the get function  */
    
    for (int i = 0; i < sizeof(accounts)/sizeof(accounts[0]); i++) {
        cout << i+1 << ". " << accounts[i].get_name() << endl;
    }
    
    // to declares a variable  and takes user input to assign a value to it.
    int account_index;
    cin >> account_index;
    
     // using if  to Check the value of account_index
    if (account_index < 1 || account_index > sizeof(accounts)/sizeof(accounts[0])) {
        cout << "Invalid account. Please try again." << endl;
        return 0;
    }

    /*  to the "Account" class and assigns it to 
    the index of "account_index-1" in the array* and print the selected acc*/
    
    Account account = accounts[account_index-1];
    cout << "Selected account: " << endl;
    account.print ();
    
    
    // while loop to choose options
    while (true) {
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1- Check balance" << endl;
        cout << "2- Deposit money" << endl;
        cout << "3- Withdraw money" << endl;
        cout << "4- Exit" << endl;

        int choice;
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }
        
        
        // Choices to select from
       switch (choice) {
            case 1:
                account.display_balance();
                break;
            case 2:
                double deposit_amount;
                cout << "Enter the amount to deposit: ";
                cin >> deposit_amount;
                account.deposit(deposit_amount);
                break;
            case 3:
                double withdraw_amount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdraw_amount;
                account.withdraw(withdraw_amount);
                break;
            case 4:
                cout << "Thank you for using AFYZ Bank ATM." << endl;
                return 0;
        }
    }

    return 0;
}


