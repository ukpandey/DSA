#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxSubarray(vector<int> v, int x, int n){
    int len = 0;
     for(int i =0; i<n; i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(sum == x) len = max(len, j-i+1);
            
        }
    }
    return len;
}

int maxSubarray2(vector<int> v, int n, int k){
    unordered_map<int,int> mp;
    int sum = 0;
    int len = 0;
    for(int i = 0; i<n; i++){
        sum+=v[i];
        if(sum == k ){
            len = max(len, i+1);
        }

        int rem = sum - k;

        if(mp.find(rem)!=mp.end()){
            len = max(len, i-mp[rem]);
        }

        if(mp.find(sum) == mp.end()){
             mp[sum] = i;
        }
    }
    return len;
}

int maxSubarray3(vector<int> v, int n, int k){

    int left = 0, right = 0, sum = v[0], len = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=v[left];
            left++;
        }

        if(sum == k){
            len = max(len, right-left+1);
        }
        right++;
        if(right<n){
            sum+=v[right];
        }
        
    }
    return len;
}

int main(){

    vector<int> v {1,2,3,4,5,1,1,1,1,1,1,-1,0,1};
    int x = 6;
    int n = v.size();

    cout<<maxSubarray(v,x,n)<<endl;

    cout<<maxSubarray2(v,n,x)<<endl;

    vector<int> v2{1,2,1,1,1,3};

    cout<<maxSubarray3(v2, v2.size(), 3);


    
}