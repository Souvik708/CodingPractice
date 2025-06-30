#include <bits/stdc++.h>

using namespace std ;

vector<int> partitionLabels(string s) {
    int n = s.length() ;
    vector<int> result ;

    // Storing the Last occuarance of ch = i ;
    vector<int> mpp (26,-1) ;
    for(int i = 0 ; i < n ; i++){
        int index = s[i] - 'a' ;
        mpp[index] = i ;
    }
    int i = 0 ;
    while(i < n){
        int end = mpp[s[i] - 'a'] ;
        int j = i ;

        while(j < end){
            end = max(end ,mpp[s[j] - 'a'] ) ;
            j ++ ;
        }
        result.push_back(j-i +1);
        i = j+1 ; 
    }
    return result ;
}

int main(){
    return 0 ;
}