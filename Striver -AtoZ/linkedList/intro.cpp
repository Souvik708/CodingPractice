#include <bits/stdc++.h>

using namespace std ;

class Node{
    public:
        int data ;
        Node* next ;

        public:
        Node(int data1 , Node* next1){
            data = data1 ;
            next = next1 ;
        }

        public:
        Node(int data1 ){
            data = data1 ;
            next = nullptr ;
        }
};

Node* convertArr2LL(vector<int>& nums){
    Node* head = new Node(nums[0]) ;
    Node* mover = head ;

    for(int i = 1 ; i < nums.size() ; i++){
        Node* temp = new Node(nums[i]) ;
        mover -> next = temp ;
        mover = temp ;
        //mover = mover -> next ;
    }
    return head ;
}

int lengthLL(Node* head){
    int count = 0 ;
    Node* temp = head ;
    while(temp){
        temp = temp ->next ;
        count ++ ;
    }
    return count ;
}

Node* removeHead(Node* head){
    if(head == nullptr) return nullptr ;
    else{
        Node* temp = head ;
        head = head -> next ;
        free(temp) ;
    }
}

Node* removeTail(Node* head){
    if(head == nullptr) return nullptr ;
    else if(head -> next == NULL){
        free(head) ;
        return NULL ;
    }
    else{
        Node* temp = head ;
        while(temp -> next -> next != nullptr)
            temp = temp -> next ;
        free(temp -> next) ;
        temp -> next = NULL ;
    }

    return head ;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head ;
    if(k == 1){
        Node* temp = head ;
        head = head -> next ;
        free(temp) ;
        return head ;
    }
    int count = 0 ;
    Node* prev = NULL ;
    Node* temp = head ;

    while(temp != NULL){
        count ++ ;

        if(count == k){
            prev -> next = prev -> next -> next ;
            free(temp) ;
            break ;
        }

        prev = temp ;
        temp = temp ->next ;
    }

    return head ;
}

Node* removeEle(Node* head, int el){
    if(head == NULL) return head ;
    if(head->data == el){
        Node* temp = head ;
        head = head -> next ;
        free(temp) ;
        return head ;
    }
    Node* prev = NULL ;
    Node* temp = head ;

    while(temp != NULL){

        if(temp->data == el){
            prev -> next = prev -> next -> next ;
            free(temp) ;
            break ;
        }

        prev = temp ;
        temp = temp ->next ;
    }

    return head ;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val,head) ;
    return temp ;
}

void print(Node* head){
    Node* temp = head ;
    while(temp){
        cout << temp->data << " " ;
        temp = temp -> next ;
    }
    cout << endl ;
}


int main(){
    vector<int> nums= {12,3,4,5,6} ;
    Node* head = convertArr2LL(nums) ;
    head = insertHead(head,111);
    print(head) ;
    return 0 ;
}