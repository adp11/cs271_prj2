#include <iostream>
#include <vector>
#include <sstream>
#include "minqueue.h"

using namespace std;

// -------------------Priviate MinHeap operations---------------------------

template <typename T>
int MinQueue<T>::parent(int i)
/*
Pre-conditions: param i must be of type int
Post-conditions: return value must be of type int
*/
{
	return (i - 1) / 2;
}

template <typename T>
int MinQueue<T>::left(int i)
/*
Pre-conditions: param i must be of type int
Post-conditions: return value must be of type int
*/
{
	return (2 * i + 1);
}

template <typename T>
int MinQueue<T>::right(int i)
/*
Pre-conditions: param i must be of type int
Post-conditions: return value must be of type int
*/
{
	return (2 * i + 2);
}

template <typename T>
void MinQueue<T>::heapify_down(int i)
/*
Pre-conditions: children of node at i are at roots of heaps themselves
Post-conditions: i is at root of the heap
*/
{
	int l = left(i);
	int r = right(i);

	int smallest = i;

	// line 52-61 means that pick the smaller child (if any) and assign it to 'smallest'
	if (l < heapSize && Q[l] < Q[i]) 
	{
		smallest = l;
	}

	if (r < heapSize && Q[r] < Q[smallest])
	{
		smallest = r;
	}

	if (smallest != i)
	{
		swap(Q[smallest], Q[i]); // swap current node with smaller child
		heapify_down(smallest); // heapify again 
	}
}

template <typename T>
void MinQueue<T>::build_min_heap()
/*
Pre-conditions: Q might or might not be a min-queue priority
Post-conditions: Q is a min-queue priority
*/
{
	for (int i = (Q.size()/2-1); i >= 0; i--) // start doing the heapify_down() at the first non-leaf node (at (size/2) -1)
	{
		heapify_down(i);
	}
}

template <typename T>
void MinQueue<T>::sort(T *A)
/*
Pre-conditions: at the start of each iteration i, elements from [i+1 ... Q.length-1] is sorted
Post-conditions: elements from [i...Q.length-1] is sorted
*/
{
	for (int i = (Q.size()-1); i >= 0; i--)
	{
		swap(Q[i], Q[0]); // swap last node with root node
		heapSize -= 1; // exclude last node from heap
		heapify_down(0); // fix problematic node at root

		A[Q.size()-1-i] = Q[i]; // put next smallest value to A (from left to right)
	}
}

// -------------------MinQueue operations---------------------------
template <typename T>
MinQueue<T>::MinQueue()
{
	heapSize = 0;
}

template <typename T>
MinQueue<T>::MinQueue(T *A, int n)
/*
Pre-conditions: param n must be of type int, param A must be pointer to array of type T
Post-conditions: a min-priority queue created from T* A
*/
{
	Q.resize(n); // allocate space in vector Q in advance
	for (int i = 0; i < n; i++) { // copy elements in A to this->Q
		Q[i] = A[i];
	}
	heapSize = n;
	build_min_heap(); // apply build() to this->Q
}

template <typename T>
string MinQueue<T>::to_string()
/*
Pre-conditions: none
Post-conditions: a string representation of the min queue Q
*/
{
	stringstream ss;
	for (int i = 0; i < Q.size(); i++)
	{
		if (i == Q.size() - 1) // prevent adding " " after the last element
		{
			ss << Q[i];
		}
		else
		{
			ss << Q[i] << " ";
		}
	}
	return ss.str();
}

template <typename T>
int MinQueue<T>::size() {
/*
Pre-conditions: none
Post-conditions: return the size of queue Q
*/
	return Q.size();
}

template <typename T>
T MinQueue<T>::min()
/*
Pre-conditions: none
Post-conditions: read min value of type T, Q is still intact
*/
{
	if (Q.size() > 0)
	{
		return Q[0];
	} else {
		// throw "Out-of-range index"; // could throw an exception here when it's out of range!
	}
}

template <typename T>
T MinQueue<T>::extract_min()
/*
Pre-conditions: none
Post-conditions: remove and return min value of type T, and Q is 1 less smaller in size
*/
{
	if (Q.size() > 0)
	{
		swap(Q[0], Q[heapSize-1]);
		T min = Q.back(); // get the min
		Q.pop_back(); // remove the min
		heapSize -= 1; // decrease heapSize
		heapify_down(0); // fix the problematic element at root
		return min;
	} else {
		// throw "Out-of-range index"; // could throw an exception here when it's out of range!
	}
}

template <typename T>
void MinQueue<T>::decrease_key(int i, T key)
/*
Pre-conditions: param i must be of type int and param key must be of type T
Post-conditions: new key is at a place where heap property is still maintained
*/
{
	if (i < Q.size()) { // prevent out-of-range error
		Q[i] = key;
		while (Q[i] < Q[parent(i)]) 
		{
			swap(Q[i], Q[parent(i)]); // keep swapping this problematic node at i upwards until heap property is restored
			i = parent(i);
		}
	}
}

template <typename T>
void MinQueue<T>::insert(T key)
/*
Pre-conditions: param key must be of type T
Post-conditions: new key is at a place where heap property holds true and queue is 1 more bigger in size
*/
{
	Q.push_back(key); // add key to the end of Q
	heapSize += 1; // increase size
	decrease_key(heapSize-1, key); // apply decrease_key() to this key to maintain heap property
}
