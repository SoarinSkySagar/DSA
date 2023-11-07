#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to push (insert) an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop (delete) an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1; // Return an invalid value to indicate an empty stack
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("%d popped from the stack.\n", data);
    return data;
}

// Function to print the elements of the stack
void printStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);
    int choice, data, count, elementsProvided = 0;

    printf("Enter the number of elements to display in the stack: ");
    scanf("%d", &count);

    printf("Enter elements for the default stack:\n");
    while (elementsProvided < count) {
        scanf("%d", &data);
        push(&stack, data);
        elementsProvided++;
    }

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                printStack(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
