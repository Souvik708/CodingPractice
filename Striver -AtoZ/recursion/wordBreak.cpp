#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    bool solve(int ind ,string s , int n , unordered_map<string,bool> &mp){
        if(ind == n){
            return true ;
        }
        for(int i = ind ; i < n ; i++){
            int pos = ind ;
            int length = i - ind + 1;
            string str = s.substr(pos,length) ;
            if(mp[str]){
                if(solve(i+1,s,n,mp)){
                    return true ;
                }
                else{
                    return false ;
                }
            }
        }
        return false ;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ;
        unordered_map<string,bool> mp ;
        for(auto it : wordDict){
            mp[it] ++ ;
        }
         return solve(0,s,n,mp) ;
    }
};