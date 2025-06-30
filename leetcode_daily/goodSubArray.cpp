#include <bits/stdc++.h>

using namespace std ;

long long countGood(vector<int>& nums, int k) {
    int n = nums.size() ;

    int i = 0 ; 
    int j = 0 ;

    unordered_map<int,int> mpp ;

    long long pair = 0 ;
    long long result = 0 ;

    while(j < n){
        pair += mpp[nums[j]] ;
        mpp[nums[j]] ++ ;

        while (pair >= k)
        {
            result += (n-j) ;
            mpp[nums[i]] -- ;
            pair -= mpp[nums[i]] ;
            i++ ;
        }
        j++ ;
    }
    return result ;
}

int main(){
    vector<int> nums = {3,1,4,3,2,2,4} ;
    int k = 2 ;
    cout << countGood(nums,k) << endl ;
    return 0 ;
}