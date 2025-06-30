#include<bits/stdc++.h>

using namespace std ;

class Solution {
  public:
    
    void solve(int i , int j,int n  ,string move ,vector<string> &ans, vector<vector<int>> &visited , vector<vector<int>>& maze ){
        if(i == n-1 && j == n-1){
            ans.push_back(move) ;
        }
        //down
        if(i+1 < n && !visited[i+1][j] && maze[i+1][j] == 1){
            visited[i+1][j] = 1 ;
            solve(i+1,j,n,move + 'D', ans , visited,maze) ;
            visited[i+1][j] = 0 ;
        }
        //up
        if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1){
            visited[i-1][j] = 1 ;
            solve(i-1,j,n,move + 'U', ans , visited,maze) ;
            visited[i-1][j] = 0 ;
        }
        //left
        if(j-1 >= 0 && !visited[i][j-1] && maze[i][j-1] == 1){
            visited[i][j-1] = 1 ;
            solve(i,j-1,n,move + 'L', ans , visited,maze) ;
            visited[i][j-1] = 0 ;
        }
        //right
        if(j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1){
            visited[i][j+1] = 1 ;
            solve(i,j+1,n,move + 'R', ans , visited,maze) ;
            visited[i][j+1] = 0 ;
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size() ;
        vector<string> ans ;
        vector<vector<int>> visited(n, vector<int>(n,0)) ;
        
        if(maze[0][0] == 0) return ans ;

        visited[0][0] = 1 ;
        if(maze[0][0] == 1) solve(0,0,n,"",ans,visited,maze) ;
        
        return ans ;
    }
};