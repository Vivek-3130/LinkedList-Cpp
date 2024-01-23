#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};

void findMax(Node* head, int &max) {
    if(!head) return;
    findMax(head->next, max);
    if(max < head->data){
        max =  head->data;
    }
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
    
    int max = -1;
    findMax(head, max);
    cout<<max;
    return 0;
}
