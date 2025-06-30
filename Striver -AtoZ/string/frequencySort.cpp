#include <bits/stdc++.h>

using namespace std ;

string frequencySort(string s){
    int n = s.length() ;
    if(n == 0) return "" ;
    if(n == 1) return s ;

    string result = "" ;
    unordered_map<char,int> mp ;
    for(char& it : s){
        mp[it] ++ ;
    }
    vector<pair<char,int>> freq ;
    for(auto it : mp){
        char ch = it.first ;
        int f = it.second ;
        freq.push_back({ch,f});
    }
    sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
    });

    for(auto it : freq){
        if(it.second > 0){
            string temp = string(it.second,it.first);
            result += temp ;
        }
    }
    return result ;
}

string frequencySort_1(string s){
    int n = s.length() ;
    if(n == 0) return "" ;
    if(n == 1) return s ;

    string result = "" ;
    unordered_map<char,int> mp ;
    for(char& it : s){
        mp[it] ++ ;
    }
    vector<pair<char,int>> freq ;
    for(auto it : mp){
        char ch = it.first ;
        int f = it.second ;
        freq.push_back({ch,f});
    }
    sort(freq.begin(), freq.end(), [](pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
    });

    for(auto it : freq){
        if(it.second > 0){
            string temp = string(it.second,it.first);
            result += temp ;
        }
    }
    return result ;
}

string findCommonResponse(vector<vector<string>>& responses) {
    int n = responses.size() ;
    map<string,int> mp ;
    for(auto& it : responses){
        set<string> unique(it.begin(),it.end()) ;
        for(auto& it1 : unique){
            mp[it1] ++ ;
        }
    }
    string result = "";
    int maxFreq = 0;
    
    for (auto& [response, freq] : mp) {
        if (freq > maxFreq || (freq == maxFreq && response < result)) {
            result = response;
            maxFreq = freq;
        }
    }
    
    return result;
}
vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
    int n = conversions.size() ;
    vector<int> result ;

    
}

int main(){
    string s = "tree" ;
//     vector<vector<string>> responses = {
//     {"good", "ok"},
//     {"ok", "bad", "good"},
//     {"good"},
//     {"bad"}
// };
    cout << frequencySort(s) << endl ;
    return 0 ;
}