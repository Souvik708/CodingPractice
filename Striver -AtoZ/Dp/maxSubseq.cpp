#include <bits/stdc++.h>

using namespace std;

int solve(int index,vector<int>nums){
    if(index == 0) return nums[index] ;
    if(index < 0) return 0 ;
    int l = nums[index] + solve(index-2,nums) ;
    int r = solve(index-1,nums) ;

    return max(l,r) ;
}

int solve2(int index,vector<int> &dp,vector<int>nums){
    if(index == 0) return nums[index] ;
    if(index < 0) return 0 ;
    if(dp[index] != -1) return dp[index] ;

    int l = nums[index] + solve2(index-2,dp,nums) ;
    int r = solve2(index-1,dp,nums) ;

    return dp[index] = max(l,r) ;
}

int solve3(int index,vector<int> &dp,vector<int>nums){
    int n = nums.size() ;
    for(int i = 1 ; i < n ; i++){
        int l = nums[i] ;
        if(i > 1) l += dp[i-2] ;
        int r = dp[i-1] ;
        dp[i] = max(l,r) ;        
    }
    return dp[n-1] ;
}

int main(){
    vector<int> nums = {2,1,4,9} ;
    vector<int> dp(4,-1) ;
    dp[0] = nums[0] ;
    cout << solve3(3,dp,nums) << endl ;
    return 0 ;
}