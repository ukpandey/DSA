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
// Brute force
vector<vector<int>> twoSumBF(Node* head, int k){
    vector<vector<int>> ans;
    Node* temp = head;
    while(temp!=NULL){
        Node* temp2 = temp->next;
        while(temp2!=NULL && temp->data + temp2->data <= k){
            if(temp->data + temp2->data == k)
                ans.push_back({temp->data, temp2->data});
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return ans;
}

vector<vector<int>> twoSum(Node* head, int k){
    vector<vector<int>> ans;
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* tail = temp;
    temp = head;
    while(temp->data < tail->data){
        if(temp->data + tail->data == k){
            ans.push_back({temp->data, tail->data});
            temp = temp->next;
            tail = tail->back;
        }
        else if(temp->data + tail->data > k){
            tail = tail->back;
        }
        else{
            temp = temp->next;
        }
    }
    return ans;
}

int main(){
    vector<int> v{1,2,3,4,5};
    Node* head = convertArrToDLL(v);
    traverse(head);
    vector<vector<int>> ans = twoSumBF(head,5);
    for(auto pairs:ans){
        for(auto it:pairs)
            cout<<it<<" ";
        cout<<endl;
    }
    ans = twoSum(head,5);
    for(auto pairs:ans){
        for(auto it:pairs)
            cout<<it<<" ";
        cout<<endl;
    }
}