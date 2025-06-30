#include<bits/stdc++.h>

using namespace std ;

int numberOfArrays(vector<int>& differences, int lower, int upper) {
    int n = differences.size() ;
    vector<int>hidden(n+1,0) ;
    int count = 0 ;
    for(int i = lower ; i<= upper ; i++){
        hidden[0] = i ;
        bool flag = true ;
        for(int j = 0 ; j < n ; j++){
            if(hidden[j] + differences[j] >= lower && hidden[j] + differences[j] <= upper){
                hidden[j+1] = hidden[j] + differences[j] ;
            }
            else{
                flag = false ;
                break ;
            }
        }
        if(flag){
            // for(auto it : hidden){
            //     cout << it << " " ;
            // }
            cout << endl ;
            count++ ;
        }
    } 
    return count ;   
}

int main(){
    vector<int>differences = {1,-3,4} ;
    int upper = 6, lower = 1 ;
    cout << numberOfArrays(differences,lower,upper) ;
    return 0 ;
}