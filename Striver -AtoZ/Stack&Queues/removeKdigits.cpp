#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length() ;
        if(k >= n) return "0" ;
        vector<char> st ;
        string ans = "" ;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.back() > num[i] && k != 0){
                st.pop_back() ;
                k -- ;
            }
            st.push_back(num[i]) ;
        }
        while(k){
            st.pop_back() ;
        }
        int i = 0 ;
        while(i < st.size() && st[i] != '0'){
            i++ ;
        }
        while(i < n){
            ans += st[i] ;
        }

        return ans ;
    }
};

int main(){
    return 0 ;
}