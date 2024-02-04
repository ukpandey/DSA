#include<iostream>
#include<vector>
#include<queue>
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

Node* mergeSortedLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node * dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data <= t2->data){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    if(t1){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}

Node* mergeKSortedList(vector<Node*> list){
    int n = list.size();
    if(!n) return NULL;
    Node* head = list[0];
    for(int i=1; i<n; i++){
        head = mergeSortedLL(head,list[i]);
    }
    return head;
}

Node* mergeKSortedList2(vector<Node*> list){
    int n = list.size();
    if(!n) return NULL;
    priority_queue<pair<int,Node*>, 
                        vector<pair<int,Node*>>, 
                        greater<pair<int,Node*>>> pq;
    for(int i=0; i<n; i++){
        if(list[i])
        pq.push({list[i]->data,list[i]});
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()){
        pair<int,Node*> p = pq.top();
        pq.pop();
        if(p.second->next)
            pq.push({p.second->next->data,p.second->next});
        temp->next = p.second;
        temp = temp->next;
    }
    return dummyNode->next;

}
int main(){
  vector<vector<int>> v{{2,4,6},{1,5}, {1,1,3,7}, {}, {8,9,10}};
  Node* head1 = convertArrtoLL(v[0]);
  Node* head2 = convertArrtoLL(v[1]);
  Node* head3 = convertArrtoLL(v[2]);
  Node* head4 = convertArrtoLL(v[3]);
  Node* head5 = convertArrtoLL(v[4]);
  vector<Node*> list{head1, head2, head3, head4,head5};
//   Node* head = mergeKSortedList(list);
//   traverse(head);
  Node* head = mergeKSortedList2(list);
  traverse(head);
}