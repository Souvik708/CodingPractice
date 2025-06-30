#include <bits/stdc++.h>

using namespace std ;

int main(){
    int age ;
    cin >> age ;

    if (age < 18)
        cout << "You are not eligible for the job !" << endl;
    else{
        cout << "You are eligible for the job" << endl ;
        if(age > 57) 
            cout << "Time for the Retirement" << endl ;
        else if(age >= 55)
            cout << "eligible for the job , but retirement is soon" << endl ;
    }
}