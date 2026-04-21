#include<iostream>
#include<vector>
using namespace std;
int candy(vector<int> ratings){
    int n = ratings.size();
    vector<int> left(n);
    // vector<int> right(n);
    left[0] = 1;
    for(int i=1; i<n; i++){
        if(ratings[i]>ratings[i-1]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i] = 1;
        }
    }
    // right[n-1] = 1;
    int current = 1, right = 1;
    int sum = max(1,left[n-1]);
    for(int i=n-2; i>=0; i--){
        if(ratings[i]>ratings[i+1]){
            // right[i] = right[i+1] + 1;
            current = right + 1;
            // right = current;
        }
        else{
            // right[i] = 1;
            current = 1;
            // right = current;
        }
        sum += max(left[i],current);
    }

    // int ans = 0;
    // for(int i=0; i<n; i++){
    //     ans = ans + max(left[i],right[i]);
    // }
    // return ans;
    return sum;
}

int candyslope(vector<int>& ratings) {
    int n = ratings.size();
    int i=1;
    int sum=1;
    while(i<n)
    {
        if(ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && ratings[i]>ratings[i-1]){
            peak += 1;
            sum+=peak;
            i++;
        }
        int down = 0;
        while(i<n && ratings[i]<ratings[i-1]){
            down += 1;
            sum += down;
            i++;
        }
        down++;

        if(peak<down){
            sum += (down-peak);
        }
    }
    return sum;
}
int main(){
    vector<int> rating = {0,2,4,3,2,1,1,3,5,6,4,0,0};
    cout<<candy(rating);
    return 0;
}