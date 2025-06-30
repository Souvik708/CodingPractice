#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int maxReach = 0 ;

        for(int i = 0 ; i < n ; i++){
            
            if(i > maxReach){
                return false ;
            }
            else{
                maxReach = max(maxReach , nums[i] + i) ;
                if(maxReach >= n-1) return true ;
            }
        }  

        return true ;      
    }
};