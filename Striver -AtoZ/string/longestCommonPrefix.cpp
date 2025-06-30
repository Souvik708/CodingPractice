#include <bits/stdc++.h>

using namespace std ;

string longestCommonPrefix(vector<string>& strs){
    int n = strs.size() ;
    int pos =-1 ;
    int minLen = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        if(strs[i].length() < minLen){
            minLen = strs[i].length() ;
            pos = i ;
        }
    }
    string prefix = "" ;
    for(int i = 0 ; i < minLen ; i++){
        bool flag = true ;
        char ch = strs[pos][i] ;
        for(int j = 0 ; j < n ; j++){
            if(ch != strs[j][i]){
                flag = false ;
                break ;
            } 
        }
        if(flag) prefix += ch ;
        else break; ;
    }
    return prefix ;
}

int main(){
    vector<string>str = {"dog","racecar","car"} ;
    cout << longestCommonPrefix(str) <<endl ;
    return 0 ;
}