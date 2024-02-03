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
    if(!head || !head->next){
        cout<<"Loop is not present\n";
        return;
    }
    Node* temp = head;
    unordered_map<Node*, int> mp;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            cout<<"loop is present and starting point is "<<temp->data<<endl;
            return;
        }
        mp[temp] = 1;
        temp=temp->next;
    }
    cout<<"Loop is not present"<<endl;
}

Node* detectLoopHarenTortoise(Node* head){
    if(!head ||!head->next) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
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
    Node* start = detectLoopHarenTortoise(head);
    if(!start) cout<<"No cycle\n";
    else cout<<start->data;


}