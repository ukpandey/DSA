#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0 || s.empty()) return 0;
    unordered_map<char, int> freq;
    int left = 0, right = 0;
    int maxLen = 0;
    while(right<s.length()) {
        freq[s[right]]++;
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;

}
int main() {
    string s = "eceba";
    int k = 2;
    cout <<lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
