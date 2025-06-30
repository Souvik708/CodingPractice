#include <bits/stdc++.h>

using namespace std ;

class MinStack {
public:
    stack<pair<int,int>> st ;
    int mini = INT_MAX ;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini,val) ;
        st.push({val,mini}) ;
    }
    
    void pop() {
        if(!st.empty()){
            return st.pop() ;
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first ;
        }            
    }
    
    int getMin() {
        if(!st.empty()){
            return st.top().second ;
        }        
    }
};


