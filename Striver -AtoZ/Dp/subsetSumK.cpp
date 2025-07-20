#include <bits/stdc++.h>

using namespace std ;

class Solution {
  public:
        bool solve1(int index,vector<int>&arr,int sum){
        int n = arr.size() ;
        if(sum == 0) return true ;
        if(index == 0){
            return (arr[0] == sum) ;
        }
        bool nontake = solve1(index-1,arr,sum) ;
        bool take = false ;
        if(sum >= arr[index]){
            take = solve1(index-1,arr,sum-arr[index]) ;
        }

        return (take || nontake) ;
    }
    //2. 2nd type of recurrance 
    bool solve2(int index,int s,vector<int>&arr,int sum){
        int n = arr.size() ;
        if(index == n){
            if(s == sum){
                return true ;
            }
            else return false ;
        }
        if(solve2(index+1,s+arr[index],arr,sum)) return true ; 
        if(solve2(index+1,s,arr,sum)) return true ; 
        
        return false ;
    }
    //3. memorization

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size() ;
        return solve1(0,arr,sum) ;
    }
};