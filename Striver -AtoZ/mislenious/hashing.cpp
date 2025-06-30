#include <bits/stdc++.h>

using namespace std ;

int main(){
    int n ;
    cin >> n ;
    int arr[n] ;
    map<int,int> hash ;

    for (int i =0 ; i< n ; i++){
        cin >> arr[i] ;
    }

    int q ;
    cin >> q ;
    int e ;

    //pre computation
    for(int i = 0 ; i < n ; i++){
        hash[arr[i]]++ ;
    }
    //
    while(q--){
        cin >> e ;
        cout << hash[e] << endl ; 
    }



    return 0 ;
}

