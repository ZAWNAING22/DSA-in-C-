// - Write the function that prints the record with the longest name in the list. 
// Output : the longest name in the list: Abdurrahmangazi 
// Length : 15
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

// Function to find and print the record with the longest name
void printLongestName(struct Student* head) {
    char longestName[50] = "";
    int longestNameLength = 0;

    while (head != NULL) {
        int nameLength = strlen(head->name);
        if (nameLength > longestNameLength) {
            longestNameLength = nameLength;
            snprintf(longestName, sizeof(longestName), "%s", head->name);
        }
        head = head->next;
    }

    if (longestNameLength > 0) {
        printf("The longest name in the list: %s\n", longestName);
        printf("Length: %d\n", longestNameLength);
    } else {
        printf("No student records in the list.\n");
    }
}

int main() {
    struct Student* studentList = NULL;

    // Insert student records into the list (same as before)
    insertStudent(&studentList, 201, "Saliha", 27);
    insertStudent(&studentList, 203, "Ece", 19);
    insertStudent(&studentList, 204, "Abdurrahmangazi", 21);

    // Print the record with the longest name
    printLongestName(studentList);

    
    return 0;
}
