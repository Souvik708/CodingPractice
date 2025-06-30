#include<bits/stdc++.h>

using namespace std ;

string removeOuterParentheses(string s){
    stack<char> st ;
    int n = s.length() ;
    if(n == 0) return "" ;
    // ??
}

string reverseWords(string s) {
    string r ;
    string word ="" ;
    int n = s.length() ;
    for(int i = n-1 ; i >= 0 ; i--){
        if(s[i] != ' '){
            word = s[i] + word ;
        }
        else if(!word.empty()){
            if(!r.empty()){
                r += ' ' ;
            }
            r += word ;
            word ="" ; 
        }
    }
    if(!word.empty()){
        if(!r.empty()){
            r += ' ' ;
        }
        r += word ; 
    } 
    return r ;
}

int main(){
    string s = " souvik sarkar " ;
    cout << reverseWords(s) ;
    return 0 ;
}