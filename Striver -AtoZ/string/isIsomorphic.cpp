#include<bits/stdc++.h>

using namespace std ;

bool isIsomorphic(string s ,string t){
    if(s.length() != t.length()){
        return false ;
    }
    unordered_map<char,int> s_map ;
    unordered_map<char,int> t_map ;
    for(int i = 0 ; i < s.length() ; i++){
        s_map[s[i]] ++ ;
        t_map[t[i]] ++ ;
    }
    for(auto it :s_map){
        if(t_map.find(it.second) != s_map.end()){
            t_map.erase(t_map.find(it.second)) ;
            s_map.erase(it.first) ;
        } 
    }
    if(t_map.empty() && s_map.empty()){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    string  s = "egg", t = "add" ;
    cout << isIsomorphic(s,t) <<endl ;
    return 0 ;
}