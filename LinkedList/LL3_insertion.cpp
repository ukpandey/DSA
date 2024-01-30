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

Node* insertAtBegining(Node* &head, int k){
    if(!head){
        head = new Node(k);
        return head;
    }
    Node* temp = new Node(k);
    temp->next = head;
    head = temp;
    return head;
}

Node* insertAtEnd(Node* head, int val){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    // cout<<"Temp:"<<temp->data<<" Head:"<<head->data<<endl;
    return head;
}

Node* insertAtKthPos(Node* head, int k , int val){
    if(k==1){
        head  = insertAtBegining(head,val);
        return head;
    }
    int c = 1;
    Node* temp = head;
    while(temp!=NULL){
        if(c==k-1){
            Node* temp2 = new Node(val);
            temp2->next = temp->next;
            temp->next = temp2;
        }
        c++;
        temp = temp->next;
    }
    return head;
}


int main(){
    vector<int> v{10,20,30,40,50};
    Node *head = convertArrtoLL(v);
    traverse(head);
    head = insertAtBegining(head, 400);
    traverse(head);
    head = insertAtEnd(head, 500);
    traverse(head);
    head = insertAtKthPos(head,1,800);
    traverse(head);
}