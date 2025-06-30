#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(k >= n) return n ;

        int maxLength = 0 ;
        int numZeors = 0 ;

        int i = 0 , j = 0 ;

        while(j < n){
            if(nums[j] == 0){
                numZeors ++ ;
            }
            while(i <= j && numZeors > k){
                if(nums[i] == 0){
                    numZeors -- ;
                }
                i ++ ;
            }

            int length = j - i + 1 ;

            maxLength = max(maxLength,length ) ;

            j ++ ; 
        }

        return maxLength ;        
    }
};

int main(){
    return 0 ;
}