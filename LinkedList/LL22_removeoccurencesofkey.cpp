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

Node* remove(Node* head, int key){
    if(!head) return head;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(prevNode) prevNode->next = nextNode;
            if(nextNode) nextNode->back = prevNode;
            free(temp);
            temp = nextNode;
        }
        else temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> v{10,4,10,10,6};
    Node* head = convertArrToDLL(v);
    traverse(head);
    head = remove(head,10);
    traverse(head);

}