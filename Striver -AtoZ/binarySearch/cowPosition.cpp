#include <bits/stdc++.h>

using namespace std ;

bool validCowPosition(vector<int>& nums, int distance,int c){
    int n = nums.size() ;
    int count = 1 ;
    int last = nums[0] ;
    for(int i = 1 ; i < n ; i++){
        int dis = nums[i] - last ;
        if(dis >= distance ){
            last = nums[i] ;
            count ++ ;
        }
    }
    if(count >= c) return true ;
    else return false ;
}

int cowPosition(vector<int>& nums , int c){
    int n = nums.size() ;
    int ans = 0 ;
    sort(nums.begin() , nums.end()) ;
    int low = 1 ;
    int high = (nums[n-1] - nums[0]) ;
    while(low <= high){
        int mid = (low + high)/2 ;
        if(validCowPosition(nums,mid,c)){
            ans = mid ;
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return high ;
}

int main(){
    vector<int> distance ={5,4,3,2,1,1000000000} ;
    int c = 2 ;
    cout << cowPosition(distance,c) << endl ;
    return 0 ;
}