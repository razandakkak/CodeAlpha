#include <iostream> 
#include <string>
#include <sstream>
using namespace std;

// Function to check if a string can be converted to a number
bool is_number(const string& s) {
    istringstream iss(s);
    float f;
    return (iss >> f) && (iss.eof());
}

int main(){
    char ans;
    do{
    int sems, b=0, credit, j, totalCperS=0;
    float grade, points, totalCofS=0, cgpa=0, totalG=0, GPA=0;
    string letter; 
    cout << "Welcome to GPA calculation, first let us introduce some instuctions:\n";
    cout <<"----------------------------------------------------------------------------------------------------\n";
    cout << "Tell us how many semesters do you want to enter?\n";
    cin >> sems;
    cout <<"----------------------------------------------------------------------------------------------------\n";
    
    cout <<"Now all you have to do is the following:\n1- Enter the credit hours for the course.\n2- Enter the grade you had\n";
    do{
    int totalC=0;
    float totalP=0, totalgrades=0;
    cout <<"----------------------------------------------------------------------------------------------------\n"; 
    cout << "Let us know how many courses you took in this semester: ";
    cin >> j;
    for (int i = 0; i < j; i++){
        float TOTALGPS=0;
        cout << "The credits of the course: ";
        cin >> credit;
        totalC += credit;
        cout << "Enter your grade in this course in letters or as a number: ";
        cin >> letter;
        if (is_number(letter)) {
            grade = stof(letter);}
        else if (letter == "A+" || letter == "A"){
                grade = 4.0;}
        else if (letter == "A-"){
                grade = 3.7;}
        else if (letter == "B+"){
                grade = 3.3;}
        else if (letter == "B"){
                grade = 3.0;}
        else if (letter == "B-"){
                grade = 2.7;}
        else if (letter == "C+"){
                grade = 2.3;}
        else if (letter == "C"){
                grade = 2.0;}
        else if (letter == "C-"){
                grade = 1.7;}
        else if (letter == "D+"){
                grade = 1.3;}
        else if (letter == "D"){
                grade = 1.0;}
        else if (letter == "F"){
                grade = 0.0;}
        else{
            cout << "Invalid grade.\n";
            i--; 
            continue; }

    totalG += grade;
    TOTALGPS += totalG;
    points = grade * credit;
    totalP += points;
    totalgrades = totalG/j;
    }
    GPA = totalP / totalC;
    cout << "Total credits you earned in this semester are: " << totalC << "\n";
    cout << "The GPA for the current semester is: " << GPA << "\n";
    b++;
    totalCofS += GPA;
    totalCperS += totalC;

    }
    while (b < sems);
    cgpa = (totalCofS / sems);
    cout << "Your CGPA  until now is:" << cgpa << "\n";
    cout << "Do you want to calculate another CGPA? (y/n): ";
    cin >> ans;
    } while (ans == 'y' || ans == 'Y');

}
