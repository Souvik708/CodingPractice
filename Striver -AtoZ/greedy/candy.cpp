#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    //Approach -1 
    int candy1(vector<int>& ratings) {
        int n = ratings.size() ;
        vector<int> left(n,1),right(n,1) ;

        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i+1] + 1 ;
            }
            else{
                left[i] = 1 ;
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1 ;
            }
            else{
                right[i] = 1 ;
            }
        }

        int sum = 0 ;

        for(int i = 0 ; i < n ; i++){
            sum += max(left[i],right[i]) ;
        }

        return sum ;
    }

    //Approach - 2
    int candy2(vector<int>& ratings) {
        int n = ratings.size() ;
        vector<int> left(n,1) ;

        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1 ;
            }
        }

        int sum = max(1,left[n-1]) ;

        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                left[i] = max(left[i+1] + 1,left[i]) ;
            }
            sum += left[i] ;
        }

        return sum ;
    }

    //Approach - 3
    int candy(vector<int>& ratings){
        int n = ratings.size() ;

        int sum = 1 ; 
        int i = 1 ;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum ++ ;
                i ++ ;
                continue;
            }
            int peak = 1 ;

            while(i < n && ratings[i] > ratings[i-1]){
                peak ++ ;
                sum += peak ;
                i ++ ;
            }

            int down = 1 ;
            while(i < n && ratings[i] < ratings[i-1]){
                down ++ ;
                sum += down ;
                i ++ ;
            }

            if(down > peak) sum += down - peak + 1 ;

        }

        return sum ;
    }
};