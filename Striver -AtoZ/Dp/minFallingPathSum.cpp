#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>> &dp){
        int m = matrix[0].size() ;
        if(j < 0 || j >= m) return 1e9 ;
        if(i == 0){
            return matrix[0][j] ;
        }
        if(dp[i][j] != -1) return dp[i][j] ;
        int up = matrix[i][j] + solve(i-1,j,matrix,dp) ;
        int leftDg = matrix[i][j] + solve(i-1,j-1,matrix,dp) ;
        int rightDg = matrix[i][j] + solve(i-1,j+1,matrix,dp) ;

        return dp[i][j] = max({up,leftDg,rightDg}) ;
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<int>> dp(n,vector<int>(m,-1)) ;

        for(int j = 0 ; j < m ; j++){
            dp[0][j] = matrix[0][j] ;
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < n ; j ++){
                int up , leftDg, rightDg ;
                up = leftDg = rightDg = 1e9 ;
                up = matrix[i][j] + dp[i-1][j] ;
                if(j > 0) leftDg = matrix[i][j] + dp[i-1][j-1] ;
                if(j < m-1) rightDg = matrix[i][j] + dp[i-1][j+1] ;

                dp[i][j] = min({up,leftDg,rightDg}) ;
            }
        }

        int minSum = INT_MAX ;
        for(int j = 0 ; j < m ; j++){
            minSum = min(minSum,dp[n-1][j]) ;
        }

        return minSum ;
    }
};