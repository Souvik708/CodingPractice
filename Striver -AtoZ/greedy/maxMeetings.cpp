#include <bits/stdc++.h>

using namespace std ;

struct Data
{
    int start ;
    int end ;
    int pos ;
};


class Solution {
  public:
    static bool comp(Data d1 , Data d2){
        return d1.end < d2.end ;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size() ;
        vector<Data> meeting(n);

        for(int i = 0 ; i < n ; i++){
            meeting[i].start = start[i] ;
            meeting[i].end = end[i] ;
            meeting[i].pos = i ;
        }

        sort(meeting.begin() , meeting.end(),comp) ;
        
        int count = 1 ;
        int freeTime = meeting[0].end ;

        for(int i = 1 ; i < n ; i++){
            if(meeting[i].start > freeTime){
                count ++ ;
                freeTime = meeting[i].end ;
            }
        }

        return count ;
    }
};