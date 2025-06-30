    int n = digits.size() ;
    unordered_set<int> st ;
    vector<int> result ;
    for(int i = 0 ; i < n-2 ; i++){
        if(digits[i] == 0) continue ;
        for(int j = i+1 ; j < n-1 ; j++){
            for(int k = j+1 ; k < n ; k++){
                int num = ((num*10 + digits[i])*10 + digits[j])* 10 + digits[k] ;
                if(num % 2 == 0){
                    st.insert(num) ;
                }
            }
        }
    }
    for(auto it : st){
        result.push_back(it) ;
    }
    sort(begin(result),end(result)) ;
    return result ;