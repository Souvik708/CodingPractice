#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size() ;
        vector<int> ans ;
        vector<int> equalKeys ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == key){
                equalKeys.push_back(i) ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < equalKeys.size() ; j++ ){
                if(abs(i - equalKeys[j]) <= k){
                    ans.push_back(i) ;
                    break ;
                }
            }
        }

        sort(ans.begin(), ans.end()) ;

        return ans ;
    }
};