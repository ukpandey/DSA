#include<iostream>
#include<vector>
using namespace std;
void reverse(int i, int j, vector<int> &nums){
    if(i>j)
        return;
    cout<<nums[i]<<" "<<nums[j]<<endl;
    swap(nums[i],nums[j]);
    reverse(++i, --j, nums);
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    int i=0;
    int j=nums.size()-1;
    reverse(i,j,nums);
    return nums;

}


// void reverse(string &s, int i){
//     cout<<i<<" "<<s.size()-i-1<<" "<<s<<endl;
//     if(i>s.size()-i-1)
//         return;
//     swap(s[i], s[s.size()-i-1]);
//     reverse(s,i+1 );
// }

bool isPalendrome(string &s, int i, int j){
    if(s[i]!=s[j])
        return false;
    if(i>j)
        return true;
    isPalendrome(s, i+1, j-1);

}

int main(){
//    string s = "Ujjwal";
//    cout<<s<<endl;
//    reverse(s,0);
//    cout<<s<<endl;
//    string s2 = "NttAN";
//    cout<<isPalendrome(s2, 0,4);
 
 vector<int> ans = {1,2,3,4,5};
 reverseArray(5,ans);
 for(auto i:ans)
    cout<<i<<" ";
    


}