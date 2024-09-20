/* 
 * BankSimApp.cpp
 *
 * Description: main function for the Bank Simulation application program
 *              This application simulates the behavior of a bank by processing events
 *              using classes developed in Part 1, 2, and 3 of the assignment.
 *              It reads input from the command line by redirecting input using the < symbol,
 *              following the algorithm outlined in Section 13.4 of the Bank Simulation document.
 *
 * Author: Amirali Bavafa and Shayan Solgi
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"

using namespace std;

int main() {
    // Initialize data structures
    PriorityQueue<Event> eventQueue; // Priority queue for event processing
    Queue<Event> departureQueue; //Queue to store the departure events

    // Read event details from commandline
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int eventTime, eventLength;
        iss >> eventTime >> eventLength;

        // Create event object
        Event event('A', eventTime, eventLength);

        // Enqueue event into event queue
        eventQueue.enqueue(event);
    }

    // Run simulation loop
    int currentTime = 0;
    int totalWaitTime = 0;
    int totalCustomers = 0;
    int nextDeparture = eventQueue.peek().getTime() + eventQueue.peek().getLength(); // initialize the time of the first departure (only for the purpose of using in while loop)
    int departureTime = eventQueue.peek().getTime(); // the time that we add to the departure queu in order to print
    cout << "Simulation Begins" << endl;

    //going through arrivals
    while (!eventQueue.isEmpty()) {
        // Process all arrival events
        if(eventQueue.peek().getTime() <= nextDeparture) {
            Event currentEvent = eventQueue.peek();
            eventQueue.dequeue();
            cout << "Processing an arrival event at time: " << currentEvent.getTime() << endl;
            totalCustomers++;
            currentTime = currentEvent.getTime();


            // Calculate wait time
            int waitTime = departureTime - currentTime;
            totalWaitTime += waitTime;


            // Enqueue departure event
            departureTime += currentEvent.getLength();
            Event departureEvent('D', departureTime);
            departureQueue.enqueue(departureEvent);
        }

        // Process departure events if the arrival time is less than next departure ( the teller is not available )
        else if (!departureQueue.isEmpty() && eventQueue.peek().getTime() >= currentTime) {
            Event currentEvent = departureQueue.peek();
            departureQueue.dequeue();
            currentTime = currentEvent.getTime();
            cout << "Processing a departure event at time: " << currentEvent.getTime() << endl;

            //if the departure proccess is done set the next departure time for the future
            if (departureQueue.isEmpty()){
                nextDeparture = eventQueue.peek().getTime() + eventQueue.peek().getLength();
                departureTime = eventQueue.peek().getTime();
            }

            else{
                nextDeparture = departureQueue.peek().getTime();
            }
        } else {
            // If no departure events pending, move the time forward to the next arrival event
            if (!eventQueue.isEmpty()) {
                currentTime = eventQueue.peek().getTime();
            }
        }
    }


    // Proccessing through the remaining departures after all the arrivals are complete so the bank will be empty before closing!
    while (!departureQueue.isEmpty()){
        Event currentEvent = departureQueue.peek();
        departureQueue.dequeue();
        currentTime = currentEvent.getTime();
        cout << "Processing a departure event at time: " << currentEvent.getTime() << endl;
    }

    // Calculate average wait time
    double averageWaitTime =(totalWaitTime / static_cast<double>(totalCustomers));

    // Output final statistics
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << totalCustomers << endl;
    cout << "\tAverage amount of time spent waiting: " << averageWaitTime << endl <<endl;

    return 0;
}
