#include <iostream>
using namespace std;

bool isHillNumber(int num) {
    string str = to_string(num);
    int n = str.length();

    if (n < 3) return false; 

    int i = 1;

    
    while (i < n && str[i] > str[i - 1]) {
        i++;
    }

   
    if (i == 1 || i == n) return false;

   
    while (i < n && str[i] < str[i - 1]) {
        i++;
    }

    
    return i == n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isHillNumber(num)) {
        cout << num << " is a hill number." << endl;
    } else {
        cout << num << " is not a hill number." << endl;
    }

    return 0;
}
