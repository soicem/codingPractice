class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == "" || endWord == "" || wordList.empty()){
            return 0;
        }
        
        int L = wordList.size();
        map<string, vector<string>> umap;
        map<string, int> visited;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < wordList[i].length(); j++){
                string s = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
                umap[s].push_back(wordList[i]);    
            }
        }
        
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        int level;
        while(!que.empty()){
            string word = que.front().first;
            level = que.front().second;
            que.pop();
            if(word == endWord){
                return level;
            }
            if(visited[word] != 0){
                continue;
            }
            visited[word] = 1;
            
            for(int j = 0; j < word.length(); j++){
                string s = word.substr(0, j) + "*" + word.substr(j + 1);
                for(auto v : umap[s]){
                    que.push(make_pair(v, level + 1));
                }
            }
        }
        
        return 0;
    }
};
