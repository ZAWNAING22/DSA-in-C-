// - Write the function that deletes the next node from the node with the searched student 
// name in the list
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

// Function to delete the next node from a node with a matching name
void deleteNextStudent(struct Student* head, const char* searchName) {
    while (head != NULL && head->next != NULL) {
        if (strcmp(head->name, searchName) == 0) {
            struct Student* temp = head->next;
            head->next = temp->next;
            free(temp); // Free the memory of the deleted node
            return;
        }
        head = head->next;
    }
}

// Function to print student information
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

    // Insert student records into the list (same as before)
    insertStudent(&studentList, 201, "Saliha", 27);
    insertStudent(&studentList, 203, "Ece", 19);
    insertStudent(&studentList, 204, "Saliha", 21);

    // Delete the next student record for students with the name 'Saliha'
    deleteNextStudent(studentList, "Saliha");

    // Print student information after deletion
    printStudents(studentList);

   

    return 0;
}
