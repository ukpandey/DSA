#include<iostream>
#include<vector>
using namespace std;

int ncr(int r, int c){
    int ans = 1;
    for(int i=0; i<c; i++){
        ans = ans*(r-i);
        ans = ans/(i+1);
    }
    return ans;
}

vector<int> printRow(int r){
    vector<int> res;
    res.push_back(1);
    r--;
    int ans = 1;
    for(int i=0; i<r; i++){
        ans = ans * (r-i);
        ans = ans/(i+1);
        res.push_back(ans);
    }
    return res;
}

int main(){
    int r,c;
    cout<<"Enter the row number and column number: ";
    cin>>r>>c;
    r--; 
    c--;
    cout<<ncr(r,c)<<endl;
    for(int i=1; i<=20; i++){
        vector<int> row = printRow(i);  
        for(auto it:row){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    

}