#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n ;
        int flag = 0 ;
        cin >> n ;
        vector<int> a(n,0) ;
        for(int i =0 ; i < n ; i++){
            cin >> a[i] ;
        }
        vector<int> freq(10,0) ;
        for(int i = 0 ; i < n ; i++){
            freq[a[i]] ++ ;
            if(freq[0] >= 3 && freq[1] >= 1 && freq[2] >= 2 && freq[3] >= 1 && freq[5] >= 1){
                flag = 1 ;
                cout << i+1 << endl ;
                break ;
            }
        }
        if(flag == 0){
            cout << 0 << endl ;
        }
    }
    return 0 ;
}
