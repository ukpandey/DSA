#include <iostream>
#include <vector>
using namespace std;

int max_consecutive_vehicles(const vector<int>& VEHICLE, int M) {
    int n = VEHICLE.size();
    int left = 0; // Left pointer of the sliding window
    int max_length = 0; // Maximum length of consecutive ones encountered so far
    int zeros_count = 0; // Number of zeros within the current window

    for (int right = 0; right < n; ++right) {
        if (VEHICLE[right] == 0) {
            zeros_count++;
        }

        // Shrink the window from the left until the number of zeros within the window is <= M
        while (zeros_count > M) {
            if (VEHICLE[left] == 0) {
                zeros_count--;
            }
            left++;
        }

        // Update the maximum length of consecutive ones within the window
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    vector<int> VEHICLE = {1, 1, 0,0,0, 1, 0, 1, 1, 1, 0, 1};
    int M = 2;
    cout << max_consecutive_vehicles(VEHICLE, M) << endl; // Output: 5

    return 0;
}
