#include<iostream>
using namespace std;
bool linearSeach(int *arr, int size, int k){
    cout<<k<<" "<<arr[0]<<endl;
    if(size == 0)
        return false;
    
    if(arr[0] == k)
        return true;
    
    return linearSeach(arr+1, size-1, k);
}

bool binarySearch(int s, int e, int *arr, int k){
    if(s>e)
        return false;
    
    int mid = (s+e)/2;
    if(arr[mid]==k)
        return true;
    
    if(k>arr[mid])
        return binarySearch(mid+1,e,arr,k);
    else
        return binarySearch(s, mid-1, arr,k);

}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    cout<<linearSeach(arr,size,5);

    cout<<endl;
    cout<<binarySearch(0,4,arr,7);

    return 0;
}