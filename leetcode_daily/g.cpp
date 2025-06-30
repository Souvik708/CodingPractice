#include <bits/stdc++.h>

using namespace std ;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size() ;
    if(n < 3) return 0 ;
    vector<int> leftMax(n,0) ;
    vector<int> rightMax(n,0) ;


    for(int i = 1 ; i < n ; i++ ){
        leftMax[i] = max(leftMax[i-1],nums[i-1]) ;
    }
    for(int i = n-2 ; i >= 0 ; i-- ){
        rightMax[i] = max(rightMax[i+1],nums[i+1]) ;
    }
    long long result = 0 ;
    for(int i = 0 ; i < n ; i++){
        long long val = (leftMax[i] - nums[i]) * rightMax[i] ;
        result = max(result,val) ;
    }
    if(result < 0) return 0 ;
    return result ;   
}

int main(){
    vector<int> nums = {12,6,1,2,7} ;
    cout << maximumTripletValue(nums) << endl ;
    return 0 ;
}