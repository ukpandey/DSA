#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char, int> mp;
    for(auto it:s){
            mp[it]++;
    }
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}