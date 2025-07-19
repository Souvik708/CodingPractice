#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st ;
        st.insert(wordList.begin(),wordList.end()) ;
        queue<vector<string>> q ;
        vector<vector<string>> ans ;

        q.push({beginWord}) ;
        st.erase(beginWord) ;

        while(!q.empty()){
            vector<string> seq = q.front() ;
            string word = seq[seq.size()-1] ;
            q.pop() ;
            if(word == endWord){ 
                ans.push_back(seq) ;
                continue;
            }

            for(int i = 0 ; i < word.length() ; i++){
                string w = word ;
                for(char ch = 'a' ; ch <= 'z' ; ch ++){
                    w[i] = ch ;
                    if(st.find(w) != st.end()){
                        vector<string> temp = seq ;
                        temp.push_back(w) ;
                        q.push(temp) ;
                    }
                }
            }
            st.erase(word) ;
        }
    }
};