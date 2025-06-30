#include<bits/stdc++.h>

using namespace std ;

void subsetSum(int ind , int sum , vector<int> &nums , vector<int> &ans){
    if(ind == nums.size()){
        ans.push_back(sum) ;
        return ;
    }
    subsetSum(ind+1,sum + nums[ind],nums,ans) ;
    subsetSum(ind+1,sum,nums,ans) ;
    return ;
}

void subsetSum2(int ind , int sum , vector<int> &nums , vector<int> &ans){
    if(ind == nums.size()){
        ans.push_back(sum) ;
        return ;
    }
    for(int i = ind ; i < nums.size() ; i ++){
        if(i > ind && nums[i] == nums[i-1]) continue ;
        subsetSum2(ind+1,sum + nums[ind],nums,ans) ;        
    }
    
    return ;
}

int main(){
    vector<int>nums = {3,4,1} ;
    vector<int>ans = {} ;
    subsetSum2(0,0,nums,ans) ;
    sort(begin(ans) ,end(ans)) ;
    for(auto it : ans){
        cout << it << " " ;
    }
    cout << endl ;
    return 0 ;
}