#include <bits/stdc++.h>

using namespace std ;


    int maxDiff(int num) {
        vector<int> digits ;
        while(num > 0){
            digits.push_back(num%10) ;
            num /= 10 ;
        }
        reverse(begin(digits),end(digits)) ;

        // maximum
        int maxi = 0  ;
        int target ;     
        for(int i = 0 ; i < digits.size() ; i++){
            if(digits[i] != 9){
                target = digits[i] ;
                break ;
            }
        }
        for(int i = 0 ; i < digits.size() ; i++){
            if(digits[i] == target){
                maxi = maxi * 10 + 9 ;
            }
            else{
                maxi = maxi * 10 + digits[i] ;        
            }
        }

        //minimum
        int mini = 0 ;
        int replace ; 
        if(digits[0] == 1){
            for(int i = 1 ; i < digits.size() ; i++){
                if(digits[i] != 1){
                    target = digits[i] ;
                    break ;
                }
            }
            replace = 0 ;
        }
        else{
            target = digits[0] ;
            replace = 1 ;
        }
        for(int i = 0 ; i < digits.size() ; i++){
            if(digits[i] == target){
                mini = mini * 10 + replace ;
            }
            else{
                mini = mini * 10 + digits[i] ;        
            }
        }

        return maxi - mini ;
    }


int main(){
    cout << maxDiff(555) << endl ;
    return 0 ;
}