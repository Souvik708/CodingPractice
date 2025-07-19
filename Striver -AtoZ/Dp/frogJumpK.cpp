#include <bits/stdc++.h>

using namespace std ;


// 1. Normal Recursive way
int solve1(int index,int k, vector<int> stones){
    if(index == 0) return 0 ;
    int minJumps = INT_MAX ;
    for(int j = 1 ; j <= k ; j++){
        if(index - j >= 0){
            int jumps = solve1(index-j,k,stones) + abs(stones[index] - stones[index-k]) ;
            minJumps = min(minJumps,jumps) ;
        }
        else break ;
    }
    return minJumps ; 
}

//2. Memorization way(Top Down)
int solve2(int index,int k, vector<int> &dp, vector<int>stones){
    if(index == 0) return 0 ;
    if(dp[index] != -1) return dp[index] ;
    int minJumps = INT_MAX ;
    for(int j = 1 ; j <= k ; j++){
        if(index - j >= 0){
            int jumps = solve2(index-j,k,dp,stones) + abs(stones[index] - stones[index-k]) ;
            minJumps = min(minJumps,jumps) ;
        }
        else break ;
    }
    return dp[index] = minJumps ;
}

//3. Tabular way(bottom up)
int solve3(int k,int n,vector<int>&dp,vector<int>stones){
    dp[0] = 0;
    for(int i = 1 ; i < n ; i++){
        int minJumps = INT_MAX ;
        for(int j = 1 ; j <= k ; j++){
            if(i - j >= 0){
                int jumps = dp[i-j] + abs(stones[i] - stones[i-j]) ;
                minJumps = min(minJumps,jumps) ;
            }
        }
        dp[i] = minJumps ;
    }
    return dp[n-1] ;
}

int main(){
    int k = 2 ;
    vector<int> stones = {30, 20, 50, 10, 40} ;
    int n = stones.size() ;
    vector<int>dp(n,-1) ;
    cout << solve1(n-1,k,stones) << endl ;
    cout << solve2(n-1,k,dp,stones) << endl ;
    cout << solve3(k,n,dp,stones) << endl ;
    return 0 ;
}