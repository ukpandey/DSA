#include<iostream>
#include<vector>
using namespace std;

int printElement(int r, int c){
    int ans = 1;
    for(int i=0; i<c; i++){
        ans = ans*(r-i);
        ans = ans/(i+1);
    }
    return ans;
}

vector<int> storeRow(int r){
    vector<int> res;
    int ans = 1;
    res.push_back(1);
    

    for(int i=1; i<r; i++){
        ans = ans*(r-i);
        ans = ans / (i);
        res.push_back(ans);
    }

    return res;

}

int main(){
    int r,c;
    cout<<"Enter Row and Colum number: ";
    cin>>r>>c;
    cout<<printElement(r-1, c-1)<<endl;

    vector<int> ans = storeRow(r);

    for(auto it:ans)
        cout<<it<<" ";

    cout<<"\n\n\n\n";

    vector<vector<int>> triangle;

    for(int i=1; i<=r; i++){
        triangle.push_back(storeRow(i));
    }

    for(int i = 0; i<triangle.size(); i++){
        // for(int j=0; j<triangle[i].size(); j++){
        //     cout<<triangle[i][j]<<" ";
        // }
        for(auto it: triangle[i])
            cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}