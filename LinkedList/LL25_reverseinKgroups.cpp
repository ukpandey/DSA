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

Node* getKthNode(Node* head, int k){
    Node* temp = head;
    k--;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
Node* reverseInKgroups(Node* head, int k){
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp!=NULL){
        Node* kthnode = getKthNode(temp, k);
        if(!kthnode){
            if(prevLast) prevLast->next = temp;
            break;
        }
        Node* nextNode = kthnode->next;
        kthnode->next = NULL;
        reverse(temp);
        if(temp == head){
            head = kthnode;
        }
        else{
            prevLast->next = kthnode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}
int main(){
    vector<int> v{10,20,30,40,50,60,70,80};
    Node *head2 = convertArrtoLL(v);
    traverse(head2);
    head2 = reverseInKgroups(head2,3);
    traverse(head2); // 30 20 10 60 50 40 70 80


}