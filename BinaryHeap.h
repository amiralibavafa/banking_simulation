/* 
 * BinaryHeap.h
 *
 * Description: min Binary Heap ADT class.
 *
 * Class Invariant:  Always a min Binary Heap.
 * 
 * Author: Amirali Bavafa and Shayan Solgi
 * Last Modification: Nov. 2023
 *
 */  

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

//#include "Queue.h"

template <class ElementType>
class BinaryHeap {
    private:
        ElementType* elements = nullptr;
        unsigned int elementCount;
        const unsigned int INITIAL_CAPACITY = 6;
        unsigned int capacity;


        //Description: heap down the element to its correct possition of the heap
        void reHeapDown(unsigned int indexOfRoot);

        //Description: heap ups the elements recursively to their right position
        void reHeapUp(unsigned int index);



    public:
        //Description : default constructor
        BinaryHeap();

        //Description: default destructor
        //             removes and delete all the memory
        ~BinaryHeap();

        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap. 
        //              It returns true if successful, otherwise false.      
        // Time Efficiency: O(log2 n)
        bool insert(ElementType & newElement);
            
        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1) 
        ElementType & retrieve() const;
        
};
#include "BinaryHeap.cpp"
#endif