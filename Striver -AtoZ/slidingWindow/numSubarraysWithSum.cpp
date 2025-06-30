#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    //Approach - 1
    int numSubarraysWithSum1(vector<int>& nums, int goal) {
        int n = nums.size() ;
        unordered_map<int,int> mp ;
        mp[0] = 1 ;

        int i = 0 ,  j = 0 ;
        int sum = 0 ;
        int count = 0 ;

        for(int i = 0 ; i < n ; i++){
            sum += nums[i] ;
            int remain = sum - goal ;
            count += mp[remain] ;
            mp[sum] ++ ;
        }
        return count ;       
    }
    //Approach -2 (Optimal)
    int atMost(vector<int> &nums,int goal){
        if(goal < 0) return 0 ;
        int n = nums.size() ;
        int count = 0 ;
        int sum = 0 ;

        int i = 0 , j = 0 ;

        while(j < n){
            sum += nums[j] ;

            while(i <= j && sum > goal){
                sum -= nums[i] ;
                i ++ ;
            }

            count += (j - i + 1) ;
        }
        return count ;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = atMost(nums,goal) - atMost(nums,goal-1) ;
        return count ;
    }


};

int main(){
    return 0 ;
}