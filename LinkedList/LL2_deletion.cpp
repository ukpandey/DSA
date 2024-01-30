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

Node *deleteHead(Node* &head){
    if(!head) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node* &head){
    if(!head || !head->next) return NULL;
    Node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deleteKthNode(Node* &head, int k){
    if(k==1) {
        return deleteHead(head);
    }
    int c = 1;
    Node *temp = head;
    Node *prev = NULL;
    while(temp!=NULL && c!=k){
        // cout<<c<<endl;
        prev = temp;
        temp = temp->next;
        c++;
    }
    if(temp!=NULL)
        prev->next = temp->next;
    delete temp;
    return head;
        
}

Node *deleteValue(Node* &head, int val){
    if(val == head->data) {
        return deleteHead(head);
    }
    int c = 1;
    Node *temp = head;
    Node *prev = NULL;
    while(temp!=NULL && temp->data!=val){
        // cout<<temp->data<<endl;
        prev = temp;
        temp = temp->next;
        c++;
    }
    if(temp!=NULL)
        prev->next = temp->next;
    delete temp;
    return head;
        
}

int main(){
    vector<int> v{10,20,30,40,50,60,70,80,90,100};
    Node *head = convertArrtoLL(v);
    cout<<"Initial Linked List\n";
    traverse(head);
    deleteHead(head);
    cout<<"After removing head\n";
    traverse(head);
    deleteTail(head);
    cout<<"After removing tail\n";
    traverse(head);
    deleteKthNode(head,5);
    cout<<"After removing 5th node\n";
    traverse(head);
    deleteValue(head, 80);
    cout<<"After removing 80\n";
    traverse(head);

    // output should be 
    // 10 20 30 40 50 60 70 80 90 100
    // 20 30 40 50 60 70 80 90 100 
    // 20 30 40 50 60 70 80 90  
    // 20 30 40 50 70 80 90
    // 20 30 40 50 70 90




}