#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    private: 
        stack<int> st;
        int minimum;
    public:
        MinStack(){}

        void push(int val){
            if(st.empty()){
                st.push(val);
                minimum = val;
                return;
            }
            else{
                if(val<minimum){
                    int newValue = (2*val)-minimum;
                    minimum = val;
                    st.push(newValue);
                }
                else{
                    st.push(val);
                }
            }
        }

        void pop(){
            if(st.empty()){
                cout<<"stack is empty";
                return;
            }
            int x = st.top();
            st.pop();
            if(x<minimum){
                int prevMin = (2*minimum)-x;
                minimum = prevMin;
            }
        }

        int top(){
            if(st.empty()){
                cout<<"stack is empty";
                return -1;
            }
            if(st.top()<minimum){
                return minimum;
            }
            else{
                return st.top();
            }
        }

        int getMin(){
            return minimum;
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