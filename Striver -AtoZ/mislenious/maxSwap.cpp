#include <bits/stdc++.h>

using namespace std ;

class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num) ; 

        int firstD = -1 ;
        int i = 0 ;  

        while(i < n.length()){
            if(n[i] < 9) firstD = i ;
            i ++ ;
            break ;
        }
    }
};

int main(){
    return 0 ;
}