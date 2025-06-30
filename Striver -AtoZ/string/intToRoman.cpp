#include<bits/stdc++.h>

using namespace std ;

string intToRoman(int num){
    vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1} ;
    vector<string> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"} ;
    string result ;
    while(num > 0){
        int pos = -1 ;
        for(int i = 0 ; i < 13 ; i++){
            if(num >= value[i]){
                pos = i ;
                break ;
            }
        }
        int times = num/value[pos] ;
        while(times --){
            result += sym[pos] ;
        }
        num = num % value[pos] ; 
    }
    return result ;
}

string intToRoman_1(int num){
    vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1} ;
    vector<string> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"} ;
    string result ;

    for(int i = 0 ; i < 13 ; i++){
        if(num == 0) break ;
        if(num >= value[i]){
            int times = num/value[i] ;
            while(times --){
                result += sym[i] ;
            }
            num = num % value[i] ;
        }
    } 
    return result ;
}

int romanToInt(string s){
    vector<char> sym = {'I','V','X','L','C','D','M'};
    vector<int> val = {1,5,10,50,100,500,1000} ;
    unordered_map<char,int> mpp ;
    for(int i = 0 ; i < 7 ;i++){
        mpp[sym[i]] = val[i] ;
    }

    int n = s.length() ;
    int result = 0 ;
    int prev ;
    for(int i = 0 ; i < n ; i++){
        if(prev < mpp[s[i]] && i != 0){
            result += (mpp[s[i]] - 2 * prev) ;
        }
        else{
            result += mpp[s[i]] ;
        }
        prev = mpp[s[i]] ;
    }
    return result ;
}

int romanToInt(string s){
    unordered_map<char,int> mymap{
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000},
    };
    int value = 0;
    for(int i=0;i<s.size();++i){
        if(mymap[s[i]] < mymap[s[i+1]])
            value -= mymap[s[i]];
        else
            value += mymap[s[i]];
    }
    return value;
}


int main(){
    int num = 283 ;
    string s = "MCMXCIV" ;
    cout << romanToInt(s) << endl ; 
    return 0 ;
}