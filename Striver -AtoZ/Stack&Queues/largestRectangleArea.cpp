#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size() ;
        stack<int> st ;

        vector<int> nse(n,-1) ;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
            }
            nse[i] = st.empty() ? n : st.top() ;
            st.push(i) ;
        }

        while (!st.empty()) st.pop();

        vector<int> pse(n,-1) ;
        for(int i = 0 ; i <= n-1 ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop() ;
            }
            pse[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ;
        }

        int area = -1 ;

        for(int i = 0 ; i < n ; i++){
            int a = heights[i] * (nse[i] - pse[i] -1) ;
            area = max(area, a) ;
        }   

        return area ;     
    }
    int largestRectangleArea2(vector<int>& heights) {
        int n = heights.size() ;
        stack<int> st ;

        int maxArea = 0 ;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i] ){
                int ele = st.top() ;
                st.pop() ;
                int nse = i ;
                int pse = st.empty() ? -1 : st.top() ;
                int area = heights[ele] * (nse - pse - 1) ;
                maxArea = max(maxArea,area) ;
            }
            st.push(i) ;
        }
        while(!st.empty()){
            int ele = st.top() ;
            st.pop() ;
            int nse = n ;
            int pse = st.empty() ? -1 : st.top() ;
            int area = heights[ele] * (nse - pse - 1) ;
            maxArea = max(maxArea,area) ;
        }

        return maxArea ;          
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size() ;
        int c = matrix[0].size() ;

        vector<vector<int>> prefixMat(r,vector<int>(c,0)) ;

        
        for(int i = 0 ; i < c ; i ++){
            int prev = 0 ;
            for(int j = 0 ; j < r ; j++){
                if(matrix[j][i] != '0'){
                    prefixMat[j][i] = matrix[j][i]-'0' + prev ;
                    prev = prefixMat[j][i] ;                    
                }
                else{
                    prev = 0 ;
                }            
            }
        }
        int maxRect = 0 ;
        for(int i = 0 ; i < r ; i++){
            int rec = largestRectangleArea2(prefixMat[i]) ;
            maxRect = max(maxRect,rec) ;
        }  

        return maxRect ;       
    }
};

int main(){
    return 0 ;
}