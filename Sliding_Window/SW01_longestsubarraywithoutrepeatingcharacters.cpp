#include<iostream>
#include<vector>
using namespace std;

int longestNonRepeatingSubstringBrute(string &s) {
        int n = s.size(); 
        int maxLen = 0;    
        for (int i = 0; i < n; i++) {
            vector<int> hash(256, 0);  
            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1) break;  
                hash[s[j]] = 1;
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen; 
 }

int longestNonRepeatingSubstring(string s){
    int n = s.size();
    int l=0, r=0;
    int ans = INT32_MIN;
    vector<int> hash(256,-1);
    while(r<n){
        if(hash[s[r]!=-1]){
            if(l<hash[s[r]]+1){
                 l = hash[s[r]]+1;
            }        
        }
        ans = max(r-l+1,ans);
        hash[s[r]]=r;
        r++;
    }
    return ans;
}


int main(){
    string s = "cabdbzacd"; 
    

    int result = longestNonRepeatingSubstring(s);

    cout << "The maximum length is:\n";
    cout << result << endl;
    return 0;
}