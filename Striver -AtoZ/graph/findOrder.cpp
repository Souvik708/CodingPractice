#include <bits/stdc++.h>

using namespace std ;

class Solution {
  private:
    string topoSort(int n,vector<vector<int>> &adj,unordered_map<int, char> indexToChar){
        vector<int> indeg(n,0) ;
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                indeg[it] ++ ;
            }
        }

        queue<int> q ;
        vector<int> topo ;

        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0){
                q.push(i) ;
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            topo.push_back(node) ;

            for(auto it : adj[node]){
                indeg[it] -- ;
                if(indeg[it] == 0){
                    q.push(it) ;
                }
            }
        }
        string ans = "";
        for (auto it : topo) {
            ans += indexToChar[it];
        }

        return ans ;
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size() ;
        unordered_set<char> st ;

        for(int i = 0 ; i < n ; i ++){
            for(auto it : words[i]){
                st.insert(it) ;
            }
        }

        int numAlpha = st.size();
        unordered_map<char, int> charToIndex;
        unordered_map<int, char> indexToChar;
        int idx = 0;
        for (char ch : st) {
            charToIndex[ch] = idx;
            indexToChar[idx] = ch;
            idx++;
        }

        // creating the graph
        vector<vector<int>> adj(numAlpha) ;
        for(int i = 0 ; i < n-1 ; i++){
            string s1 = words[i] ;
            string s2 = words[i+1] ;
            int len = min(s1.length(),s2.length()) ;
            int flag = 0 ;
            for(int j = 0 ; j < len ; j ++){
                if(s1[j] != s2[j]){
                    flag = 1 ;
                    int u = charToIndex[s1[j]];
                    int v = charToIndex[s2[j]];

                    adj[u].push_back(v) ;
                    break ;
                }
            }
            if(!flag && s1.length() > s2.length()){
                return "" ;
            }
        }

        //topo sort
        string ans = topoSort(numAlpha,adj,indexToChar) ;

        if(ans.length() < numAlpha) return "" ;
        else return ans ;
        
    }
};