#include<bits/stdc++.h>

using namespace std ;

string largestOddNumber(string nums){
    int n = nums.length() ;
    bool flag = false ;
    int i ;
    for(i = n-1 ; i >=0 ; i--){
        int d = (nums[i] + 0) - 48 ;
        if(d % 2 == 1){
            flag = true ;
            break ;
        }
    }
    if(flag) return nums.substr(0,(i+1)) ;
    else return "" ;
}

int main(){
    string nums ="7542351161" ;
    cout << largestOddNumber(nums) <<endl ;
    return 0 ;
}