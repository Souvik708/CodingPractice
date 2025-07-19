#include <bits/stdc++.h>

using namespace std ;

// User function Template for C++
queue<pair<int,int>> q ;
class Solution {
  private:
    void bfs(int r,int c,vector<vector<int>>& visited,vector<vector<int>>& grid){
        int n = grid.size() ;
        int m = grid[0].size() ;
        visited[r][c] = 1 ;
        q.push({r,c}) ;

        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;

            int drow[] = {-1,-1,0,+1,+1,+1,0,-1} ;
            int dcol[] = {0,+1,+1,+1,0,-1,-1,-1} ;

            for(int i = 0 ; i < 8 ; i++){
                int nr = row + drow[i] ;
                int nc = col + dcol[i] ;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1){
                    visited[nr][nc] = 1 ;
                    q.push({nr,nc}) ;
                }
            }
        }

    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> visited(n,vector<int>(m,0)) ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && !visited[i][j] ){
                    count ++ ;
                    bfs(i,j,visited,grid) ;
                }
            }
        }
        return count ;
    }
};
