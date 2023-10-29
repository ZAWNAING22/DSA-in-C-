// Write a function that stores the student number, name and age, traverses all the nodes in 
// the list, writes all the student information on the screen and counts it. 
// The output should look like this on the screen:
//  1- Saliha 27 201 
// 2- Ece 19 203
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to insert a student record at the beginning of the list
void insertStudent(struct Student** head, int number, const char* studentName, int studentAge) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->studentNumber = number;
    snprintf(newStudent->name, sizeof(newStudent->name), "%s", studentName);
    newStudent->age = studentAge;
    newStudent->next = *head;
    *head = newStudent;
}

// Function to print student information and count students
void printStudents(struct Student* head) {
    int studentCount = 0;

    while (head != NULL) {
        studentCount++;
        printf("%d- %s %d %d\n", studentCount, head->name, head->age, head->studentNumber);
        head = head->next;
    }

    printf("Total students: %d\n", studentCount);
}

int main() {
    struct Student* studentList = NULL;

    // Insert student records into the list
    insertStudent(&studentList, 201, "Saliha", 27);
    insertStudent(&studentList, 203, "Ece", 19);

    // Print student information and count students
    printStudents(studentList);

    

    return 0;
}
