#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1; // Return an error value
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    
    free(temp);
    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data, numDefaultElements;
    
    printf("Enter the number of default elements: ");
    scanf("%d", &numDefaultElements);
    
    for (int i = 0; i < numDefaultElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        enqueue(queue, data);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
