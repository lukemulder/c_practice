#include "stack.h"
#include <stdlib.h>

Stack* createStack()
{
  Stack* s = (Stack*)malloc(sizeof(Stack));

  s->head = NULL;
  s->size = 0;

  return s;
}

void deleteStack(Stack *s)
{
  StackNode* curr_node;
  StackNode* next_node;

  curr_node = s->head;

  while(curr_node != NULL)
  {
    next_node = curr_node->next;
    free(curr_node);

    curr_node = next_node;
  }

  free(s);
}

void stackPush(Stack *s, int value)
{
  if(s == NULL) { return; }

  StackNode* n = malloc(sizeof(StackNode));

  if(n == NULL) { return; }

  n->next = s->head;
  n->value = value;

  s->head = n;
  s->size++;
}

int stackPop(Stack *s)
{
  if(s == NULL || s->head == NULL) { return INT32_MAX; }

  StackNode* temp;
  int r;

  temp = s->head;
  r = temp->value;

  s->head = s->head->next;
  s->size--;

  free(temp);

  return r;
}

int stackPeak(Stack *s)
{
  if(s == NULL) { return INT32_MAX; }

  return s->head->value;
}

int stackSize(Stack *s)
{
  if(s == NULL) { return 0; }
  
  return s->size;
}