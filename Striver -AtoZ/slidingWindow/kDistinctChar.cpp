#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.length() ;
        unordered_map<char,int> mp ;

        int i = 0 , j = 0 , maxLength = 0 ;

        while(j < n){
            mp[s[j]] ++ ;

            while(i <= j && mp.size() > k){
                mp[s[i]] -- ;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]) ;
                }
                i ++ ;
            }
            maxLength = max(maxLength,(j - i + 1)) ;

            j ++ ;
        }

        return maxLength ;
    }
};