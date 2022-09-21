#include <iostream>
#include <vector>
#include <sstream>
#include "minqueue.h"

using namespace std;

// -------------------Priviate MinHeap operations---------------------------

template <typename T>
int MinQueue<T>::parent(int i)
/*
Pre-conditions: i must be of type int
Post-conditions: must be of type int
*/
{
	return (i - 1) / 2;
}

template <typename T>
int MinQueue<T>::left(int i)
/*
Pre-conditions: i must be of type int
Post-conditions: must be of type int
*/
{
	return (2 * i + 1);
}

template <typename T>
int MinQueue<T>::right(int i)
/*
Pre-conditions: i must be of type int
Post-conditions: must be of type int
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

		T temp = Q[smallest];
		Q[smallest] = Q[i];
		Q[i] = temp;
		heapify_down(smallest);
	}
}

template <typename T>
void MinQueue<T>::build_min_heap()
/*
Pre-conditions: Q might or might not be a min-queue priority
Post-conditions: Q is a min-queue priority
*/
{
	for (int i = Q.size() / 2; i >= 0; i--)
	{
		heapify_down(i);
	}
}

template <typename T>
void MinQueue<T>::sort(T *A)
/*
Pre-conditions: elements from [i+1 ... Q.length-1] is sorted
Post-conditions: elements from [i...Q.length-1 is sorted]
*/
{
	for (int i = Q.size(); i > 0; i--)
	{
		T temp = Q[i];
		Q[i] = Q[0];
		Q[0] = temp;
		heapSize -= 1;
		heapify_down(0);
	}

}

// -------------------MinQueue operations---------------------------
template <typename T> // constructor
MinQueue<T>::MinQueue()
{
	heapSize = 0;
}

template <typename T>
MinQueue<T>::MinQueue(T *A, int n)
/*
Pre-conditions: n must be of type int, A must be pointer to array of type T
Post-conditions: a min-priority queue created from T* A
*/
{
	for (int i = 0; i < n; i++) {
		Q.push_back(A[i]);
	}
	heapSize = n;
	build_min_heap();
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
		T min = Q[0];
		Q[0] = Q[heapSize - 1];
		Q.pop_back();
		heapSize -= 1;
		heapify_down(0);
		return min;
	}
}

template <typename T>
void MinQueue<T>::decrease_key(int i, T key)
/*
Pre-conditions: index must be of type int and key must be of type T
Post-conditions: new key is at a place where heap property is still kept
*/
{
	if (Q.size() != 0) { // test case of empty Q
		Q[i] = key;
			while (Q[i] < Q[parent(i)])
			{
				int parentIndex = parent(i);
				T temp = Q[i];
				Q[i] = Q[parent(i)];
				Q[parent(i)] = temp;
				i = parentIndex;
			}
	}
	
}

template <typename T>
void MinQueue<T>::insert(T key)
/*
Pre-conditions: key must be of type T
Post-conditions: new key is at a place where heap property is still kept and queue is 1 more bigger in size
*/
{
	Q.push_back(key);
	decrease_key(heapSize, key);
	heapSize += 1;
}

template <typename T>
string MinQueue<T>::to_string()
/*
Pre-conditions: none
Post-conditions: a string representation of the queue Q
*/
{
	stringstream ss;
	for (int i = 0; i < Q.size(); i++)
	{
		if (i == Q.size() - 1)
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