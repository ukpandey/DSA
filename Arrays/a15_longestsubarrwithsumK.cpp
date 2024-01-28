#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int bruteForce(vector<int> v, int k)
{
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int c = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            c++;
            if (sum == k)
            {
                ans = max(ans, c);
                break;
            }
            // if (sum > k)
            //     break;
        }
    }
    return ans;
}

// this will work for both 0 and negative integers
int better(vector<int> v, int k)
{
    int n = v.size();
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
            maxLen = max(maxLen, i + 1);
        int rem = sum - k;

        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxLen;
}

// this will work only for positive integers
int optimal(vector<int> v, int k)
{
    int left = 0, right = 0, n = v.size();
    int sum = v[0];
    int maxLen = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= v[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += v[right];
    }
    return maxLen;
}

int main()
{
    vector<int> v{1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k = 3;
    cout << bruteForce(v, k) << endl;
    cout << better(v, k) << endl;
    cout<<optimal(v,k);
}