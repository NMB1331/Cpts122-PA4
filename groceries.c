#include "groceries.h"

//Function that adds a node to the queueNode
void enqueue(struct queue *line, struct queueNode *new_node)
{
  if (line->head == NULL)
  {
    line->head = new_node;
    line->tail = new_node;
    new_node->next = NULL;
    //printf("Item made head of list\n"); //Debugging
  }
  else
  {
    line->tail->next = new_node;
    line->tail = new_node;
    new_node->next = NULL;
    //printf("Item inserted at end of queue\n"); //Debugging
  }
}

//Function that removes the first node from the queue
void dequeue(struct queue *line)
{
  if (line->tail == line->head)
  {
    struct queueNode *temp = line->head;
    line->head = NULL;
    line->tail = NULL;
    free(temp);
    //printf("Emptied the list!\n");
  }
  else
  {
    struct queueNode *temp = line->head;
    line->head = line->head->next;
    free(temp);
    //printf("Removed node from front of the queue!\n");
  }
}

//Function that prints a queue
void print_queue(struct queue *line)
{
  if (line->head == NULL)
  {
    printf("EMPTY LINE\n");
    return;
  }
  struct queueNode *current = line->head;
  printf("FRONT ->\n");
  while(current != NULL)
  {
    printf("  Customer number: %d\n", current->customer_number);
    printf("  Service time: %d\n", current->service_time);
    printf("  Total time: %d\n\n", current->total_time);

    current = current->next;
  }
}

//Function that randomly generates a new customer_number
struct queueNode *generate_random_customer(int *cust_number)
{
  struct queueNode *new_node = malloc(sizeof(struct queueNode));
  if (new_node != NULL)
  {
    new_node->customer_number = *cust_number;
    new_node->service_time = rand() % 10 + 2;
    //new_node->total_time = current_service_time;

    (*cust_number)++;
    return new_node;
  }
  else
  {
    printf("Malloc failed\n");
    return NULL;
  }

}

//Function that waits for a certain number of seconds
//Courtesy of http://stackoverflow.com/questions/3930363/implement-time-delay-in-c
void waitFor(unsigned int seconds)
{
  unsigned int retTime = time(0) + seconds;   // Get finishing time.
  while (time(0) < retTime);               // Loop until it arrives.
}
