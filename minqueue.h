#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct MinQueue {

public: // public methods that will be used externally
  MinQueue();
  MinQueue(T* A, int n);

  void insert(T key);
  T min();
  T extract_min();
  string to_string();
  void sort(T *A);
  void decrease_key(int i, T key);
  int size();

private: // properties and methods that are for internal use only
  vector<T> Q;
  int heapSize;

  int parent(int i);
  int left(int i);
  int right(int i);
  void heapify_down(int i);
  void build_min_heap();
};

#endif