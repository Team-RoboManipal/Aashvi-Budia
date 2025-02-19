#include <iostream>
using namespace std;


long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms = 40;
    cout << "First 40 terms of the Fibonacci sequence:\n";
    for (int i = 0; i < terms; i++) {
        cout << fibonacci(i) << "\n";
    }
    cout << endl;
    return 0;
}
