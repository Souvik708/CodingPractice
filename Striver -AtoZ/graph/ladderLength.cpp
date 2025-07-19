#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st ;
        for(auto it : wordList){
            st.insert(it) ;
        }
        queue<pair<string,int>> q ;
        q.push({beginWord,1}) ;
        st.erase(beginWord) ;

        while(!q.empty()){
            string word = q.front().first ;
            int l = q.front().second ;
            q.pop() ;
            if(word == endWord) return l ;

            for(int i = 0 ; i < word.length() ; i++){
                string w = word ;
                for(char ch ='a' ; ch <= 'z' ; ch++){
                    w[i] = ch ;
                    if(st.find(w) != st.end()){
                        q.push({w,l+1}) ;
                        st.erase(w) ;
                    }
                }
            }
        }

        return 0 ;
    }
};