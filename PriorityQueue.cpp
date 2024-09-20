/* 
 * PriorityQueue.cpp
 *
 * Description: BinaryHeap-based implementation of PriorityQueue as an ADT class
 * Class Invariant: Priority Queue maintained in ascending order based on the priority of elements
 *
 * Author: Amirali Bavafa and Shayan Solgi
 */

//#include "PriorityQueue.h"
#include "BinaryHeap.h"

//Description: Default Constructor 
template <class ElementType>
PriorityQueue<ElementType> :: PriorityQueue(){
    List = new BinaryHeap<ElementType>();
}

//Description: Default Destructor
template <class ElementType>
PriorityQueue<ElementType> :: ~PriorityQueue(){
    delete List;
}


// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType> :: isEmpty() const{
    return List->getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType> :: enqueue(ElementType & newElement){
    return List->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType> :: dequeue(){
    List->remove();
    return;
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType> :: peek() const{
    return List->retrieve();
}