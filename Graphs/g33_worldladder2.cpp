#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

vector<vector<string>> wordLadderLength(vector<string> words, string startWord, string endWord){
    unordered_set<string> visited(words.begin(),words.end());
    vector<vector<string>> ans;
    vector<string> usedOnLevel;
    int level = 0;
    usedOnLevel.push_back(startWord);
    queue<vector<string>> q;
    q.push(usedOnLevel);
    while(!q.empty()){
        vector<string> front = q.front();
        q.pop();
        if(front.size()>level){
            level++;
            for(auto it:usedOnLevel){
                visited.erase(it);
            }
        }
        string word = front.back();
        if(word == endWord){
            if(ans.size()==0) ans.push_back(front);
            else if(ans[0].size() == front.size()) ans.push_back(front);
        }
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(visited.find(word)!=visited.end()){
                    front.push_back(word);
                    q.push(front);
                    usedOnLevel.push_back(word);
                    front.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}
int main(){
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startWord = "hit", endWord = "cog";
    vector<vector<string>> ans = wordLadderLength(words,startWord,endWord);
    for(auto it:ans){
        for(auto it2:it)
            cout<<it2<<"->";
        cout<<endl;
    }
    return 0;
}