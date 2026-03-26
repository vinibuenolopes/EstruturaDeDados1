#include "fila.h"

Queue* create (int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = 0;
  q->back = 0;
  q->size = size;
  q->array = (int *)malloc(size*sizeof(int));
  return q;
}

void destroy (Queue *q) {
  free (q->array);  
  free (q);
}

int empty (Queue *q) {
  return (q->front == q->back);
}

int full (Queue *q) {
  return (((q->back + 1) % q->size) == q->front);
}

void enqueue (int e, Queue *q) {
  if (full(q)) {
     printf("queue overflow\n");
     exit(1);
  }	  
  q->array[q->back] = e;
  q->back = (q->back + 1) % q->size;
}

int dequeue (Queue *q) {
  if (empty(q)) {
    printf("queue underflow\n");
    exit(1); 
  }	  
  int e = q->array[q->front];
  q->front = (q->front + 1) % q->size;
  return e;
}

void print (Queue *q) {
  int i;	
  printf("Queue: ");
  for (i = q->front; i != q->back; i=(i+1)%q->size) {
    printf("%d ", q->array[i]);
  }
  printf("\n");
}

