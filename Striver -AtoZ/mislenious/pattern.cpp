#include <bits/stdc++.h>

using namespace std ;

void pattern_1(int n){
	// Write your code here.
	for(int i=0 ; i<n ; i++){
        for (int j = 0; j < n; j++){
            cout << "*";
        }
          cout << endl;
    }
}

void pattern_2(int n) {
	for(int i=0 ; i<n ; i++){
        for (int j = 0; j < i+1; j++){
            cout << "* ";
        }
          cout << endl;
    }
}

void pattern_3(int n) {
	for(int i=1 ; i<=n ; i++){
        for (int j = 1; j < i+1; j++){
            cout << j << " ";
        }
          cout << endl;
    }
}

void Pattern_4(int n) {
	// Write your code here
	for(int i=1 ; i<=n ; i++){
        for (int j = 1; j < i+1; j++){
            cout << i << " ";
        }
          cout << endl;
    }
}

void Pattern_5(int n){
    // Write your code here.
	for(int i=1 ; i<=n ; i++){
        for (int j= 1; j <= i; j++){
            cout << j << " ";
        }
          cout << endl;
    }
}


void Pattern_6(int n){
    for(int i =0 ; i<n ; i++){
        for(int j=0 ; j<n-1-i ; j++){
            cout <<" " ;
        }
        for(int k=0; k<i+1 ; k++){
            cout << "*" ;
        }
        for(int l=0; l<i ; l++){
            cout << "*" ;
        }
        cout << endl ;

    }

}

void Pattern_7(int n){
    for(int i =0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            cout <<" " ;
        }
        for(int k=0; k<n-i ; k++){
            cout << "*" ;
        }
        for(int l=0; l<n-1-i ; l++){
            cout << "*" ;
        }
        cout << endl ;

    }

}

void Pattern_8(int n){
    
    for(int i=0; i<n ; i++){
        for(int j=0 ; j <=i ; j++){
            cout << "* " ;
        }
        cout << endl ;
    }

    for(int i=0; i<n-1 ; i++){
        for(int j=0 ; j <(n-1)-i ; j++){
            cout << "* " ;
        }
        cout << endl ;
    }
}

void Pattern_9(int n){
    for(int i=0 ; i< n ; i++){
        for(int j=0 ; j<i+1 ; j++){
            if((i+j)%2==0){
                cout << "1";
            }
            else{
                cout << "0" ;
            }
        }
        cout << endl ;
    }
}

void Pattern_10(int n){
    for(int i=1 ; i<=n ; i++){
        //number
        for(int j=1 ; j<=i ; j++){
            cout << j ;
        }
        //space
        for(int k=1 ; k<=2*(n-i); k++){
            cout << " " ;
        } 
        //number
        for(int j=i ; j>0 ; j--){
            cout << j ;
        }
        cout << endl ;
    }
}

void Pattern_11(int n){
    int counter = 0 ;
    for(int i=0 ;i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            cout << ++counter ;
        }
        cout << endl ;
    }
}

void Pattern_12(int n){
    for(int i=0 ;i<n ; i++){
        for(char ch ='A' ; ch<='A'+i ; ch++){
            cout << ch << " ";
        }
        cout << endl ;
    }
}

void Pattern_13(int n){
    for(int i=0 ;i<n ; i++){
        for(char ch ='A' ; ch<='A'+(n-1-i) ; ch++){
            cout << ch << " ";
        }
        cout << endl ;
    }
}

void Pattern_14(int n){
    for(int i=0 ;i<n ; i++){
        char ch ='A'+ i ;
        for(int j=0 ; j<=i ; j++){
            cout << ch << " ";
        }
        cout << endl ;
    }
}

// difficult
void Pattern_15(int n){
    char ch = 'A';
    for(int i =0 ; i<n ; i++ ){
        for(int j=0 ; j< n-1-i ; j++){
            cout << " " ;
        }
        for(int k=0 ; k<=i ; k++){
            cout << (char)(ch+k) ;
        }
        for(int l=n-1 ;l>=0 ;l--){
            cout << (char)(ch+l) ;
        }
        cout << endl ;
    }
}






int main(){
 int num ;
 cin >> num ;
 Pattern_15(num) ;
 return 0;
}