#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *back;
        Node(int val){
            data = val;
            next = NULL;
            back = NULL;
        }

};
Node* convertArrToDLL(vector<int> v){
    int n = v.size();
    if(n==0) return NULL;
    Node *head = new Node(v[0]);
    Node *prev = head;
    for(int i=1; i<n; i++){
        Node *temp = new Node(v[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traverse(Node* head){
    if(!head) return;
    int len = 0;
    while(head!=NULL){
        cout<<head->data<<" ";
        len++;
        head = head->next;
    }
    cout<<"\nLength:"<<len<<endl;
}

Node* insertAtHead(Node* head, int val){
    if(!head){
        return new Node(val);
    }
    Node *temp = new Node(val);
    temp->next = head;
    head->back = temp;
    head = temp;
    return head;
}

Node* insertBeforeTail(Node* head , int val){
    if(!head){
        return new Node(val);
    }
    if(head->next == NULL){
        return insertAtHead(head,val);
    }
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* temp = new Node(val);
    temp->next = tail;
    temp->back = tail->back;
    tail->back->next = temp;
    tail->back = temp;
    return head;
}

Node* insertAfterTail(Node* head, int val){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->back = temp;
    return head;
}

Node* insertAtKthPos(Node* head, int k, int val){
    if(k==1){
        return insertAtHead(head,val);
    }
    int c=0;
    Node* temp = head;
    while(temp!=NULL){
        c++;
        if(c==k) break;
        temp=temp->next;
    }
    if(temp==NULL && k==c+1){
        return insertAfterTail(head,val);
    }
    else if(temp==NULL && k>c+1){
        cout<<"Not Possible because we can not insert at kth position\n";
        cout<<"As kth positon is greater than len+1\n";
        return head;
    }
    Node* newNode = new Node(val);
    newNode->back = temp->back;
    newNode->next = temp;
    temp->back->next = newNode;
    temp->back = newNode;
    return head;
}

int main(){
    vector<int> v{1,2,3,4,5};
    Node* head = convertArrToDLL(v);
    traverse(head); // 1 2 3 4 5
    head = insertAtHead(head,100);
    traverse(head); // 100 1 2 3 4 5
    head = insertBeforeTail(head, 1000);
    traverse(head); // 100 1 2 3 4 1000 5
    head = insertAtKthPos(head, 1, 200);
    traverse(head); // 200 100 1 2 3 4 1000 5
    head = insertAtKthPos(head,8,300);
    traverse(head); // 200 100 1 2 3 4 1000 300 5
    head = insertAtKthPos(head,10,400);
    traverse(head); // 200 100 1 2 3 4 1000 300 5 400
    head = insertAtKthPos(head,15,2000);
    traverse(head);

}