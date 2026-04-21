#include <bits/stdc++.h>
using namespace std;

    // Binary search to find the first index where value >= x
int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // Default if x not found

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;       // Possible answer
            high = mid - 1;  // Look for smaller index
        } else {
            low = mid + 1;   // Search right half
        }
    }
    return ans;
}

    // Find row with max number of 1s
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int cnt_ones = m - lowerBound(matrix[i], m, 1);  // 1s = total - index of first 1
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int rowWithMax1s(vector<vector<bool>>& mat) {
    int maxRow = -1, row = 0;
    int R = mat.size();
    int C = mat[0].size();
    int col = C - 1;

    // Move till we are inside the matrix
    while (row < R && col >= 0) {
        // If the current value is 0, move down to the next row
        if (mat[row][col] == 0) {
            row += 1;
        }
        // Else if the current value is 1, update ans and
        // move to the left column
        else {
            maxRow = row;
            col -= 1;
        }
    }
    return maxRow;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}
