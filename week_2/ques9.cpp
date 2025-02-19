#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_ROWS = 10; // Maximum number of rows (strings)
const int MAX_COLS = 100; // Maximum string length

// Function to sort individual strings in ascending order
void sortIndividualStrings(char arr[MAX_ROWS][MAX_COLS], int numRows) {
    for (int i = 0; i < numRows; i++) {
        int length = strlen(arr[i]);
        sort(arr[i], arr[i] + length);
    }
}

// Function to rearrange strings based on length in ascending order
void sortStringsByLength(char arr[MAX_ROWS][MAX_COLS], int numRows) {
    for (int i = 0; i < numRows - 1; i++) {
        for (int j = i + 1; j < numRows; j++) {
            if (strlen(arr[i]) > strlen(arr[j])) {
                // Swap strings if the current string is longer than the next
                char temp[MAX_COLS];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Function to print the array
void printStrings(char arr[MAX_ROWS][MAX_COLS], int numRows) {
    for (int i = 0; i < numRows; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int numRows;
    char arr[MAX_ROWS][MAX_COLS];

    cout << "Enter the number of strings: ";
    cin >> numRows;
    cin.ignore(); // Ignore leftover newline from the previous input

    cout << "Enter the strings:\n";
    for (int i = 0; i < numRows; i++) {
        cin.getline(arr[i], MAX_COLS);
    }

    // Sort each individual string
    sortIndividualStrings(arr, numRows);

    // Sort strings by length
    sortStringsByLength(arr, numRows);

    cout << "\nSorted strings by individual characters and by length:\n";
    printStrings(arr, numRows);

    return 0;
}
