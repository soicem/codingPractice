class Solution {
public:
    vector<vector<string>> ans;
    map<string, vector<string>> prefixMap;
    void backtrack(string s, vector<string> pAns){
        int len = pAns.size();
        
        if(len == s.length()){
            ans.push_back(pAns);
            return;
        }
        
        string key = "";
        
        for(int i = 0; i < len; i++){
            key += pAns[i][len];
        }
        
        for(auto value : prefixMap[key]){
            pAns.push_back(value);
            backtrack(value, pAns);
            pAns.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        for(auto word: words){
            for(int i = 0; i < word.size(); i++){
                string subWord = word.substr(0, i + 1);
                prefixMap[subWord].push_back(word);
            }
        }
        
        for(auto word: words){
            backtrack(word, {word});
        }
        
        return ans;
    }
};
