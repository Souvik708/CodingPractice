#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() ;
        if(k >= n){
            return accumulate(cardPoints.begin(),cardPoints.end(),0) ;
        }
        int leftSum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0) ;
        int rightSum = 0 ;
        int maxSum = leftSum ;

        int right = n - 1 ;
        for(int i = k-1 ; i >= 0 ; i++){
            leftSum -= cardPoints[i] ;
            rightSum += cardPoints[right --] ;
            maxSum = max(maxSum, rightSum + leftSum) ;
        } 

        return maxSum ;       
    }
};