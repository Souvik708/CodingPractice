#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size() ;
        set<int> st ;

        for(auto it : arr){
            st.insert(it) ;
        }

        unordered_map<int,int> mp ; // Element -> Rank
        int rank = 1 ;
        for(auto it : st){
            mp[it] = rank ++ ;
        } 
        vector<int> ans ;

        for(auto it : arr){
            ans.push_back(mp[it]) ;
        }  

        return ans ;     
    }
};