#include<iostream>
#include<vector>
using namespace std;

vector<int> aestoridCollisions(vector<int> aestroids){
    vector<int> ans;
    for(int i=0; i<aestroids.size(); i++){

        /* Push the asteroid in stack if a 
        right moving asteroid is seen */
        if(aestroids[i]>0){
            ans.push_back(aestroids[i]);
        }

        /* Else if the asteroid is moving 
        right, perform the collisions */
        else{

            /* Until the right moving asteroids are 
            smaller in size, keep on destroying them */
            while(!ans.empty() && ans.back()>0 && 
             ans.back() < abs(aestroids[i])){
                ans.pop_back();
            }
            /* If there is right moving asteroid 
            which is of same size */
            if(ans.back() == abs(aestroids[i])){
                ans.pop_back();
            }
            /* Otherwise, if there is no left
            moving asteroid, the right moving 
            asteroid will not be destroyed */
            else if(ans.empty() or ans.back()<0){
                ans.push_back(aestroids[i]);
            }
        }
    }
    return ans;
}
int main(){
    vector<int> v = {4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans = aestoridCollisions(v);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}