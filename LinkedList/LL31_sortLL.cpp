#include<iostream>
#include<vector>
using namespace std;

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
Node* findMiddle(Node* head){
    Node* fast = head->next;
    Node *slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortedLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node * dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(!head || !head->next) return head;
    Node* mid = findMiddle(head); 
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    left = sortLL(left);
    right = sortLL(right);
    return mergeSortedLL(left,right);
}

int main(){
    vector<int> v{4,1,6,3,2,5};
    Node *head1 = convertArrtoLL(v);
    traverse(head1);
    head1 = sortLL(head1);
    traverse(head1);
}