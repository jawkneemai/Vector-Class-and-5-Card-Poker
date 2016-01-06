//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"
#include <iostream>

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
        mCapacity = INITIAL_CAPACITY;
        mSize = 0;
        mElements = new T[mCapacity];
    }

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
        mCapacity = 0;
        mSize = 0;
        delete[] mElements;
    }

	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		// TODO: Implement
		return mCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
		// TODO: Implement
		return mSize;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
        if (index > mSize - 1 || index < 0) // mSize - 1 because size is always greater than index by 1
        {
            error("Index is out of bounds!");
        }
        
        return mElements[index];
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
        if (index > mSize - 1 || index < 0)
        {
            error("Index is out of bounds!");
        }
        
        return mElements[index];
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void insert_back(const T& value)
	{
        if (mSize < mCapacity)
        {
            mElements[mSize] = value;
            mSize++;
        }
        else if (mSize >= mCapacity)
        {
            mCapacity = mCapacity * CAPACITY_MULTIPLIER;
            T *temp = new T[mCapacity];
            for (int i = 0; i < mSize; i++)
            {
                temp[i] = mElements[i];
            }
            delete[] mElements; // delete old array
            mElements = temp; // point mElements to new array
            mElements[mSize] = value;
            mSize++;
        }
    }

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& get_back()
	{
		return mElements[mSize-1]; // mSize always greater again
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void remove_back()
	{
		if (mSize <= 0)
        {
            error("There is nothing in your vector!!");
        }
        mSize--; // [] overload will take care of not accessing the data that is still in the array but is no longer available to user
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
        if (vector.size() <= 0)
        {
            os << "{}" << std::endl;
        }
        else
        {
            os << "{";
            for (int i = 0; i < vector.size() - 1; i++)
            {
                os << vector[i] << ", ";
            }
            os << vector[vector.size()-1] << "}"; // No comma after last element
        }
		return os;
	}
private:
    unsigned int mCapacity;
    unsigned int mSize;
    T* mElements;

	// Disallow assignment and copy construction
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{

	}

	ITPVector(const ITPVector<T>& other)
	{

	}
};
