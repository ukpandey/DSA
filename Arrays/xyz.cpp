#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double input1, input2;
    while(true){
        cout<<"Enter input1: ";
        cin>>input1;
        cout<<"Enter input2: ";
        cin>>input2;
        double mul = input1*input2;
        cout<<"Enter divide factor: ";
        double d;
        cin>>d;
        mul = mul/d;
        mul = mul - 1.41;
        mul = cos(mul);
        mul = mul*100;
        cout<<mul;
        cout<<"\nDo you want to continue: (y/n)";
        char ch;
        cin>>ch;
        if(ch=='n')
            break;
    }
}