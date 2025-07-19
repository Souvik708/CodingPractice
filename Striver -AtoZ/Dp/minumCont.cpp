#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&triangle){
        int n = triangle.size() ;
        if(i == n-1){
            return triangle[n-1][j] ;
        }
        int down = triangle[i][j] + solve(i+1,j,triangle) ;
        int diagonal = triangle[i][j] + solve(i+1,j+1,triangle) ;

        return min(down,diagonal) ;
    }

    int solve2(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        int n = triangle.size() ;
        if(i == n-1){
            return triangle[n-1][j] ;
        }
        if(dp[i][j] != -1) return dp[i][j] ;
        int down = triangle[i][j] + solve2(i+1,j,triangle,dp) ;
        int diagonal = triangle[i][j] + solve2(i+1,j+1,triangle,dp) ;

        return dp[i][j] = min(down,diagonal) ;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size() ;
        int n = triangle[0].size() ;
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;

        return solve(m-1,n-1,triangle) ;
    }
};