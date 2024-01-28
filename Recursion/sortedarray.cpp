#include<iostream>
using namespace std;
bool isSorted(int *arr, int size){
    if(size==0 || size==1)
        return true;
    
    if(arr[0]>arr[1])
        return false;
    
    return isSorted(arr+1, size-1);

}

int findSum(int *arr, int size){
    if(size ==0)
        return 0;
    if(size==1)
        return arr[0];
    int sum = arr[0] + findSum(arr+1, size-1);
    return sum;
}

int main(){
    int arr[5] = {1,2,8,4,5};
    cout<<isSorted(arr,5)<<endl;
    cout<<findSum(arr,5);

    return 0;
}