#include <bits/stdc++.h>

using namespace std ;

bool rotateString(string s, string goal){
    int n = s.length() ;
    if( n != goal.length()) return false ;
    if(s == goal) return true ;

    if((s+s).find(goal) != string::npos) return true ;
    return false ;
}

int main(){
    string s = "defdefdefabcabc", goal = "defdefabcabcdef" ;
    cout << rotateString(s,goal) << endl ;
    return 0 ;
}