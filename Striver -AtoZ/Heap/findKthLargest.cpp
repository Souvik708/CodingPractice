#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size() ;
        priority_queue<int,vector<int>,greater<int>> minHeap ;

        for(auto it : nums){
            minHeap.push(it) ;
            if(minHeap.size() > k){
                minHeap.pop() ;
            }
        }        

        return minHeap.top() ;
    }
};