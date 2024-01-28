#include<iostream>
#include<vector>
#include<set>
using namespace std;

void removeDuplicateSet(vector<int> &v){
    set<int> st;
    int n = v.size();
    for(int i=0; i<n; i++){
        st.insert(v[i]);
    }
    int index = 0;
    for(auto it:st){
        v[index++] = it;
    }
    cout<<"Index: "<<index<<endl;
}

void removeDuplicate(vector<int> &v){
    int n = v.size();
    int p1= 0;
    int p2 = 1;
    while(p2!=n){
        if(v[p1] == v[p2]){
            p2++;
        }
        else{
            p1++;
            v[p1] = v[p2];
            p2++;
        }
    }
}
int main(){
    vector<int> v{1,1,1,2,2,3,3,3,3,4,6,6};
    // removeDuplicateSet(v);
    removeDuplicate(v);
    for(auto it: v)
        cout<<it<<" ";


}