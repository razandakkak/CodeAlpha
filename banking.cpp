#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer{
private:
string Fname, Lname, address;
int age;

public:
Customer(string fn, string ln, string ad, int a) : Fname(fn), Lname(ln), address(ad), age(a) {}

void displayDetails(string part = "full") {
        if (part == "first") {
            cout << Fname << "\n";} 
        else if (part == "last") { cout << Lname << "\n";}
        else {
            cout << Fname << " " << Lname << "\t";
            cout << "Address: " << address << "\t";
            cout << "Age: " << age << "\t";}}


string getNames(){ return Fname + " " + Lname;}

void setNames(string fn, string ln){
    Fname = fn;
    Lname = ln;}

int getAge(){ return age;}

void setAge(int a){ age = a;}

string getAddress(){ return address;}

void setAddress(string ad){ address = ad;}
};


class Transaction{
private:
string ID, type, accountNumber;
double amount;

public:
Transaction(string tid, string typ, string acn, double amnt): ID(tid), type(typ), accountNumber(acn), amount(amnt){}

void displayTransaction(){
    cout << "Transaction ID: " << ID << "\n";
    cout << "Transaction Type: " << type << "\n";
    cout << "Amount: " << amount << "\n";
    cout << "Account Number: " << accountNumber << "\n";}

string getTransactionID() { return ID; }
string getTransactionType() { return type; }
double getAmount() { return amount; }
string getAccountNumber() { return accountNumber; }
};



class Accounts{
private:
string accountNumber;
double balance;
vector<Transaction> transactions;

public:
Accounts(string acn, double b) : accountNumber(acn), balance(b){}

void displayDetails(){
    cout << "Your account number is: " << accountNumber << "\n";
    cout << "Your balance is: " << balance << "\n";}

void displayTransactions() {
        for (auto& transaction : transactions) {
            transaction.displayTransaction();
            cout << "\n";}}

void deposit(double amount){
    balance += amount;
    cout << "Your deposit amount is: " << amount << "\n";
    cout << "Your new balance is: " << balance << "\n";
    // Add transaction
    transactions.push_back(Transaction("T" + to_string(transactions.size() + 1), "deposit", accountNumber, amount));}

void withdraw(double amount){
    if (amount < balance){
        balance -= amount;
        cout << "Your withdraw amount is: " << amount << "\n";
        cout << "Your balance now is: " << balance << "\n";
        transactions.push_back(Transaction("T" + to_string(transactions.size() + 1), "withdrawal", accountNumber, amount));}
    else{
        cout << "Your balance is very short, cannot perform this operation.";}}

double Showbalance(){ return balance;}
string ShowAccountNb(){ return accountNumber;}
};



class Services{
public:
static void transfer(Accounts &fromAccount, Accounts &toAccount, Customer& fromCustomer,
 Customer& toCustomer, double amount) {
        if (fromAccount.Showbalance() >= amount) {
            cout << "Transfer from " << fromCustomer.getNames() << " to " << toCustomer.getNames() << ":\n";
            fromCustomer.displayDetails("last");
            fromAccount.withdraw(amount);
            toCustomer.displayDetails("last");
            toAccount.deposit(amount);
            cout << "Transfer successful.\n";} 
        else {cout << "Transfer failed; Insufficient funds from:\n";
        fromCustomer.displayDetails();}}
};



int main(){
Customer customer1("Razan", "Dakak", "Tripoli, Lebanon", 24);
Customer customer2("Jane", "Moh", "Beirut, Lebanon", 28);
Customer customer3("Myriam", "Esper", "Saida, Lebanon", 32);
Customer customer4("Jean", "Said", "Dubai, UAE", 40);

    // Display customer details
customer1.displayDetails();
Accounts account1("123456789", 100.0);
account1.displayDetails();
cout << "\n";

customer2.displayDetails();
Accounts account2("987654321", 268.0);
account2.displayDetails();
cout << "\n";

customer3.displayDetails();
Accounts account3("A532487236", 1000.0);
account3.displayDetails();
cout << "\n";

customer4.displayDetails();
Accounts account4("1543b3453", 950.0);
account4.displayDetails();
cout << "\n";

    // Perform some transactions
cout << "Deposit for ";
customer1.displayDetails("last");
account1.deposit(500.0);
cout << "\n";
cout << "Withdraw for ";
customer1.displayDetails("last");
account1.withdraw(200.0);
cout << "\n";
account1.displayTransactions();

cout << "Deposit for ";
customer2.displayDetails("last");
account2.deposit(1000.0);
cout << "\n";

cout << "Withdraw for ";
customer3.displayDetails("last");
account3.withdraw(600.0);
cout << "\n";
account3.displayTransactions();

cout << "Withdraw for ";
customer4.displayDetails("last");
account4.withdraw(1000.0);
cout << "\n";
account4.displayTransactions();

    // Transfer funds between accounts
cout << "\nFirst transfer opertation:\n";
Services::transfer(account1, account2, customer1, customer2, 300.0);
cout << "\nSecond transfer opertation:\n";
Services::transfer(account3, account4, customer3, customer4, 500.0);


 
return 0;
}
