#include <bits/stdc++.h>

using namespace std ;

void solve(int index ,int n, int s , int sum , vector<int>& ds,int arr[]){
    if(index == n){
        if(s == sum){
            for(auto it : ds){
                cout << it << " " ;
            }
            cout << endl ;
        }
        return ;
    }
    //take
    ds.push_back(arr[index]) ;
    s += arr[index] ;
    solve(index+1,n,s,sum,ds,arr) ;
    ds.pop_back() ;
    s -= arr[index] ;
    //not take
    solve(index+1,n,s,sum,ds,arr) ;
}

bool solve2(int index ,int n, int s , int sum , vector<int>& ds,int arr[]){
    if(index == n){
        if(s == sum){
            for(auto it : ds){
                cout << it << " " ;
            }
            cout << endl ;
            return true ;
        }
        return false ;
    }
    //take
    ds.push_back(arr[index]) ;
    s += arr[index] ;
    if(solve2(index+1,n,s,sum,ds,arr) == true) return true  ;
    ds.pop_back() ;
    s -= arr[index] ;
    //not take
    if(solve2(index+1,n,s,sum,ds,arr) == true) return true  ;

    return false ;
}

int solve3(int index ,int n, int s , int sum , vector<int>& ds,int arr[]){
    if(index == n){
        if(s == sum){
            for(auto it : ds){
                cout << it << " " ;
            }
            cout << endl ;
            return 1 ;
        }
        return 0 ;
    }
    //take
    ds.push_back(arr[index]) ;
    s += arr[index] ;
    int l = solve3(index+1,n,s,sum,ds,arr)  ;
    ds.pop_back() ;
    s -= arr[index] ;
    //not take
    int r = solve3(index+1,n,s,sum,ds,arr)  ;

    return l+r ;
}

int main(){
    int n = 5 ;
    int sum = 3 ;
    int arr[] = {1,1,2,3,1} ;
    vector<int> ds ;

    cout << "No subs:" << solve3(0,n,0,sum,ds,arr) << endl ;
}