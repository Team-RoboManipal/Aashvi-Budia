#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
 
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Binary Search function
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found, return index
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, target;
    char choice;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose sorting method ('s' for Selection Sort, 'b' for Bubble Sort): ";
    cin >> choice;

   
    if (choice == 's') {
        selectionSort(arr, n);
    } else if (choice == 'b') {
        bubbleSort(arr, n);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Sorted array: ";
    printArray(arr, n);

    // Binary Search
    cout << "Enter the number to search for: ";
    cin >> target;

    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Number found at position: " << result << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
