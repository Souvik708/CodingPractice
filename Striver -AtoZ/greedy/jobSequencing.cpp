#include <bits/stdc++.h>

using namespace std ;

struct Job{
    int deadline;
    int profit ;
};

class Solution {
  public:

    static bool comp(Job j1 , Job j2){
        return j1.profit > j2.profit ;
    } 

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size() ;
        vector<Job> jobs(n) ;

        int maxDeadline = 0 ;

        for(int i = 0 ; i < n ; i++){
            jobs[i].deadline = deadline[i] ;
            jobs[i].profit = profit[i] ;
            maxDeadline = max(maxDeadline,deadline[i]) ;
        }

        map<int,int> hash ;
        for(int i = 0 ; i <= maxDeadline ; i++ ) 
            hash[i] = -1 ;

        sort(begin(jobs),end(jobs),comp) ;

        int maxProfit = 0 ;
        int count  = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = jobs[i].deadline ; j > 0 ; j--){
                if(hash[j] == -1){
                    count ++ ;
                    maxProfit += jobs[i].profit ;
                    hash[j] = i ;
                    break ;
                }
            }
        }

        return {count,maxProfit} ;
    }
};