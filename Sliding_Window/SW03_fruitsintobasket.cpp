#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        for (int start = 0; start < fruits.size(); ++start) {
            unordered_map<int, int> basket;
            int currentCount = 0;
            for (int end = start; end < fruits.size(); ++end) {
                basket[fruits[end]]++;
                if (basket.size() > 2) {
                    break;
                }
                currentCount++;
            }
            maxFruits = max(maxFruits, currentCount);
        }
        return maxFruits;
    }

 int totalFruit2(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int maxFruits = 0;
        int left = 0;
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }

int fruitsInBaskets3(vector<int> fruits){
    int n = fruits.size();
    int l=0, r=0;
    int ans = 0;
    unordered_map<int,int> basket;
    while(r<n){
        basket[fruits[r]]++;
        if(basket.size()>2){
            basket[fruits[l]]--;
            if(basket[fruits[l]]==0){
                basket.erase(fruits[l]);
            }
            l++;
        }
        ans = max(r-l+1, ans);
        r++;
    }
    return ans;
}
 //fruits = [1, 2, 3, 2, 2]
int main(){
    vector<int> fruits= {1, 3,2,1, 3, 2, 2};
    cout<<"Total fruits: "<<fruitsInBaskets3(fruits);
    return 0;
}