#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j] ;
        if(i < 0 || j < 0) return 0 ;

        if(dp[i][j] != -1) return dp[i][j] ;
        int up = 0 ; 
        int right = 0 ;
        if(i > 0) up = grid[i][j] + solve(i-1,j,grid,dp) ;
        if(j > 0) right = grid[i][j] + solve(i,j-1,grid,dp) ;

        return dp[i][j] = min(up,right) ;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> dp(m,vector<int>(n,-1)) ;

        dp[0][0] = grid[0][0] ;

        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                int up = 0 ; 
                int right = 0 ;
                if(i > 0) up = grid[i][j] + dp[i-1][j] ;
                if(j > 0) right = grid[i][j] + dp[i][j-1] ; 
                dp[i][j] = min(up,right) ;
            }
        }
        return dp[m-1][n-1] ;
    }
};