#include <bits/stdc++.h> 

using namespace std ;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        cin.ignore();
        string s ;
        getline(cin , s) ;
        int count = 0 ;
        int currentCount = 0 ;
       
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '.'){
                currentCount ++ ;
                count ++ ;
                if(currentCount == 3){
                    cout << 2 << endl ;
                    break; ;  
                }
            }
            else{
                currentCount = 0 ;
            }
        }
        if(currentCount != 3){
            cout << count << endl ; 
        }
    }

    return 0 ;
}