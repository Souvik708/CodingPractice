#include <bits/stdc++.h>

using namespace std ;

long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size() ;
    int maxi = INT_MIN ;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] > maxi){
            maxi = nums[i] ;
        }
    }

    long long maxFrequency = 0 ;
    int i = 0;
    int j= 0 ;
    long long result = 0 ;
    while( j < n){
        if(nums[j] == maxi ){
            maxFrequency ++ ;
        }
        while(i <= j && maxFrequency >= k){
            result += (n - j) ;
            if(nums[i] == maxi) maxFrequency -- ;
            i ++ ;
        }
        j ++ ;
    }
    return result ;
}

int main(){
    vector<int> nums = {1,3,2,3,3} ;
    int k = 2 ;
    cout << countSubarrays(nums,k) << endl ;
    return 0 ;
}