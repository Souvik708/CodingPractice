#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length() ;
        unordered_map<char,int> freq ;

        int i = 0 , j = 0 ;
        int maxFreq = 0 ;
        int maxLength = 0 ;

        while(j < n){
            freq[s[j]] ++ ;
            maxFreq = max(maxFreq,freq[s[j]]) ;


            while(i <= j && (j - i + 1) - maxFreq > k){
                if(freq[s[i]] == 1){
                    freq.erase(s[i]) ;
                }
                else{
                    freq[s[i]] -- ;
                }
                maxFreq = 0 ;
                for(auto it : freq){
                    maxFreq = max(maxFreq,it.second) ;
                }  
                i ++ ;      
            }

            maxLength = max(maxLength,(j - i + 1)) ;

            j ++ ;
        }  

        return maxLength ;      
    }
};

int main(){
    return 0 ;
}