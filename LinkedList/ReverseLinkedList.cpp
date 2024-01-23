#include <iostream>
using namespace std;
//Run and coded by Vivek Pandey
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
    reverse(head);
    print(head);
    return 0;
}
