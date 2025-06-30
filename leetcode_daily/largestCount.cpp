#include<bits/stdc++.h>

using namespace std ;

int digitSum(int n){
    int sum = 0 ;
    while(n > 0){
        sum += n % 10 ;
        n = n/10 ;
    }
    return sum ;
}

int countLargestGroup(int n) {
    unordered_map<int,int> mpp ;
    for(int i = 1 ; i <= n ; i++){
        mpp[digitSum(i)] ++ ;
    }
    int maxi = 0 ;
    for(auto it : mpp){
        if(maxi < it.second){
            maxi = it.second ;
        }
    }
    int count = 0 ;
    for(auto it : mpp){
        if(maxi == it.second){
            count ++ ;
        }
    }
    return count ;
}

int main(){
    int n = 13 ;
    cout << countLargestGroup(13) ;
    return 0 ;
}