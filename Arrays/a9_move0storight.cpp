#include<iostream>
#include<vector>
using namespace std;
void moveZeros(vector<int> &v){
    int j=-1;
    for(int i=0; i<v.size(); i++){
        if(v[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1) return;

    for(int i=j+1; i<v.size(); i++){
        if(v[i]!=0){
            swap(v[i], v[j]);
            j++;
        }
    }
}
int main(){
    vector<int> v{0,0,0,0,0,1,3,4,2,5};
    moveZeros(v);
    for(auto it:v)
        cout<<it<<" ";

}