#include<bits/stdc++.h>

using namespace std ;

int maxDepth(string s){
    int n = s.length() ;
    //stack<char> st ;
    int maxi = 0 ;
    int depth = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '('){
            depth ++ ;
        }
        else if(s[i] == ')'){
            maxi = max(maxi,depth) ;
            depth -- ;
        }
    }
    return maxi ;
}

int main(){
    string s = "()(())((()()))";
    cout << maxDepth(s) << endl ;
    return 0 ;
}