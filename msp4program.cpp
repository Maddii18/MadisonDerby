#include <iostream>
#include <algorithm>

// Constants for the number of components
const int NUM_MSP = 4;
const int NUM_QUIZZES = 4;

// Structure to store student information
struct Student {
    int msp[NUM_MSP];
    int labCourse;
    int midtermExam;
    int finalExam;
    int quizzes[NUM_QUIZZES];
    int bonusPoints;
    char finalGrade;
};

// Function declarations
void readGrades(Student& student);
void calculateFinalGrade(Student& student);
void printFinalGrade(const Student& student);

int main() {
    Student student;

    // Read grades from the user
    readGrades(student);

    // Calculate the final grade
    calculateFinalGrade(student);

    // Print the final grade
    printFinalGrade(student);

    return 0;
}

// Function to read grades from the user
void readGrades(Student& student) {
    printf("Enter grades for MSP 1 to MSP 4: ");
    for (int i = 0; i < NUM_MSP; ++i) {
        scanf("%d", &student.msp[i]);
    }

    printf("Enter grade for Lab Course: ");
    scanf("%d", &student.labCourse);

    printf("Enter grade for Midterm Exam: ");
    scanf("%d", &student.midtermExam);

    printf("Enter grade for Final Exam: ");
    scanf("%d", &student.finalExam);

    printf("Enter grades for Quizzes 1 to 4: ");
    for (int i = 0; i < NUM_QUIZZES; ++i) {
        scanf("%d", &student.quizzes[i]);
    }

    printf("Enter bonus points: ");
    scanf("%d", &student.bonusPoints);
}

// Function to calculate the final grade
void calculateFinalGrade(Student& student) {
    // Drop the lowest MSP grade
    int minMsp = *std::min_element(student.msp, student.msp + NUM_MSP);
    int sumMSP = 0;
    for (int i = 0; i < NUM_MSP; ++i) {
        if (student.msp[i] != minMsp) {
            sumMSP += student.msp[i];
        }
    }

    // Drop the lowest quiz grade
    int minQuiz = *std::min_element(student.quizzes, student.quizzes + NUM_QUIZZES);
    int sumQuizzes = 0;
    for (int i = 0; i < NUM_QUIZZES; ++i) {
        if (student.quizzes[i] != minQuiz) {
            sumQuizzes += student.quizzes[i];
        }
    }

    // Calculate the total points for both components
    double workComponent = static_cast<double>(sumMSP + student.labCourse + student.bonusPoints) / (NUM_MSP + 2);
    double recallComponent = static_cast<double>(sumQuizzes + student.midtermExam + student.finalExam) / (NUM_QUIZZES + 2);

    // Determine the greater component and assign weights accordingly
    double finalGrade;
    if (workComponent >= recallComponent) {
        finalGrade = 0.6 * workComponent + 0.4 * recallComponent;
    } else {
        finalGrade = 0.4 * workComponent + 0.6 * recallComponent;
    }

    // Assign letter grade based on University guidelines
    if (finalGrade >= 90) {
        student.finalGrade = 'A';
    } else if (finalGrade >= 80) {
        student.finalGrade = 'B';
    } else if (finalGrade >= 70) {
        student.finalGrade = 'C';
    } else if (finalGrade >= 60) {
        student.finalGrade = 'D';
    } else {
        student.finalGrade = 'F';
    }
}

// Function to print the final grade
void printFinalGrade(const Student& student) {
    printf("Final Grade: %c\n", student.finalGrade);
}
