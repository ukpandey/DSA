#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Always remember that null->next is not null.
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node *convertArrtoLL(vector<int> v)
{
    int n = v.size();
    if (n == 0)
        return NULL;
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(v[i]);
        temp = temp->next;
    }
    return head;
}

// To traverse on next and child pointers
// we could do this in flat function as well 
void traverse2(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t2 = temp;
        while (t2 != NULL)
        {
            cout << t2->data << " ";
            t2 = t2->child;
        }
        cout << endl;
        temp = temp->next;
    }
}

void traverse(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->child;
    }
}

// using child pointer instead of next pointer
Node *convertArrtoLL2(vector<int> v){
    int n = v.size();
    if (n == 0)
        return NULL;
    Node *head = new Node(v[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->child = new Node(v[i]);
        temp = temp->child;
    }
    return head;
}


Node* flat(Node *head)
{
    vector<int> v ;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t2 = temp;
        while (t2 != NULL)
        {
            v.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }

    sort(v.begin(), v.end());
    head = convertArrtoLL2(v);
    return head;
}

int main()
{
    vector<int> v{3, 2, 1, 4, 5};
    Node *head = convertArrtoLL(v);
    head->next->child = new Node(10);
    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(11);
    head->next->next->child->child->child = new Node(12);
    head->next->next->next->child = new Node(9);
    head->next->next->next->next->child = new Node(6);
    head->next->next->next->next->child->child = new Node(8);

    /*
    Linked list is like this
    3  2  1  4  5
       10 7  9  6
          11    8
          12
    */
   
    traverse2(head);
    head = flat(head);
    traverse(head);
}