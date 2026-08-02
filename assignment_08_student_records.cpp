// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Define the Student struct
struct Student {
    string name;                 // Student's full name
    int id;                      // Unique student ID number
    vector<double> scores;       // List of scores from multiple assessments
};

// Function prototypes
void addStudent(vector<Student>& students);     
void displayAllStudents(const vector<Student>& students);
void calculateAverageScore(const vector<Student>& students);

// Main function
int main() {
    vector<Student> students; // Vector to store student records
    bool running = true;

    while (running) {
        // Display the menu
        cout << "===============================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "===============================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageScore(students);
                break;
            case 4:
                running = false;
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Error: Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

// Function to add a student record
void addStudent(vector<Student>& students) {    
    Student newStudent;
    cout << "Student name: ";
    getline(cin, newStudent.name);
    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    newStudent.scores.resize(numScores);
    for (int i = 0; i < numScores; ++i) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> newStudent.scores[i];
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}

// Function to display all student records
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << left << setw(20) << "Name" 
         << setw(10) << "ID" 
         << setw(30) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << string(70, '-') << endl;

    for (const auto& student : students) {
        cout << left << setw(20) << student.name 
             << setw(10) << student.id;

        double sum = 0.0;
        for (double score : student.scores) {
            cout << score << " ";
            sum += score;
        }
        double average = student.scores.empty() ? 0.0 : sum / student.scores.size();
        cout << setw(10) << fixed << setprecision(2) << average << endl;
    }
}   

// Function to calculate and display the average score for a specific student
void calculateAverageScore(const vector<Student>& students) {
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (const auto& student : students) {
        if (student.id == searchId) {
            double sum = 0.0;
            for (double score : student.scores) {
                sum += score;
            }
            double average = student.scores.empty() ? 0.0 : sum / student.scores.size();
            cout << student.name << "'s average score: " << fixed << setprecision(2) << average << endl;
            return;
        }
    }

    cout << "Error: Student ID " << searchId << " not found.\n";
}
