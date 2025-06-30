
#include <bits/stdc++.h>

using namespace std ;

    bool isValidInt(vector<int> &nums , int h){
        int prev = -1 ;
        for(auto it : nums){
            if(it > h){
                prev = it ;
                break ;
            }
        }
        for(auto it : nums){
            if(it > h && it != prev){
                return false ;
            }
        }
        return true ;
    }
    bool isEqual(vector<int> &nums , int k){
        for(auto it : nums){
            if(it != k){
                return false ;
            }
        }
        return true ;
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int>copy = nums ;
        sort(nums.begin() , nums.end()) ;
        for(auto it : nums){
            if(it < k) return -1 ;
        }
        int op = 0 ;
        for(int i = n-1 ; i >= 0 ; i--){
            if(isEqual(nums,k)){
                return op ;
            }
            if(isValidInt(nums,k)){
                return ++op ;
            }
            if(isValidInt(nums,copy[i])){
                for(int j = 0 ; j < n ; j++){
                    if(nums[j] > copy[i]){
                        nums[j] = copy[i] ;
                    }
                }
                op ++ ;
            }
        }
        return op ;
    }

int main(){
            unordered_set<int> s ;
            s.in
    vector<int> nums = {9,7,5,3} ;
    int k = 1 ;
    cout << minOperations(nums,k) ;
    return 0 ;
}