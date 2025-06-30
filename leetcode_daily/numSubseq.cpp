#include <bits/stdc++.h>

using namespace std ;

const int MOD = 1e9 + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end()) ;

        vector<int> power(n,0) ;
        power[0] = 1 ;
        for(int i = 1 ; i < n ; i++){
            power[i] = (power[i-1] * 2) % MOD ;
        }

        int numSeq = 0 ;
        int i = 0 ; 
        int j = n-1 ;
        int sum = 0 ;

        while(i <= j){
            int sum = nums[i] + nums[j] ;
            if(sum <= target){
                int diff = j - i ;
                numSeq = ((int)numSeq%MOD + power[diff])%MOD ;
                i ++ ;
            }
            else{
                j ++ ;
            }
        }

        return numSeq % MOD ;        
    }
};

int main(){
    vector<int> nums = {3,5,6,7} ;
    //cout << Solution::numSubseq(nums,9) ;
    return 0 ;
}