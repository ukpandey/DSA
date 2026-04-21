/*
Problem Statement: Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.

Examples

Input :cardScore = [1, 2, 3, 4, 5, 6] , k = 3
Output : 15
Explanation :Choosing the rightmost cards will maximize your total score. 
So optimal cards chosen are the rightmost three cards 4 , 5 , 6.
Th score is 4 + 5 + 6 => 15.
*/
#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    // Get the total number of cards
    int n = cardPoints.size();

    // Calculate initial sum by picking first k cards from front
    int total = 0;
    for (int i = 0; i < k; ++i) {
        total += cardPoints[i];
    }

    // Store current max score
    int maxPoints = total;

    // Move the window from front to back k times
    for (int i = 0; i < k; ++i) {
        // Subtract card from front
        total -= cardPoints[k - 1 - i];

        // Add card from back
        total += cardPoints[n - 1 - i];

        // Update max score if needed
        maxPoints = max(maxPoints, total);
    }

    // Return the best score
    return maxPoints;
}
int main() {
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << maxScore(cards, k) << endl;

    return 0;
}