#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

bool valid(string name);
void create();
void tovector();

class account {
private:
    string name;
    string PIN;
    string balance;

public:
    account(string n, string p, string b) {
        name = n;
        PIN = p;
        balance = b;
    }

    static void newacc() {
        create();
    }

    string get_name() {
        return name;
    }

    string get_PIN() {
        return PIN;
    }

    string get_balance() {
        return balance;
    }

    static void login();
};

vector<account> accounts;

bool valid(string name) {
    for (char n : name) {
        if (!isalpha(n))
            return false;
    }
    return true;
}

bool digit(string num) {
    for (char c : num) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void account::login() {
    string ename;
    string epin;
    bool found = false;

    cout << "enter your name" << endl;
    cin >> ename;
    cout << "enter your pin" << endl;
    cin >> epin;

    tovector();

    for (account& acc : accounts) {
        if (acc.get_name() == ename && acc.get_PIN() == epin) {
            found = true;
            cout << "welcome " << acc.get_name() << endl;
            cout << "your balance is " << acc.get_balance() << endl;
            cout << "1.deposit\n2.withdraw\n3.exit" << endl;

            string choice;
            while (true) {
                cin >> choice;
                if (choice == "1" || choice == "2" || choice == "3")
                    break;
                cout << "invalid enter numbers only" << endl;
            }

            if (choice == "1") {
                cout << "enter the amount you want to deposit" << endl;
                int intbalance = stoi(acc.get_balance());
                int deposit;
                cin >> deposit;
                intbalance += deposit;
                acc.balance = to_string(intbalance);
                cout << "your new balance is " << acc.get_balance() << endl;

                ofstream file("baccs.csv");
              file << "name,PIN,balance" <<endl;
                for (account& a : accounts)
                    file << a.get_name() << "," << a.get_PIN() << "," << a.get_balance() << endl;
            }

            else if (choice == "2") {
                cout << "enter the amount you want to withdraw" << endl;
                int intbalance = stoi(acc.get_balance());
                int withdraw;
                cin >> withdraw;
                while (withdraw > intbalance) {
                    cout << "not enough money" << endl;
                    cin >> withdraw;
                }
                intbalance -= withdraw;
                acc.balance = to_string(intbalance);
                cout << "your new balance is " << acc.get_balance() << endl;

                ofstream file("baccs.csv");
              file << "name,PIN,balance" <<endl;
                for (account& a : accounts)
                    file << a.get_name() << "," << a.get_PIN() << "," << a.get_balance() << endl;
            }

            else if (choice == "3") {
                break;
            }
        }
    }

    if (!found)
    {
      cout << "invalid name or pin 1 try left" << endl;
        login();
      
    }  
}

void create() {
    string nn, name;
    string PIN, balance;

    cout << "Enter your name: ";
    while (true) {
        cin >> nn;
        if (valid(nn))
            break;
        cout << "Invalid name. Please enter again: ";
    }
    name = nn;

    cout << "Create your PIN" << endl;
    while (true) {
        cin >> PIN;
        if (digit(PIN))
            break;
        cout << "invalid enter numbers only" << endl;
    }

    cout << "enter your balance" << endl;
    while (true) {
        cin >> balance;
        if (digit(balance))
            break;
        cout << "invalid enter numbers only" << endl;
    }

    cout << "your account has been created " << endl;
    account acc(name, PIN, balance);
    ofstream file("baccs.csv", ios::app);
    file << acc.get_name() << "," << acc.get_PIN() << "," << acc.get_balance() << endl;
}

void tovector() {
    accounts.clear();
    ifstream file("baccs.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string name, PIN, balance;
        getline(ss, name, ',');
        getline(ss, PIN, ',');
        getline(ss, balance, ',');
        account acc(name, PIN, balance);
        accounts.push_back(acc);
    }
}