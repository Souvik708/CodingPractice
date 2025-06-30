#include<bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ;
        unordered_map<int,int> mp ;

        int i = 0 , j = 0 ;
        int maxLength = 0 ;

        while(j < n){
            mp[fruits[j]] ++ ;

            while(i <= j && mp.size() > 2){
                if(mp[fruits[i]] == 1){
                    mp.erase(fruits[i]) ;
                }
                else{
                    mp[fruits[i]] -- ;
                }
                i ++ ;
            }
            int length = j - i + 1 ;
            maxLength = max(maxLength,length) ;

            j ++ ;
        }

        return maxLength ;

    }
};

int main(){

}