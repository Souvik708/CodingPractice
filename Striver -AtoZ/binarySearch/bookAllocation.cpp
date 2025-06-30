#include<bits/stdc++.h>

using namespace std ;

int validBookAllocation(vector<int>& nums, int k , int p){
    int n = nums.size() ;
    int sum = nums[0] ;
    int count = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(sum + nums[i] <= p){
            sum = sum + nums[i] ;
        }
        else{
            sum = nums[i] ;
            count ++ ;
        }
    }
    return count ;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size() ;
    int first = nums[0] , second = INT_MIN ;
    for(int i = 1 ; i < n ; i++ ){
        if(first < nums[i]){
            second = first ;
            first = nums[i] ;
        }
        if(second < nums[i] && nums[i] != first){
            second = nums[i] ;
        }
    }
    int low = first ;
    int high = accumulate(nums.begin(),nums.end(),0) ;

    while(low <= high){
        int mid = (low + high)/2 ;
        int scount = validBookAllocation(nums,k,mid) ;

        if(scount > k){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ; 
        }
    }
    return low ;
}

int main(){
    vector<int> nums = {7,2,5,10,8} ;
    int k = 2 ;
    cout << splitArray(nums,k) << endl ;
    return 0 ;
}