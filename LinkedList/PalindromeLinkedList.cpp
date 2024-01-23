#include <iostream>
using namespace std;
// Run and Debugged by Vivek Pandey
class Node{
    public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr){}
};
Node* reverse(Node* head){
    Node* prev = nullptr;
    while(head){
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }return prev;
}
bool checkPalindron(Node* head) {
    Node* first = head;
    Node* second = head->next;
    
    while(second && second->next){
        first = first->next;
        second = second->next->next;
    }
    first->next = reverse(first->next);
    second = first->next;
    first = head;

    while(second && first){
        if(second->data != first->data) {
            return false;
        }
            
        first = first->next;
        second = second->next;
    }
    return true;
}
int main() {
    Node *head = nullptr;
    int n;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    if(checkPalindron(head)){
        cout<<"True";
    }else{
        cout<<"False";
    }return 0;
}
