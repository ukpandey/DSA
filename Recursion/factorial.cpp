#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    return n * fact(n-1);
}

int power(int n){
     if(n==0)
        return 1;
     return 2 * power(n-1);
}

int fibonacci(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Fact of "<<n<<" is "<<fact(n);

    cout<<"\n2^"<<n<<" is "<<power(n);

    cout<<"\nfibb "<<fibonacci(n);

    return 0;
}