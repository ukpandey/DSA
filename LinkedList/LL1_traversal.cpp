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

void findElement(Node* head, int k){
    Node *temp = head;
    int c=1;
    while(temp!=NULL){
        if(temp->data == k){
            cout<<"Found at Pos: "<<c<<endl;
            return;
        }
        c++;
        temp = temp->next;
    }
    cout<<"Not found"<<endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    traverse(head);
    cout<<endl;
    vector<int> v{10,20,30,40,50};
    Node *head2 = convertArrtoLL(v);
    traverse(head2);

    findElement(head2, 40);

}