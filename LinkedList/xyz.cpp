#include<iostream>
using namespace std;
int main(){
    string s = "apple";
    for(auto it:s){
        cout<<it<<" ";
    }
    s.append("h");
    cout<<s;
}