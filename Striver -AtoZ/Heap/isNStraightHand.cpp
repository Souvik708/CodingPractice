#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size() ;
        if(n % groupSize != 0) return false ;
        int numGroups = n/groupSize ;
        map<int,int> mp ;

        for(auto it : hand){
            mp[it] ++ ;
        } 

        while(!mp.empty()){
            int curr = mp.begin() -> first ;
            for(int i = 0 ; i < groupSize ; i++){
                if(mp.find(curr + i) == mp.end()){
                    return false ;
                }
                mp[curr + i] -- ;
                if(mp[curr + i] == 0){
                    mp.erase(curr + i) ;
                }
            }
        } 

        return true ;      
    }
};

int main(){
    return 0 ;
}