#include <bits/stdc++.h>

using namespace std ;


int countSubArraySumWithK(int k , vector<int> &nums){
    map<int,int> preSum ;
    int n = nums.size() ;
    int count = 0 ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += nums[i] ;
        if(sum == k){
            count ++ ;
        }
        int rem = sum - k ;
        if(preSum.find(rem) != preSum.end()){
            count = count + preSum[rem] ;
        }
        if(preSum.find(rem) == preSum.end()){
            preSum[sum] ++ ;
        }
    }
    return count ;
}
int BinarySearch(int target , vector<int> &nums , int low , int high){
    if(low > high){
        return -1;
    }
    else{
        int mid = (low+high)/2 ;
        if(nums[mid] == target){
            return mid ;
        }
        else if(nums[mid] > target){
            BinarySearch(target,nums,low,mid-1) ;
        }
        else{
            BinarySearch(target,nums,mid+1,high) ;    
        }
    }
}

int countDays(int days, vector<vector<int>>& meetings) {
    int daysOff = 0 ;
    int end = 0 ;
    int n = meetings.size () ;
    sort(meetings.begin() , meetings.end());
    for(int i = 0 ; i < n ; i++){
        if(meetings[i][0] > end){
            daysOff += meetings[i][0] - end -1 ; 
        }
        end = max(meetings[i][1],end) ;
    }
    if(end < days){
        daysOff += days - end ;    
    }
    return daysOff ;
}

int mergeIntervals(vector<vector<int>>& intervals){
    vector<vector<int>> result ;
    sort(begin(intervals) , end(intervals)) ;
    int n = intervals.size() ;

    result.push_back(intervals[0]);
    for(int i = 1 ; i < n ; i++){
        if(result.back()[1] > intervals[i][0]){
            result.back()[1] = max(result.back()[1] , intervals[i][1]) ;
        }
        else{
            result.push_back(intervals[i]) ; ;
        }
    }
    return result.size() ;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    // x- axis
    vector<vector<int>> hori ;
    // y - axis
    vector<vector<int>> vert ;
    for(auto &cor : rectangles){
        int x1 = cor[0] ;
        int y1 = cor[1] ;
        int x2 = cor[2] ;
        int y2 = cor[3] ;

        hori.push_back({x1,x2}) ;
        vert.push_back({y1,y2}) ;
    }
     if(mergeIntervals(hori) >= 3 || mergeIntervals(vert) >= 3){
        return true ;
     }
     else{
        return false ;
     }
}

int minOperations(vector<vector<int>>& grid, int x) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<int>flaten ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            flaten.push_back(grid[i][j]) ;
        }
    }
    int rem = flaten[0] % x ;
    for(auto it : flaten){
        if(it % x != rem){
            return -1 ;
        }
    }
    sort(begin(flaten) ,end(flaten)) ;
    int k = flaten.size() ;
    int median = k/2 ;
    int operation = 0 ;

    for(int i= 0 ; i < k ; i++){
        operation += abs(flaten[i] - flaten[median]) /x ;
    }
    return operation ;
}

vector<int> firstLast(vector<int> &nums , int x){
    int n = nums.size() ;
    int first = -1 ;
    int last = -1 ;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] == x){
            if(first == -1){
                first = i ;
            }
            else{
                last = i ;
            }
        }
    }

    return {first,last} ;
}
int bs(vector<int> &nums, int k , int low , int high ){

    while( low <= high ){
        int mid =  (low + high ) /2 ;
        if(nums[mid] == k){
            return mid ;
        }
        else if (nums[mid] > k){
            high = mid - 1 ;
        }
        else{
            low = mid + 1;
        }
    }
    return -1 ;
}

int search(vector<int>& nums) {
    int n = nums.size() ;
    int result = INT_MAX ;
    int low = 0 ; 
    int high = n-1 ;

    while(low <= high){
        int mid = (low + high)/2 ;
        if(nums[mid] > nums[low]){
            result = min(result ,nums[low]) ;
            low = mid + 1 ;
        }
        else{
            result = min(result,nums[mid]) ;
            high = mid -1 ;
        }
    }
    return result ;
}

int primeScore(int n){
    set<int> s;
    if(n % 2 == 0) s.insert(2) ;
    while(n % 2 == 0){
        n = n/2 ;
    }
    for(int i = 3 ; i*i <= n ; i += 2){
        while( n % i == 0){
            s.insert(i) ;
            n = n/i ;
        }
    }
    return s.size() ;
}
vector<int> func(vector<int> & nums){
    int n = nums.size() ;
    vector<int> result(n-1,0) ;
    for(int i = 0 ; i < n ; i++){
        result[i] = primeScore(nums[i]) ;
    }
    return result ;
}
int reverseDegree(string s) {
    int  n = s.length()  ; //3
    int sum = 0 ; 
    for(int i = 0 ; i < n ; i++){ //
        int d = (s[i]-'a' + 1) ;
        sum += (26 - d + 1)*(i+1)  ;
    }
    return sum ;
}

int maxActiveSectionsAfterTrade(string s) {
    int n = s.length() ;
    int ones = 0 ;
    int maxZeroes = 0 ;
    bool flag = false ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1') {
            ones ++ ;
            flag = true ;
        }
    }
    if(flag == false) return n ; // all zeroes
    for(int i = 0 ; i < n ; i++){
        int right = 0 ;
        int left = 0;
        if(s[i] == '1' ){
            for(int  j = i+1 ; j < n ; j++){
                if(s[j] == '0'){
                     right++ ;
                }
                else{
                    break;
                }
            }
            for(int  j = i-1 ; j >= 0 ; j--){
                if(s[j] == '0'){
                     left++ ;
                }
                else{
                    break;
                }
            }
            if(left >=1 && right >=1)
                maxZeroes = max(maxZeroes,(right+left)) ;
        }
    }
    return maxZeroes + ones ;
}
vector<int> minCosts(vector<int>& cost) {
    int n = cost.size() ;
    int currentMin = INT_MAX ;
    vector<int> ans(n,0) ;
    for(int i = 0 ; i < n ; i++){
        currentMin = min(currentMin , cost[i]) ;
        ans[i] = currentMin ;
    }
    return ans ;
}
long long timeToEat(vector<int> &nums , int h){
    int n = nums.size() ;
    long long total = 0 ;
    for(int i = 0 ; i < n ; i++){
        total += ceil((double)nums[i]/(double)h) ;
    }
    cout <<"total time to eat if h is "<< h << " = " << total << endl ;
    return total ;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size() ;
    int maxElement = INT_MIN ;
    for(int i = 0 ; i < n ; i++){
        if(maxElement < piles[i]){
            maxElement = piles[i] ;
        }
    }
    cout << "max =" << maxElement << endl ;
    int low = 1 , high = maxElement ;
    while(low <= high){
        int mid = (low + high)/2 ;
        if(timeToEat(piles,mid) <= h){
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    return low ;
}

int main(){
    vector<int> piles =  {30,11,23,4,20} ;
    int h = 6 ;
    cout << minEatingSpeed(piles,h) << endl;
    return 0 ;
}