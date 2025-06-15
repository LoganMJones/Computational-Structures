//  Logan Jones
#include <iostream>

using namespace std;

long long fibonacci(long long n);
long long summation(long long n);

int main() {
    int i1;
    int i2;
    long long fib;
    long long sum;
    // Read in an integer number
    cout << "Warning: 50 took 65 seconds to compute on an m1 macbook pro ";
    cout << endl << "Enter Fibonacci integer <= 50 ): ";
    cin >> i1;
    // Compute and display the corresponding Fibonacci number using a recursion
    fib = fibonacci(i1);

    cout << "The Fibonacci number for " << i1 << " is " << fib << endl;

    // Read in a second integer
    cout << "Enter Summation integer <= 50,000" << endl;
    cin >> i2;
    // Compute and display the summation of all the integer values
    sum = summation(i2);

    cout << "Summation for " << i2 << " is " << sum << endl;

    return 0;
}

long long fibonacci(long long n){ // recursive fibonacci algorithm
    if (n < 2){
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

long long summation(long long n){
    long long sum = 0;
    // Use a loop to find the sum of all the numbers from 1 to n,
    for (long long i = 1; i <= n; i++){
        sum += i;
    }
    // then compare it to the result of the formula (n(n+1))/2
    if (sum == (n*(n+1))/2){ //If they are the same say they are the same, 
        cout << "Sum matches Formula (n(n+1))/2" << endl;
    }
    else{ //if they are different, report that
        cout << "Sum does not match Formula (n(n+1))/2" << endl;
    }
    return sum;
}

