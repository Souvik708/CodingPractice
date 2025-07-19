#include <bits/stdc++.h>

using namespace std ;

class DisjiontSets{
    vector<int> rank,parent,size ;
public :
    DisjiontSets(int n){
        rank.resize(n+1,0) ;
        parent.resize(n+1) ;
        size.resize(n+1,1) ;
        for(int i = 0 ; i  <= n ; i++){
            parent[i] = i ;
        }
    }

    int findUparent(int u){
        if(u == parent[u]) return u ;
        else{
            return parent[u] = findUparent(parent[u]) ;
        }
    }

    void unionRank(int u, int v){
        int ulp_u = findUparent(u) ;
        int ulp_v = findUparent(v) ;
        if(ulp_u == ulp_v) return ;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
            

        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUparent(u) ;
        int ulp_v = findUparent(v) ;
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u ;            
        }
        else{
            parent[ulp_v] = ulp_u ;
            rank[ulp_u] ++ ;

        }
    }
};

int main(){
    DisjiontSets ds(7) ;
    ds.unionBySize(1,2) ;
    ds.unionBySize(2,3) ;
    ds.unionBySize(4,5) ;
    ds.unionBySize(6,7) ;
    ds.unionBySize(5,6) ;
    if(ds.findUparent(3) == ds.findUparent(7)){
        cout << "same\n" ;
    }
    else{
        cout << "not same\n" ;
    }
    ds.unionBySize(3,7) ;
    if(ds.findUparent(3) == ds.findUparent(7)){
        cout << "same\n" ;
    }
    else{
        cout << "not same\n" ;
    }
    return 0 ;
}