# Bank Management System  

## Overview  
The **Bank Management System** is a simple console-based C++ application that allows users to create, manage, and perform transactions on bank accounts. The system supports both single and joint account holders, with features like deposits, withdrawals, PIN changes, and account closure.  

## Features  
- ✅ Create a bank account (Single or Joint)  
- ✅ Deposit money into an account  
- ✅ Withdraw money from an account  
- ✅ Change account PIN  
- ✅ Check account balance  
- ✅ Close an account  
- ✅ Secure authentication using PIN  
- ✅ Randomly generated unique account numbers  

## Technologies Used  
- **C++** (Standard Library:
- `<vector>`, `<algorithm>`, `<cstdlib>`, `<ctime>`)  
- Object-Oriented Programming (OOP) principles  

## Usage
When you run the program, you will see a menu like this:
```sql
-----------------------------------------------
        BANK MANAGEMENT SYSTEM
-----------------------------------------------
1 - Create Account
2 - Change PIN
3 - Deposit into Account
4 - Withdraw from Account
5 - Check Balance
6 - Close Account
7 - Exit
-----------------------------------------------
Enter your choice: 
```
Follow the prompts to perform actions like creating an account, making deposits, withdrawals, etc.

# Example
Creating an account:
```yaml
ENTER YOUR DETAILS HERE:
Name of Account Holder: JohnDoe
Do you want to have a joint holder account? Type YES/NO: NO
Enter the pin: 1234
Enter the type of account:
1 - Savings Account
2 - Current Account
Enter your choice here: 1
Enter the balance you want to have initially in your account: 5000

ACCOUNT CREATED SUCCESSFULLY
Account Number: 1000005678
Account Holder Name: JohnDoe
Balance in your account: 5000
Type of Account: Savings```
