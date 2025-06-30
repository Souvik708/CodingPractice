#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ;
        unordered_map<char,int> mp ;

        int i = 0 , j = 0 ;
        int maxLength = 0 ;

        while(j < n){
            mp[s[j]] ++ ;

            while( i <= j && mp[s[j]] > 1){
                mp[s[i]] -- ;
                i ++ ;
            }

            maxLength = max(maxLength, j - i + 1) ;

            j ++ ;
        }        
    }
};

int main(){
    return 0 ;

}