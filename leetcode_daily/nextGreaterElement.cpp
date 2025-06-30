#include<bits/stdc++.h>

using namespace std ;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
int n1 = nums1.size() ;
int n2 = nums2.size() ;
vector<int> result ;
    for(int i = 0 ; i < n1 ; i++){
        int pos = 0 ;
        for(int j = 0 ; j < n2 ; j++){
            if(nums2[j] == nums1[i]){
                pos = j ;
                break ;
            }
        }
        bool flag = false ;
        for(int k = pos+1 ; k < n2 ; k++){
            if(nums2[k] > nums2[pos]){
                flag = true ;
                result.push_back(nums2[k]) ;
                break ;
            }
        }
        if(flag == false){
            result.push_back(-1) ;   
        }
    }
    return result ;
}

int main(){
    vector<int> nums1 = {4,1,2} ;
    vector<int> nums2 ={1,3,4,2} ;
    vector<int> result = nextGreaterElement(nums1,nums2) ;
    for(auto it : result){
        cout << it << " " ;
    }
    cout << endl ;
    return 0 ;
}