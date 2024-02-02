#include<iostream>
#include<stack>
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
Node* add1(Node* head){
    if(!head) return head;
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    while(temp!=NULL){
        int sum = carry;
        if(temp) sum+=temp->data;
        curr->next = new Node(sum%10);
        curr = curr->next;
        carry = sum/10;
        temp = temp->next;
    }
    temp = head;
    head = reverse(head);
    dummyHead = dummyHead->next;
    dummyHead = reverse(dummyHead);
    return dummyHead;
}

//using recursion
int helper(Node* head){
    if(head==NULL) return 1;
    int carry = helper(head->next);
    head->data+=carry;
    if(head->data<10){
        return 0;
    }
    head->data = 0;
    return 1;
}

Node* add1Recursion(Node* head){
    if(!head) return head;
    int carry;
    carry = helper(head);
    if(carry){
        Node* temp = new Node(1);
        temp->next = head;
        head = temp;
        return head;
    }
    return head;
}
int main(){
    vector<int> v{9,9,9,9};  //output should be 9999+1 = 10000
    Node* head = convertArrtoLL(v);
    Node* ans = add1(head);
    traverse(ans);
    ans = add1Recursion(head);
    traverse(ans);
}