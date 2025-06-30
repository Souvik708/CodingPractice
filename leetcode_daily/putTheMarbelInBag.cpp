#include <bits/stdc++.h>

using namespace std ;

long long putMarbles(vector<int>& weights, int k) {
    int n = weights.size() ;
    vector<long long> pairSum(n-1,0) ;
    for(int i = 0 ; i < n-1 ; i++){
        pairSum.push_back(weights[i]+weights[i+1]) ;
    }
    sort(pairSum.begin() ,pairSum.end()) ;
    long long minSum ,maxSum ;
    for(int i = 0 ; i < k - 1 ; i++){ // we always have take k-1 pair
        minSum += pairSum[i] ;
        maxSum += pairSum[n-2-i] ; // pairSum size is (n-1), So last index is (n-1)-1-i
    }
    return maxSum -minSum ;
}

int main(){
    return 0 ;
}