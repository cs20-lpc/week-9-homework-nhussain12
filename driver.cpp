#include "QueueFactory.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

int main() {

    // Simulation #1: Ticket Counter Implementation
    /**********************************************************************************************
     * A small ticket counter can serve only a limited number of customers at a time. Customers 
     * arrive randomly and form a waiting line. If the line is already full, newly arriving 
     * customers cannot join and must leave. The counter serves one customer at a time. Implement 
     * the waiting line using a queue data structure. The maximum number of customers that can wait 
     * in line is 10. When the queue is full, new arrivals are turned away.
     * 
     * To simulate the arrival and service process: 
     * Generate a random number between -1 and 1 a total of 100 times. If the number is negative, 
     * remove (dequeue) one element from the queue to represent a customer being served and leaving. 
     * If the number is 0 or positive, add (enqueue) a new customer to the queue to represent a new 
     * arrival. The actual values stored in the queue are not important.
     * *******************************************************************************************/

     // Create queue to represent the ticket counter's line
     Queue<int> * counterLine = QueueFactory<int>::GetQueue(10);

     // Seed random number generator
     srand(time(0));

     // Establish min/max values for random number generator
     int min_val = -1;
     int max_val = 1;
     
     // Tracks the # of new arrivals (created by random number generator)
     int arrivals = 0; 

     // Create a loop that will simulate the arrival and service process
     while (arrivals < 100) {
        int customer = (rand() % (max_val - min_val + 1)) + min_val;
        arrivals++;

        if (customer >= 0) {
            if (counterLine->getLength() >= 10) {
                cout << "The line for the ticket counter is full, please come back at a later time." << endl;
            } else {
                counterLine->enqueue(customer);
                cout << "A new customer has joined the line!" << endl;
            }
        } else {
            if (counterLine->isEmpty()) {
                cout << "No customers in line!" << endl;
            } else {
                counterLine->dequeue();
                cout << "A customer has been served and is now leaving!" << endl;
            }
        }
     }

    // Simulation #2: Bank Service Line Implementation
    /**********************************************************************************************
     * A busy bank serves customers who arrive randomly throughout the day. Each customer joins 
     * the end of the line when they arrive, and the line can grow dynamically as needed. There is 
     * no fixed maximum size for the waiting line. Implement the waiting line using a queue data 
     * structure.
     * 
     * To simulate customer arrivals and departures:
     * Generate a random number between -1 and 2 a total of 100 times. If the number is negative, 
     * remove (dequeue) one element from the queue to represent a customer finishing service. If 
     * the number is 0 or positive, add (enqueue) a new customer to the queue to represent an 
     * arrival. The actual values added to the queue are not important.
     * *******************************************************************************************/

     // Create queue to represent the bank's line
     Queue<int> * bankLine = QueueFactory<int>::GetQueue();

     // Establish min/max values for random number generator
     int min_val2 = -1;
     int max_val2 = 2;
     
     // Tracks the # of new arrivals (created by random number generator)
     int bank_arrivals = 0; 

     // Create a loop that will simulate the arrival and service process
     while (bank_arrivals < 100) {
        int bank_customer = (rand() % (max_val2 - min_val2 + 1)) + min_val2;
        bank_arrivals++;

        if (bank_customer >= 0) {
            bankLine->enqueue(bank_customer);
            cout << "A new customer has joined the bank line!" << endl;
        } else {
            if (bankLine->isEmpty()) {
                cout << "No bank customers in line!" << endl;
            } else {
                bankLine->dequeue();
                cout << "A bank customer has been served and is now leaving!" << endl;
            }
        }
     }

    return 0;
}
