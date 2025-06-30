#include <bits/stdc++.h> 

using namespace std ;

void printN(int n){
    if(n == 1){
        cout << n << endl ;
    }
    else{
        cout << n << endl ;
        printN(n-1) ;
    }
}

int sumN(int n){
    int sum= 0 ;
    if(n == 1){
        return 1;    
    }
    else{
        return (n + sumN(n-1)) ;
    }
}

int factorialN(int n){
    if (n == 1 || n == 0)
        return 1 ;

    else{
        return n * factorialN(n-1) ;
    }
}

int fibboN(int n){
    if (n ==1 || n== 2)
        return 1 ;
    else{
        return fibboN(n-1) + fibboN(n-2) ;
    }

}

int printArr(int arr[], int n){

    if(n == 0){
        cout << arr[0] <<" " ;
    }
    else{
        printArr(arr,n-1) ;
        cout << arr[n]<< " " ;
    }
    return 0;
}

int reverseArr(int arr[] , int i , int n){
    return 0 ;
}

bool palidrome(int i , string &s){
    if(i>=s.size()/2) return true ;
    if(s[i] != s[s.size()-i-1]) return false ;
    return palidrome(i+1,s) ;
}

int main(){
    int n = 10;
    string s = "SouuoS" ;
    cout << palidrome(0,s) ;
    cout << endl ;
    return 0;
}