#include<iostream>
#include<vector>
using namespace std;

// Always remember that null->next is not null.
class Node{
    public:
        int data;
        Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

void traverse(Node *head){
    if(!head) return;
    int len = 0;
    Node *temp = head;
    while(temp->next!=NULL){
        len++;
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    len++;
    cout<<temp->data;
    cout<<"\nLength: "<<len<<endl;
}

Node* convertArrtoLL(vector<int> v){
    int n = v.size();
    if(n==0) return NULL;
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1; i<n; i++){
        temp->next = new Node(v[i]);
        temp = temp->next;
    }
    return head;
}

Node* reverse(Node* head){
    if(!head || !head->next ) return head;
    Node *prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* reverse2(Node* head){
    if(!head || !head->next) return head;
    Node* newHead = reverse2(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    vector<int> v{1,2,3,4,5};
    Node *head = convertArrtoLL(v);
    traverse(head);
    head = reverse(head);
    traverse(head);
    head = reverse2(head);
    traverse(head);
}