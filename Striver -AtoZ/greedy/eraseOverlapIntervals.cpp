#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>v2){
        return v1[1] < v2[1] ;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        sort(begin(intervals),end(intervals),comp) ;

        int count = 1 ;
        int freeTime = intervals[0][1] ;

        for(int i = 1 ; i < n ; i++){
            if(freeTime <= intervals[i][0]){
                count ++ ;
                freeTime = intervals[i][1] ;
            }
        }

        return n - count ;
    }
};