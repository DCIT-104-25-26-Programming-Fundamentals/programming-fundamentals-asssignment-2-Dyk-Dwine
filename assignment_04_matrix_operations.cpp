// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols, int transposed[10][10]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Function to add two matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10],  int rows, int cols, int sum[10][10]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int colsB, int product[10][10]) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            product[i][j] = 0; // Initialize the product element
            for (int k = 0; k < colsA; ++k) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}   

// Main function
int main() {
    // Part A: Transpose a Matrix
    int rows, cols;
    int matrix[10][10], transposed[10][10];
    cout << "Enter number of rows for the matrix: ";
    cin >> rows;
    cout << "Enter number of columns for the matrix: "; 
    cin >> cols;

    // Input the original matrix
    for (int i = 0; i < rows; ++i) {    
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }   

    // Transpose the matrix
    transposeMatrix(matrix, rows, cols, transposed);    

    // Display the original and transposed matrices
    cout << "\nOriginal Matrix:\n";     
    displayMatrix(matrix, rows, cols);
    cout << "\nTransposed Matrix:\n";   
    displayMatrix(transposed, cols, rows);

    // Part B: Add Two Matrices
    int matrixA[10][10], matrixB[10][10], sum[10][10];
    cout << "\nEnter number of rows for the matrices to add: ";     
    cin >> rows;
    cout << "Enter number of columns for the matrices to add: "; 
    cin >> cols;

    // Input the first matrix
    cout << "\nEnter elements for the first matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    // Input the second matrix
    cout << "\nEnter elements for the second matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    // Add the matrices
    addMatrices(matrixA, matrixB, rows, cols, sum);

    // Display the sum matrix
    cout << "\nSum of the Matrices:\n";
    displayMatrix(sum, rows, cols);

    // Part C: Multiply Two Matrices
    int rowsA, colsA, rowsB, colsB; 

    cout << "\nEnter number of rows for matrix A: ";
    cin >> rowsA;   

    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;   

    cout << "Enter number of rows for matrix B: ";
    cin >> rowsB;       

    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;   

    // Check if multiplication is possible
    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B for multiplication." << endl;
        return 1; // Exit the program with an error code
    }
    
    int matrixC[10][10], product[10][10];   

    // Input matrix A
    cout << "\nEnter elements for matrix A:\n";
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    // Input matrix B
    cout << "\nEnter elements for matrix B:\n";
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    // Multiply the matrices
    multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB, product);

    // Display the product matrix
    cout << "\nProduct of the Matrices:\n";
    displayMatrix(product, rowsA, colsB);
}   

