# 💳 Bank Account Simulator (C++)

A simple C++ console-based banking system that allows users to create an account, log in, deposit, and withdraw money. This project simulates the core functionalities of a banking application using object-oriented programming and file handling in C++.

---

## 🚀 Features

- 👤 Create new bank accounts
- 🔐 Login using name and PIN
- 💰 View current balance
- ➕ Deposit money
- ➖ Withdraw money (with balance validation)
- 🗃️ All data is saved in a CSV file (`baccs.csv`)

---

## 🛠️ Tech Stack

- C++
- File I/O (`fstream`)
- CSV format for data storage
- Standard library tools like `vector`, `stringstream`, and `cctype`

---

## 📦 Project Structure

- `main.cpp` — the entry point of the program
- `accounts.h` — contains the class definition and main logic
- `baccs.csv` — stores users' data (name, PIN, balance)

---

## 🧠 Learning Goals

- Practice Object-Oriented Programming in C++
- Work with file input/output for persistent data
- Handle user input and basic validation
- Use vectors and stringstreams to manage structured data

---

## 📸 Preview (Console Output)

```txt
hello user
1.login
2.create account

Enter your name: Ahmed
Create your PIN: 1234
Enter your balance: 5000
Your account has been created.

Enter your name: Ahmed
Enter your PIN: 1234
Welcome Ahmed
Your balance is 5000
1.deposit
2.withdraw
3.exit