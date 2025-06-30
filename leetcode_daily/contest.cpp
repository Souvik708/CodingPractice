#include<bits/stdc++.h>

using namespace std  ;

int maxFreqSum(string s) {
    int n = s.length () ;
    unordered_map<char,int> mp ;

    for(int i = 0 ; i < n ; i++){
        mp[s[i]] ++ ;
    }
    int maxV = INT_MIN ;
    int maxC = INT_MIN ;

    for(auto it : mp){
        if(it.first == 'a' || it.first == 'e' ||it.first == 'i' ||it.first == 'o' ||it.first == 'u'){
            if(it.second > maxV){
                maxV = it.second ;
            }
        }
        else{
            if(it.second > maxC){
                maxC = it.second ;
            }            
        }
    }
    return maxV+maxC ;

}
bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;
        for (int i = 0; i < m; ++i) {
            totalSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        if (totalSum % 2 != 0) return false;
        
        long long halfSum = totalSum / 2;

        long long rowSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            rowSum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if (rowSum == halfSum) return true;
        }

        vector<long long> colSums(n, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colSums[j] += grid[i][j];
            }
        }

        long long verticalSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            verticalSum += colSums[j];
            if (verticalSum == halfSum) return true;
        }

        return false;

}



int main(){
    int n = 0 ;
    vector<vector<int>>nums = {{14742,71685,59237,27190}} ;
    cout << canPartitionGrid(nums) <<endl ;
    return 0 ;
}