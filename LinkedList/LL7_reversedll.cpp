#include<iostream>
#include<vector>
#include<stack>
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

Node* reverseDLLStack(Node* head){
    if(!head || !head->next) return head;
    Node* temp = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* reverseDLL(Node* head){
     if(!head || !head->next) return head;
     Node* last = NULL;
     Node* curr = head;
     while(curr!=NULL){
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
     }
     head = last->back;
     return head;
}

int main(){
    vector<int> v{1,2,3,4,5};
    Node* head = convertArrToDLL(v);
    traverse(head);
    head = reverseDLLStack(head);
    traverse(head);
    head = reverseDLL(head);
    traverse(head);

}