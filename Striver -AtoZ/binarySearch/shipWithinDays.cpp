#include <bits/stdc++.h>

using namespace std ;

bool validcapacity(vector<int>& weights, int days, int capacity){
    int n = weights.size() ;
    int reqDay = 1 ;
    int sum = 0 ;
    for(int i = 0 ; i < n; i++){
        if(weights[i] > capacity) return false;
        if(sum + weights[i] <= capacity){
            sum += weights[i] ;
        }
        else{
            reqDay ++ ;
            sum = weights[i] ;
        }
    }
    return (reqDay <= days) ;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size() ;
    //int low = *min_element(weights.begin(), weights.end()); -> this thinking is wrong because min capacity of the ship must >= max element ,
    //                                                              otherwise we can not ship the max weight.
    int low = *max_element(weights.begin(), weights.end()); 
    int high = accumulate(weights.begin() , weights.end() ,0) ;
    while( low <= high){
        int mid = (low + high)/2 ;
        if(validcapacity(weights,days,mid)){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return low ;
}

// int uniqueXorTriplets(std::vector<int>& nums) {
//     int n = nums.size();
//     unordered_map<int> pairXor ;

// }

int uniqueXorTriplets(const vector<int>& nums) {
    unordered_set<int> distinctTripleXors;
    int n = nums.size();

    unordered_set<int> pairXors;
    pairXors.reserve(n * n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            pairXors.insert(nums[i] ^ nums[j]);
        }
    }

    for(auto px : pairXors) {
        for(int x : nums) {
            distinctTripleXors.insert(px ^ x);
        }
    }

    return distinctTripleXors.size();
}

int main(){
    vector<int> nums = {6,7,8,9} ;
    //int days = 5 ;
    cout << uniqueXorTriplets(nums) << endl ;
    return 0;
}