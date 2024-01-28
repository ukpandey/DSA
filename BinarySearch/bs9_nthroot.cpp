#include <iostream>
using namespace std;
int findNtimesmid(int mid, int n, int m){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans*mid;
        if(ans>m) return 2; 
    }
    if(ans==m) return 1;
    return 0;
}
int nthRootofM(int n, int m)
{
    int low = 1;
    int high = m;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        int midN = findNtimesmid(mid,n,m);
        if(midN==1) 
            return mid;
        else if(midN==2)
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    cout<<nthRootofM(n,m);
}