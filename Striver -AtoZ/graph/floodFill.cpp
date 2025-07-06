#include <bits/stdc++.h>

using namespace std ;

class Solution {
private:
    // 1.DFS approach
    void dfs(int row,int col , int initial , int color , vector<vector<int>>& ans, int n , int m , int drow[] ,int dcol[]){
        ans[row][col] = color ;

        for(int i = 0 ; i < 4 ; i++){
            int nr = row + drow[i] ;
            int nc = col + dcol[i] ;

            if(nc >= 0 && nc < m && nr >= 0 && nr < n && ans[nr][nc] == initial && ans[nr][nc] != color){
                dfs(nr,nc,initial,color,ans,n,m,drow,dcol) ;
            }
        }
    }
public:
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() ;
        int m = image[0].size() ;
        vector<vector<int>>ans =  image ;

        int iniColor = image[sr][sc] ;

        int drow[] = {-1,0,+1,0} ;
        int dcol[] = {0,+1,0,-1} ;

        dfs(sr,sc,iniColor,color,ans,n,m,drow,dcol) ;

        return ans ;
    }

    //2.BFS approach
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() ;
        int m = image[0].size() ;
        vector<vector<int>>ans =  image ;
        queue<pair<int,int>> q ;

        int iniColor = image[sr][sc] ;
        q.push({sr,sc}) ;

        int drow[] = {-1,0,+1,0} ;
        int dcol[] = {0,+1,0,-1} ;

        while(!q.empty()){
            int r = q.front().first ;
            int c = q.front().second ;
            ans[r][c] = color ;
            q.pop() ;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + drow[i] ;
                int nc = c + dcol[i] ;

                if(nc >= 0 && nc < m && nr >= 0 && nr < n && ans[nr][nc] == iniColor && ans[nr][nc] != color){
                    q.push({nr,nc}) ;
                }
            }
        }

        return ans ;
    }
};