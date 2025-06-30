#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end());

        int i = 0 , j = 0 , maxLength = 0 ;

        while(j < n){

            while(i <= j && (nums[j] - nums[i]) > 1){
                i ++ ;
            }

            if((nums[j] - nums[i]) == 1){
                maxLength = max(maxLength, j - i + 1) ;
            }

            j ++ ;
        }  

        return maxLength ;      
    }
};