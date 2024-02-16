#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

class bank_account {
    int account_number;
    char name[30];
    char type;
    int money_deposit;

public:
    int retacno() const {
        return account_number;
    }

    void create_account();
    void display_account() const;
};

void write_account();
void display_account(int n);
void delete_account(int n);

void bank_account::create_account() {
    system("cls");
    cout << "\t Enter the account number" << endl;
    cin >> account_number;
    cin.ignore();
    cout << "\t Enter the name of the acount holder" << endl;
    cin.getline(name, 50);
    cout << "\t Enter the type of the account:" << endl;
    cin >> type;
    type = toupper(type);
    cout << "\t Enter the initial amount (the amount should be >=500 for savings account and >=1000 for current account):" << endl;
    cin >> money_deposit;
    cout << "\t THANK YOU FOR CREATING YOUR ACCOUNT................" << endl;
}

void bank_account::display_account() const {
    cout << "\tBank Account number is :" << account_number << endl;
    cout << "\t Name of the account holders name :" << name << endl;
    cout << "\tThe account type is :" << type << endl;
    cout << "\tBalance amount in the account is :" << money_deposit << endl;
}

void write_account() {
    bank_account ac;
    ofstream outfile;
    outfile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
    outfile.close();
}

void delete_account(int n) {
    bank_account ac;
    ifstream infile;
    ofstream outfile;
    infile.open("account.dat", ios::binary);
    if (!infile) {
        cout << "\tFile is not found" << endl;
        return;
    }
    outfile.open("temp.dat", ios::binary);
    infile.seekg(0, ios::beg);
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(bank_account))) {
        if (ac.retacno() != n) {
            outfile.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
        }
    }
    infile.close();
    outfile.close();
    remove("account.dat");
    rename("temp.dat", "account.dat");
}

void display_account(int n) {
    bank_account ac;
    bool flag = false;
    ifstream infile;
    infile.open("account.dat", ios::binary);
    if (!infile) {
        cout << "File is not found" << endl;
        return;
    }
    cout << "\tDetails of the account:" << endl;
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(bank_account))) {
        if (ac.retacno() == n) {
            ac.display_account();
            flag = true;
        }
    }
    infile.close();
    if (!flag) {
        cout << "\tThe account number does not exist" << endl;
    }
}

int main() {
    char ch;
    int num;
    cout << "\t---------------------------------" << endl;
    cout << "\tWELCOME TO THE BANK MANAGEMENT SYSTEM" << endl;
    cout << "\t--------------------------------------" << endl;

    cout << "\t---MAIN MENU---" << endl;
    cout << "\t1.CREATE AN ACCOUNT" << endl;
    cout << "\t2.DEPOSIT MONEY" << endl;
    cout << "\t3.WITHDRAW MONEY" << endl;
    cout << "\t4.CHECK THE BALANCE IN THE ACCOUNT" << endl;
    cout << "\t5.ALL THE ACCOUNT HOLDERS LIST" << endl;
    cout << "\t6.CLOSE AN ACCOUNT" << endl;
    cout << "\t7.MODIFY THE ACCOUNT" << endl;
    cout << "\t8.EXIT" << endl;

    cout << "\tENTER YOUR OPTION:" << endl;
    cin >> ch;

    switch (ch) {
        case '1':
            write_account();
            break;

        case '2':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            cin >> num;
            // Code for option 2
            break;

        case '3':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            cin >> num;
            // Code for option 3
            break;

        case '4':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            cin >> num;
            display_account(num);
            break;

        case '5':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            cin >> num;
            // Code for option 5
            break;

        case '6':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            delete_account(num);
            break;

        case '7':
            system("cls");
            cout << "\tEnter the account number:" << endl;
            cin >> num;
            // Code for option 7
            break;

        case '8':
            cout << "\tTHANKS FOR USING BANK MANAGEMENT SYSTEM" << endl;
            break;
    }

    return 0;
}
