#include<bits/stdc++.h>

using namespace std ;

class Solution {
  public:
    //1. Normal recurrence relation
    int solve(int day,int last, vector<vector<int>>arr){
        int maxi = 0 ;
        if(day == 0){
            for(int t = 0 ; t <=3 ; t++){
                if(t != last){
                    maxi = max(maxi,arr[0][t]) ;
                }
            }
            return maxi ;
        }
        for(int t = 0 ; t <= 3 ; t++){
            if(t != last){
                int points = arr[day][t] + solve(day-1,t,arr) ;
                maxi = max(maxi,points) ;
            }
        }
        return maxi ;
    }
    //1. memorization technique
    int solve(int day,int last, vector<vector<int>>arr,vector<vector<int>> &dp){
        int maxi = 0 ;
        if(day == 0){
            for(int t = 0 ; t <=3 ; t++){
                if(t != last){
                    maxi = max(maxi,arr[0][t]) ;
                }
            }
            return maxi ;
        }
        if(dp[day][last] != -1) return dp[day][last] ;
        for(int t = 0 ; t <= 3 ; t++){
            if(t != last){
                int points = arr[day][t] + solve(day-1,t,arr,dp) ;
                maxi = max(maxi,points) ;
            }
        }
        return dp[day][last] = maxi ;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size() ;
        vector<vector<int>> dp(n,vector<int>(4,-1)) ;
        
        dp[0][0] = max(arr[0][1],arr[0][2]) ;
        dp[0][1] = max(arr[0][0],arr[0][2]) ;
        dp[0][2] = max(arr[0][0],arr[0][1]) ;
        dp[0][3] = max({arr[0][0],arr[0][1],arr[0][2]}) ;

        for(int day = 1 ; day < n ; day++){
            for(int last = 0 ; last <= 3 ; last ++){
                for(int task = 0 ; task <= 2 ; task ++){
                    if(task != last){
                        int point = arr[day][task] + dp[day-1][task] ;
                        dp[day][last] = max(dp[day][last],point) ;
                    }
                }
            }
        }

        return dp[n-1][3] ;
    }
};

