
// FastQueue.h
// Template Class FastQueue definition file
// Created Jun 7, 6:40PM

// To prevent multiple includes of the same file
#ifndef FASTQUEUE_H
#define FASTQUEUE_H

// Header file includes
#include <iostream>
#include <vector>
#include <stdexcept>

// Class FastQueue
template<typename T>
class FastQueue {

/* Variable naming scheme: Class member variables are preceded with a small 'm' e.g. mSize,
 *                         and user input values are preceded with a small 'i' e.g. iValue
 *
 * DEBUG comments:        Start and end with / * * /
 */

// Declaring public member functions
public:

    // class FastQueue's constructor
    explicit FastQueue(size_t iCapacity = 2, bool iPrintStatus = false);

    // Method to enqueue a value into the FastQueue
    void enqueue(const T& iValue);

    // Method to dequeue a value from the FastQueue
    T dequeue();

    // Method to return reference to front of queue
    T &front();

    // Method to return reference to front of queue
    T &back();

    //  Method to return reference to value at some index of queue
    T &at(size_t iIndex);

    // Method to return size of queue
    size_t size();

    // Method to return capacity of queue
    size_t capacity();

    // Method to check if queue is Full
    bool fastQueueIsFull();

    // Method to check if queue is empty
    bool fastQueueIsEmpty();

    // Bruteforce print
    void printInternalVector();

    // Method to shrink internal memory buffer exactly to size
    void shrink_to_fit();

// Declaring private fields
private:
    std::vector<T> mQueue;
    size_t mSize;
    size_t mCapacity;
    size_t mFront;
    size_t mRear;
    bool mPrintStatus;

};

// Function implementations

/*  Class FastQueue's constructor
 * Takes in user input as a vector<T> Queue, and assigns values.
 * Also allocates a new object as default value.
 */
template<typename T>
FastQueue<T>::FastQueue(size_t iCapacity, bool iPrintStatus) {

    // If previous capacity was 0, make it 2
    if (iCapacity == 0)
        iCapacity = 2;

    // Get even number for capacity
    if (iCapacity % 2 != 0)
        iCapacity++;

    // Assign defaults
    mQueue.resize(iCapacity);;
    mCapacity = iCapacity;
    mFront = 0;
    mRear = 0;
    mSize = 0;
    mPrintStatus = iPrintStatus;
}

/* class FastQueue's enqueue() function
 * Adds a new element to the end of the queue. O(1) average.
 */
template<typename T>
void FastQueue<T>::enqueue(const T& iValue) {

    // Increment FastQueue size
    mSize++;


    // If queue is full, expand its capacity Insert new value at the end of the queue (to obey FIFO ordering)
    if (fastQueueIsFull()) {

        if (mPrintStatus)
            std::cout << "\n ## EXPANDING CAPACITY ##\n";

        // Save previous values
        size_t oldCapacity = mCapacity;
        size_t oldSize = size();

        // Double the capacity
        mCapacity *= 2;

        // Allocate new queue with the new capacity
        std::vector<T> newQueue;
        newQueue.resize(mCapacity);

        // Copy data from older queue to new queue
        for (size_t i = 0; i < oldSize; ++i)
            newQueue[i] = mQueue[(mFront + i) % oldCapacity];

        // Replace old with new queue and update parameters
        mQueue = newQueue;
        mFront = 0;
        mRear = oldSize;
    }

    try {
        // Enqueue new element at Rear end of queue
        mQueue[mRear] = iValue;
    }
    catch (std::out_of_range& excep) {
        std::cout << excep.what() << "\n";
    }

    catch (...) {
        std::cout << "\n Fecked up\n";
    }



    // Increment mRear in a circular fashion
    mRear = (mRear + 1) % mCapacity;

    // Print status
    if (mPrintStatus)
        std::cout << "\n New value " << iValue << " successfully added to FastQueue.\n";
}

/* class FastQueue's dequeue() function
 * Removes an element from the head of the queue.
 * Does nothing if the queue is already empty. O(1).
 */
template<typename T>
T FastQueue<T>::dequeue() {

    // If mQueue is empty, throw out_of_range exception
    if (fastQueueIsEmpty())
        throw std::out_of_range("\n ERROR! QUEUE IS EMPTY!\n");

    // Fetch the head of the queue
    T dequeuedValue = mQueue[mFront];

    // Increment head circularly
    mFront = (mFront + 1) % mCapacity;

    // Decrement FastQueue size
    mSize--;

    // Print status
    if (mPrintStatus)
        std::cout << "\n Value " << dequeuedValue << " successfully dequeued from FastQueue.\n";

    // Return dequeued value
    return dequeuedValue;
}

