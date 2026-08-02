// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double calculateAverage(int arr[], int size) {
    if (size == 0) return 0.0; // Avoid division by zero
    int sum = calculateSum(arr, size);
    return static_cast<double>(sum) / size;
}

int findMaximum(int arr[], int size) {
    if (size == 0) return 0; // Handle empty array case
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMinimum(int arr[], int size) {
    if (size == 0) return 0; // Handle empty array case
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
} 

// Main function
int main() {
    int N;
    cout << "How many numbers? ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: Number of elements must be a positive integer." << endl;
        return 1; // Exit the program with an error code
    }

    int numbers[100]; // Assuming a maximum of 100 numbers for simplicity

    for (int i = 0; i < N; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = calculateSum(numbers, N);
    double average = calculateAverage(numbers, N);
    int maxVal = findMaximum(numbers, N);
    int minVal = findMinimum(numbers, N);

    cout << "\nResults:\n";
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}
