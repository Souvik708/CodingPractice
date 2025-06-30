#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

bool isSorted(int a[] , int n){
    for(int i = 1 ; i< n ; i++){
        if(a[i] >= a[i-1]){

        }
        else{
            return false ;
        }
    }
    return true ;
}

int duplicate(int a[] , int n){
    int j= 0 ;
    for(int i=1 ; i<n ; i++ ){
        if(a[i]!=a[j]){
           a[j+1] = a[i] ; 
           j++ ;
        }
    }
    return (j+1) ;
}
void leftRotation(int a[], int n, int d){
    reverse(a,a+d) ;
    reverse(a+d,a+n);
    reverse(a,a+n) ;
    for(int i=0 ; i< n ; i++){
        cout << a[i] << " " ;
    }
}
void moveZeroes(vector<int>& nums) {
        vector<int>temp ;
        for(int i=0 ; i< nums.size() ; i++){
            if(nums[i]!=0)
                temp.push_back(nums[i]) ;
        }
        for(int i=0 ; i<temp.size() ; i++)
            nums[i] = temp[i] ;
        for(int i=temp.size(); i<nums.size() ; i++)
            nums[i] = 0 ;
        for(auto it:nums) cout << it << "," << endl ;
}
void moveZeroes_optimal(vector<int>& nums) {
        int n = nums.size() ;
        int j= -1 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i]==0){
                j=i ;
                break ;
            }
        }
        for(int i = j+1 ; i<n ; i++){
            if(nums[i]!= 0 ){
                swap(nums[i],nums[j]) ;
                j++ ;
            }
        }
        for(auto it:nums) cout << it << "," << endl ;
}

    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct
        vector<int> union1 ;
        int i=0,j =0 ;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                if(union1.back()!= a[i] || union1.size()== 0){
                union1.push_back(a[i]) ;
                }
                i++ ;
                
            }
            if(a[i]>b[j]){
                if(union1.back()!= b[j] || union1.size()== 0){
                union1.push_back(b[j]) ;
                }
                j++ ;
                
            }
            else{
                if(union1.back()!= a[i] || union1.size()== 0){
                union1.push_back(a[i]) ;
                }
                i++ ;
                j++ ;
                
            }
        }
        while(i<a.size()){
            union1.push_back(a[i]);
            i++ ;
        }
        while(j<b.size()){
            union1.push_back(b[j]);
            j++ ;
        }
        return union1 ;
    }

int findMaxConsecutiveOnes(vector<int>& nums) {
int count= 0 ;
int maxCount = 0;
for(auto it : nums){
    if(it!=0){
        count++ ;
        maxCount=max(maxCount,count) ;
    }
    else{
        count = 0 ;
    }
}
return maxCount ;       
}

int longestSubArrayWithSumK(vector<int> &nums,int k){
    int right =0 , left = 0 ;
    long long sum = nums[0] ;
    int maxLen =0 ;
    while(right < nums.size()){
        while(left <= right && sum > k){
            sum -= nums[left] ;
            left ++ ; 
        }
        if(sum == k){
            maxLen = max(maxLen , right - left +1) ;
        }
        right ++ ;
        sum += nums[right] ;
    }
    return maxLen ;
}
vector<int> twoSum(vector<int>& nums, int target) {
   vector<int>indices ;
   int right = nums.size() -1 , left = 0 ;
   while(left <= right){
    if(nums[right]+nums[left] == target){
        indices.push_back(left) ;
        indices.push_back(right) ;
        return indices ;
    }
    else if(nums[right]+nums[left] > target) right -- ;
    else left ++ ;    
    }
    return indices ;
}

int main(){
    vector<int>n1 = {1,2,3,4} ;
    vector<int>index ;
    index =  twoSum(n1,6) ;
    for(auto it : index){
        cout << it << " " ;
    }
    cout << endl ;
    return 0 ;
}