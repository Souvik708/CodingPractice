#include <bits/stdc++.h>

using namespace std ;

vector<int> findEvenNumbers(vector<int>& digits) {
    int n = digits.size() ;
    vector<int> fq(10,0) ;
    for(auto it : digits){
        fq[it] ++ ;
    }
    vector<int> result ;
    for(int i = 1 ; i < 9 ; i++){
        if(fq[i] == 0) continue ;
        fq[i] -- ;
        for(int j = 0 ; j < 9 ; j++){
            if(fq[j] == 0) continue ;
            fq[j] -- ;
            for(int k = j+1 ; k < n ; k++){
                if(fq[j] == 0) continue ;
                fq[j] -- ;
                int num = 0 ;
                num = digits[i]*100 + digits[j]*10 + digits[k] ;
                if(num % 2 == 0){
                    result.push_back(num) ;
                }
                fq[k] ++ ;
            }
            fq[j] ++ ;
        }
        fq[i] ++ ;
    }
    return result ;
}



int main(){
    return 0 ;
}