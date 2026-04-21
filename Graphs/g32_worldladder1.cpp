#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

int wordLadderLength(vector<string> words, string startWord, string endWord){
    unordered_set<string> visited(words.begin(),words.end());
    queue<pair<string,int>> q;
    q.push({startWord,1});
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==endWord) return steps;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(visited.find(word)!=visited.end()){
                    visited.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main(){
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startWord = "hit", endWord = "cog";
    cout<<wordLadderLength(words,startWord,endWord);
    return 0;
}