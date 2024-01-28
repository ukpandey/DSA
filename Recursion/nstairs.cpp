#include<iostream>
using namespace std;

int countDistinctWaysToReachNthStair(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    
    return countDistinctWaysToReachNthStair(n-1) 
    + countDistinctWaysToReachNthStair(n-2);
}

int main(){
    
    int n;
    cin>>n;
    cout<<"Number of ways "<<countDistinctWaysToReachNthStair(n);
    return 0;
}