#include <bits/stdc++.h>

using namespace std ;

vector<int> bfs(vector<vector<int>> &adj){
    int n = adj.size() ;
    vector<int> visited(n,0) ;
    queue<int> q ;
    vector<int> ans ;

    for(int i = 0 ; i < n ; i ++){
        if(!visited[i]){
            visited[i] = 1;
            q.push(i) ;
        
            while(!q.empty()){
                int node = q.front() ;
                ans.push_back(node) ;
                q.pop() ;

                for(auto it : adj[node]){
                    if(!visited[it]){
                        visited[it] = 1 ;
                        q.push(it) ;
                    }
                }
            }
        }
    }

    return ans ;
}

int main(){
    int n , m ;
    cin >> n >> m ;

    // 1. Adjacency matrix(undirected graph)
    int adj[n+1][n+1] ;
    for(int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }

    //2. Adjacency list(undirected graph)
    vector<int> list[n+1] ;
    for(int i = 0 ; i < m ; i++){
        int u , v ;
        cin >> u >> v ;
        list[u].push_back(v) ;
        list[v].push_back(u) ;
    }

    // 1. Adjacency matrix(undirected weighted graph)
    int adj[n+1][n+1] ;
    for(int i = 0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        adj[u][v] = w ;
        adj[v][u] = w ;
    }

    //2. Adjacency list(undirected graph)
    vector<pair<int,int>> list[n+1] ;
    for(int i = 0 ; i < m ; i++){
        int u , v , w ;
        cin >> u >> v >> w ;
        list[u].emplace_back(v,w) ;
        list[v].emplace_back(u,w) ;
    }

}