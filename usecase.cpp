#include <iostream>
#include "minqueue.cpp"
#include "vector"
#include "sstream"
#include <unordered_map>

using namespace std;

template <typename T>
string to_string(vector<T> result)
{
    stringstream ss;
    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
        {
            ss << result[i];
        }
        else
        {
            ss << result[i] << " ";
        }
    }
    return ss.str();
}

template <typename T>
string sliding_window(T nums[], int n, int k)
{
    if (n == 0)
    { // check for invalid input
        return "";
    }
    unordered_map<T, int> uMap; // we add elements which are to be deleted in a map

    MinQueue<T> pq;
    vector<T> res; // this will be the result array to return

    for (int i = 0; i < k; i++) // insert into heap the first k times
    {
        uMap[nums[i]]++;
        pq.insert(nums[i]);
    }

    res.push_back(pq.min()); // remove min of current window and add to "res"

    for (int i = k; i < n; i++)
    {
        int temp = nums[i - k]; // the leftmost out-of-range-by-1 element
        uMap[nums[i]]++;
        pq.insert(nums[i]);
        if (pq.min() != temp) // if the leftmost out-of-range-by-1 element is not the min of current heap, then that 'min' is valid and add it to 'res'
        {
            uMap[temp]--;
            res.push_back(pq.min());
            continue;
        }

        uMap[temp]--;
        pq.extract_min();

        while (pq.size() && uMap[pq.min()] == 0) // keep taking out the current min of heap as long as queue is not empty and the corresponding value of that 'min' in hashMap is 0
        {
            pq.extract_min();
        }
        res.push_back(pq.min());
    }

    return to_string(res);
}