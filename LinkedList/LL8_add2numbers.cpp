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

Node* add2LL(Node* head1, Node* head2){
    Node* dummyHead = new Node(-1);
    int carry = 0;
    Node* t1 = head1;
    Node* t2 = head2;
    Node* curr =  dummyHead;

    while (t1 || t2)
    {
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
    
}


int main(){
    Node *head1 = convertArrtoLL({3,5});
    Node *head2 = convertArrtoLL({4,5,9,9}); // 7 0 0 0 1
    traverse(head1);
    traverse(head2);

    Node* ans = add2LL(head1, head2);
    traverse(ans);
}