#include<iostream>
#include<vector>
#include<unordered_map>
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
void detectLoop(Node* head){
    if(!head) return;
    Node* temp = head;
    int timer = 1;
    unordered_map<Node*, int> mp;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            cout<<"Length of the loop is "<<timer - mp[temp]<<endl;
            return;
        }
        mp[temp] = timer++;
        temp=temp->next;
    }
    cout<<"Loop is not present"<<endl;
}

int findLength(Node* slow, Node* fast){
    int c = 1;
    fast = fast->next;
    while(slow!=fast){
        c++;
        fast = fast->next;
    }
    return c;
}

int detectLoopHarenTortoise(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow,fast);
    }
    return 0;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;
    detectLoop(head);
    int len = detectLoopHarenTortoise(head);
    cout<<"Length of cycle is:"<<len;
}