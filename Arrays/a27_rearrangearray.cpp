// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
// Without altering the relative order of positive and negative elements, 
//you must return an array of alternately positive and negative values.
// Note: Start the array with positive elements.
#include<iostream>
#include<vector>
using namespace std;

// this is optimal if number of negatives != positives
vector<int> bruteForce(vector<int> v){
    int n = v.size();
    vector<int> positive,negative, ans(n,0);
    for(int i=0; i<n; i++){
        if(v[i] > 0)
            positive.push_back(v[i]);
        else
            negative.push_back(v[i]);
    }
    if(positive.size()>negative.size()){
        for(int i=0; i<negative.size(); i++){
            ans[2*i]=positive[i];
            ans[2*i+1] = negative[i];
        }
        int index = negative.size()*2;
        for(int i=negative.size(); i<positive.size(); i++){
         ans[index++] = positive[i];   
        }
    }
    else{
        for(int i=0; i<positive.size(); i++){
        ans[2*i]=positive[i];
        ans[2*i+1] = negative[i];
        }
        int index = positive.size()*2;
        for(int i=positive.size(); i<negative.size(); i++){
         ans[index++] = negative[i];   
        }
    }
    return ans;
}

// this is optimal only if number of positives == negatives
vector<int> optimal(vector<int> v){
    int n=v.size();
    vector<int>ans(n,0);
    int pindex = 0, nindex = 1;
    for(int i=0; i<n; i++){
        if(v[i]>0){
            ans[pindex] = v[i];
            pindex+=2;
        }
        else{
            ans[nindex] = v[i];
            nindex+=2;
        }
    }
    return ans;
}
int main(){
    vector<int> v{1,2,-3,4,-5,-6};
    vector<int> ans = bruteForce(v);
    for(auto it: ans)
        cout<<it<<" ";
    
    ans = optimal(v);
    for(auto it: ans)
        cout<<it<<" ";
}