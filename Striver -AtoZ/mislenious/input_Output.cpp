#include<iostream>
#include<bits/stdc++.h> //<- This header include all the libraries 

using namespace std ;

int main(){
    std::cout<< "Hey souvik" << endl << "Sarkar" << endl ;

    // int , long ,long long ,  float and Double 
    /*
    Range :
    int = -10^9 to 10^9
    long = -10^12 to 10^12
    long long = -10^18 to 10^18
    */
     int x,y ;
     cin >> x >> y ;
     cout << "Value of x :" << x << "Value of y :" << y << endl;

    // string , Getline

     string s1 ;
     cin >> s1 ; // <- This will print the first word before the space
     cout << s1 << endl;
     /*
     if string = Hey souvik I'm cool then the o/p of cout will be "Hey"
     */

     string str ; //<- This thing is will print every thing before the line break like enter 
     getline(cin, str ) ;
     cout << str << endl ;
       /*
     if string = Hey souvik I'm cool then the o/p of cout will be "Hey Souvik I'm cool"
     */

    //char

    char ch ; // <- For single character we use char also can use 
    cin >> ch ;
    cout << ch ;

}