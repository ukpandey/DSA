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

Node* findMiddleBrute(Node* head){
    int c = 0; 
    Node* temp = head;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    int middleNode = (c/2)+1;
    temp = head;
    while(temp!=NULL){
        middleNode--;
        if(middleNode == 0) break;
        temp = temp->next;
    }
    return temp;
}

Node* findMiddle(Node* head){
    Node* fast = head;
    Node *slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);

    Node* mid = findMiddleBrute(head);
    cout<<mid->data<<endl;

    mid = findMiddle(head);
    cout<<mid->data;


}