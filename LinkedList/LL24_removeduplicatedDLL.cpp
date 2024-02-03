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

Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && temp->data == nextNode->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> v{1,1,2,3,3,3,4,5,5,6};
    Node* head = convertArrToDLL(v);
    traverse(head);
    head = removeDuplicates(head);
    traverse(head);
}