#include <bits/stdc++.h>

using namespace std ;

int findKthPositive(vector<int>& nums , int k){
    int n = nums.size() ;
    int m = nums[n-1] ;
    unordered_map<int,int> mpp(m+1) ;
    for(auto it : nums){
        mpp[it] ++ ;
    }
    int count = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(mpp[i] == 0){
            count ++ ;
            if(count == k){
                return i ;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {2,3,4,7,11} ;
    int k = 5 ;
    cout << findKthPositive(nums,k) << endl ;
    return 0;
}