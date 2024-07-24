#include "queue.h"
#include <stdlib.h>

Queue* createQueue()
{
  Queue* q = (Queue*)malloc(sizeof(Queue));

  q->head = NULL;
  q->size = 0;

  return q;
}

void deleteQueue(Queue *q)
{
  if(q == NULL) { return; }

  QueueNode* curr_node;
  QueueNode* next_node;

  curr_node = q->head;

  while(curr_node != NULL)
  {
    next_node = curr_node->next;
    free(curr_node);

    curr_node = next_node;
  }

  free(q);
}

void queueEnqueue(Queue *q, int value)
{
  if(q == NULL) { return; }

  QueueNode* temp;
  QueueNode* n = malloc(sizeof(QueueNode));

  if(n == NULL) { return; }

  n->next = NULL;
  n->value = value;

  q->size++;

  if(q->head == NULL)
  {
    q->head = n;
    return;
  }

  temp = q->head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = n;
}

int queueDequeue(Queue *q)
{
  if(q == NULL || q->head == NULL) { return INT32_MAX; }

  QueueNode* temp;
  int r;

  temp = q->head;
  r = temp->value;

  q->head = q->head->next;
  q->size--;

  free(temp);

  return r;
}

int queuePeak(Queue *q)
{
  if(q == NULL || q->head == NULL) { return INT32_MAX; }

  return q->head->value;
}

int queueSize(Queue *q)
{
  if(q == NULL) { return 0; }

  return q->size;
}