#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length() ;
        unordered_map<char,int> mp ;

        int count = 0 , i = 0 , j = 0 ;

        while(j < n){
            mp[s[j]] ++ ;

            while(i <= j && mp.size() == 3){
                count = count + (n - j) ;
                if(mp[i] == 1){
                    mp.erase(mp[s[i]]) ;
                }
                mp[s[i]] -- ;
                i -- ;    
            }

            j ++ ;
        } 
        return count ;       
    }
    //Approach 2
    int numberOfSubstrings(string s) {
        int n = s.length() ;
        int count = 0 ;
        int arr[3] = {-1,-1,-1} ;

        for(int i = 0 ; i < n ; i++){
            arr[s[i] - 'a']  = i ;

            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                count += 1 + min(arr[0],arr[1],arr[2]) ;
            }
        }

        return count ;       
    }

};