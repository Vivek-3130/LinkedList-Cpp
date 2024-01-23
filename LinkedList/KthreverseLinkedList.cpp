#include <iostream>
#include <stack>
using namespace std;
// It's Vivek Only
class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};
Node* reverse(Node* head){
    Node* prev = nullptr;    
    while(head ){
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

Node* kth(Node* head, int k) {
    stack<Node*> s;
    Node* dumN = new Node(0);
    Node* dummyNode = dumN;
    Node* curr = head;
    
    while(curr){
        if((int)s.size() != k){
            s.push(curr);
            curr = curr->next;
        }else{
            while(!s.empty()){
                dummyNode->next = s.top();
                s.pop();
                dummyNode = dummyNode->next;
            }
        }

    }
    while(!s.empty()){
        dummyNode->next = s.top();
        s.pop();
        dummyNode = dummyNode->next;
    }
    dummyNode->next = nullptr;
    return dumN->next;
}

void print(Node* head) {
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main() {  
    Node *head = nullptr;
    int n;
    while(cin>>n){
        if(n == -1) break;
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }
        
    int k;
    cin>>k;
    head = reverse(head);
    if(k == 0) {
        print(head);
        return 0;
    }
    // print(head);
    head = kth(head, k);
    print(head);
    return 0;
}
