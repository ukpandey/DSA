// Problem Statement:
// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. 
//Find the number(between 1 to N), that is not present in the given array.
#include<iostream>
#include<vector>
using namespace std;

int bruteForce(int N, vector<int> a){
    for(int i=1; i<=N; i++){
        int flag=0;
        for(int j=0; j<N-1; j++){
            if(a[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0)
            return i;
    }
    return -1;
}

int better(int N, vector<int> a){
    vector<int> v(N+1,0);
    for(int i=0; i<N-1; i++){
        v[a[i]]++;
    }
    for(int i=1; i<N+1; i++){
        if(v[i]==0)
            return i;
    }
    return -1;
}

int usingSum(int N, vector<int> a){
    int Nsum = (N*(N+1))/2;
    int sum = 0;
    for(auto it:a)
        sum+=it;
    return Nsum-sum;

}

int optimal(int N, vector<int> a){
    int xor1=0, xor2=0;
    for(int i=0; i<N-1; i++){
        xor1 = xor1^a[i];
        xor2 = xor2^(i+1);
    }
    xor2 = xor2^N;
    return xor1^xor2;
}

int main(){
    int N = 6;
    vector<int> a = {1,3,4,5,6};
    cout<<bruteForce(N,a)<<endl;
    cout<<better(N,a)<<endl;
    cout<<usingSum(N,a)<<endl;
    cout<<optimal(N,a);
}