/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Amirali Bavafa and Shayan Solgi 
 *         aba234             ssa523
 */


#include "Queue.h"
#include "EmptyDataCollectionException.h"


// Description: Constructor
template <class ElementType>
Queue<ElementType>::Queue() {
    elements = new ElementType[INITIAL_CAPACITY];
}

//Description: Copy Constructor
//Copying datas from other to elements and our queue
template <class ElementType>
Queue<ElementType>::Queue(const Queue& other) : capacity(other.capacity), elementCount(other.elementCount), frontindex(other.frontindex), backindex(other.backindex) {
    elements = new ElementType[capacity];
   
    //copying datas to elements array
    for (int i = 0; i < elementCount; i++) {
        elements[i] = other.elements[i];
    }
}


// Overloaded Assignment Operator
template <class ElementType>
Queue<ElementType>& Queue <ElementType>::operator=(const Queue& other) {
    // Check for self-assignment
    if (this != &other) {
        // Delete existing elements
        delete[] elements;

        // Copy new elements
        capacity = other.capacity;
        elementCount = other.elementCount;
        frontindex = other.frontindex;
        backindex = other.backindex;
        elements = new ElementType[capacity];
        for (int i = 0; i < elementCount; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::enqueue(ElementType newElement) {

    //increasing size if the queue is full 
    if (elementCount == capacity){
        int newCapacity = capacity * 2;

        //initializing a new array with the new size
        ElementType* newArr = new ElementType[newCapacity];

        //copying all the elements from main array to the newArr
        for (int i = 0 ; i < elementCount ; i++){
            newArr[i] = elements[(frontindex + i) % capacity];
        }

        //setting front index and back to default since we are resetting the elements array
        frontindex = 0;
        backindex = elementCount;

        delete[] elements;
        elements = newArr;

        capacity = newCapacity;
    }

    //enqueuing the new element
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue() {

    //Check to see if the array is empty and returns nothing if the array is empty
    if (isEmpty()){
        return;
    }

    //dequeuing 
    elementCount--;
    frontindex = (frontindex + 1) % capacity;

    //After dequeuing we check to see if there is too much of capacity left unused so we can deallocate them
    if ( elementCount <= capacity / 4 && capacity / 2 >= INITIAL_CAPACITY){
        int newCapacity = capacity / 2;
        ElementType* newArr = new ElementType[newCapacity];

        //Copying elements to the new array
        for (int i = 0 ; i < elementCount ; i++){
            newArr[i] = elements[(frontindex + i) % capacity];
        }

        frontindex = 0;
        backindex = elementCount;

        delete[] elements;
        //moving everythin to our original array
        elements = newArr;

        capacity = newCapacity;
    }
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
template <class ElementType>
ElementType Queue<ElementType>::peek() const {

    //return 9999 as an error when empty
    if (isEmpty()){
        throw EmptyDataCollectionException("The Queue is Empty.");
    }

    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

template <class ElementType>
Queue<ElementType>::~Queue(){
    delete[] elements;
    elements = nullptr;
}