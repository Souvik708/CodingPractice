#include <bits/stdc++.h>

using namespace std ;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size() ;
        sort(begin(bt),end(bt)) ;
        long long wt  = 0;
        for(int i = 0 ; i < n ; i++){
            wt += bt[i]*(n-i-1);
        }

        return  wt/n ;
    }
};