//  Logan Jones
//  Filename: bitwise.cpp
//  ---------------------------------------------------------------------------
//  Reads two sets from the user and then prints several of their operations.
//  ---------------------------------------------------------------------------
#include <iostream>

using namespace std;

// getters
int getSet(string const& setName);
int getInt(string const& prompt);
// ------------------    Exploring C++ Bitwise Operators   --------------------
// https://en.cppreference.com/w/cpp/language/operator_arithmetic
// ----------------------------------------------------------------------------
// everything that's in the universal set but not in the provided set
int complementSet(int set);
// Bitwise AND  a & b
int intersectionSets(int setA, int setB);
// Bitwise OR   a | b
int unionSets(int setA, int setB);
// a & ~b
int differenceSets(int setA, int setB);
// Bitwise XOR  a ^ b
int symmetricDiffSets(int setA, int setB);
// printing helpers
void displayOperations(int setA, int setB);
string setStr(int set);

int main() {
    cout << "This program will ask you for the elements to complete two sets "
         << "& will display the results of various set operations\n\n";
    int setA = getSet("SetA"); // get sets from user and formats as an int
    int setB = getSet("SetB");
    displayOperations(setA, setB); // print set operation results

    return 0;
}

// gets a set from the user and returns it as an integer
int getSet(string const& setName) { // first prompt for number of elems
    int tmpSet = 0;
    string prompt = "Please enter the number of elements in set "+setName+": ";
    int numElems = getInt(prompt); // number of set elements
    for (int i = 1; i < numElems+1; i++){ // for each element
        prompt = "Please enter element " + to_string(i) + ": ";
        tmpSet = tmpSet | ( 1 << getInt(prompt)); // get elem and add to set
    }
    cout << endl;
    return tmpSet;
}

// gets a valid int from 0-9 and returns it
int getInt(string const &prompt = "enter a value between 0-9"){
    int validInt;
    while (true) {
      cout << prompt;
      cin >> validInt;
        // if user input is good and int is 0-9 return int otherwise, reprompt
      if (!cin.fail() && validInt >= 0 && validInt <= 9) {
          return validInt;
      }
      cin.clear(); // clear cin errorstate
      cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      cout << "Integers between 0-9 only please" << endl;
    }
  }

void displayOperations(int setA, int setB) {
    cout << "Input Sets" << endl;
    cout << "Set A = " << setStr(setA) << endl;
    cout << "Set B = " << setStr(setB) << endl << endl;

    cout << "Complement of A = " << setStr(complementSet(setA)) << endl;
    cout << "Complement of B = " << setStr(complementSet(setB)) << endl;
    cout << "Union of A and B = " << setStr(unionSets(setA, setB)) << endl;
    cout << "Intersection of A and B = "
         << setStr(intersectionSets(setA, setB)) << endl;
    cout << "Difference of A and B = "
         << setStr(differenceSets(setA, setB)) << endl;
    cout << "Symmetric Difference of A and B = ";
    cout << setStr(symmetricDiffSets(setA, setB)) << endl;
}

// prints set in the format {elem,elem,elem,elem}
string setStr(int set) {
    string tmp = "{";
    bool first = true;// handle commas
    for (int i = 0; i <= 9; i++){ // for 0-9
        if (set & (1 << i)){ // if in set, add to tmp
            if (!first){ // add comma if not the first element
                tmp += ",";
            }
            tmp += to_string(i);
            first = false;
        }
    } // put closing bracket and return
    return tmp + "}";
}

// everything in the universal set 0-9, not in the set provided.
int complementSet(int set){
    int tmp = 0;
    for (int i = 0; i <= 9; i++) {
        if (!(set & (1 << i))) { // if not in set, but in universal set 0-9
            tmp = tmp | ( 1 << i); // add to tmp
        }
    } // return the complement set
    return tmp;
}
// Bitwise OR   a | b
int unionSets(int setA, int setB){
    return setA | setB;
}
// Bitwise AND  a & b
int intersectionSets(int setA, int setB){
    return setA & setB;
}
// a & ~b keep everything in a but not b in other words a - b
int differenceSets(int setA, int setB){
    return setA & (~setB);
}
// Bitwise XOR  a ^ b
int symmetricDiffSets(int setA, int setB){
    return setA ^ setB;
}



