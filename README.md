# Cpts122-PA4
Washington State University Computer Science 122- Programming Assignment 4: Grocery Store Simulator
Assigned: Monday, February 13, 2017
Due: Wednesday, February 22, 2017 by midnight
 
I. Learner Objectives:
 
At the conclusion of this programming assignment, participants should be able to:
*       Design and implement a dynamic queue
*       Allocate and de-allocate memory at runtime
*       Manipulate links in a dynamic queue
*       Insert items into a dynamic queue
*       Delete items from a dynamic queue
*       Traverse a dynamic queue
 
II. Prerequisites:
 
Before starting this programming assignment, participants should be able to:
*       Analyze a basic set of requirements for a problem
*       Compose C language programs
*       Create basic test cases for a program
*       Apply arrays, strings, and pointers
*       Summarize differences between array notation and pointer notation
*       Apply pointer arithmetic
*       Apply basic string handling library functions
*       Define and implement structures in C
*       Summarize the operations of a linked list
*       Describe the operations  of a queue including: enqueue ( ), dequeue ( ), printQueue ( )
 
III. Overview & Requirements:
 
Note: parts of this assignment were inspired by Deitel and Deitel’s Supermarket Simulation problem. We’ve all had the pleasant experience of standing in line at the grocery store. As I’m standing in line I’m always trying to figure out if I chose the line with the fastest service. In most cases, I fail miserably. Let’s write a program to simulate two lines in a grocery store, which will allow us to better understand how to select the fastest line.
 
For this assignment you will need to simulate two lines using queues. This will require that you develop enqueue ( ) (insert), dequeue ( ) (delete), and printQueue ( ) operations for a queue. Although you will instantiate two queues, each one of these will consist of the same kind of queue nodes. Define a queue node in the following manner:
 
typedef struct queueNode
{
     int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
     int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
     int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
 
     struct queueNode *pNext;
} QueueNode;
 
You must also define a queue in the following manner:
 
typedef struct queue
{
     QueueNode *pHead;
     QueueNode *pTail;
} Queue;
 
One of your queues will represent the express lane and the other a normal lane. You will randomly generate arrival times and service times of customers into each lane. The express lane has customers arrive every one to five minutes, and customers arrive every three to eight minutes in the normal lane. Service times vary from one to five minutes, and three to eight minutes, for express and normal lane customers, respectively. As customers arrive into each line print out a message indicating in which line each customer arrives, along with the overall corresponding arrival time and customer number. When customers have finished checking out, print out a message indicating which line the customer was in, along the corresponding customer number and totalTime in the line. Allow for the simulation to run for n number of minutes, where n is inputted by the user.
 
The general program flow is as follows:
Generate a random number between 1 – 5 and 3 – 8 for express and normal lanes, respectively. This represents the arrival time of the first customer into each lane. Set the variable for total time elapsed to 0.
As customers arrive into each line, randomly generate a service time for each. Start processing the customers in the lanes based on service time. Randomly generate the arrival time of the next customer into each line. Elapsed time should be updated by one unit.
As each minute elapses, a new customer may arrive and/or another customer may be done checking out. Display the appropriate messages as described above.
For every 10 minutes, print out the entire queue for each line
Repeat steps 2 through 4 for n minutes of simulation.
 
Hints: since this is a simulation one minute is really one unit of time. Thus, the incrementing of an integer variable could represent one minute of time elapsing.
 
BONUS:
 
Modify QueueNode such that it contains a pointer to the start of a dynamic singly linked list. The linked list will consist of grocery items corresponding to one person. These items should be strings like “cereal”, “milk”, “steak”, etc. Adjust the serviceTime of the QueueNode so that it is no longer random, but proportional to the number of items for the person served.
 
IV. Submitting Assignments:
 
Using the OSBLE+ MS VS plugin, please submit your solution. Please visit http://osble.codeplex.com/wikipage?title=Submitting%20an%20Assignment&referringTitle=VS%20Plugin for more information about submitting using OSBLE+.
Your project must contain at least one header file (a .h file) and two C source files (which must be .c files.
Your project must build properly. The most points an assignment can receive if it does not build properly is 65 out of 100.
 
V. Grading Guidelines:
 
This assignment is worth 100 points. Your assignment will be evaluated based on a successful compilation and adherence to the program requirements. We will grade according to the following criteria:
 
*       10 pts – Appropriate top-down design, style, and commenting according to class standards
*       25 pts – Correct usages of two queues in simulation
*       5 pts – Correct QueueNode definition
*       5 pts – Correct Queue definition
*       10 pts – Correct makeNode()
*       10 pts – Correct printQueue()
*       5 pts – Correct isEmpty()
*       15 pts – Correct enqueue()
*       15 pts – Correct dequeue()
 
*       BONUS: Up to 20 pts for implementation of grocery item list/customer
