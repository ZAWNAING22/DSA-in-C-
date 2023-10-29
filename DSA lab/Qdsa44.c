// 5- Write the function that searches records by student name in the list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to insert a student record at the beginning of the list (same as before)
void insertStudent(struct Student** head, int number, const char* studentName, int studentAge) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->studentNumber = number;
    snprintf(newStudent->name, sizeof(newStudent->name), "%s", studentName);
    newStudent->age = studentAge;
    newStudent->next = *head;
    *head = newStudent;
}

// Function to search and print student records by name
void searchStudentByName(struct Student* head, const char* searchName) {
    int studentCount = 0;

    while (head != NULL) {
        if (strcmp(head->name, searchName) == 0) {
            studentCount++;
            printf("%d- %s %d %d\n", studentCount, head->name, head->age, head->studentNumber);
        }
        head = head->next;
    }

    if (studentCount == 0) {
        printf("No student found with the name: %s\n", searchName);
    }
}

int main() {
    struct Student* studentList = NULL;

    // Insert student records into the list (same as before)
    insertStudent(&studentList, 201, "Saliha", 27);
    insertStudent(&studentList, 203, "Ece", 19);
    insertStudent(&studentList, 204, "Saliha", 21); // Add another student with the same name

    // Search and print student records by name
    printf("Students with the name 'Saliha':\n");
    searchStudentByName(studentList, "Saliha");

    // Free memory (not shown here, but you should free the allocated memory for nodes when done)

    return 0;
}
