#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() ;

        vector<int> prefixSum(0) ;
        int sum = 0 ;
        int maxFreq  = 0 ;

        sort(nums.begin(),nums.end()) ;
        
        for(int i = 0 ; i < n ; i++){
            prefixSum[i] = sum ;
            sum += nums[i] ;
        }

        for(int i = n-1 ; i >= 0 ; i--){
            int numEle = (i - 1) + 1 ;
            int operation = numEle * nums[i] - prefixSum[i] ;
            if(operation <= k ){
                maxFreq = numEle + 1 ;
                break;
            } 
        }

        return maxFreq ;
    }
};