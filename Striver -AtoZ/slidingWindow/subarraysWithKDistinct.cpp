#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int,int> mp ;
        int count = 0 ;

        int i = 0 , j = 0 ;

        while(j < n){
            mp[nums[i]] ++ ;

            while(i <= j && mp.size() > k){
                mp[nums[i]] -- ;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]) ;
                }
                i ++ ;
            }

            if(mp.size() == k){
                count ++ ;
            }

            j ++ ;
        } 

        return count ;       
    }
};