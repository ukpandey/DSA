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
Node *sortBruteForce(Node* head){
    if(!head || !head->next) return head;
    int c0,c1,c2;
    c0=c1=c2=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0) c0++;
        else if(temp->data == 1) c1++;
        else c2++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(c0){
            temp->data = 0;
            c0--;
        }
        else if(c1){
            temp->data = 1;
            c1--;
        }
        else if(c2){
            temp->data = 2;
            c2--;
        }
        temp=temp->next;
    }
    return head;

}

Node* sort(Node* head){
    if(!head || !head->next) return head;
    Node *zeroHead = new Node(-1);
    Node *L0 = zeroHead;
    Node *oneHead = new Node(-1);
    Node *L1 = oneHead;
    Node *twoHead = new Node(-1);
    Node* L2 = twoHead;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            L0->next = temp;
            L0 = L0->next;
        }
        else if(temp->data == 1){
            L1->next = temp;
            L1 = L1->next;
        }
        else if(temp->data == 2){
            L2->next = temp;
            L2 = L2->next;
        }
        temp = temp->next;
    }
    L0->next = (oneHead->next)?oneHead->next:twoHead->next;
    L1->next = twoHead->next;
    L2->next = NULL;
    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}
int main(){
    vector<int> v{1,0,2,2,2,0,1,1};
    Node *head = convertArrtoLL(v);
    traverse(head);
    // head = sortBruteForce(head);
    // traverse(head);
    head = sort(head);
    traverse(head);

}