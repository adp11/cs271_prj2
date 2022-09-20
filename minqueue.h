#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MinQueue {
public:
  MinQueue();  // empty constructor initializing an empty minimum priority queue (min heap)
  MinQueue(T* A, int n); // create a minimum priority queue (min heap) of the n elements in A

  void insert(T key);
  T min();
  T extract_min();
  void percolate_up(int i);
  string to_string();

private:
  
  vector<T> Q;
  int heapSize;

  int parent(int i);
  int left(int i);
  int right(int i);
  void heapify(int i);
  void build_min_heap();
  void heapsort();
  // void deallocate(); // private method for destructor
};

#endif