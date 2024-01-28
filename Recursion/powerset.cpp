#include<iostream>
#include<vector>
using namespace std;
void solve(int i, vector<int> nums, vector<int> output, vector<vector<int>> &ans){
    //base case
    if(i>=nums.size()){
        ans.push_back(output);
        return;
    }

    solve(i+1, nums, output, ans);
    output.push_back(nums[i]);
    solve(i+1,nums,output,ans);
}

int main(){
    vector<int> nums = {1,2};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(index,nums,output,ans);
//     for(int i =0; i < ans.size(); i++){
//         for(auto it = ans.begin(); it != ans.end(); it++)
//         {
//             cout<<*it<<" ";
//         }
//         cout<<endl;
// }
    for(int i =0; i<ans.size(); i++){
        cout<<"{ ";
        for( int j =0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
            cout<<"}";
        cout<<endl;
    }
   cout<<ans.size();

}