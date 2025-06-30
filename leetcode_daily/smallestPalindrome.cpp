#include <bits/stdc++.h>

using namespace std ;

    string smallestPalindrome(string s, int k) {
        int n = s.length() ;
        int half = n/2 ;

        string first = s.substr(0,half) ;
        string second = s.substr(half) ;  

        sort(first.begin(), first.end());
        string p = first ;
        if(k > 1){ 
            for(int i = 0 ; i < k-1 ; i++){
               next_permutation(p.begin(), p.end()) ;
               if(first == p) return "" ;
            }
        }
        first = p ;
        reverse(p.begin() , p.end()) ;
        if(n%2 == 0) return (first + p) ;
        else{
            return (first + s[half] + p) ;
        }

        return "" ;
    }

int main(){
    string s = "aa" ;
    int k = 2 ;
    cout << smallestPalindrome(s,k) << endl ;
    return 0 ;
}