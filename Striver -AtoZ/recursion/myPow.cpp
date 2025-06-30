#include <bits/stdc++.h>

using namespace std ;

double solve(double x , long n){
    if(n == 0) return 1 ;
    else{
        if(n % 2 == 0){
            return solve(x*x,n/2) ;
        }
        else{
            return x * solve(x*x,(n-1)/2) ;
        }
    }
}

double myPow(double x, int n) {
    if(x == 0) return 0 ;
    if(n < 0){
        return solve(1/x,-n) ;
    }
    else{
        return solve(x,n) ;
    }
}

int main(){
    cout << myPow(2.000,-2) <<endl ;
    return 0 ;
}