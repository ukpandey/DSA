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
bool isPalindromeBrute(Node* head){
    if(!head || !head->next) return true;
    Node* temp = head;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->data!=s.top()){
            return false;
        }
        s.pop();
        temp = temp->next;
    }
    return true;
}

bool isPalindrome(Node* head){
    if(!head || !head->next) return true;
    Node* fast = head;
    Node* slow = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main(){
    vector<int> v{1,2,3,3,2,1};
    Node* head = convertArrtoLL(v);
    cout<<isPalindrome(head)<<endl;
    cout<<isPalindromeBrute(head);
    return 0;
}