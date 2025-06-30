#include <bits/stdc++.h>

using namespace std ;

int main(){
    int t  ;
    cin >> t ;
    while(t--){
        int n , x ;
        cin >> n >> x ;
        vector<int> a(n) ;
        for(int i = 0 ; i< n ; i++){
            cin >> a[i] ;
        }
        int maxDistance = INT_MIN ;
        for(int i = 0 ; i< n-1 ; i++){
           maxDistance = max((a[i+1] - a[i]) , maxDistance) ; 
        }
        maxDistance = max(maxDistance , (a[0] - 0)) ;
        maxDistance = max(maxDistance , (2*(x-a[n-1]))) ;
        cout << maxDistance << endl ;
    }
    return 0 ;
}