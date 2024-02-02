#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

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

Node *intersectionPresent(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}

int getDifference(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2; // if difference is neg-> length of list2 > length of list1 else vice-versa
}

// utility function to check presence of intersection
Node *intersectionPresent2(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);
    if (diff < 0)
        while (diff++ != 0)
            head2 = head2->next;
    else
        while (diff-- != 0)
            head1 = head1->next;
    while (head1 != NULL)
    {
        if (head1 == head2)
            return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
}

Node *intersectionPresent3(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;

    while (d1 != d2)
    {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }

    return d1;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = head->next->next;

    Node *ans = intersectionPresent(head, head2);
    traverse(ans);

    ans = intersectionPresent2(head, head2);
    traverse(ans);

    ans = intersectionPresent3(head, head2);
    traverse(ans);
}