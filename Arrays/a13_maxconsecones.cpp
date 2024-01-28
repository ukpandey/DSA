#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v{0,0,1,2,3,0,0,0,0,3,0,0,0};
    int c=0;
    int maxi = 0;
    for(auto it:v){
        if(it==0){
            c++;
            maxi = max(maxi,c);
        }
        else
            c=0;
    }
    cout<<maxi;
}