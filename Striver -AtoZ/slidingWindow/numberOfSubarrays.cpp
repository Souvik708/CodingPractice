#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
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
            j ++ ;
        }
        return count ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 1) nums[i] = 1 ;
            else nums[i] = 0 ;
        }
        int count = atMost(nums,k) - atMost(nums,k-1) ;

        return count ;               
    }
};

int main(){
    return 0 ;
}