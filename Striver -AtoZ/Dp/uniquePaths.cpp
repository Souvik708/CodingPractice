#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    // 1. recursion
    int solve(int i,int j){
        if(i == 0 && j == 0) return 1 ;
        if(i < 0 || j < 0) return 0 ;
        int up = solve(i-1,j) ;
        int down = solve(i,j-1) ;

        return up+down ;
    }
    // 1. Memorization
    int solve2(int i,int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1 ;
        if(i < 0 || j < 0) return 0 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        int up = solve(i-1,j) ;
        int down = solve(i,j-1) ;

        return dp[i][j] = up+down ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0){
                    dp[0][0] = 1 ;
                    continue ;
                }
                int up = dp[i-1][j] ;
                int down = dp[i][j-1] ;
                dp[i][j] = up + down ;
            }
        }

        return dp[m-1][n-1] ;
    }
};