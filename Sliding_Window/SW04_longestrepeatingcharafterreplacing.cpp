/*
Problem Statement: Given an integer k and a string s, any character in the string can 
be selected and changed to any other uppercase English character. This operation can be performed up to k times. 
After completing these steps, return the length of the longest substring that contains the same letter.

Examples
Input: s = "BAABAABBBAAA", k = 2
Output: 6
Explanation: We can change the B at index 0 and 3 (0-based indexing) to A.The new string becomes "AAAAAABBBAAA".
  The substring "AAAAAA" is the longest substring with the same letter, and its length is 6.
*/
#include<iostream>
#include<vector>
using namespace std;

int characterReplacement1(string s, int k) {
    vector<int> freq(26, 0);
    int left = 0, right = 0;
    int maxCount = 0;
    int maxLength = 0;
    while (right < s.size()) {
        freq[s[right] - 'A']++;
        maxCount = max(maxCount, freq[s[right] - 'A']);
        while ((right - left + 1) - maxCount > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}
         
int characterReplacement2(string s, int k) {
    int n = s.size();
    int l=0, r=0;
    vector<int> hash(26,0);
    int maxFrequency=0, windowSize;
    int ans = 0;
    while(r<n){
        hash[s[r]-'A']++;
        maxFrequency = max(maxFrequency,hash[s[r]-'A']);
        windowSize = r-l+1;
        if(windowSize-maxFrequency>k){
            hash[s[l]='A']--;
            l++;
        }
        ans = max(r-l+1,ans);
        r++;
    }
    return ans;
}

int main(){
    string s = "BAABAABBBAAA";
    int k = 2;
    cout<<characterReplacement2(s,k);
    return 0;
}