#include <iostream>
using namespace std;

void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter elements of the matrix" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows1, int cols1, int cols2) {
    // Initializing all elements of result matrix to 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    cout << "Enter rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;

    
    cout << "Enter rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;

    
    if (cols1 != rows2) {
        cout << "Error: Matrices are not compatible for multiplication." << endl;
        return 1;
    }

    int a[10][10], b[10][10], c[10][10];

    
    inputMatrix(a, rows1, cols1);
    inputMatrix(b, rows2, cols2);

    multiplyMatrices(a, b, c, rows1, cols1, cols2);

    cout << "final matrix after multiplication:" << endl;
    printMatrix(c, rows1, cols2);

    return 0;
}
