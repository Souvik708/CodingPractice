#include <bits/stdc++.h>

using namespace std ;

class MyQueue {
public:
    stack<int> s1,s2 ;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
        s1.push(x) ;

        while(!s2.empty()){
            s1.push(s2.top()) ;
            s2.pop() ;
        }        
    }
    
    int pop() {
        if(!s1.empty()){
            int el = s1.top() ;
            s1.pop() ;
            return el ;
        }
        else return -1 ;        
    }
    
    int peek() {
        if(!s1.empty()){
            return s1.top() ;
        }
        return -1 ;        
    }
    
    bool empty() {
        if(s1.size() == 0) return true ;
        else return false ;        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */