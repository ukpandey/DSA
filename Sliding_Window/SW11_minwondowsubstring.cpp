#include<iostream>
#include<vector>

using namespace std;

string minWindow(string s, string t){
    if (s.empty() || t.empty()) {
        return "";
    }
    int n = s.size(), m = t.size();
    vector<int> hash(256,0);
    int l=0, r=0, minLen = INT32_MAX, startIndex = -1, count = 0;
    for(auto ch:t){
        hash[ch]++;
    }
    while(r<n){
        if(hash[s[r]]>0){
            count++;
        }
        hash[s[r]]--;
        while(count==m){
            if(r-l+1<minLen){
                minLen = r-l+1;
                startIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0){
                count--;
            }
            l++;
        }
        r++;
    }

    return startIndex==-1?"":s.substr(l,l+minLen);
}
int main(){
    string s = "ddaaabbca", t = "abc";
    return 0;
}

d -2 , -1, 0
a -2 , -1 , 0, 1
b -1
c 0

count 3 hogya, min len 8

count 2 hogya, min len 4