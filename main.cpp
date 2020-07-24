// main.cpp
// class FastQueue's driver file

#include "FastQueue.h"
#include <string>

using namespace std;

int main() {

    cout << "\n Enter initial FastQueue capaciy:\n> ";
    size_t initial_capacity = 0;
    cin >> initial_capacity;

    string status_messages;
    do {
        cout << "\n Enable printing of status/debug messages? (type yes or no):\n> ";
        cin >> status_messages;
    } while (status_messages != "yes" && status_messages != "no");

    bool status_flag = false;

    if (status_messages == "yes")
        status_flag = true;


    // ********* class FastQueue Testing *********

    // Delare int FastQueue
    FastQueue<int> fQueue(initial_capacity, status_flag);

     cout << "\n Running class FastQueue functionality tests....\n";

    // Enqueue 5 elements
    cout << "\n Enqueueing 5,6,92,32,73 ...";
    fQueue.enqueue(5);
    fQueue.enqueue(6);
    fQueue.enqueue(92);
    fQueue.enqueue(32);
    fQueue.enqueue(73);

    // Show current queue
    fQueue.printInternalVector();

    // Try to dequeue
    try {
        cout << "\n\t Dequeing ... " << fQueue.dequeue()
             << "\n\t Dequeing ... " << fQueue.dequeue()
             << endl;
    }

    // Use catch block to catch possible exception
    catch (out_of_range& excep) {

        // Show exception (error) message
        cout << excep.what();
    }

    cout << "\n Testing FastQueue::front() and FastQueue::back() functions...\n";
    // Try to display front() and back() elements
    try {
        cout <<"\n Front element after 2 dequeues: " << fQueue.front() << endl;
        cout <<"\n Current Rear element: " << fQueue.back() << endl;

        cout << "\n Enqueueing 82 ...";
        fQueue.enqueue(82);
        cout <<"\n New Rear element after enqueue: " << fQueue.back() << endl;
    }

    // Catch possible exceptions
    catch (out_of_range& excep) {

        // Show exception (error) message
        cout << excep.what();
    }

    cout << "\n Testing FastQueue::at() function...\n";
    // Try to display elements at index 2 and 3
    try {
        cout <<"\n Element at index 2: " << fQueue.at(2) << endl;
        cout <<"\n Element at index 3: " << fQueue.at(3) << endl;
    }

        // Catch possible exceptions
    catch (out_of_range& excep) {

        // Show exception (error) message
        cout << excep.what();
    }

    cout << "\n Testing FastQueue::shrink_to_fit() ...";
    cout << "\n Queue size and capacity before shrink_to_fit(): "
         <<"\n " << fQueue.size() << "\t"<<fQueue.capacity();

    // Shrink internal vector to fit number of elements (+2 for stability)
    fQueue.shrink_to_fit();

    cout << "\n Queue size and capacity after shrink_to_fit(): "
         <<"\n " << fQueue.size() << "\t"<<fQueue.capacity();

    // Enqueue again after shrink_to_fit

    cout << "\n Enqueueing 7,9 ...";
    fQueue.enqueue(7);
    fQueue.enqueue(9);

    // Shrink again
    cout <<"\n Running shrink_to_fit() again ...";
    fQueue.shrink_to_fit();

    // Show final results
    cout << "\n Printing queue (through dequeing): \n";

    // Show results
    while (!fQueue.fastQueueIsEmpty()) {
        int de = fQueue.dequeue();
        cout << "\t"<< de;
    }

    cout << "\n Testing if FastQueue is now empty: " << (fQueue.fastQueueIsEmpty() ? "Queue is empty" : "Queue not empty") << endl;

    // Enqueue 5 elements
    cout << "\n Enqueueing 43,993,882,45,83 ...";
    fQueue.enqueue(43);
    fQueue.enqueue(993);
    fQueue.enqueue(882);
    fQueue.enqueue(45);
    fQueue.enqueue(93);

    cout << "\n Current Queue (after running shrink_to_fit(), then dequeing completely,"
            "\n and then enqueing 5 more elements to test shrink_to_fit():\n";
    // Show results
    while (!fQueue.fastQueueIsEmpty()) {
        int de = fQueue.dequeue();
        cout << "\t"<< de;
    }


    cout << "\n\n ******* ALL TESTS PASSED *******";

    cout << "\n";

    // Debugging purposes
    // fQueue.printInternalVector();

    return 0;
}