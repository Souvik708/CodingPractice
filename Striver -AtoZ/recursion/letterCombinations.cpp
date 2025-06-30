#include<bits/stdc++.h>

using namespace std ;

void combinations(int ind , string digits ,string &temp , vector<string> ans,unordered_map<char,string> &mp){
    if(ind == digits.size()){
        ans.push_back(temp) ;
        return ;
    }
    char ch = digits[ind] ;
    string str = mp[ch] ;

    for(int i = 0 ; i < str.length() ; i++){
        temp.push_back(str[i]) ;
        combinations(ind+1 , digits,temp , ans , mp) ;
        temp.pop_back() ;
    }
    return ;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char,string> mp ;
    mp['2'] = "abc";
    mp['3'] = "def" ;
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    vector<string> result ;
    string temp = "" ;

    combinations(0,digits,temp,result,mp) ;

    return result ;
}

int main(){
    return 0 ;
}