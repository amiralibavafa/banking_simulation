/* 
 * BinaryHeap.cpp
 *
 * Description: min Binary Heap ADT class.
 *
 * Class Invariant:  Always a min Binary Heap.
 * 
 * Author: Amirali Bavafa and Shayan Solgi
 * Last Modification: Nov. 2023
 *
 */  

#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;

//Description : default constructor
template <class ElementType>
BinaryHeap<ElementType> :: BinaryHeap(){
    elements = new ElementType[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
}


//Description: default destructor
//             removes and delete all the memory
//Time Efficiency: O(N)
template <class ElementType>
BinaryHeap<ElementType> :: ~BinaryHeap(){
    delete [] elements;
    elementCount = 0;
    capacity = 0;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType> :: insert(ElementType & newElement){
    if (elementCount == 0){// the binary heap is empty so insert it to the first index
        elements[0] = newElement;
        elementCount++;
        return true;
    }

    //If the capicity is full we double size the capacity and insert the new element
    if ( capacity == elementCount){
        unsigned int newCapacity = capacity * 2;
        ElementType* newElements = new ElementType[newCapacity];

        //inserting elements from old array into new one
        for (int i = 0 ; i < elementCount ; i++){
            newElements[i] = elements[i];
        }

        delete [] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    elements[elementCount] = newElement;
    elementCount++;
    reHeapUp(elementCount - 1);
    return true;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType> :: getElementCount() const {
    return elementCount;
}


// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() is we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType & BinaryHeap<ElementType> :: retrieve() const{
    if (elementCount == 0){
        throw EmptyDataCollectionException("Binary heap is empty");
    }

    return elements[0];
}

// Utility method
// Description: Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Utility method
// Description: Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType> :: reHeapUp(unsigned int index){
    // If the index is 0, it means we've reached the root of the heap, so no need to heap up further
    if (index == 0) {
        return;
    }

    // Calculate the parent index
    unsigned int parentIndex = (index - 1) / 2;

    // Compare the current element with its parent
    // If the current element is smaller (for a min heap) or larger (for a max heap) than its parent, swap them
    if (elements[index] <= elements[parentIndex]) { // For a min heap
        ElementType tmp = elements[parentIndex];
        elements[parentIndex] = elements[index];
        elements[index] = tmp;
        // Recursively heap up the parent element   
        reHeapUp(parentIndex);
    }
    return;
}