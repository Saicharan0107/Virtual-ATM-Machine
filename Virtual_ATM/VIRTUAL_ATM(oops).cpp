#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For find_if
#include <cstdlib>   // For rand()
#include <ctime>     // For time()

using namespace std;

class Account {
public:
    string name_of_account_holder;
    string name_of_joint_account_holder;
    long long int account_number;
    int balance;
    string type_of_account;
    string pin;

    // Constructor for single holder account
    Account(string accholdername, int bal, string typeofacc, string pc)
        : name_of_account_holder(accholdername), balance(bal), type_of_account(typeofacc), pin(pc) {
        account_number = rand() % 100000 + 1000000000;
        name_of_joint_account_holder = "No Joint Holder in this account";
    }

    // Constructor for joint holder account
    Account(string accholdername, string jointholdername, int bal, string typeofacc, string pc)
        : name_of_account_holder(accholdername), name_of_joint_account_holder(jointholdername), balance(bal), type_of_account(typeofacc), pin(pc) {
        account_number = rand() % 100000 + 1000000000;
    }
};

vector<Account> accts;

void display_details(long long int accnum) {
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        cout << "\nAccount Number : " << it->account_number;
        cout << "\nAccount Holder Name : " << it->name_of_account_holder;
        cout << "\nJoint Holder Name : " << it->name_of_joint_account_holder;
        cout << "\nBalance in your account : " << it->balance;
        cout << "\nType of Account : " << it->type_of_account;
    } else {
        cout << "Account doesn't exist with the given Account Number.";
    }
}

bool create_account(vector<Account>& accts) {
    system("cls");
    string accholder_name;
    cout << "\nENTER YOUR DETAILS HERE : ";
    cout << "\nName of Account Holder : ";
    cin >> accholder_name;
    string str;
    cout << "\nDo you want to have a joint holder account? Type YES/NO : ";
    cin >> str;
    string joint_holder;
    if (str == "YES") {
        cout << "Enter the name of Joint Holder : ";
        cin >> joint_holder;
    }
    string pin;
    cout << "\nEnter the pin : ";
    cin >> pin;
    string typeofacc;
    cout << "\nEnter the type of account : ";
    int choice;
    cout << "1 - Savings Account\n";
    cout << "2 - Current Account\n";
    cout << "Enter your choice here : ";
    cin >> choice;
    if (choice == 1)
        typeofacc = "Savings";
    else
        typeofacc = "Current";

    int balance;
    cout << "\nEnter the balance you want to have initially in your account : ";
    cin >> balance;

    //========SINGLE HOLDER ACCOUNT===========//
    if (typeofacc == "Savings" && str == "YES") {
        Account ob(accholder_name, joint_holder, balance, typeofacc, pin);
        accts.push_back(ob);
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|     ACCOUNT CREATED SUCCESSFULLY              |" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        display_details(ob.account_number);
        return true;
    }

    //If it is current account and balance is insufficient
    if (typeofacc == "Current" && balance < 10000 && str == "YES") {
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|     INSUFFICIENT BALANCE                      |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        return false;
    }

    //Current account with sufficient balance
    else if (typeofacc == "Current" && str == "NO") {
        Account ob(accholder_name, joint_holder, balance, typeofacc, pin);
        accts.push_back(ob);
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|     ACCOUNT CREATED SUCCESSFULLY              |" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        display_details(ob.account_number);
        return true;
    }

    //========JOINT HOLDER ACCOUNT===========//
    if (typeofacc == "Savings" && str == "NO") {
        Account ob(accholder_name, balance, typeofacc, pin);
        accts.push_back(ob);
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|     ACCOUNT CREATED SUCCESSFULLY              |" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        display_details(ob.account_number);
        return true;
    }

    //If it is current account and balance is insufficient
    if (typeofacc == "Current" && balance < 10000 && str == "NO") {
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|     INSUFFICIENT BALANCE                      |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        return false;
    }

    //Current account with sufficient balance
    else {
        Account ob(accholder_name, balance, typeofacc, pin);
        accts.push_back(ob);
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|     ACCOUNT CREATED SUCCESSFULLY              |" << "\n";
        cout << "\t\t|                                               |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        display_details(ob.account_number);
        return true;
    }
}

