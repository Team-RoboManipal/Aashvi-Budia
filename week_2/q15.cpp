#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {

    if (n <= 1) {
        return;
    }


    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
         
            swap(arr[i], arr[i + 1]);
        }
    }


    bubbleSort(arr, n - 1);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; 

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    bubbleSort(arr, n);


    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}
