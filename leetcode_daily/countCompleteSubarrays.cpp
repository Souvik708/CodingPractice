#include <bits/stdc++.h>

using namespace std ;

int distinctCount(vector<int>& nums){
    int n = nums.size() ;
    unordered_set<int> st ;
    for(int i = 0 ; i < n ; i++){
        st.insert(nums[i]) ;
    }
    return st.size() ;
}

int countCompleteSubarrays(vector<int>& nums){
    int n = nums.size() ;
    int totalDistinct = distinctCount(nums) ;
    unordered_map<int,int> mp ;
    int count = 0 ;
    int i =0 ;
    int j = 0 ;

    while( j < n){
        mp[nums[j]] ++ ;

        while(i <= j && mp.size() == totalDistinct){
            count += (n-j) ;
            mp[nums[i]] -- ;
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]) ;
            }
            i ++ ;
        }
        j++ ;
    }
    return count ;
}

int main(){
    vector<int> nums= {1,3,1,2,2} ;
    cout << countCompleteSubarrays(nums) << endl ;
    return 0 ;
}