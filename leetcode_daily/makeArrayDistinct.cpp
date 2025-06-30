#include <bits/stdc++.h>

using namespace std ;

bool isDistinct(vector<int>& nums){
    int n = nums.size() ;
    if(n < 3) return true ;
    vector<int>copy_nums = nums ;
    sort(copy_nums.begin() , copy_nums.end()) ;
    int current = copy_nums[0] ;
    for(int k = 1 ; k <= n-1 ; k++){
        if(copy_nums[k] == current){
            return false ;
            break ;
        }
        current = copy_nums[k] ;
    }
    return true ;
}

int minimumOperation(vector<int>& nums){
    int n = nums.size() ;
    if(n == 0) return 0 ;
    if(n < 3) return 1 ;
    int result = 0 ;
    int i = 0 ;
    while(nums.size() != 0){
        if(isDistinct(nums)){
            if(nums.size() < 3){
                return result++ ;
            }
            return result ;
        }
        else{
            result ++ ;
            nums.erase(nums.begin(),nums.begin()+3) ;
        }
    }
}

int main(){
    vector<int> nums = {4,5,6,4,4} ;
    cout << minimumOperation(nums) <<endl ;
    return 0 ;
}