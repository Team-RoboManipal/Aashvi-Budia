#include <iostream>
using namespace std;

void copyString(char* source, char* destination) {
    while (*source != '\0') {
        *destination = *source; 
        source++;          
        destination++;         
    }
    *destination = '\0'; 
}

int main() {
    char source[100], destination[100];

    cout << "Enter a string to copy: ";
    cin.getline(source, 100);

    // Call the copy function
    copyString(source, destination);

    cout << "Copied string: " << destination << endl;

    return 0;
}
