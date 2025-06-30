#include<bits/stdc++.h>

using namespace std ;

long long countSubarrays(vector<int>& nums, long long k) {
    int n = nums.size() ;
    int i = 0 , j = 0 ;
    long long sum = 0 ;
    long long score = 0 ;
    long long result = 0 ;

    while (j < n)
    {
        sum += nums[j] ;

        while(i <= j && sum * (j -i + 1) >= k){
            sum -= nums[i] ;
            i ++ ;
        }
        result += (j - i + 1) ;
        j ++ ;
    }
    return result ;
    
}

int main(){
    vector<int> nums = {2,1,4,3,5} ;
    long long k = 10 ;
    cout << countSubarrays(nums,k) << endl ;
    return 0 ;
}