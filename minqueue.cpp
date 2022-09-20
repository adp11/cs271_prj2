#include <iostream>
#include <vector>
#include <sstream>
#include "minqueue.h"

using namespace std;

// -------------------Priviate MinHeap operations---------------------------

template <typename T>
int MinQueue<T>::parent(int i)
{
	return (i - 1) / 2;
}

template <typename T>
int MinQueue<T>::left(int i)
{
	return (2 * i + 1);
}

template <typename T>
int MinQueue<T>::right(int i)
{
	return (2 * i + 2);
}

template <typename T>
void MinQueue<T>::heapify(int i)
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
		heapify(smallest);
	}
}

template <typename T>
void MinQueue<T>::build_min_heap()
{
	for (int i = Q.size()-1 / 2; i >= 0; i--)
	{
		heapify(i);
	}
}

template <typename T>
void MinQueue<T>::heapsort()
{
	build_min_heap();
	for (int i = Q.size()-1 / 2; i >= 0; i--)
	{
		T temp = Q[i];
		Q[i] = Q[0];
		Q[0] = temp;
		heapSize -= 1;
		heapify(0);
	}
}

// -------------------MinQueue operations---------------------------
template <typename T>
MinQueue<T>::MinQueue()
{
	vector<int> Q;
	heapSize = 0;
}

template <typename T>
MinQueue<T>::MinQueue(T *A, int n)
{
	vector<T> Q(n);
	heapSize = n;
	build_min_heap();
}

template <typename T>
T MinQueue<T>::min()
{
	if (Q.size() > 0)
	{
		return Q[0];
	}
}

template <typename T>
T MinQueue<T>::extract_min()
{
	if (Q.size() > 0)
	{
		T min = Q[0];
		Q[0] = Q[heapSize - 1];
		heapSize -= 1;
		heapify(0);
		return min;
	}
}

template <typename T>
void MinQueue<T>::percolate_up(int i)
{
	while (Q[i] < Q[parent(i)])
	{
		int parentIndex = parent(i);
		T temp = Q[i];
		Q[i] = Q[parent(i)];
		Q[parent(i)] = temp;
		i = parentIndex;
	}
}

template <typename T>
void MinQueue<T>::insert(T key)
{
	Q.push_back(key);
	percolate_up(heapSize);
	heapSize += 1;
}

template <typename T>
string MinQueue<T>::to_string()
{
	cout << "Q.size(): " << Q.size() << endl;
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