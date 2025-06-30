#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size() ;

        sort(nums.begin() , nums.end()) ;

        int countSeq = 1 ;
        int start = 0 ; 

        for(int i = 0 ; i < n ; i++){
            if(nums[i] - nums[start] > k ){
                countSeq ++ ;
                start = i ;
            }
        }

        return countSeq ;
    }
};

int main(){
    return 0 ;
}