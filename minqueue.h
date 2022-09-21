#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct MinQueue {
public:
  MinQueue();// DONE
  MinQueue(T* A, int n);// DONE

  void insert(T key);// DONE
  T min();// DONE
  T extract_min();// DONE
  string to_string();// DONE
  void sort(T *A);
  void decrease_key(int i, T key);// DONE
  int size();// DONE

private:
  
  vector<T> Q;
  int heapSize;

  int parent(int i);// DONE
  int left(int i);// DONE
  int right(int i);// DONE
  void heapify_down(int i);// DONE
  void build_min_heap();// DONE
  
};

#endif