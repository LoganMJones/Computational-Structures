//  Logan Jones
//  Filename: hw5.cpp
//  ---------------------------------------------------------------------------
//  This program explores recursion with the strings and summation
//  ---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int sumRange(int val1, int val2);
void printRevString(string theString, int position);

int main(){
    // ----------------------- summation --------------------------------------
    int user1;
    int user2;

    cout << "Please enter your range of integers (on one or more lines)"
    << endl;
    cin >> user1 >> user2;

    cout << "The sum of all integers from " << user1 << " to " << user2
    << " is " << sumRange(user1, user2) << endl;   
    
    // ----------------------- string recursion -------------------------------
    string line;
    cout << "Please enter a string: ";
    cin.ignore(1, '\n');
    getline(cin, line);
    cout << "The reverse of your input is:" << endl;
    printRevString(line, 0);
    cout << endl;

    return 0;
}

int sumRange(int val1, int val2){
    // if equal return value
    if (val1 == val2){
        return val1;
    }
    // ensure that val 1 is greater than val 2
    if (val1 < val2) { 
        int tempInt = val1;
        val1 = val2;
        val2 = tempInt;
    }
    // return val1 + recursive call to sumrange
    return val1 + sumRange(val1-1, val2);
}

void printRevString(string theString, int position){
    // convert theString's size to an int and check if larger than current position
    if (static_cast<int>(theString.length()) > position){ 
        //recursively call with position plus one and then print out current position
        printRevString(theString, position + 1);
        cout << theString[position];
    }
}
