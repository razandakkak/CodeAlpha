#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void Registration();
void Login();
void Forgot();
void Change();


int main() {
    int c;
    char anotherop;

    do{
    
    cout << "\nWelcome to our page, what would you like to do?" << endl;
    cout << "1: Registration\n 2:Login\n 3:Forgot Password\n 4:Change password\n";
    cin >> c;
    cout << endl;

    switch (c) {
            case 1:
                Registration();
                break;
            case 2:
                Login();
                break;
            case 3:
                Forgot();
                break;
            case 4:
                Change();
                break;
            default:
                cout << "Invalid number.\n";
                break;
        }

    
    cout << "\nYou want to do another operation?\n";
    cin >> anotherop;
    
    
    } while (anotherop == 'y' || anotherop == 'Y');

}


void Registration() {
    string newID, newPASS, eID;
    int count =0;
    cout <<"Welcome new member!\n" ;
    cout << "Please enter a username: ";
    cin >> newID;
    cout << "Please enter a password: ";
    cin >> newPASS;

    ifstream f1("records.txt");
    
    while (f1 >> eID){
        if (newID == eID){
            count = 1;
            break;
            }
        }
    f1.close();

    if (count == 1){
        cout <<"Sorry this username exists, try another one\n";
        Registration();
        }
        
    else {
        ofstream f1("records.txt", ios::app);
        f1 << newID << " " << newPASS << endl;
        cout << "You are all set! Welcome on board.\n";
            }
}

void Login() {
    string oldID, oldPASS, LID, LPASS;
    int rightanswer;
    cout <<"Welcome back buddy!\n";
    cout <<"Enter your username:";
    cin >> oldID;
    cout << "Enter your password:";
    cin >> oldPASS;

    ifstream input("records.txt");

    while (input >> LID >> LPASS){
        if (oldID == LID && oldPASS == LPASS ){
            rightanswer = 1;
        }}
        if (rightanswer == 1){
            cout << "Welcome back\n";
        }
        else {
            cout << "Sorry wrong credentials! Try again.\n";
            Login();
        }
    }

void Forgot() {
    string fusername, exuser, expass;
    int plus;
    char answer;
    do{cout << "\nDon't worry we are here to help!\n";
    cout << "Please enter your username: ";
    cin >> fusername;

    ifstream in("records.txt");

    while(in >> exuser >> expass){
        if (fusername == exuser){
            plus = 1;
        }
    
    }
    in.close();

    if(plus == 1){
        cout << "We found your password! here it is:\n";
        cout << expass;
    }
    else{
        cout << "Sorry, your username was not found, do you want to try again? y/n\n";
        cin >> answer;

    }} while (answer == 'y' || answer == 'Y');


}

void Change(){
    string youruser, youroldpass, olduser, oldpass, newone;
    int w, t;
    cout << "Let us first know you! Please enter your username: ";
    cin >> youruser;
    
    ifstream u("Records.txt");

    while (u >> olduser){
        if (olduser == youruser){
            w = 1;
        }
    }
    u.close();
    if ( w ==1){
        cout << "Now please write your old password: ";
        cin >> youroldpass;
    }
    else{
        cout << "sorry we did not find any username like this, please try again.\n";
        Change();
    }

    ifstream y("Records.txt");

    while (y >> oldpass){
        if ( oldpass == youroldpass){
            t =1;
        }

    }
    
    y.close();

    if (t == 1){
        cout << "Please enter your desired new password: ";
        cin >> newone;
        ofstream y("records.txt", ios::app);
        y <<  youruser << " " << newone << endl;
        
        cout << "You are all set! Welcome on board.\n";

    }
    
    else{
        cout << "Sorry this password is wrong. ";
        }
    
}



