#include <iostream>
using namespace std;


int sumOfDigitsRecursive(int n) {
    if (n == 0) {
        return 0; /
    }
    return (n % 10) + sumOfDigitsRecursive(n / 10); s
}


int sumOfDigitsIterative(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10; 
        n /= 10;       
    }
    return sum;
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;


    if (number < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1; 
    }

    
    int recursiveSum = sumOfDigitsRecursive(number);
    cout << "Sum of digits (recursive): " << recursiveSum << endl;

 
    int iterativeSum = sumOfDigitsIterative(number);
    cout << "Sum of digits (iterative): " << iterativeSum << endl;

    return 0;
}