bool change_pin() {
    long long int accnum;
    cout << "Enter your account number : ";
    cin >> accnum;
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        string newpin;
        string oldpin;
        cout << "Enter the old pin : ";
        cin >> oldpin;
        if (oldpin == it->pin) {
            cout << "Enter new pin : ";
            cin >> newpin;
            it->pin = newpin;
            display_details(it->account_number);
            return true;
        } else {
            cout << "Invalid Pin. Try Again";
            return false;
        }
    } else {
        cout << "Account doesn't exist with the given Account Number.";
        return false;
    }
}

bool deposit_into_account() {
    long long int accnum;
    cout << "Enter your account number : ";
    cin >> accnum;
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        string pinfordepo;
        cout << "Enter the pin : ";
        cin >> pinfordepo;
        if (pinfordepo == it->pin) {
            int deposit_amount;
            cout << "Enter the amount you want to deposit : ";
            cin >> deposit_amount;
            it->balance += deposit_amount;
            cout << "Your Updated details : ";
            display_details(it->account_number);
            return true;
        } else {
            cout << "Invalid Pin. Try Again";
            return false;
        }
    } else {
        cout << "Account doesn't exist with the given Account Number.";
        return false;
    }
}

bool withdraw_from_account() {
    long long int accnum;
    cout << "Enter your account number : ";
    cin >> accnum;
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        string pinfordepo;
        cout << "Enter the pin : ";
        cin >> pinfordepo;
        if (pinfordepo == it->pin) {
            int withdrawl_amount;
            cout << "Enter the amount you want to withdraw : ";
            cin >> withdrawl_amount;
            if (it->balance >= withdrawl_amount) {
                it->balance -= withdrawl_amount;
                cout << "Your Updated details : ";
                display_details(it->account_number);
                return true;
            } else {
                cout << "Oooopssss!!!! Insufficient Balance";
                return false;
            }
        } else {
            cout << "Invalid Pin. Try Again";
            return false;
        }
    } else {
        cout << "Account doesn't exist with the given Account Number.";
        return false;
    }
}

bool balance_inquiry() {
    long long int accnum;
    cout << "Enter your account number : ";
    cin >> accnum;
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        string pinfordepo;
        cout << "Enter the pin : ";
        cin >> pinfordepo;
        if (pinfordepo == it->pin) {
            cout << "Account Number : " << it->account_number;
            cout << "\nBalance in your account : " << it->balance;
            return true;
        } else {
            cout << "Invalid Pin. Try Again";
            return false;
        }
    } else {
        cout << "Account doesn't exist with the given Account Number.";
        return false;
    }
}

bool close_account() {
    long long int accnum;
    cout << "Enter your account number : ";
    cin >> accnum;
    auto it = find_if(accts.begin(), accts.end(), [accnum](const Account& acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        accts.erase(it);
        cout << "Account successfully closed.\n";
        return true;
    } else {
        cout << "Account doesn't exist with the given Account Number.\n";
        return false;
    }
}

int main() {
    // Initialize random number generator
    srand(static_cast<unsigned>(time(0)));

    int choice;
    while (true) {
        cout << "\n\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t|          BANK MANAGEMENT SYSTEM               |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "\t\t| 1 - Create Account                            |" << "\n";
        cout << "\t\t| 2 - Change PIN                                |" << "\n";
        cout << "\t\t| 3 - Deposit into Account                      |" << "\n";
        cout << "\t\t| 4 - Withdraw from Account                     |" << "\n";
        cout << "\t\t| 5 - Check Balance                             |" << "\n";
        cout << "\t\t| 6 - Close Account                             |" << "\n";
        cout << "\t\t| 7 - Exit                                      |" << "\n";
        cout << "\t\t|-----------------------------------------------|" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_account(accts);
                break;
            case 2:
                change_pin();
                break;
            case 3:
                deposit_into_account();
                break;
            case 4:
                withdraw_from_account();
                break;
            case 5:
                balance_inquiry();
                break;
            case 6:
                close_account();
                break;
            case 7:
                cout << "Exiting the system. Have a nice day!";
                return 0;
            default:
                cout << "Invalid choice. Please try again.";
                break;
        }
    }
}
