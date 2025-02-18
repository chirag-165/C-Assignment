#include <stdio.h>

void calcTotalAndAvg(int ascore[], int examScores[], int numA, int numExams);
void displayResults(int ascore[], int examScores[], int numA, int numExams, int total, float avg);

int main() {
    char *assign[] = {"Assignment 1", "Assignment 2"};
    char *exams[] = {"Exam 1"};
    int ascore[] = {80, 90};
    int examScores[] = {85};
    int numA = 2;
    int numExams = 1;

    calcTotalAndAvg(ascore, examScores, numA, numExams);

    return 0;
}

void calcTotalAndAvg(int ascore[], int examScores[], int numA, int numExams) {
    int total = 0;
    float avg = 0.0;
    int totalItems = numA + numExams;

    for (int i = 0; i < numA; i++) {
        total += ascore[i];
    }

    for (int i = 0; i < numExams; i++) {
        total += examScores[i];
    }

    avg = (float)total / totalItems;

    displayResults(ascore, examScores, numA, numExams, total, avg);
}

void displayResults(int ascore[], int examScores[], int numA, int numExams, int total, float avg) {
    printf("\nGradebook:\n");
    printf("-----------------------------\n");
    printf("Assignment/Exam     Score\n");

    for (int i = 0; i < numA; i++) {
        printf("Assignment %d      %d\n", i + 1, ascore[i]);
    }

    for (int i = 0; i < numExams; i++) {
        printf("Exam %d            %d\n", i + 1, examScores[i]);
    }

    printf("-----------------------------\n");
    printf("Total Score: %d\n", total);
    printf("Average: %.2f\n", avg);
}
