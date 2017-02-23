#include "groceries.h"
#include "groceries.c"

int main(void)
{
  //Time seeded for rand(), variables initialized
  //printf("Pointless grocery simulator. Thanks, college\n");
  srand((unsigned int) (time NULL));
  Queue regular_line, express_line;
  Queue *reg_head = &regular_line, *exp_head = &express_line;
  int customer_number = 1;
  int loop_counter = 0, sim_time = 0;
  int time_till_next_reg = 0, time_till_next_exp = 0, reg_diff = 0, exp_diff = 0;

  //Prints the directions
  print_instructions();

  //Gets the time that the simulation should last
  do
  {
    printf("Enter how long the simulation should last (I recommend 100) ");
    scanf(" %d", &sim_time);
  } while(sim_time <= 0);


  //MAIN SIMULATION BODY
  //Every loop is one time unit (second in actual time)
  while(loop_counter < sim_time)
  {
    printf("TIME: %d\n\n", loop_counter);
      //Adds customers to the line, after the randon time (above)
    if (time_till_next_reg <= 0)
    {
      enqueue(reg_head, generate_random_customer(&customer_number, REG_LINE));
    }
    if (time_till_next_exp <= 0)
    {
      enqueue(exp_head, generate_random_customer(&customer_number, EXP_LINE));
    }

    //Generates the times until the next customer
    if (time_till_next_reg <= 0)
    {
      time_till_next_reg = rand() % 5 + 3;
    }
    if (time_till_next_exp <= 0)
    {
      time_till_next_exp = rand() % 5 + 3;
    }

    //Displays the lines (only regular for now, because I'm fucking lazy)
    print_queue(reg_head, exp_head);

    //Services the person in front, pops them when they're done
    if (regular_line.head != NULL && regular_line.head->service_time == 0)
    {
      dequeue(reg_head);
    }
    if (express_line.head != NULL && express_line.head->service_time == 0)
    {
      dequeue(exp_head);
    }

    //Updates times for the next loop through
    loop_counter++;
    time_till_next_exp--;
    time_till_next_reg--;
    if (regular_line.head != NULL)
    {
      regular_line.head->service_time--;
    }
    if (express_line.head != NULL)
    {
      express_line.head->service_time--;
    }

    //Updates total time spent in line for every customer
    QueueNode *current = reg_head->head;
    while(current != NULL)
    {
      current->total_time += 1;
      current = current->next;
    }
    current = exp_head->head;
    while(current != NULL)
    {
      current->total_time += 1;
      current = current->next;
    }

    waitFor(1);
    system("clear");
  }

  return 0;
}
