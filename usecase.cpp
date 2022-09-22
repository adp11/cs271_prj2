#include <iostream>
#include "minqueue.cpp"
#include "vector"
#include "sstream"
#include <queue>
#include <unordered_map>

using namespace std;


template <typename T>
string to_string(vector<T> result) {
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
string sliding_window(T nums[], int n, int k) {
	if (n == 0) {
		return "";
	}
	unordered_map<T, int> ump;

	MinQueue<T> pq;
    vector<T> ans;
    
    for(int i=0;i<k;i++)
    {
        ump[nums[i]]++;
        pq.insert(nums[i]);
    }
    
    
    ans.push_back(pq.min());
    
    for(int i=k;i<n;i++)
    {
        int temp=nums[i-k];
        ump[nums[i]]++;
        pq.insert(nums[i]);
        if(pq.min()!=temp)
        {
            ump[temp]--;
            ans.push_back(pq.min());
            continue;
        }
        
        ump[temp]--;
        pq.extract_min();
        
        while(pq.size() && ump[pq.min()] == 0)
        {
            pq.extract_min();
        }
        ans.push_back(pq.min());
    }
    
    return to_string(ans);
}