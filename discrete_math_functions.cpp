//  Logan Jones
//  ---------------------------------------------------------------------------
//  This program identifies various properties of a provided function
//  ---------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Valid if no x value has two y values and all x and y values are part of the 
// Domain and Range respectively (we will accept partial functions as valid)
bool validFunction = true;
// functin declarations
bool inRange(int i);
bool OneToOne(const unordered_map<int, int> m);
bool Onto(const unordered_map<int, int> m);
ostream &printResults(ostream &out, const unordered_map<int, int>);

// Function is invalid if x or y is less than one or greater than five
// Function is invalid if any x value appears twice
// One-to-one: no repeated y values
// Onto: five y values
// Bijection: both one-to-one and onto
int main(){
    int numPairs = 0;
    unordered_map<int, int> function;
    cout << "How many ordered pairs does your function contain? (1-5)" << endl;
    cin >> numPairs; // grab number of ordered pairs.
    cout << endl;

    // end early if numPairs is out of bounds. 
    if (!inRange(numPairs)){ // custom in range function
        cout << "User input out of range" << endl;
        return 0; // end main
    }

    cout << "Enter ordered pairs one at a time in the form 'x y' between 1-5";
    cout << endl;

    // grab ordered pairs and store in a map of ints. 
    for (int i = 1; i <= numPairs; i++){
        int x,y;
        cout << "Pair " << i << ": " << endl;
        cin >> x >> y;
        cout << endl;
        // if x and y are between 1-5 (in the domain and range)
        if (inRange(x) && inRange(y)) {
            auto insertion = function.insert({x, y});
            if (!insertion.second){ // if insertion fails due to duplicate x
                validFunction = false;
            }
        }
        else{ // out of range
            validFunction = false;
            function.insert({x, y});
        }
    } // end for loop, function initialized.
    
    // print out function properties
    printResults(cout, function);

    return 0; // end main
}


// true if between 1-5 otherwise false.
bool inRange(int i){
    return (i >= 1 && i <= 5);
}

// One-to-one:  No y value has more than one x that maps to it 
//      (e.g., f(3) = 2 and f(4) = 2 is NOT one-to-one)
bool OneToOne(const unordered_map<int, int> m){
    unordered_set<int> yValues;
    // iterate through all pairs and check if 1 to 1
    for (const auto& pair : m){
        if (yValues.count(pair.second)){ // if already exists in set
            return false;
        }
        // else insert y value into set
        yValues.insert(pair.second);
    }// end for, no duplicate y values
    return true;
}

// Onto:  for every y in the Range, there is at least one x such that f(x) = y.
bool Onto(const unordered_map<int, int> m){
    unordered_set<int> yValues; 
    for (const auto& pair : m){ // initialize yvalue set
        yValues.insert(pair.second);
    }
    // checks if y value is missing from function
    for (size_t i = 1; i <= 5; i++){ 
        if (!yValues.count(i)){
            return false;
        }
    }
    return true;
}

ostream& printResults(ostream& out, const unordered_map<int, int> m){
    
    // function invalid, return early 
    if (!validFunction){ 
        out << "That is not a valid function" << endl;
        return out;
    }

    out << "Function described by:" << endl;

    for (const auto& pair : m){
        out << "f(" << pair.first << ") = " << pair.second << endl;
    }
    out << endl;

    out << "This function is a valid function" << endl;


    bool isOneToOne = OneToOne(m);
    bool isOnto = Onto(m);

    if(isOneToOne){ // 1-to-1
        out << "This function is 1-to-1" << endl;
    }
    else{
        out << "This function is not 1-to-1" << endl;
    }
    
    if (isOnto){
        out <<  "This fuction is onto" << endl;
    }
    else{
        out << "This fuction is not onto" << endl;
    }

    if (isOneToOne && isOnto){
        out << "This function is a bijection" << endl;
    }
    else{
        out << "This function is not a bijection" << endl << endl;
    }

    return out;

}
