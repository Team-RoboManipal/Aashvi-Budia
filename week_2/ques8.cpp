#include <iostream>
using namespace std;

const int MAX = 10;

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX][MAX], B[MAX][MAX], AB[MAX][MAX], transAB[MAX][MAX], transA[MAX][MAX], transB[MAX][MAX], transBA[MAX][MAX];


    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;


    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible. Columns of A must equal rows of B." << endl;
        return 1;
    }


    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }


    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }


    multiplyMatrices(A, B, AB, rowsA, colsA, colsB);


    transposeMatrix(AB, transAB, rowsA, colsB);


    transposeMatrix(A, transA, rowsA, colsA);
    transposeMatrix(B, transB, rowsB, colsB);


    multiplyMatrices(transB, transA, transBA, colsB, rowsB, rowsA);


    cout << "\nMatrix A * B:\n";
    printMatrix(AB, rowsA, colsB);

    cout << "\nTranspose of (A * B):\n";
    printMatrix(transAB, colsB, rowsA);

    cout << "\nTranspose of B * Transpose of A:\n";
    printMatrix(transBA, colsB, rowsA);

    // Verify if (A * B)^T == B^T * A^T
    bool identityHolds = true;
    for (int i = 0; i < colsB; i++) {
        for (int j = 0; j < rowsA; j++) {
            if (transAB[i][j] != transBA[i][j]) {
                identityHolds = false;
                break;
            }
        }
        if (!identityHolds) break;
    }

    if (identityHolds) {
        cout << "\nThe identity (A * B)^T = B^T * A^T holds.\n";
    } else {
        cout << "\nThe identity (A * B)^T = B^T * A^T does not hold.\n";
    }

    return 0;
}
