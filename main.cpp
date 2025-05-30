#include <iostream>
#include "accounts.h"
using namespace std;

string name, op;

int main() {
    cout << "hello user" << endl;
    cout << "1.login\n2.create account" << endl;

    while (true) {
        cin >> op;
        if (digit(op) && (op == "1" || op == "2"))
            break;
        cout << "invalid enter numbers only" << endl;
    }

    if (op == "1") {
        account::login();
    } else if (op == "2") {
        account::newacc();
    }
}