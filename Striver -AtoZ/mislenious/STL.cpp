#include<bits/stdc++.h>

using namespace std ;

// Pairs
void explainPair(){
    pair<int,int> p = {1,3} ;
    cout << p.first <<p.second << endl ;

    pair<int,pair<int,int>> q = {1,{2,3}} ;
    cout << q.first << q.second.first << q.second.second << endl;

    pair<int,int> arr[] = {{1,2},{2,3},{3,4},{4,5}} ;
    cout << arr[1].first << endl ;
    cout << arr[1].second << endl ;

}

void explainVector(){

    // 1. Declearations 

    vector<int>v;
    v.push_back(1) ;
    v.emplace_back(2) ; //<- emplace_back is faster than push_back

    vector<pair<int,int>> vec ;
    vec.push_back({1,2}) ; // <- for the push back we have to write the pair in "{}" but for emplace we dont.
    vec.emplace_back(1,2) ;

    vector<int>v1(5,20) ;

    vector<int>v2(v1) ;

    // 2. Iterators

    v1 = {10,15,20,5,6,7} ;

    cout << v1[0] << " " << v1.at(0) ; // <-- two types of printing a[0] is more preferable

    vector<int>::iterator it = v1.begin() ;

    cout << *it++  <<  endl;


    //vector<int>::iterator it = v1.end() ;

    // vector<int>::iterator it = v1.rend() ;

    // vector<int>::iterator it = v1.rbegin() ;

    for(vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++){
        
        cout << *it << " " ;
    }

    for(auto it = v1.begin() ; it != v1.end() ; it++){
        
        cout << *it << " " ;
    }

    for(auto it : v1){       // <--- For each loop here "it" refers to "int"
        
        cout << it << " " ;
    }

    // 3. Erase

    // v1 = {10,15,20,5,6,7} 

    v1.erase(v1.begin()+1) ; // <-- this will delete 15 , so after v1 = {10,20,5,6,7}

    // Multiple deletion erase(begin add , end add) but end add should be not included [ begin, end)

    // want to delete 20 , 5 from v1 then add of 20 and add of 6 should be given

    v1.erase(v1.begin()+1, v1.begin()+3) ; // <-- this will delete 20 , 5

    // 4. Insert Function

    vector<int> v3 = {300,200,100} ;

    v3.insert(v3.begin()+1, 10) ; // <--  v3 = {300,10,200,100} 

    v3.insert(v3.begin()+1,2,5) ; // <--  v3 = {300,5,5,10,200,100} 

    vector<int> copy = {1,2,3,4} ;

    v3.insert(v3.begin(),copy.begin(),copy.end()) ; // <--  v3 = {1,2,3,4,300,5,5,10,200,100}

    // 5. Other Function

    cout << v3.size() ; // <--  10

    v3.pop_back() ; // <--  100

    vector<int> v4 = {1,2} ;

    v3.swap(v4) ;// <--  v4 = {1,2,3,4,300,5,5,10,200} , v3 = {1,2}

    v3.clear() ; // <-- {}

    //v3.empty() ; // <--- 0 (Not empty)

}

void explainList(){
    list<int> ls ;

    ls.push_back(1) ;
    ls.emplace_back(2) ;

    ls.push_front(6) ;

    ls.emplace_front(1) ;
}

void explainStack(){
    stack<int> st ;

    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    st.push(4) ;

    st.emplace(5) ;

    cout << st.top() ;

    st.pop() ;

    cout << st.size() ;
    cout << st.empty() ;

    stack<int> st1,st2 ;
    st1.swap(st2) ;
}

void explainQueue(){
    queue<int> q;

    q.push(1) ;
    q.push(2) ;
    q.push(3) ;

    q.emplace(4) ;

    q.back() += 5;

    cout << q.back() ;
    cout << q.front() ;

    q.pop() ;
}

void explainMap(){
    map<int,int> mpp ;
    map<int,pair<int,int>> mpp1 ;
    map<pair<int,int>,int> mpp2 ;

    mpp2[{1,1}]=2 ;
    mpp2[{1,2}]=3 ;
    mpp2[{1,3}]=4 ;
    mpp2[{1,4}]=5 ; 

    mpp2.insert({{1,5},6}) ;
    mpp2.emplace(make_pair(1,6),7) ;

    for(auto it : mpp2){
        cout <<"("<<it.first.first<<","<<it.first.second<<")"<<"-->"<< it.second << endl ;
    }
}

int main(){
    //explainPair() ;
    //explainVector() ;
    explainMap() ;
    return 0;
}