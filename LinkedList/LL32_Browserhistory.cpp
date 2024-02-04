#include<iostream>
using namespace std;
class Node{
    public:
        string data;
        Node* next;
        Node* back;
        Node(string s){
            data = s;
            next = NULL;
            back = NULL;
        }
};

class Browser
{
    Node* currPage;
    public:
    
    Browser(string &homepage)
    {
        currPage = new Node(homepage);
    }

    void visit(string url)
    {
        Node* newNode = new Node(url);
        currPage->next = newNode;
        newNode->back = currPage;
        currPage = currPage->next;
    }

    string back(int steps)
    {
        while(steps){
            if(currPage->back){
                currPage = currPage->back;
            }
            else break;
            steps--;
        }
        return currPage->data;
    }

    string forward(int steps)
    {
        while(steps){
            if(currPage->next){
                currPage = currPage->next;
            }
            else break;
            steps--;
        }
        return currPage->data;
    }
};

int main(){
    string s = "gym4weebs.com";
    Browser B(s);
    B.visit("youtube.com");
    B.visit("instagram.com");
    B.visit("linkedin.com");
    B.visit("buySuplements.com");
    cout<<B.back(9)<<endl;;
    cout<<B.forward(2);
}