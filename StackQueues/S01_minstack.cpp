#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    private: 
        stack<pair<int,int>> st;
    public:
        MinStack(){}

        void push(int val){
            if(st.empty()){
                st.push({val,val});
                return;
            }
            int minimum = min(val,getMin());
            st.push({val,minimum});
        }

        void pop(){
                st.pop();
        }

        int top(){
                return st.top().first;
        }

        int getMin(){
            return st.top().second;
        }
};
int main(){
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    return 0;
}