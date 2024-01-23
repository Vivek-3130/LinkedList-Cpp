#include <iostream>
using namespace std;
//Your Vivek Pandey
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

int main() {  
    Node *head = nullptr;
    int n;
    while(cin>>n){
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    int find = head->data;
    head = head->next;
    
    if(findNode(head,find)) {
        cout<<"Present"<<endl;
    }else {
        cout<<"Not Present"<<endl;
    }
    
    return 0;
}
