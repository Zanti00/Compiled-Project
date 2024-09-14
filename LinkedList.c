#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

struct node {
    int x;
    struct node *next;
    struct node *prev;
};

struct node *head, *curr, *tail, *current, *temp, *newNode;

char choice;

char mainMenu();
void createList();
void displayList();
void insertNumber();
void deleteNumber();
void searchNumber();

int main(){

    do{
        mainMenu();
    }while(toupper(choice) != 'F');
    
    return 0;
}

char mainMenu(){

    printf("\t\tMAIN MENU\n\nA. Create a Linear Linked List\nB. Display a Linear Linked List\nC. Insert a number in the Linear Linked List\nD. Delete a number from the Linear Linked List\nE. Search a number\nF. Exit\n\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    choice = toupper(choice);
    switch(choice){
        case 'A': createList(); break;
        case 'B': displayList(); break;
        case 'C': insertNumber(); break;
        case 'D': deleteNumber(); break;
        case 'E': searchNumber(); break;
        case 'F': printf("\nExiting program. Thank you for using!\n"); return choice;
        default: printf("\nInvalid option! Please select between provided options\n"); return 0;
    }
    return choice;
}
void createList(){

    head = curr = tail = NULL;

    curr = (struct node*)malloc(sizeof(struct node));

    printf("Enter an integer value (press 0 for exit): ");
    scanf("%d", &curr->x);

    while(curr->x != 0){
        if(head == NULL){
            head = curr;
            head->prev = NULL;
            head->next = NULL;
            tail = curr;
        }
        else{
            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;
            tail = curr;
        }
        curr = (struct node*)malloc(sizeof(struct node));

        printf("Enter an integer value (press 0 for exit): ");
        scanf("%d", &curr->x);
    }

    if(head == NULL){
        printf("\nNo data was entered!\n");
    }

    int tempValue;
    current = head;
    // sort the list using Ballon sorting technique
    while(current != NULL){
        temp = current->next;
        while(temp != NULL){
            if(current->x > temp->x){
                tempValue = current->x;
                current->x = temp->x;
                temp->x = tempValue;
            }
            temp = temp->next;
        }
        current = current->next;
    }

    mainMenu();
}
void displayList(){
    
    curr = head;
    while(curr != NULL){
        printf("%3d", curr->x);
        curr = curr->next;
    }

    mainMenu();
}
void insertNumber(){

    do{
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter an integer value (press 0 for exit): ");
        scanf("%d", &newNode->x);

        if(newNode->x != 0) {
            if (head == NULL) {
                head = tail = newNode;
                newNode->next = NULL;
                newNode->prev = NULL;
            } else if (newNode->x <= head->x) { // prompts if user inputted a less number or equal than the head's value
                newNode->next = head;
                newNode->prev = NULL;
                head->prev = newNode;
                head = newNode;
            } else if (newNode->x >= tail->x) { // prompts if user inputted a greater number or equal than the tail's value
                newNode->next = NULL;
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            } else { // prompts if user inputted a equal number it will be put beside its equal number
                struct node *temp = head;
                while (temp != NULL && temp->x < newNode->x) {
                    temp = temp->next;
                }
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
        else{
            free(newNode);
        }
        do{
            printf("\nDo you want to insert another number (Y/N)? ");
            scanf(" %c", &choice);
        }while(toupper(choice) != 'Y' && toupper(choice) != 'N');
    
    }while(toupper(choice) != 'N');

    mainMenu();
}
void deleteNumber(){
    int num, counter;

    do{
    printf("Enter number number to delete: ");
    scanf("%d", &num);

    temp = head;
        while (temp != NULL) {
            if (temp->x == num) {
                // If the node to be deleted is the head node
                if (temp == head) {
                    head = temp->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    } else {
                        tail = NULL; // List becomes empty
                    }
                }
                // If the node to be deleted is the tail node
                else if (temp == tail) {
                    tail = temp->prev;
                    if (tail != NULL) {
                        tail->next = NULL;
                    } else {
                        head = NULL; // List becomes empty
                    }
                }
                // If the node to be deleted is in the middle
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                struct node* nodeToDelete = temp;

                temp = temp->next;

                free(nodeToDelete);
            } else {
                temp = temp->next;
            }
        }
        do{
            printf("Delete another (Y/N)? ");
            scanf(" %c", &choice);
        }while(toupper(choice) != 'Y' && toupper(choice) != 'N');
    }while(toupper(choice) != 'N');
    mainMenu();
}
void searchNumber(){

    int num;
    do{
        char checker = false;
        printf("Enter number to search: ");
        scanf("%d", &num);

        temp = head;

        while(temp != NULL){
            if(num == temp->x){
                checker = true;
            }
            temp = temp->next;
        }

        if(checker){
            printf("\n%d is in the list\n", num);
        }
        else{
            printf("\n%d is not in the list\n", num);
        }

        do{
            printf("Do you want to search another number (Y/N)? ");
            scanf(" %c", &choice);
        }while(toupper(choice) != 'Y' && toupper(choice) != 'N');
    }while(toupper(choice) != 'N');
}

