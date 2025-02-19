#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Function to convert decimal to hexadecimal
string decimalToHex(int decimal) {
    string hexStr;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hexStr = char(remainder + '0') + hexStr;
        else
            hexStr = char(remainder - 10 + 'A') + hexStr;
        decimal /= 16;
    }
    return hexStr.empty() ? "0" : hexStr;
}

// Function to convert decimal to octal
string decimalToOctal(int decimal) {
    string octalStr;
    while (decimal != 0) {
        octalStr = char((decimal % 8) + '0') + octalStr;
        decimal /= 8;
    }
    return octalStr.empty() ? "0" : octalStr;
}



int decimalToBinary(int decimal)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (decimal> 0) {

        // storing remainder in binary array
        binaryNum[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--){
        cout << binaryNum[j];}
}






int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    cout << "Hexadecimal: " << decimalToHex(decimal) << endl;
    cout << "Octal: " << decimalToOctal(decimal) << endl;
    cout << "Binary: " << decimalToBinary(decimal) << endl;

    return 0;
}
