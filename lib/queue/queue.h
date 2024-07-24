#ifndef QUEUE_H
#define QUEUE_H

// Node for the queue
typedef struct QueueNode {
    int value; // Value associated with the key
    struct QueueNode *next; // Pointer to the next node in the bucket
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode *head; // Head of the queue
    int size; // Number of elements in the queue
} Queue;

// Function to create a new queue
// @return Pointer to the newly created queue
Queue* createQueue();

// Function to delete a queue
// @param table The queue to delete
void deleteQueue(Queue *s);

// Function to insert value onto the top of the queue
// @param table The queue
// @param value The value to insert
void queueEnqueue(Queue *s, int value);

// Function to remove a value from the queue
// @param queue
// @return The value on the top of the queue
int queueDequeue(Queue *s);

// Function to peak at the top value of the queue
// @param queue
// @return The value on the top of the queue
int queuePeak(Queue *s);

// Function to retrieve a size of the queue
// @param queue
// @return The size of the queue
int queueSize(Queue *s);

#endif // QUEUE_H