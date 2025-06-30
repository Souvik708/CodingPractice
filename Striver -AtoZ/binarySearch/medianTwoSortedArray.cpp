#include <bits/stdc++.h>

using namespace std ;

vector<int> mergeSortedArray(vector<int>& a ,vector<int>& b){
    int n = a.size() ;
    int m = b.size() ;

    vector<int> result ;

    int i = 0 ;
    int j = 0 ;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            result.push_back(a[i]) ;
            i ++ ;
        }
        else{
            result.push_back(b[j]) ;
            j ++ ;
        }
    }
    while(i < n){
        result.push_back(a[i]) ;
        i ++ ;        
    }
    while(j < m){
        result.push_back(b[j]) ;
        j ++ ;
    }
    for(auto it : result){
        cout << it << " " ;
    }
    cout << endl ;
    return result ;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> result = mergeSortedArray(nums1,nums2) ;
    int n = result.size() ;

    if(n % 2 == 1){
        return (double)result[n/2] ;
    }
    else{
        int mid1 = n/2 ;
        int mid2 = mid1 - 1 ;

        return (((double)result[mid1] + (double)result[mid2])/(double)2) ;
    }
    return -1 ;
}
    int maxNonDecreasingLength(vector<int>& nums) {
    vector<int> st;
    for (int x : nums) {
        int m = x;
        while (!st.empty() && st.back() > m) {
            m = max(m, st.back());
            st.pop_back();
        }
        st.push_back(m);
    }
    return (int)st.size();
    }

int main(){
    vector<int>nums1 = {19,80,63,74} ;
    vector<int>nums2 = {3,4} ;
    cout << maxNonDecreasingLength(nums1) << endl ;
    return 0 ;
}