#include <iostream>
#include <vector>
using namespace std;

// Always remember that null->next is not null.
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void traverse(Node *head)
{
    if (!head)
        return;
    int len = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        len++;
        cout << temp->data << "->";
        temp = temp->next;
    }
    len++;
    cout << temp->data;
    cout << "\nLength: " << len << endl;
}

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

Node *deleteMiddleBrute(Node *head)
{
    if(!head || !head->next) return NULL;
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    int middleNode = (c / 2);
    temp = head;
    while (temp != NULL)
    {
        middleNode--;
        if (middleNode == 0)
        {
            Node *mid = temp->next;
            temp->next = temp->next->next;
            delete mid;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *deleteMiddle(Node *head)
{
    if(!head || !head->next) return NULL;
    Node *fast = head;
    Node *slow = head;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    slow->next = slow->next->next;
    delete mid;
    return head;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    Node *head = convertArrtoLL(v);
    traverse(head);

    head = deleteMiddleBrute(head);
    traverse(head);

    head = deleteMiddle(head);
    traverse(head);
}