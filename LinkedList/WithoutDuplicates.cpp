#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};

bool findNode(Node* head, int value) {
    while(head) {
        if(head->data == value) {
            return true;
        }

        head = head->next;
    }
    
    return false;
}
void print(Node* head) {
    if(!head) return;
    print(head->next);
    cout<<head->data<<" ";
}

int main() {  
    Node *head = nullptr;
    int n;
    while(cin>>n){
        if(!findNode(head,n)){
            Node* newNode = new Node(n);
            newNode->next = head;
            head = newNode;
        }
    }

    print(head);
    return 0;
}
