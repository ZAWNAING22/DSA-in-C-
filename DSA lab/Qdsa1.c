// // 1- Write a function that adds all odd numbers to the beginning of 
// //the list and all even 
// // numbers to the end of the list until -1 is entered from the keyboard.


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void add(struct node **head, int num) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        if (num % 2 == 0) {
            temp->next = *head;
            *head = temp;
        } else {
            struct node *last = *head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
        }
    }
}

int main() {
    struct node *head = NULL;
    int n;

    printf("Enter integer numbers (-1 to exit):\n");
    while (1) {
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        add(&head, n);
    }

    while (head != NULL) {
        printf(" %d \n", head->data);
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
