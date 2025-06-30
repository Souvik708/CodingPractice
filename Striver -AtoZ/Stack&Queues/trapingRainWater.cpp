#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    // Approach - I

    int trap1(vector<int>& height) { // T.C = O(3n) , S.C = O(n)
        int n = height.size() ;

        vector<int> prefixMax(n,-1) , suffixMax(n,-1) ;

        //Finding max element in the left
        prefixMax[0] = height[0] ;

        for(int i = 1 ; i < n ; i++){
            prefixMax[i] = max(height[i],prefixMax[i-1]) ; //O(n)
        }

        // finding max element from the right 
        suffixMax[n-1] = height[n-1] ;

        for(int i = n-2 ; i >= 0 ; i--){
            suffixMax[i] = max(height[i],suffixMax[i+1]) ;//O(n)
        }

        int total = 0 ; 

        for(int i = 0 ; i < n ; i++){
            if(height[i] < prefixMax[i] && height[i] < suffixMax[i]){
                total += min(prefixMax[i],suffixMax[i]) - height[i] ; // O(n)
            }
        }

        return total ;
    }

    // Approach - II
    
    int trap2(vector<int>& height) { 
        int n = height.size() ;

    }

};