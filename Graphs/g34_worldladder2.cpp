class Solution {
public:
    map<string,int> mp;
    
    void dfs(string endWord,string beginWord, vector<vector<string>> &vec,vector<string> &vs){
        if(endWord==beginWord){
            reverse(vs.begin(),vs.end());
            vec.push_back(vs);
            reverse(vs.begin(),vs.end());
            return;
        }
        for(int j=0;j<endWord.size();j++){
                    string ss=endWord;
                    for(char c='a';c<='z';c++){
                        ss[j]=c;
                        if(mp.find(ss)!=mp.end() && mp[ss]+1==mp[endWord])
                    {vs.push_back(ss);dfs(ss,beginWord,vec,vs);vs.pop_back();}    
                    }
                }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> s;
        for(string i : wordList){
            s.insert(i);
        }
        s.erase(beginWord);
        q.push(beginWord);
        int h=0;
        while(!q.empty()){
            int l=q.size();h++;
            while(l--){
                string i=q.front();
                mp[i]=h;
                q.pop();
                for(int j=0;j<i.size();j++){
                    string ss=i;
                    for(char c='a';c<='z';c++){
                        ss[j]=c;
                        if(s.find(ss)!=s.end()) {q.push(ss);s.erase(ss);}
                    }
                }
            }
        }vector<vector<string>> vec;
        if(mp.find(endWord)!=mp.end()){
            vector<string> vs;
            vs.push_back(endWord);
            dfs(endWord, beginWord,vec,vs);
        }return vec;
    }
};