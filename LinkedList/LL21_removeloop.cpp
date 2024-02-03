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
Node* detectAndRemoveLoop(Node* head){
    if(!head || !head->next){
        cout<<"Loop is not present\n";
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    unordered_map<Node*, int> mp;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            cout<<"loop is present and starting point is "<<temp->data<<endl;
            prev->next = NULL;
            return head;
        }
        mp[temp] = 1;
        prev = temp;
        temp=temp->next;
    }
    cout<<"Loop is not present"<<endl;
    return head;
}

Node* detectAndRemoveLoopHarenTortoise(Node* head){
    if(!head ||!head->next) return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            cout<<"Loop detected at node: "<<slow->data<<endl;
            prev->next = NULL;
            return head;
        }
    }
    return head;;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;
    
    // head = detectAndRemoveLoop(head);
    // traverse(head);
    head = detectAndRemoveLoopHarenTortoise(head);
    traverse(head);


}