#include<bits/stdc++.h>

using namespace std ;


    int solve(int index,int prev,vector<int>nums,int mod,vector<vector<int>>&dp){
        if(index == 0){
            if(prev == -1 || (nums[prev] + nums[index]) % 2 == mod){
                return 1 ;
            }
            else return 0 ;
        }
        if(dp[index][prev] != -1) return dp[index][prev] ;
        int take = 0 ;
        int notTake = 0 ;
        if(prev == -1 || (nums[prev] + nums[index]) % 2 == mod){
            take = 1 + solve(index-1,index,nums,mod,dp) ;
        }
        notTake = solve(index-1,prev,nums,mod,dp) ;

        return dp[index][prev] = max(take,notTake) ;
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp1(n,vector<int>(n,-1)),dp2(n,vector<int>(n,-1)) ;
        solve(n-1,-1,nums,0,dp1) ;
        solve(n-1,-1,nums,1,dp2) ;

        return max(dp1[n-1][-1])
    }

    int main(){
        vector<int> nums = {1,2,3,4} ;
        int n = nums.size() ;
        cout << maximumLength(nums)  << endl ;
        return 0 ;
    }