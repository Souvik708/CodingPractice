#include <bits/stdc++.h>

using namespace std ;

//1) print name 5 times
void solve(int counter){
    if(counter == 5){
        return ;
    }
    else{
        cout << "Souvik" << endl ;
        solve(counter+1) ;
    }
}
//2)Print linearly from 1 to N
void solve_2(int n){
    if(n == 0) return ;
    solve_2(n-1) ;
    cout << n << endl ;
}
//3)Print linearly from N to 1
void solve_3(int n){
    if(n == 0) return ;
    cout << n << endl ;
    solve_3(n-1) ;
}


int main(){
    int counter = 0 ;
    solve_3(10) ;
    return 0 ;
}