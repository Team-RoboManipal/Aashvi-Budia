#include <iostream>
#include <string>
using namespace std;


void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(char arr[], int n){
    int i=0;
    
    for(i=0;i<n;i++){
        cout <<arr[i];
        
    }
}

int main(){
    std::string str;
     while (str.empty()){
        std::cout<<"enter the character array:";
        std::getline(std::cin, str);

    }
    int n=str.length();
    char arr[n];
    for(int i=0; i<n;i++){

        arr[i]=str[i];
    }

    cout<< "the original array is ";

    printArr(arr,n);
    cout<< "\n";
    bubbleSort(arr,n);

    cout<< "the new array is ";
    printArr(arr,n);






}


