#include <bits/stdc++.h>

using namespace std ;

long solve(string s, int st , long result , bool neg){
    if(st >= s.length()) return result ;
    if(!isdigit(s[st])){
        return result ;
    }
    else{
        int d = s[st] -'0' ;
        result = result * 10 + d ;
        if(neg){
            if(result < INT_MIN){
                return INT_MIN ;
            }
            else{
                return solve(s,st+1 , result, neg) ;        
            }
        }
        if(result > INT_MAX){
            return INT_MAX ;
        }
        return solve(s,st+1 , result, neg) ;
    }
}

int myAtoi(string s){
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;  // skip leading spaces

    if (i == n) return 0;

    bool neg = false;
    if (s[i] == '-' || s[i] == '+') {
        neg = (s[i] == '-');
        i++;
    }
    long ans = solve(s, i, 0 , neg) ;
    return neg ? -ans : ans ;
}

int main(){
    return 0 ;
}