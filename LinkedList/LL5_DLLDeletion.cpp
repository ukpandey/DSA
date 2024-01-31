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
    if(!head) {
        cout<<"aaya kya?";
        return;
    }
    int len = 0;
    while(head!=NULL){
        cout<<head->data<<" ";
        len++;
        head = head->next;
    }
    cout<<"\nLength:"<<len<<endl;
}

Node* deleteHead(Node* head){
    if(!head || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(!head || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // Node* prev = temp->back;
    temp->back->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    if(k==1){
        return deleteHead(head);
    }
    int c=0;
    Node* temp = head;
    while(temp!=NULL){
        c++;
        if(c==k)
            break;
        temp = temp->next;
    }
    if(c<k){
        cout<<"Kth node exceeds the length of linked list\n";
        cout<<"Hence no deletion is possible\n";
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    return head;
}

//it will never be head
void deleteGivenNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
}
int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    Node* head = convertArrToDLL(v);
    traverse(head);
    head = deleteHead(head);
    traverse(head);
    head = deleteTail(head);
    traverse(head);
    head = deleteKthNode(head, 15);
    traverse(head);
    deleteGivenNode(head->next->next);
    traverse(head);
    return 0;
}