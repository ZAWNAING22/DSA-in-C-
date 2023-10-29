// Add 100 randomly generated numbers to the list, write the c code that sorts all the 
// numbers entered from largest to smallest and prints them on the screen.
// 3- Output : 54->58->62->65->71->73->……102 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list in the specified format
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("...");
}

// Function to perform a bubble sort on the list in descending order
void bubbleSort(struct Node* head) {
    int swapped, temp;
    struct Node* current;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;
        while (current->next != NULL) {
            if (current->data < current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    struct Node* head = NULL;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Add 100 random numbers to the list
    for (int i = 0; i < 100; i++) {
        int randomNum = rand() % 100; // Generating random numbers between 0 and 99
        insertNode(&head, randomNum);
    }

    // Sort the list in descending order
    bubbleSort(head);

    // Print the sorted list in the specified format
    printList(head);

    // Free memory (not shown here, but you should free the allocated memory for nodes when done)

    return 0;
}
