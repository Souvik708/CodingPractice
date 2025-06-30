#include <bits/stdc++.h>

using namespace std ;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size() ;
        sort(begin(arr),end(arr)) ;
        sort(begin(dep),end(dep)) ;

        int i = 0 , j = 0 ;
        int maxCount = 0 ;
        int count = 0 ;

        while(i < n){
            if(arr[i] <= dep[j]){
                count ++ ;
                i ++ ;
            }
            else{
                count -- ;
                j ++ ;
            }

            maxCount = max(maxCount,count) ;
        }

        return maxCount ;
    }
};
