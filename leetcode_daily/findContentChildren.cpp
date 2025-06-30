#include<bits/stdc++.h>

using namespace std ;

// int findContentChildren(vector<int>& g, vector<int>& s) {
//     int n1 = g.size() ;
//     int n2 = s.size() ;
//     int count =0 ;
//     for(int i = 0 ; i < n1 ; i++){
//         int pos = -1 ;
//         int c = INT_MAX ;
//         bool flag = false ;
//         for(int j = 0 ; j < n2 ; j++){
//             if(s[j] >= g[i]){
//                 flag = true ;
//                 if(c > s[j]){
//                     c = s[j] ;
//                     pos = j ;
//                 }
//             }
//         }
//         if(flag && pos != -1){
//             count ++ ;
//             s[pos] = -1 ;

//         }
//     }
//     return count ;
// }
int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size() ;
    int m = s.size() ;

    sort(g.begin() , g.end()) ;
    sort(s.begin() , s.end()) ;

    int i = 0 ;
    int j = 0 ;

    int count = 0 ;

    while(i < n && j < m){
        if(g[i] > s[j]){
            j++ ;
        }
        else{
            count ++ ;
            i++ ;
            j++ ;
        }
    }
    return count ;
}

int main(){
    vector<int> g ={1,2,3} ;
    vector<int> s ={3} ;
    cout << findContentChildren(g,s) << endl ;
    return 0 ;
}