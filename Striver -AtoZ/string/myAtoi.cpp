#include<bits/stdc++.h>

using namespace std ;


int myAtoi(string s){ // iterative version
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;  // skip leading spaces

    if (i == n) return 0;

    bool neg = false;
    if (s[i] == '-' || s[i] == '+') {
        neg = (s[i] == '-');
        i++;
    }

    long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        if (!neg && result >= INT_MAX) return INT_MAX;
        if (neg && -result <= INT_MIN) return INT_MIN;
        i++;
    }

    return neg ? -result : result;

}

int main(){
    cout << myAtoi("-042") << endl ;
    return 0 ;
}