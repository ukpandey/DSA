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

Node* findNthNode(Node* temp , int k){
    int c = 1;
    while(temp!=NULL){
        if(c==k) return temp;
        c++;
        temp = temp->next;
    }
    return temp;
}

Node* kRightRotate(Node* head, int k){
    if(!head || k==0) return head;
    Node* temp = head;
    int len = 1;
    while(temp->next!=NULL){
        temp = temp->next;
        len++;
    }
    if(k%len == 0) return head;
    k = k%len;
    temp->next = head;
    Node* newLastNode = findNthNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}


int main(){
    vector<int> v{10,20,30,40,50};
    Node *head = convertArrtoLL(v);
    traverse(head);
    head = kRightRotate(head,3);
    traverse(head); // 30 40 50 10 20


}