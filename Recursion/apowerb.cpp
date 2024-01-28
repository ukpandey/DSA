#include<iostream>
using namespace std;
int i=0;
long long power(long a, long b){
    cout<<a<<i++<<endl;
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    
    // a^b/2
    long ans = power(a, b/2);

    if(b%2==0)
        return ans*ans;
    else
        return a*ans*ans;
}

int main(){
    long a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    cout<<a<<"^"<<b<<"="<<power(a,b);
    return 0;
} 