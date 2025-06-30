#include <bits/stdc++.h>

using namespace std ;

class MyStack {
public:
    queue<int> q ; 
    MyStack() {

    }
    
    void push(int x) {
        int n = q.size() ;
        q.push(x) ;

        for(int i = 0 ; i < n ; i++){
            q.push(q.front()) ;
            q.pop() ;
        }       
    }
    
    int pop() {
        int n = q.size() ;
        if(n == 0) return -1 ;
        else{
            int a = q.front() ;
            q.pop() ;
            return a ;
        }        
    }
    
    int top() {
        int n = q.size() ;
        if(n == 0) return -1 ;
        else{
            return q.front() ;
        }        
    }
    
    bool empty() {
        int n = q.size() ;
        if(n == 0) return true ;
        else return false ;        
    }
};

int main(){
    return 0 ;
}