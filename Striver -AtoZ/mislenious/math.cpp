#include<bits/stdc++.h>

using namespace std ;

int count_digit(int n){
    int res=0  ;
    int count = 0 ;
    int num = n ;

    while(n!=0){
        res = n % 10 ;
        if(num%res == 0){
            count ++ ;
        }
        n=n/10 ;
    }
    cout << count << endl ;
    return 0 ;
}

int reverse_digit(int n){
    int res=0  ;
    int reverse = 0 ;

    while(n!=0){
        res = n % 10 ;
        reverse = (reverse*10)+res ;
        n=n/10 ;
    }
    cout << reverse << endl ;
    return 0 ;
}

int pallindrome(int n){
    int res=0  ;
    int reverse = 0 ;
    int num =n ;

    while(n!=0){
        res = n % 10 ;
        reverse = (reverse*10)+res ;
        n=n/10 ;
    }
    if (num == reverse)
        cout << num <<" is Pallindrome" << endl ;
    else
        cout << num <<" is not Pallindrome" << endl ;
    return 0 ;
}

int armstrong(int n){
    int res=0  ;
    int armstrong = 0 ;
    int num =n ;

    while(n>0){
        res = n % 10 ;
        armstrong = armstrong +pow(res,count_digit(n)) ;
        //cout << armstrong << endl ;
        n=n/10 ;
    }
    if (num == armstrong)
        cout << num <<" is Armstrong" << endl ;
    else
        cout << num <<" is not Armstrong" << endl ;
    return 0 ;
}

int allDivisor(int num){
    vector<int> divisor ;
    for(int i=1 ; i<=sqrt(num) ; i++){
        if(num % i == 0 ){

            divisor.emplace_back(i) ;

            if(num/i != i)
                divisor.emplace_back(num/i) ;  
        }
    }
    sort(divisor.begin(),divisor.end()) ;
    for(auto it: divisor){
        cout << it << " " ;
    }
    cout << endl ;
    return 0 ;
}

int isPrime(int num){
    int count =0 ;
    for(int i=1 ; i<=sqrt(num) ; i++){
        if(num % i == 0 ){
             count ++ ;

            if(num/i != i)
                count ++ ;  
        }
        if(count > 2) break ;
    }
    if(count == 2)
        cout <<"Is a prime number"<< endl ;
    else 
        cout <<"Is not a prime number"<< endl ;
    return 0 ;
}

// GCD version
//1. GCD : O(sqrt(n))
void GCD(int n1 , int n2){
    int n = max(n1,n2) ;
    int m = (n1+n2)-n ;
    int gcd = 0 ;
    for (int i=1; i*i <= n ; i++ ){
        if(n % i == 0 ){
             if(m % i == 0) gcd = max(gcd,i) ;

            if(n/i != i)
                if(m % n/i == 0)gcd = max(gcd,n/i) ;  
        }
    }
    cout << gcd << endl ;
}

//2. GCDv2 : O(min(n1,n2))
void GCDv2(int n1 , int n2){
    for (int i=min(n1,n2); i <= 1 ; i++ ){
        if( n1% i == 0 && n2% i == 0){
            cout << i << endl ;
            break ;
        }
    }
}

//3.GCD_Euclidean:O(log min(a,b)) <-- THis is the optimal approach

void GCD_Euclidean(int a, int b){
    while(a>0 && b>0){
        if(a>b) a=a%b ;
        else b=b%a ;
    }
    if(a == 0) cout << a ;
    else cout << b ;
}


int main(){

    int num1,num2 ;
    cin >> num1 >> num2 ;
    GCD(num1,num2) ;

}