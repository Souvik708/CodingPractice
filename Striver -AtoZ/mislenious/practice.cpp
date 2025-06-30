#include <bits/stdc++.h>

using namespace std ;

bool divideArray(vector<int>& nums) {
    map<int,int> mpp ;
    for(auto it : nums){
        mpp[it] ++ ;
    }
    bool flag = true ;
    for(auto it : mpp){
        if(it.second %2 == 1){
            return false ;
        }
    }
    return true ;        
}
bool isNice(vector<int>& nums , int i , int j){
    int mask = 0 ;
    if(i == j) return true ;
    for(int k = i ; k<=j ; k++){
        if((nums[k] & mask) == 0){
            mask = mask | nums[k] ;
        }
        else{
            return false ;
        }
    }
    return true ;
}
// int longestNiceSubarray(vector<int>& nums) {
//     int n = nums.size() ;
//     int maxLen = 1 ;
//     for(int i =0 ; i< n ; i++){
//         for(int j =i ; j<n ; j++){
//             if(isNice(nums,i,j)){
//                 maxLen = max(maxLen , j-i+1) ;
//             }
//             else{
//                 break ;
//             }
//         }
//     }
//     return maxLen ;
// }
int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size() ;
    int maxLen = 1 ;
    int left= 0;
    int right = 0 ;
    int mask = 0 ;
    while(left<= right && right<n){
        while((mask & nums[right]) != 0){
            mask = mask ^ nums[left] ;
            left ++ ;
        }
        if((mask & nums[right]) == 0){
            maxLen = max(maxLen, right-left+1);
        }
        right++ ;
    }
    return maxLen ;
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size() ;
    int carry = 0 ;
    for(int i = n-1 ; i >= 0 ; i--){
        if(i == n-1){
            if((digits[i]+ 1)> 9){
                digits[i] = 0 ;
                carry = 1;
            }
            else{
                digits[i] = digits[i] + 1 ;
                carry = 0 ;
            }                
        }
        else{
            if((digits[i]+ carry)> 9){
                digits[i] = 0 ;
                carry = 1;
            }
            else{
                digits[i] = digits[i] + carry ;
                carry = 0 ;
            }
        }
    }
    if(carry == 1) digits.insert(digits.begin(),1) ;
    return digits ;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans ;
    int i = 0 , j = 0 ;
    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            ans.push_back(nums1[i]) ;
            i ++ ;
        }
        else{
            ans.push_back(nums2[j]) ;
            j ++ ;
        }
    }
    while(i < m){
        ans.push_back(nums1[i]) ;
        i ++ ;            
    }
    while(j < n){
        ans.push_back(nums2[j]) ;
        j ++ ;            
    }
    for (int k = 0; k < m + n; k++) {
        nums1[k] = ans[k];
    }       
}
void transpose(vector<vector<int>>& matrix){
    int n = matrix.size() ;
    cout << "after Transpose : " << endl ;
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i > j){
                swap(matrix[i][j] , matrix[j][i]) ;
            }
        }
    }
        for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix[0].size() ;
    transpose(matrix) ;
    for(int i = 0 ; i < n ; i++){
        reverse(matrix[i].begin() , matrix[i].end()) ;
    }       
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}} ;
    int n = matrix.size() ;
    cout << "Before Rotation : " << endl;
        for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
    }
    rotate(matrix) ;
    cout << "after rotation :" << endl ;
    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}