/* class FastQueue's front() method
 * Returns reference to the first element of the queue.
 * Throws out_of_range if the container is empty.
 */
template<typename T>
T &FastQueue<T>::front() {

    // If mQueue is empty, throw out_of_range exception
    if (fastQueueIsEmpty())
        throw std::out_of_range("\n ERROR! QUEUE IS EMPTY!\n");

    // else return Front element by reference
    return mQueue[mFront];
}

/* class FastQueue's back() method
 * Returns reference to the last element of the queue.
 * Throws out_of_range if the container is empty.
 */
template<typename T>
T &FastQueue<T>::back() {

    // If mQueue is empty, throw out_of_range exception
    if (fastQueueIsEmpty())
        throw std::out_of_range("\n ERROR! QUEUE IS EMPTY!\n");

    // else return Rear element by reference
    return mQueue[mRear - 1];
}

/* class FastQueue's at() method
 * Returns reference to the index-th element of the queue.
 * Throws out_of_range if the container size is less than index.
 */
template<typename T>
T &FastQueue<T>::at(size_t iIndex) {

    // If mQueue is empty or iIndex exceeds the size, throw out_of_range exception
    if (fastQueueIsEmpty()) {
        throw std::out_of_range("\n ERROR! QUEUE IS EMPTY!\n");
    } else if (iIndex > mSize) {
        throw std::out_of_range("\n ERROR! INDEX EXCEEDS MAXIMUM SIZE!\n");
    }

    // use std::vector::at() method to return value at index iIndex
    return mQueue.at(iIndex % mSize);
}

/* class FastQueue's size() method
 * Returns size of the queue.
 */
template<typename T>
size_t FastQueue<T>::size() {

    // Calculate and return the size of FastQueue
    return (mRear + mCapacity - mFront) % mCapacity;
    //return mSize;
}

/* class FastQueue's capacity() method
 * Returns capacity of the queue.
 */
template<typename T>
size_t FastQueue<T>::capacity() {

    // Return the capacity of FastQueue
    return mCapacity;
}

/* class FastQueue's fastQueueIsFull() method
 * Returns true if space for only one element remains in the queue,
 * so that the underlying vector can be expanded in time.
 */
template<typename T>
bool FastQueue<T>::fastQueueIsFull() {

    // To allow the queue to expand quickly (while there is stills space for 1 element)
    return mSize == mCapacity - 1;
}

/* class FastQueue's fastQueueIsEmpty() method
 * Returns true if queue is empty.
 */
template<typename T>
bool FastQueue<T>::fastQueueIsEmpty() {

    // If mFront = mRear, queue is empty
    return mFront == mRear;
}

/* class FastQueue's printInternalVector() method
* Prints the internal vector buffer on stdout
*/
template<typename T>
void FastQueue<T>::printInternalVector() {
    std::cout << "\n Printing internal memory buffer:\n";

    // Iterate over the vector and display elements
    for (const auto &i : mQueue)
        std::cout << "\t" << i;

    std::cout << std::endl;

}

/* class FastQueue's shrink_to_fit() method
 * Shrinks the currently-allocated vector to
 * a size equal to number of elemens + 2 (for stability and to
 * prevent collision of mFront and mRear indices) */
template<typename T>
void FastQueue<T>::shrink_to_fit() {

    // Declare a new queue with smaller size
    std::vector<T> newQueue(size(), T());

    // Fill the new queue with values from current queue in correct order
    size_t iter = 0;
    while (!fastQueueIsEmpty())
        newQueue[iter++] = dequeue();

    // Replace original class member queue with the new shrunken queue
    mQueue = newQueue;

    // Update indices, size and capacity parameters
    mSize = newQueue.size();
    mFront = 0;
    mRear = mSize;

    // Set the capacity to no. of elements +2 incase of even or +3 in case of odd number
    // of elements, so that capacity is always atleast 2 more than size. Queue remains stable.
    mCapacity = (mSize % 2 == 0 ? mSize + 2 : mSize + 3);

    /* DEBUG
    std::cout << "\n Now new size() and mCapacity "
     << "\n " << mSize << "\t" << mCapacity << "\t" << "\n";

    std::cout << "\n Hit enter to explode:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    std::cin.get();

    */

    std::cout << "\n Successfully shrinked queue to fit number of elements (+2 for stability).\n";
}

#endif //FASTQUEUE_H
