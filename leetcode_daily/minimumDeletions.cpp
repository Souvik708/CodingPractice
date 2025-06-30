#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length() ;
        if( k >= n) return 0 ;
        unordered_map<char,int> mp ;

        for(int i = 0 ; i < n ; i++){
            mp[word[i]] ++ ;
        }
        vector<int>freq(n) ;

        for(auto it : mp){
            freq.push_back(it.second) ;
        } 

        sort(begin(freq),end(freq)) ;
        
               
    }
};

int main(){
    return 0 ;
}