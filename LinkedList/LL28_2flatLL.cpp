#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
}

Node *mergeSortedLL(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    if (list1)
        res->child = list1;
    else
        res->child = list2;
    if (dummyNode->child)
        dummyNode->child->next = NULL;
    return dummyNode->child;
}

Node *flat(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *mergedHead = flat(head->next);
    head = mergeSortedLL(head, mergedHead);
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