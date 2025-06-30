#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length() ;
        int m = t.length() ;
        if( m > n) return "" ;

        unordered_map<char,int> mp ;
        for(auto &ch : t){
            mp[ch] ++ ; 
        }

        int count = 0 ;
        int strtInd = -1 ;
        int minLength = INT_MAX ;

        int i = 0 ;
        int j = 0 ;

        while(j < n){
            if(mp[s[j]]-- > 0 ) count ++ ;
            
            while(count == m){
                int length = j - i + 1 ;
                if(length < minLength){
                    minLength = length ;
                    strtInd = i ;
                }
                mp[s[i]] ++ ;
                if(mp[s[i]] > 0) count -- ;
                
                i ++ ;
            }

            j ++ ;
        }  

        return strtInd == -1 ? "" : s.substr(strtInd,minLength) ;     
    }
};