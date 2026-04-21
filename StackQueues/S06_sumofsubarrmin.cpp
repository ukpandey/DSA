/*
I was confused about the 12 subarrays at first, but after combining two explanations in 
comments, it became clear. Hope this helps!

Consider the array [1,4,6,7,3,7,8,1], where we want to focus on the contribution of
 3 and determine in how many subarrays it will be the minimum.

We eliminate 1 from both ends since it is smaller than 3, leaving us with [4,6,7,3,7,8].

Now, for each subarray in [4,6,7,3,7,8] that starts at any of [4,6,7,3], the possible 
ending values are [3,7,8] (including 3 - since we focusing on 3 as minimum).

There are 4 possible starting points, and for each starting point, 
there are 3 possible ending points. Thus, the total number of subarrays is 4 × 3 = 12.

Example breakdown:
Subarray starting at 4 (includes 3 ends at 3, 7, or 8):
[4,6,7,3]
[4,6,7,3,7]
[4,6,7,3,7,8]

Subarray starting at 6 (includes 3 and ends at 3, 7, or 8):
[6,7,3]
[6,7,3,7]
[6,7,3,7,8]

Subarray starting at 7 (includes 3 and ends at 3, 7, or 8):
[7,3]
[7,3,7]
[7,3,7,8]

Subarray starting at 3 (includes 3 and ends at 3, 7, or 8):
[3]
[3,7]
[3,7,8]

Thus, the total number of valid subarrays is 12

Edge case 

1 4 6 7 3 3 7 8 1
0 1 2 3 4 5 6 7 8

consider index 4

{4,6,7,3}  {4,6,7,3,3} {4,6,7,3,3,7} {4,6,7,3,3,7,8}
{6,7,3}      {6,7,3,3} {6,7,3,3,7} {6,7,3,3,7,8}
{7,3}           {7,3,3} {7,3,3,7} {7,3,3,7,8}
{3}                {3,3} {3,3,7} {3,3,7,8}

for index 5 
{4,6,7,3,3} {6,7,3,3} {7,3,3} {3,3}

output: 

1,1,1,1,4,1,1,1,8,
9,3,2,1,4,3,2,1,1,
127
PS E:\DSAnew\DSA\StackQueues> g++ .\S06_sumofsubarrmin.cpp
PS E:\DSAnew\DSA\StackQueues> .\a.exe
1,1,1,1,4,5,1,1,9,
8,3,2,1,1,3,2,1,1,
127

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubMins(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> left(n), right(n);
    stack<int> st;

    // distance to previous smaller element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    for(auto it:left)
        cout<<it<<",";

    cout<<endl;

    while (!st.empty()) st.pop();

    // distance to next smaller or equal element + Edge case
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? (n - i) : (st.top() - i);
        st.push(i);
    }

    for(auto it:right)
        cout<<it<<",";

    cout<<endl;

    int result = 0;
    for (int i = 0; i < n; i++) {
        
        // Contribution of current element
        result += arr[i] * left[i] * right[i];
    }

    return result;
}

int main() {
    vector<int> arr = {1,4,6,7,3,3,7,8,1};
    cout << sumSubMins(arr) << endl; 
    return 0;
}