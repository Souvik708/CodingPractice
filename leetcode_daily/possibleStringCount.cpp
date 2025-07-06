#include <bits/stdc++.h>

using namespace std ;




    int possibleStringCount(string word) {
        int n = word.length() ;
        int count = 1;

        for(int i = 1 ; i < n ; i++){
            if(word[i] == word[i-1]){
                count ++ ;
            }
        }
        return count ;       
    }


int main(){
    string s = "abbcccc" ;
    cout << possibleStringCount(s)  ;
}