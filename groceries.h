#ifndef GROCERY
#define GROCERY

#define REG_LINE 1
#define EXP_LINE 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct queueNode
{
  int customer_number;
  int service_time;
  int total_time;
  struct queueNode *next;

}QueueNode;

typedef struct queue
{
  struct queueNode *head;
  struct queueNode *tail;

}Queue;

//Function that prints directions
void print_instructions(void);

//Function that adds a node to the queueNode
void enqueue(struct queue *line, struct queueNode *new_node);

//Function that removes the first node from the queue
void dequeue(struct queue *line);

//Function that prints a queue
void print_queue(struct queue *line, struct queue *line2);

//Function that simulates a person entering a line
void add_to_line(struct queue *line, int *customer_number);

//Function that randomly generates a new customer_number
//Line type 1 for regular, 2 for express
struct queueNode *generate_random_customer(int *cust_number, int line_type);

//Function that waits for a certain number of seconds
//Courtesy of http://stackoverflow.com/questions/3930363/implement-time-delay-in-c
void waitFor(unsigned int seconds);


#endif
